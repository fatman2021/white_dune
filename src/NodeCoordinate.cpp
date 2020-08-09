/*
 * NodeCoordinate.cpp
 *
 * Copyright (C) 1999 Stephen F. White
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program (see the file "COPYING" for details); if 
 * not, write to the Free Software Foundation, Inc., 675 Mass Ave, 
 * Cambridge, MA 02139, USA.
 */

#include <stdio.h>
#include "stdafx.h"
#include "math.h"

#ifndef FLT_MAX 
# include <float.h>
#endif

#include "NodeCoordinate.h"
#include "Node.h"
#include "Proto.h"
#include "MFVec3f.h"
#include "ExposedField.h"
#include "Field.h"
#include "RenderState.h"
#include "DuneApp.h"
#include "Util.h"
#include "Vec3f.h"
#include "Scene.h"
#include "resource.h"
#include "FaceData.h"
#include "NodeIndexedFaceSet.h"
#include "NodeIndexedLineSet.h"
#include "NodePointSet.h"
#include "NodeLineSet.h"
#include "NodeTriangleSet.h"
#include "NodeTriangleFanSet.h"
#include "NodeTriangleStripSet.h"
#include "NodeIndexedTriangleSet.h"
#include "NodeIndexedTriangleFanSet.h"
#include "NodeIndexedTriangleStripSet.h"
#include "NodeQuadSet.h"
#include "NodeIndexedQuadSet.h"
#include "NodeNurbsGroup.h"
#include "NodeNurbsSurface.h"
#include "NodeNurbsCurve.h"
#include "NodeNurbsTrimmedSurface.h"
#include "NodeHAnimHumanoid.h"
#include "NodeHAnimJoint.h"
#include "Path.h"

enum {
     SIDE_RIGHT = 0,
     SIDE_LEFT = 1,
     SIDE_NONE = 2,
     SIDE_BOTH = 3
};

ProtoCoordinate::ProtoCoordinate(Scene *scene)
  : WonderlandExportProto(scene, "Coordinate")
{
    point.set(
          addExposedField(MFVEC3F, "point", new MFVec3f()));
    setFieldFlags(point, EIF_RECOMMENDED);
}

Node *
ProtoCoordinate::create(Scene *scene)
{ 
    return new NodeCoordinate(scene, this); 
}

NodeCoordinate::NodeCoordinate(Scene *scene, Proto *def)
  : Node(scene, def)
{
    m_matrix = Matrix::identity();
}

void
NodeCoordinate::setField(int index, FieldValue *value, int cf)
{
    bool setNurbsField = false;
    if (hasParent()) {
        for (int i = 0; i < getNumParents(); i++) {
            Node *parent = getParent(i);
            if (parent->getType() == VRML_NURBS_CURVE) {
                MFVec3f *newValue = new MFVec3f((MFVec3f *)value);
                newValue->ref();
                ((NodeNurbsCurve *)parent)->setControlPoints(newValue);
                setNurbsField = true;
            } else
                parent->update();
        }
    }
    if (!setNurbsField)        
        Node::setField(index, value, cf);
}

