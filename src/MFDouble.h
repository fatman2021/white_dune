/*
 * MFDouble.h
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

#include "Array.h"
#include "FieldValue.h"
#include "SFDouble.h"

class MFDouble : public MFieldValue {
public:
                        MFDouble(int stride = 1);
                        MFDouble(int len, int stride);
                        MFDouble(MFDouble &value);
                        MFDouble(MFDouble *value);
                        MFDouble(double *values, int len, int stride = 1);
                        MFDouble(float *values, int len, int stride = 1);
                        MFDouble(double value);
    virtual            ~MFDouble();

    virtual int         getType() const { return MFDOUBLE; }
    virtual int         getStride() { return 1; }
    virtual MyString    getString(int index, int stride);
    virtual const char *getTypeName() { return "MFDouble"; }

    virtual int         writeData(int filedes, int i); 
    virtual int         writeDataC(int filedes, int i, int languageFlag);

    virtual const char *getTypeC(int languageFlag) { return "double"; }

    virtual bool        readLine(int index, char *line);

    virtual int         getNumbersPerType(void) { return getStride(); }
    virtual bool        needCheckFloat(void) { return true; }

    virtual bool        equals(MFDouble *value);
    virtual void        clamp(const FieldValue *min, const FieldValue *max);
    virtual FieldValue *copy(); 

    virtual int         getSFSize()
                           { return m_value.size() / getStride(); }
    virtual FieldValue *getSFValue(int index); 
    virtual void        setSFValue(int index, FieldValue *value);
    void                setSFValue(int index, double value);

    double             *getValues() { return m_value.getData(); }
    double              getValue(int i) { return m_value[i]; }
    int                 getSize() { return m_value.size(); }
    void                setValue(int index, double value) 
                           { m_value[index] = value; }

    virtual void        insertSFValue(int index, FieldValue *value);
    void                insertSFValue(int index, double value);

    virtual void        removeSFValue(int index);

    double              getMaxValue();
    double              getMinValue();

    MyString            getEcmaScriptComment(MyString name, int flags);

    virtual bool        isX3DType() { return true; }

    FieldValue         *getRandom(Scene *scene, int nodeType);

protected:
    MyArray<double>     m_value;
};
