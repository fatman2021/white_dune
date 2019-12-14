/*
 * MFVec3f.h
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

#pragma once

#include "MFFloat.h"
#include "Vec3f.h"
#include "MFVec3d.h"
#include "MFString.h"

class MFVec3f : public MFFloat {
public:
                        MFVec3f() : MFFloat() {}
                        MFVec3f(int size) : MFFloat(size * 3) {}
                        MFVec3f(MFVec3f *values) :
                              MFFloat(((MFVec3f *)values)->getValues(), 
                                      ((MFVec3f *)values)->getSize()) {}
                        MFVec3f(float *values, int len) :
                                MFFloat(values, len) {}
                        MFVec3f(double *values, int len) :
                                MFFloat(values, len) {}
                        MFVec3f(MFVec2f *mfVec2f);
                        MFVec3f(float x, float y, float z) : MFFloat(3) 
                             {
                             m_value[0] = x;
                             m_value[1] = y;
                             m_value[2] = z;
                             }

    MFVec3f            *getMFVec3f(void);
    MFVec3d            *getMFVec3d(void);

    virtual int         getType() const { return MFVEC3F; }
    virtual const char *getTypeName() { return "MFVec3f"; }
    virtual int         getStride() { return 3; }
    virtual FieldValue *copy();

    virtual bool        readLine(int index, char *line);

    virtual bool        equals(FieldValue *value);

    virtual FieldValue *getSFValue(int index);
    virtual void        setSFValue(int index, FieldValue *value);
    virtual void        setSFValue(int index, float *values);
    virtual void        setSFValue(int index, float x, float y, float z);

    float              *getValue(int index)
                              { return m_value.getData() + index * 3; } 

    void                setVec(int index, Vec3f v);
    Vec3f               getVec(int index);

    virtual void        insertSFValue(int index, FieldValue *value);
    virtual void        insertSFValue(int index, float *values);
    virtual void        insertSFValue(int index, float x, float y, float z);

    virtual void        appendSFValue(float x, float y, float z) 
                           { insertSFValue(getSFSize(), x, y, z); }
    virtual void        appendSFValue(float *values) 
                           { insertSFValue(getSFSize(), values); }
    virtual void        appendVec(Vec3f v) 
                           { insertSFValue(getSFSize(), v.x, v.y, v.z); }
                        
    Vec3f               getMinBoundingBox(void);
    Vec3f               getMaxBoundingBox(void);

    virtual void        removeSFValue(int index) 
                            { 
                            m_value.remove(3 * index); 
                            m_value.remove(3 * index); 
                            m_value.remove(3 * index); 
                            }

    void                flip(int index);
    void                swap(int fromTo);

    MyString            getEcmaScriptComment(MyString name, int flags);

    bool                supportAnimation(bool x3d) { return true; }

    randomFunction(MFVec3f)                  
};