void
NodeCoordinate::drawHandles(void)
{
    if (m_scene->getVertexModifier())
        return;
    if (TheApp->getDrawAvoided() && !m_scene->isTranslation())
        return;

    RenderState state;

    glPushAttrib(GL_LIGHTING);
    glDisable(GL_LIGHTING);
    glPushName(0);

    bool showPoints = false;
    if (hasParent()) {
        if (getParent()->getType() == VRML_NURBS_CURVE)
            showPoints = true;
        if (getParent()->getType() == VRML_NURBS_CURVE_2D)
            showPoints = true;
        if (getParent()->getType() == VRML_INDEXED_LINE_SET)
            showPoints = true;
        if (getParent()->getType() == VRML_POINT_SET)
            showPoints = true;
    }
    int mode = m_scene->getSelectionMode();
    MyMesh *mesh = getMesh();
    if ((mode == SELECTION_MODE_VERTICES) || showPoints) {
        state.startDrawHandles();
        for (int ci = 0; ci < point()->getSFSize(); ci++) {
            bool hidden = false;
            for (int i = 0; i < m_scene->getNumHiddenVertices(); i++)
                if (m_scene->getHiddenVertex(i) == ci) {
                    hidden = true;
                    break;
                }
            if (hidden)
                continue;
            state.setHandleColor(m_scene, ci);
            glLoadName(ci);
            state.drawHandle(Vec3f(point()->getValue(ci)));
        }
        state.endDrawHandles();
    } else if (mode == SELECTION_MODE_FACES) {
        if (mesh == NULL) {
            glPopName();
            glPopAttrib();
            return;
        }
        if (mesh) {
            if (mesh->ccw())
               glFrontFace(GL_CCW);
            else 
               glFrontFace(GL_CW);
        }
        state.startDrawHandles();
        MFInt32 *ci = mesh->getCoordIndex();
        for (int i = 0; i < mesh->getNumFaces(); i++) {
            FaceData *face = mesh->getFace(i);
            int offset = face->getOffset();

            glEnable(GL_COLOR_MATERIAL);
            glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE); 

            if (m_scene->isInSelectedHandles(i))
                Util::myGlColor3f(1.0f, 1.0f, 1.0f);
            else
                Util::myGlColor4f(0.8f, 0.8f, 0.8f, 0.0f);
            glLineWidth(2.0f);
            glPolygonMode(GL_FRONT, GL_LINE);
            glLoadName(NO_HANDLE);
            glBegin(GL_POLYGON);
            for (int j = offset; j < offset + face->getNumVertices(); j++) {
                if (ci->getValue(j) >= point()->getSFSize())
                    continue;
                Vec3f vec = point()->getValue(ci->getValue(j));
                Vec3f w = state.project(vec);
                glVertex3f(w.x, w.y, w.z);
            }
            glEnd();

            Util::myGlColor4f(0.8f, 0.8f, 0.8f, 0.0f);

            glEnable(GL_POLYGON_OFFSET_FILL);
            glPolygonOffset(0.0f, 2.0f);

            glPolygonMode(GL_FRONT, GL_FILL);

            glLineWidth(1.0f);

            glLoadName(i);
            glBegin(GL_POLYGON);
            for (int j = offset; j < offset + face->getNumVertices(); j++) {
                if (ci->getValue(j) >= point()->getSFSize())
                    continue;
                Vec3f vec = point()->getValue(ci->getValue(j));
                Vec3f w = state.project(vec);
                glVertex3f(w.x, w.y, w.z);
            }
            glEnd();

            glPolygonOffset(0.0f, 0.0f);
            glDisable(GL_POLYGON_OFFSET_FILL);
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
        state.endDrawHandles();
    } else if (mode == SELECTION_MODE_LINES) {
        if (mesh == NULL) {
            glPopName();
            glPopAttrib();
            return;
        }
        if (mesh) {
            if (mesh->ccw())
               glFrontFace(GL_CCW);
            else 
               glFrontFace(GL_CW);
        }
        state.startDrawHandles();
        MFInt32 *ci = mesh->getCoordIndex();
        for (int i = 0; i < mesh->getNumLines(); i++) {
            glEnable(GL_COLOR_MATERIAL);
            glColorMaterial(GL_BACK, GL_AMBIENT_AND_DIFFUSE); 

            int numLine = mesh->getLine(i).begin;
            if (m_scene->isInSelectedHandles(numLine))
                Util::myGlColor3f(0.0f, 1.0f, 0.0f);
            else
                Util::myGlColor3f(1.0f, 1.0f, 1.0f);

            glLoadName(numLine);
            glBegin(GL_LINES);
            if (numLine >= ci->getSFSize()) {
                glEnd();                
                continue;
            }
            if (ci->getValue(numLine) >= point()->getSize()) {
                glEnd();                
                continue;
            }
           Vec3f vec = point()->getValue(ci->getValue(numLine));
            Vec3f w = state.project(vec);
            glVertex3f(w.x, w.y, w.z);
            if (mesh->getLine(i).end >= ci->getSFSize()) {
                glEnd();                
                continue;
            }
            if (ci->getValue(mesh->getLine(i).end) >= point()->getSize()) {
                glEnd();                
                continue;
            }
            vec = point()->getValue(ci->getValue(mesh->getLine(i).end));
            w = state.project(vec);
            glVertex3f(w.x, w.y, w.z);
            glEnd();
        }
        state.endDrawHandles();
    } if (mode == SELECTION_HANIM_JOINT_WEIGHT) {
        NodeHAnimHumanoid *human = this->getHumanoid();
        if (human != NULL) {
            state.startDrawHandles();
            NodeHAnimJoint *joint = (NodeHAnimJoint *)
                                    m_scene->getLastSelectedHAnimJoint();
            if (joint) {
                for (int ci = 0; ci < point()->getSFSize(); ci++)
                    if (joint->skinCoordIndex()->find(ci) > -1) { 
                        bool hidden = false;
                        for (int i = 0; i < m_scene->getNumHiddenVertices(); 
                             i++)
                            if (m_scene->getHiddenVertex(i) == ci) {
                                hidden = true;
                                break;
                            }
                        if (hidden)
                           continue;
                        state.setHandleColor(m_scene, ci);
                        glLoadName(ci);
                        state.drawHandle(Vec3f(point()->getValue(ci)));
                    }
            } else {
                human->buildJointHasWeightArray();
                MyArray<int> *arrayPtr = human->getJointHasNoWeightArray();
                for (long i = 0; i < (*arrayPtr).size(); i++) {
                    int ci = (*arrayPtr)[i];
                    bool hidden = false;
                    for (int i = 0; i < m_scene->getNumHiddenVertices(); i++)
                        if (m_scene->getHiddenVertex(i) == ci) {
                            hidden = true;
                            break;
                        }
                    if (hidden)
                        continue;
                    state.setHandleColor(m_scene, ci);
                    glLoadName(ci);
                    state.drawHandle(Vec3f(point()->getValue(ci)));
                }
            }
            state.endDrawHandles();
        }
    }
    glPopName();
    glPopAttrib();
}

