/*
 * MFString.h
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

#include "FieldValue.h"

class ElementList;

class MFString : public MFieldValue {
public:
                        MFString();
                        MFString(const MFString &string);
                        MFString(MyString *value);
                        MFString(MyString value);
                        MFString(StringArray *values);
    virtual            ~MFString();

    virtual int         getType() const { return MFSTRING; }
    virtual const char *getTypeName() const { return "MFString"; }
    virtual MyString    getString(int index, int stride) const;

    virtual int         write4FieldPipe(int filedes, int indent) const; 

    virtual int         writeCWonderlandArt(int filedes, 
                                            const char* variableName,
                                            int languageFlag) const;

    virtual int         writeDataC(int filedes, int i, int languageFlag) const;
    virtual int         writeRaw(int filedes, int indent) const;

    virtual int         writeData(int filedes, int i) const; 
    virtual int         writeDataXml(int filedes, int i) const; 

    virtual const char *getTypeC(int languageFlag) const; 

    virtual bool        readLine(int index, char *line);

    virtual int         getNumbersPerType(void) const { return 0; }

    virtual bool        equals(const FieldValue *value) const;
    virtual FieldValue *copy();

    virtual int         getSFSize() const { return m_value.size(); }
    virtual FieldValue *getSFValue(int index) const;
    virtual void        setSFValue(int index, FieldValue *value);
    virtual void        setSFValue(int index, const char* value);

    const MyString     *getValues() const { return m_value.getData(); }
    MyString            getValue(int i) const { return m_value[i]; }
    int                 getSize() const { return m_value.size(); }
    void                setValue(int index, MyString value) 
                           { m_value[index] = value; }

    virtual void        insertSFValue(int index, FieldValue *value);
    virtual void        insertSFValue(int index, const char* value);
    virtual void        removeSFValue(int index) { m_value.remove(index); }

    MyString            getEcmaScriptComment(MyString name, int flags) const;

    FieldValue         *getRandom(Scene *scene, int nodeType);
private:
    StringArray         m_value;
};
