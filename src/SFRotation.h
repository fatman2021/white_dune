/*
 * SFRotation.h
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

#ifndef _SFROTATION_H
#define _SFROTATION_H

#ifndef _FIELDVALUE_H
#include "FieldValue.h"
#endif
#ifndef _VEC3F_H
#include "Vec3f.h"
#endif
#ifndef _MATRIX_H
#include "Matrix.h"
#endif
#ifndef _QUATERNION_H
#include "Quaternion.h"
#endif

class SFRotation : public FieldValue {
public:
                        SFRotation(float x, float y, float z, float w);
                        SFRotation(const float *value);
                        SFRotation(Vec3f euler, int mode);
                        SFRotation(const Quaternion &q);
                        SFRotation(const Matrix &mat);
                        SFRotation(void);  // silly default

    void                generateQuaternion();
    virtual int         getType() const { return SFROTATION; }
    virtual const char *getTypeName() { return "SFRotation"; }
    virtual int         getStride() { return 4; }
    virtual MyString    getString(int index, int stride);

    virtual int         writeData(int filedes, int i); 

    virtual int         writeC(int filedes, const char* variableName,
                               int languageFlag);
    virtual const char *getTypeC(int languageFlag) { return "float"; }
    virtual bool        isArrayInC(void) { return true; }

    virtual int         writeAc3d(int filedes, int indent);

    virtual bool        readLine(int index, char *line);

    virtual int         getNumbersPerType(void) { return 4; }
    virtual bool        needCheckFloat(void) { return true; }

    virtual bool        equals(FieldValue *value);
    virtual FieldValue *copy() { return new SFRotation(*this); }

    virtual void        fixAngle(double angleUnit) 
                            {
                            if (angleUnit != 0) 
                                m_value[3] *= angleUnit;
                            }

    virtual void        reverseFixAngle(double angleUnit) 
                            {
                            if (angleUnit != 0) 
                                m_value[3] /= angleUnit;
                            }

    float              *getValue() { return m_value; }
    float               getValue(int pos) { return m_value[pos]; }
    void                setValue(int index, float value);
    void                setValue(float v1, float v2, float v3, float v4);
    Vec3f               getEulerAngles(int order);
    void                setEulerAngles(Vec3f angles, int order);
    void                angleMult(float mult);
    const Quaternion   &getQuat();
    void                normalize();

    Vec3f               operator *(const Vec3f &v);

    MyString            getEcmaScriptComment(MyString name, int flags);

    virtual bool        supportAnimation(bool x3d) { return true; }
    virtual bool        supportInteraction(void) { return true; }

    void                flip(int index);
    void                swap(int fromTo);

    SFRotation          slerp(SFRotation rot, double t);
    SFRotation          inverse(void);
    SFRotation          multiply(SFRotation rot);

    FieldValue         *getRandom(Scene *scene, int nodetype);
private:
    Quaternion          m_quaternion;
    float               m_value[4];
    Vec3f               m_euler;
    int                 m_eulerOrder;
    bool                m_eulerDirty;
};

#endif // _SFROTATION_H