Vec3f
NodeCoordinate::getHandle(int handle, int *constraint, int *field)
{
    *field = point_Field() ;

    int mode = m_scene->getSelectionMode();
    if (mode == SELECTION_MODE_VERTICES) {
        if (handle >= 0 && handle < point()->getSFSize()) {
            Vec3f ret((Vec3f)point()->getValue(handle));
            TheApp->PrintMessageWindowsVertex(IDS_VERTEX_SELECTED, "point", 
                                              handle, 
                                              (Vec3f)point()->getValue(handle));
            return ret;
        }
    } else if (mode == SELECTION_MODE_FACES) {
        MyMesh *mesh = getMesh();
        if (mesh == NULL)
            return Vec3f(0.0f, 0.0f, 0.0f);
        MFInt32 *ci = mesh->getCoordIndex();
        if (handle >= 0 && handle < mesh->getNumFaces()) {
            FaceData *face = mesh->getFace(handle);
            int offset = face->getOffset();
            int numVertices = face->getNumVertices();
            MyString status = "";
            if (handle >= 0) {
                status.catInt(handle);
                status += ": ";
                for (int i = offset; i < offset + numVertices; i++) {
                    Vec3f vec = point()->getVec(ci->getValue(i));
                    status.catFloat(vec.x);
                    status += ",";
                    status.catFloat(vec.y);
                    status += ",";
                    status.catFloat(vec.z);
                    status += " (";
                    status.catInt(ci->getValue(i));
                    status += ")";
                    status += " ";
                }
                TheApp->PrintMessageWindowsString(IDS_FACE_SELECTED, 
                                                  (const char *)status);
            }
            Vec3f first;
            if (face->getNumVertices() > 0)
                first = point()->getValue(ci->getValue(offset));
            return first;
        }
    } else if (mode == SELECTION_MODE_LINES) {
        MyMesh *mesh = getMesh();
        if (mesh == NULL)
            return Vec3f(0.0f, 0.0f, 0.0f);
        MFInt32 *ci = mesh->getCoordIndex();
        if (handle >= 0 && handle < ci->getSFSize()) {
            MyString status = "";
            if (handle >= 0) {
                status.catInt(handle);
                status += ": ";
                status += " (";
                int h1 = handle;
                if (h1 >= point()->getSize()) {
                   Vec3f first = point()->getValue(ci->getValue(handle));
                   return first;
                }
                Vec3f vec = point()->getValue(ci->getValue(h1));
                status.catFloat(vec.x);
                status += ",";
                status.catFloat(vec.y);
                status += ",";
                status.catFloat(vec.z);
                status += ")";
                status += " ";
                int h2 = mesh->getLine(handle).end;
                if (h2 >= point()->getSize()) {
                    Vec3f first = point()->getValue(ci->getValue(handle));
                    return first;
                }
                vec = point()->getValue(ci->getValue(h2));
                status += "(";
                status.catFloat(vec.x);
                status += ",";
                status.catFloat(vec.y);
                status += ",";
                status.catFloat(vec.z);
                status += ")";
                TheApp->PrintMessageWindowsString(IDS_LINES_SELECTED, 
                                                  (const char *)status);
            }
            Vec3f first = point()->getValue(ci->getValue(handle));
            return first;
        }
    }
    if (mode == SELECTION_HANIM_JOINT_WEIGHT) {
        if (handle >= 0 && handle < point()->getSFSize()) {
            Vec3f ret((Vec3f)point()->getValue(handle));
            TheApp->PrintMessageWindowsVertex(IDS_VERTEX_SELECTED, "point", 
                                              handle, 
                                              (Vec3f)point()->getValue(handle));
            return ret;
        }
    }
    return Vec3f(0.0f, 0.0f, 0.0f);
}

