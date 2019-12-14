/*
 * SFTime.h
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

#ifndef _SFTIME_H
#define _SFTIME_H

#ifndef _FIELDVALUE_H
#include "FieldValue.h"
#endif

class SFTime : public FieldValue {
public:
                        SFTime(double value);
                        SFTime(void) { m_value = 0.0; } // silly default

    virtual int         getType() const { return SFTIME; }
    virtual const char *getTypeName() { return "SFTime"; }
    virtual MyString    getString(int index, int stride);

    virtual int         writeData(int filedes, int i); 

    virtual const char *getTypeC(int languageFlag) { return "double"; }
    virtual const char *getDefaultC(int languageFlag) { return "0"; }

    virtual bool        readLine(int index, char *line);

    virtual int         getNumbersPerType(void) { return 1; }
    virtual bool        needCheckFloat(void) { return true; }

    virtual bool        equals(FieldValue *value);
    virtual FieldValue *copy() { return new SFTime(*this); }

    double              getValue() { return m_value; }

    virtual void        clamp(const FieldValue *min, const FieldValue *max);
    MyString            getEcmaScriptComment(MyString name, int flags);

    virtual bool        supportAnimation(bool x3d) { return false; }
    virtual bool        supportInteraction(void) { return true; }

    FieldValue         *getRandom(Scene *scene, int nodetype) 
                           { return new SFTime(FLOAT_RAND()); }
private:
    double              m_value;
};

#endif // _SFTIME_H
