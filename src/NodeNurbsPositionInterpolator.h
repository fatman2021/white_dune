/*
 * NodeNurbsPositionInterpolator.h
 *
 * Copyright (C) 1999 Stephen F. White, 2004 J. "MUFTI" Scheurich
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

#ifndef _NODE_NURBS_POSITION_INTERPOLATOR_H
#define _NODE_NURBS_POSITION_INTERPOLATOR_H

#ifndef _PROTO_MACROS_H
#include "ProtoMacros.h"
#endif
#ifndef _PROTO_H
#include "Proto.h"
#endif
#include "NodeNurbsCurve.h"

#include "SFMFTypes.h"

class Mesh;

class ProtoNurbsPositionInterpolator : public Proto {
public:
                    ProtoNurbsPositionInterpolator(Scene *scene);
    virtual Node   *create(Scene *scene);

    virtual int     getType() const { return VRML_NURBS_POSITION_INTERPOLATOR; }
    int             getNodeClass() const 
                       { return CHILD_NODE | INTERPOLATOR_NODE; }

    FieldIndex      dimension;
    FieldIndex      keyValue;
    FieldIndex      controlPoint;
    FieldIndex      keyWeight;
    FieldIndex      knot;
    FieldIndex      order;
};

class NodeNurbsPositionInterpolator : public Node {
public:
                    NodeNurbsPositionInterpolator(Scene *scene, Proto *proto);
                    ~NodeNurbsPositionInterpolator();
    virtual int     getX3dVersion(void) const { return 0; }
    virtual Node   *copy() const 
                       { return new NodeNurbsPositionInterpolator(*this); }

    virtual void    draw();
    virtual void    drawHandles(void);

    virtual Vec3f   getHandle(int handle, int *constraint, int *field);
    virtual void    setHandle(int handle, const Vec3f &v);

    virtual void    setField(int index, FieldValue *value, int cf = -1);

    virtual void    flip(int index);
    virtual void    swap(int fromTo);

    virtual bool    maySetDefault(void) { return false; }

    virtual bool    avoidProtoOnPureVrml(void) { return true; }
    virtual int     writeProto(int filedes);
    int             write(int filedes, int indent);

    void            createNurbsCurve();

    virtual Node   *toNurbsCurve(void);

    Node           *convert2X3d(void);
    Node           *convert2Vrml(void);

    fieldMacros(SFInt32, dimension,         ProtoNurbsPositionInterpolator)
    fieldMacros(MFVec3f, keyValue,          ProtoNurbsPositionInterpolator)
    fieldMacros(SFNode,  controlPoint,      ProtoNurbsPositionInterpolator)
    fieldMacros(MFFloat, keyWeight,         ProtoNurbsPositionInterpolator)
    fieldMacros(MFFloat, knot,              ProtoNurbsPositionInterpolator)
    fieldMacros(SFInt32, order,             ProtoNurbsPositionInterpolator)
protected:
    MFVec3f        *getControlPoints(void);
    void            setControlPoints(const MFVec3f *points);
protected:
    NodeNurbsCurve *m_nurbsCurve;
    bool            m_nurbsCurveDirty;
    Array<float>    m_chain;
};
#endif // _NODE_NURBS_POSITION_INTERPOLATOR_H