void
NodeCoordinate::setMatrix(const Vec3f &v)
{
    TransformMode *tm = m_scene->getTransformMode();
    m_matrix = Matrix::identity();
    if (tm->getMode() == TM_TRANSLATE)
        return;
    NodeTransform *trans = (NodeTransform *)
                           m_scene->searchTransform()->getNode();
    if (trans) {
         trans = (NodeTransform *)trans->copy();
         switch (tm->getMode()) {
           case TM_ROTATE:
             trans->setHandle(ROTATION, v * 10);
             trans->getMatrix(m_matrix);
             if (!m_matrix.isValid())
                 m_matrix = Matrix::identity();
             break;
           case TM_SCALE:
             trans->setHandle(SCALE, v * 0.1);
             trans->getMatrix(m_matrix);
             if (!m_matrix.isValid())
                 m_matrix = Matrix::identity();
             break;
         }
    }
}

void
NodeCoordinate::setHandle(int handle, const Vec3f &v)
{
    int mode = m_scene->getSelectionMode();
    if (mode == SELECTION_MODE_VERTICES)
        setHandleVertices(handle, v);
    else if (mode == SELECTION_MODE_FACES)
        setHandleFaces(handle, v);
    else if (mode == SELECTION_MODE_LINES)
        setHandleLines(handle, v);
}

void
NodeCoordinate::setBeginHandles(void)
{
    if (!m_scene->isTranslation())
        TheApp->disableDraw();;

    m_selectedVerticesHandles.resize(0);
    m_selectedVertices.resize(0);
    m_selectedVertices2.resize(0);
    m_selectedVerticesWithoutX.resize(0);
    m_validSymVerticesHandles.resize(0);
}

void
NodeCoordinate::setEndHandles(void)
{
    MyMesh *mesh = getMesh();
    if (mesh == NULL)
        return;
    if (!m_scene->isTranslation())
        TheApp->enableDraw();
    if ((m_scene->getSelectionMode() == SELECTION_MODE_FACES) ||
        (m_scene->getSelectionMode() == SELECTION_MODE_LINES)) {
        for (long i = 0; i < m_selectedVerticesHandles.size(); i++)
            setHandleVertices(m_selectedVerticesHandles[i], 
                              m_selectedVertices2[i]);
    }
    if (!m_scene->isTranslation())
        update();
}

