/*
 * SFColor.cpp
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
#include "DuneApp.h"

#include "SFColor.h"
#include "SFFloat.h"

SFColor::SFColor(float r, float g, float b)
{
    m_value[0] = r; m_value[1] = g; m_value[2] = b;  m_value[3] = 1.0f;
}

SFColor::SFColor(const float *values)
{
    m_value[0] = values[0];
    m_value[1] = values[1];
    m_value[2] = values[2];
    m_value[3] = 1.0f;
}

MyString    
SFColor::getString(int index, int stride) const
{
    MyString ret = "";
    char buffer[256];
    mysnprintf(buffer, 255, "%g", m_value[stride]);
    ret += buffer;
    return ret;
}

void SFColor::setValue(float v1, float v2, float v3)
{
    m_value[0] = v1;
    m_value[1] = v2;
    m_value[2] = v3;
    m_value[3] = 1.0f;
}

void SFColor::setValue(float v1, float v2, float v3, float v4)
{
    m_value[0] = v1;
    m_value[1] = v2;
    m_value[2] = v3;
    m_value[3] = v4;
}

// silly default
SFColor::SFColor(void)
{
    m_value[0] = 1.0f; m_value[1] = 1.0f; m_value[2] = 1.0f;  m_value[3] = 1.0f;
}

bool        
SFColor::readLine(int index, char *line)
{
    if (sscanf(line, "%f %f %f", m_value + 0, m_value + 1, m_value + 2) != 3)
        return false;
    for (int i = 0; i < 3; i++)
        if ((m_value[i] < 0.0) ||
            (m_value[i] > 1.0))
            return false;
    return true;
}

bool
SFColor::equals(const FieldValue *value) const
{
    if (value->getType() == SFCOLOR) {
        for (int i = 0; i < 3; i++)
            if (((SFColor *) value)->getValue()[i] != m_value[i])
                return false;
        return true;
    }
    return false;
}

int 
SFColor::writeData(int f, int i) const
{
    return mywritef(f, "%g %g %g", m_value[0], m_value[1], m_value[2]);
}

int
SFColor::writeC(int filedes, const char* variableName, int languageFlag) const
{
    RET_ONERROR( mywritestr(filedes, "m_") )
    RET_ONERROR( mywritestr(filedes, variableName) )
    RET_ONERROR( mywritestr(filedes, "[") )
    if (languageFlag & C_SOURCE)
        RET_ONERROR( mywritestr(filedes, "3") )
    RET_ONERROR( mywritestr(filedes, "] = { ") )
    if (languageFlag & JAVA_SOURCE)
        RET_ONERROR( mywritef(filedes, "%gf, %gf, %gf", m_value[0], m_value[1], 
                                                        m_value[2]))
    else
        RET_ONERROR( mywritef(filedes, "%g, %g, %g", m_value[0], m_value[1], 
                                                     m_value[2]))
    RET_ONERROR( mywritestr(filedes, " };\n") )
    return 0;
}

void
SFColor::clamp(const FieldValue *min, const FieldValue *max)
{
    for (int i = 0; i < 3; i++) {
        if (m_value[i] < 0.0f) m_value[i] = 0.0f;
        if (m_value[i] > 1.0f) m_value[i] = 1.0f;
    }
}

MyString
SFColor::getEcmaScriptComment(MyString name, int flags) const
{
    const char *indent = ((FieldValue *)this)->getEcmaScriptIndent(flags);
    MyString ret;
    ret = "";
    if (TheApp->GetEcmaScriptAddAllowedValues()) {
        ret += indent;
        ret += "// allowed values:\n";

        ret += indent;
        ret += "   // 3 floating point numbers, range: 0.0 to 1.0\n";
    }
    if (TheApp->GetEcmaScriptAddAllowedComponents()) {
        ret += indent;
        ret += "// allowed components:\n";

        ret += indent;
        ret += "   // red:   ";
        ret += name;
        ret += ".r or ";
        ret += name;
        ret += "[0]\n   ";

        ret += indent;
        ret += "// green: ";
        ret += name;
        ret += ".g or ";
        ret += name;
        ret += "[1]\n   ";

        ret += indent;
        ret += "// blue:  ";
        ret += name;
        ret += ".b or ";
        ret += name;
        ret += "[2]\n";
    }
    if (TheApp->GetEcmaScriptAddAvailableFunctions()) {
        ret += indent;
        ret += "// available functions:\n";
        if (flags != EL_EVENT_IN) {
            ret += indent;
            ret += "   // ";
            ret += name;
            ret += " = new SFColor(float_r, float_g, float_b);\n";

            ret += indent;
            ret += "   // ";
            ret += name;
            ret += ".setHSV(float_h, float_s, float_v);\n";
        }
        if (flags != EL_EVENT_OUT) {
            ret += indent;
            ret += "   // numeric[3] = ";
            ret += name;
            ret += ".getHSV();\n";

            ret += indent;
            ret += "   // string_str = ";
            ret += name;
            ret += ".toString();\n";
       }
    }
    if (TheApp->GetEcmaScriptAddExampleUsage()) {
        ret += indent;
        ret += "// example usage:\n";
        if (flags != EL_EVENT_IN) {
             ret += indent;
             ret += "   // ";
             ret += name;
             ret += " = new SFColor(0, 0.2, 1);\n";

             ret += indent;
             ret += "   // ";
             ret += name;
             ret += ".r = 0.5;\n";
        } 
        if (flags != EL_EVENT_OUT) {
             ret += indent;
             ret += "   // float_r = ";
             ret += name;
             ret += ".r;\n";
        }
    }
    return ret;
}

FieldValue *
SFColor::getRandom(Scene *scene, int nodeType)
{
    Vec3f vec(RAND(), RAND(), RAND());
    vec.normalize();
    return new SFColor(vec.x, vec.y, vec.z);
}