void
NodeCoordinate::setHandleFaces(int handle, const Vec3f &v)
{
    m_scene->addSelectedHandle(handle);
    MyMesh *mesh = getMesh();
    if (mesh == NULL)
        return;
    float epsilon = TheApp->GetHandleEpsilon();
    MFInt32 *ci = mesh->getCoordIndex();
    if (handle >= mesh->getNumFaces())
        return;
    FaceData *face = mesh->getFace(handle);
    int offset = face->getOffset();
    Vec3f first;
    if (face->getNumVertices() > 0)
        first = point()->getValue(ci->getValue(offset));
    int side = SIDE_BOTH;
    bool allLeft = true;
    for (int j = offset; j < offset + face->getNumVertices(); j++) {
        Vec3f vec = point()->getValue(ci->getValue(j));
        if (vec.x <= 0) {
            allLeft = false;
            break;
        }
    }
    bool allRight = true;
    for (int j = offset; j < offset + face->getNumVertices(); j++) {
        Vec3f vec = point()->getValue(ci->getValue(j));
        if (vec.x >= 0) {
            allRight = false;
            break;
        }
    }
    if (allRight && !allLeft)
        side = SIDE_RIGHT;
    if (allLeft && !allRight)
        side = SIDE_LEFT;
    if (v.z > v.x && v.z > v.y)
        side = SIDE_NONE;
    for (int j = offset; j < offset + face->getNumVertices(); j++) {
        Vec3f vec = point()->getValue(ci->getValue(j));
        Vec3f yzFirst (0, first.y, first.z);
        Vec3f vec2 = vec;
        switch (side) {
          case SIDE_BOTH:
          case SIDE_RIGHT:
          case SIDE_LEFT:
            vec2 = vec2 - first;;
            vec2.x += v.x;
            vec2.y += v.y;
            vec2.z += v.z;
            break;
          case SIDE_NONE:
            vec2 = vec2 - yzFirst;;
            vec2.y += v.y;
            vec2.z += v.z;
        }
        Vec3f vecWithoutX = vec2;
        vecWithoutX.x = 0;
        bool validSymVerticesHandles = false;
        bool isInSelectedVertices = false;
        for (long n = 0; n < m_selectedVertices.size(); n++) {
            if (m_selectedVerticesHandles[n] == ci->getValue(j)) {
                isInSelectedVertices = true;
                break;
            }    
            if ((!isInSelectedVertices) && m_scene->getXSymetricMode() &&
                (fabsf(m_selectedVertices[n].x + vec.x) < epsilon) &&
                (fabsf(m_selectedVertices[n].y - vec.y) < epsilon) &&
                (fabsf(m_selectedVertices[n].z - vec.z) < epsilon)) {
                validSymVerticesHandles = true;
                m_validSymVerticesHandles[n] = true;
                break;
            }
        }          
        if (!isInSelectedVertices) {
            m_selectedVerticesHandles.append(ci->getValue(j));
            m_selectedVertices.append(vec);
            m_selectedVertices2.append(vec2);
            m_selectedVerticesWithoutX.append(vecWithoutX);
            m_validSymVerticesHandles.append(validSymVerticesHandles);
        }
    }
}

void
NodeCoordinate::setHandleLines(int handle, const Vec3f &v)
{
    MyMesh *mesh = getMesh();
    if (mesh == NULL)
        return;
    float epsilon = TheApp->GetHandleEpsilon();
    MFInt32 *ci = mesh->getCoordIndex();
    if (handle >= ci->getSFSize())
        return;
    int index = -1;
    for (int i = 0; i < mesh->getNumLines(); i++)
        if (mesh->getLine(i).begin == handle) {
            index = i;
            break;
        }
    if (index < 0)
        return;
    int index1 = mesh->getLine(index).begin;
    int index2 = mesh->getLine(index).end;
    Vec3f vec = point()->getValue(ci->getValue(index1));
    Vec3f first = vec;
    Vec3f vec2 = vec + v - first;
    Vec3f vecWithoutX = vec2;
    vecWithoutX.x = vec.x;
    bool validSymVerticesHandles = false;
    bool isInSelectedVertices = false;
    for (long n = 0; n < m_selectedVertices.size(); n++) {
        if (m_selectedVerticesHandles[n] == ci->getValue(index1)) {
            isInSelectedVertices = true;
            break;
        }   
        if ((fabsf(m_selectedVertices[n].x + vec.x) < epsilon) &&
            (fabsf(m_selectedVertices[n].y - vec.y) < epsilon) &&
            (fabsf(m_selectedVertices[n].z - vec.z) < epsilon)) {
            m_validSymVerticesHandles[n] = true;            
            validSymVerticesHandles = true;
            break;
        }          
    } 
    if (!isInSelectedVertices) {
        m_selectedVerticesHandles.append(ci->getValue(index1));
        m_selectedVertices.append(vec);
        m_selectedVertices2.append(vec2);
        m_selectedVerticesWithoutX.append(vecWithoutX);
        m_validSymVerticesHandles.append(validSymVerticesHandles);
    }
    vec = point()->getValue(ci->getValue(index2));
    vec2 = vec + v - first;
    isInSelectedVertices = false;
    for (long n = 0; n < m_selectedVertices.size(); n++) {
        if (m_selectedVerticesHandles[n] == ci->getValue(index2))
        {
            isInSelectedVertices = true;
            break;
        }    
        if (m_scene->getXSymetricMode() &&
            (fabsf(m_selectedVertices[n].x + vec.x) < epsilon) &&
            (fabsf(m_selectedVertices[n].y - vec.y) < epsilon) &&
            (fabsf(m_selectedVertices[n].z - vec.z) < epsilon)) {
            validSymVerticesHandles = true;
            m_validSymVerticesHandles[n] = true;
            break;
        }          
    }
    if (!isInSelectedVertices) {
        m_selectedVerticesHandles.append(ci->getValue(index2));
        m_selectedVertices.append(vec);
        m_selectedVertices2.append(vec2);
        m_selectedVerticesWithoutX.append(vecWithoutX);
        m_validSymVerticesHandles.append(validSymVerticesHandles);
    }
}

void
NodeCoordinate::setHandleVertices(int handle, const Vec3f &v)
{
    MFVec3f *newValue = new MFVec3f(*point());

    float epsilon = TheApp->GetHandleEpsilon();
    int numPoints = point()->getSFSize();
    if (handle >= 0 && handle < numPoints) {
        Vec3f oldV = point()->getValue(handle);
        TransformMode *tm = m_scene->getTransformMode();
        Vec3f newV = v;
        if (!tm->hasTranslation())
            newV = m_matrix * oldV;
/*
        if ((v.x == - oldV.x) && (v.x != 0.0f))
            return;
        if (m_scene->getXSymetricMode() && (fabsf(oldV.x) < epsilon))
            newValue->setValue(handle * 3, 0);
        else
*/
        newValue->setValue(handle * 3, newV.x);
        newValue->setValue(handle * 3 + 1, newV.y);
        newValue->setValue(handle * 3 + 2, newV.z);
        // set other handles for symetric modelling
        // which also snap handles at the same place
        setHandle(newValue, handle, newV, oldV, true, true);
        if (m_scene->getXSymetricMode()) {
            NodeNurbsGroup *nurbsGroup = findNurbsGroup();
            if (nurbsGroup)
               nurbsGroup->setHandle(this, 1, newV, oldV);
        }
    }
}

bool
NodeCoordinate::setHandle(MFVec3f *value, int handle,
                          const Vec3f &newV, const Vec3f &oldV,
                          bool already_changed, bool bypassChecks)
{
    bool ret = false;
    bool changed = false;
    MFVec3f *newValue = (MFVec3f *) value->copy();

    if (m_scene->getXSymetricMode()) {
        float epsilon = TheApp->GetHandleEpsilon();
        int numPoints = newValue->getSize() / 3;
        for (int i = 0; i < numPoints; i++) {
            if (i != handle) {
                Vec3f vPoint = point()->getValue(i);
                if (   (fabsf(vPoint.z - oldV.z) < epsilon) 
                    && (fabsf(vPoint.y - oldV.y) < epsilon)) {
                    if (fabsf(vPoint.x - oldV.x) < epsilon) {
                        ret = true;
                        changed = true;
                        if (fabsf(oldV.x) < epsilon)
                            newValue->setValue(i * 3, 0);
                        else
                            newValue->setValue(i * 3, newV.x);
                        newValue->setValue(i * 3 + 1, newV.y);
                        newValue->setValue(i * 3 + 2, newV.z);
                    } else if (fabsf(vPoint.x + oldV.x) < epsilon) {
                        ret = true;
                        changed = true;
                        if (fabsf(oldV.x) < epsilon)
                            newValue->setValue(i * 3, 0);
                        else
                            newValue->setValue(i * 3, - newV.x);
                        newValue->setValue(i * 3 + 1,   newV.y);
                        newValue->setValue(i * 3 + 2,   newV.z);
                    }  
                }                 
            }
        }
    }
    if (already_changed | bypassChecks)
        changed = true;

    if (changed) {
        m_scene->setField(this, point_Field(), newValue);
    }
    return ret;
}

bool
NodeCoordinate::checkHandle(int handle)
{
    if (m_scene->getSelectionMode() == SELECTION_MODE_VERTICES) {
       MFVec3f *points = point();
       if (points && (points->getSize() > 0) && 
            m_scene->getXSymetricMode()) {
            float epsilon = TheApp->GetHandleEpsilon();
            Vec3f hPoint = point()->getValue(handle);
            for (int i = 0; i < m_scene->getSelectedHandlesSize(); i++) {
                if (!validHandle(m_scene->getSelectedHandle(i)))
                    continue;
                if (m_scene->getSelectedHandle(i) == handle) 
                   return true;
                else {
                    if (m_scene->getSelectedHandle(i) >= point()->getSFSize()) 
                        continue;
                    Vec3f vPoint = point()->getValue(
                                       m_scene->getSelectedHandle(i));
                    if ((fabsf(vPoint.z - hPoint.z) < epsilon) &&
                        (fabsf(vPoint.y - hPoint.y) < epsilon)) {
                        if (fabsf(vPoint.x - hPoint.x) < epsilon)
                            return true;
                        else if (fabsf(vPoint.x + hPoint.x) < epsilon)
                            return true;  
                    }                 
                }
            }
        }
    } else if (m_scene->getSelectionMode() == SELECTION_MODE_FACES) {
        if (!m_scene->getXSymetricMode())
            return false;
        MyMesh *mesh = getMesh();
        if (mesh == NULL)
            return false;
        float epsilon = TheApp->GetHandleEpsilon();
        if (handle >= mesh->getNumFaces())
            return false;
        MFInt32 *ci = mesh->getCoordIndex();
        FaceData *hFace = mesh->getFace(handle);
        int hOffset = hFace->getOffset();
        for (int i = 0; i < m_scene->getSelectedHandlesSize(); i++) {
            FaceData *face = mesh->getFace(m_scene->getSelectedHandle(i));
            int offset = face->getOffset();
            int vertSym = 0;
            for (int j = 0; j < face->getNumVertices(); j++) {
                Vec3f vPoint = point()->getValue(ci->getValue(offset + j));
                for (int n = 0; n < face->getNumVertices(); n++) {
                    Vec3f hPoint = point()->getValue(ci->getValue(hOffset + n));
                    if ((fabsf(vPoint.z - hPoint.z) < epsilon) &&
                        (fabsf(vPoint.y - hPoint.y) < epsilon) &&
                        (fabsf(vPoint.x + hPoint.x) < epsilon))
                        vertSym++;
                }                 
            if (vertSym == face->getNumVertices())
               return true;  
            }
        }
    }
    return false;
}

int
NodeCoordinate::getMaxHandle(void)
{
    if (point() == NULL)
        return 0;
    int mode = m_scene->getSelectionMode();
    if (mode == SELECTION_MODE_VERTICES)
        return point()->getSFSize() - 1;
    else if (mode == SELECTION_MODE_FACES) {
        MyMesh *mesh = getMesh();
        if (mesh == NULL)
            return 0;
        return mesh->getNumFaces();
    }     

    return point()->getSFSize() - 1;
}

void 
NodeCoordinate::draw(Node *node)
{
    switch (node->getType()) {
      case VRML_INDEXED_FACE_SET:
        ((NodeIndexedFaceSet *)node)->meshDraw();
        break;
      case VRML_INDEXED_LINE_SET:
        ((NodeIndexedLineSet *)node)->lineDraw();
        break;
      case VRML_POINT_SET:
        ((NodePointSet *)node)->pointDraw();
        break;
      case X3D_LINE_SET:
        ((NodeLineSet *)node)->lineDraw();
        break;
      case X3D_TRIANGLE_SET:
        ((NodeTriangleSet *)node)->meshDraw();
        break;
      case X3D_TRIANGLE_FAN_SET:
        ((NodeTriangleFanSet *)node)->meshDraw();
        break;
      case X3D_TRIANGLE_STRIP_SET:
        ((NodeTriangleStripSet *)node)->meshDraw();
        break;
      case X3D_INDEXED_TRIANGLE_SET:
        ((NodeIndexedTriangleSet *)node)->meshDraw();
        break;
      case X3D_INDEXED_TRIANGLE_FAN_SET:
        ((NodeIndexedTriangleFanSet *)node)->meshDraw();
        break;
      case X3D_INDEXED_TRIANGLE_STRIP_SET:
        ((NodeIndexedTriangleStripSet *)node)->meshDraw();
        break;
      case X3D_QUAD_SET:
        ((NodeQuadSet *)node)->meshDraw();
        break;
      case X3D_INDEXED_QUAD_SET:
        ((NodeIndexedQuadSet *)node)->meshDraw();
        break;
    }
}

void
NodeCoordinate::flip(int index)
{
    MFVec3f *coords = point();
    if (coords != NULL)
        coords->flip(index);
    if (hasParent())
        getParents().update();
}

void
NodeCoordinate::update()
{
    if (hasParent())
        getParents().update();
}

void
NodeCoordinate::swap(int fromTo)
{
    MFVec3f *coords = point();
    if (coords != NULL)
        coords->swap(fromTo);
    if (hasParent())
        getParents().update();
}

NodeNurbsGroup *
NodeCoordinate::findNurbsGroup()
{
    // find NurbsSet/NurbsGroup in 
    if (hasParent()) {
        for (int i = 0; i < getNumParents(); i++) {
            Node* parent = getParent(i);
            if (parent->getType() == VRML_NURBS_SURFACE) {
                if (parent->hasParent()) {
                    for (int j = 0; j < getNumParents(); j++) {
                        Node* grandParent = parent->getParent(j);
                        if (grandParent->getType() == VRML_NURBS_GROUP) {
                            return (NodeNurbsGroup *) grandParent;
                        } else if (grandParent->getType() == VRML_SHAPE)
                            if (grandParent->hasParent())
                                if (grandParent->getParent()->getType() == 
                                    VRML_NURBS_GROUP)
                                    return (NodeNurbsGroup *) 
                                           grandParent->getParent();
                    }
                }
            }
        } 
    }
    return NULL;
}

bool    
NodeCoordinate::hasTwoSides(void)
{
    if (hasParent())
        return getParent()->hasTwoSides();
    return false;
}

bool
NodeCoordinate::isDoubleSided(void)
{
    if (hasParent())
        return getParent()->isDoubleSided();
    return false;
}

void
NodeCoordinate::toggleDoubleSided(void)
{
    if (hasParent())
        getParent()->toggleDoubleSided();
}

void
NodeCoordinate::flipSide(void)
{
    if (hasParent())
        getParent()->flipSide();
}

bool    
NodeCoordinate::validHandle(int handle) 
{ 
    if (handle < 0)
        return false;
    if (point() == NULL)
        return false;
    int mode = m_scene->getSelectionMode();
    if (mode == SELECTION_MODE_VERTICES) {
        if (handle >= point()->getSFSize())
            return false;
        for (int i = 0; i < m_scene->getNumHiddenVertices(); i++)
            if (m_scene->getHiddenVertex(i) == handle)
                return false;
        if (!m_scene->getXSymetricMode())
            return true;
        return !m_scene->checkXSymetricOrSameHandle(handle, point());
    } else if (mode == SELECTION_MODE_FACES) {
        MyMesh *mesh = getMesh();
        if (mesh == NULL)
            return false;
        if (handle > mesh->getNumFaces())
            return false;
    } else if (mode == SELECTION_MODE_LINES) {
        MyMesh *mesh = getMesh();
        if (mesh == NULL)
            return false;
        if (handle > mesh->getNumLines())
            return false;
    }
    return true;
}

MyMesh *
NodeCoordinate::getMesh(void)
{
    NodeIndexedFaceSet *faceSet = NULL;
    MyMesh *mesh = NULL;
    if (hasParent())
        if (getParent()->getType() == VRML_INDEXED_FACE_SET) {
            faceSet = (NodeIndexedFaceSet *)getParent();
            mesh = faceSet->getMesh();
        }
    return mesh;
}

void
NodeCoordinate::subdivide(void)
{
    NodeIndexedFaceSet *faceSet = NULL;
    if (hasParent())
        if (getParent()->getType() == VRML_INDEXED_FACE_SET) {
            faceSet = (NodeIndexedFaceSet *)getParent();
        }
    if (faceSet)
        faceSet->subdivide();

}

void            
NodeCoordinate::selectSymetricHandles(void)
{
     for (int i = 0; i < m_scene->getSelectedHandlesSize(); i++) {
          int handle = m_scene->getSelectedHandle(i);
          if (!validHandle(handle))
             continue;
          if (checkHandle(handle))
              m_scene->addSelectedHandle(handle);                
    }
}
