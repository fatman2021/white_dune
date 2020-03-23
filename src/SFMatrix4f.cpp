/*
 * SFMatrix4f.cpp
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

#include "swt.h"
#include "SFMatrix4f.h"
#include "SFFloat.h"

MyString    
SFMatrix4f::getString(int index, int stride) const
{
    MyString ret = "";
    char buffer[256];
    mysnprintf(buffer, 255, "%g", m_value[stride]);
    ret += buffer;
    return ret;
}

bool
SFMatrix4f::equals(const FieldValue *value) const
{
    if (value->getType() == SFMATRIX4F) {
        SFMatrix4f *v = (SFMatrix4f *) value;
        for (int i = 0; i < 16; i++)
            if (v->getValue()[i] != m_value[i])
                return false;
        return true;
    } else {
        return false;
    }
}

void
SFMatrix4f::clamp(const FieldValue *min, const FieldValue *max)
{
    if (min) {
        float fmin = ((SFFloat *) min)->getValue();
        for (int i = 0; i < 16; i++) {
            if (m_value[i] < fmin) m_value[i] = fmin;
        }
    }

    if (max) {
        float fmax = ((SFFloat *) max)->getValue();
        for (int i = 0; i < 16; i++) {
            if (m_value[i] > fmax) m_value[i] = fmax;
        }
    }
}

bool        
SFMatrix4f::readLine(int index, char *line)
{
    if (sscanf(line, "%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f", 
               m_value + 0, m_value + 1, m_value + 2, m_value + 3, 
               m_value + 4, m_value + 5, m_value + 6, m_value + 7, 
               m_value + 8, m_value + 9, m_value + 10, m_value + 11, 
               m_value + 12, m_value + 13, m_value + 14, m_value + 15 
              ) != 16)
        return false;
    return true;
}

int 
SFMatrix4f::writeData(int f, int i)
{
    return mywritef(f, "%g %g %g %g  %g %g %g %g  %g %g %g %g  %g %g %g %g", 
                       m_value[0], m_value[1], m_value[2], m_value[3], 
                       m_value[4], m_value[5], m_value[6], m_value[7], 
                       m_value[8], m_value[9], m_value[10], m_value[11],
                       m_value[12], m_value[13], m_value[14], m_value[15]);
}

int 
SFMatrix4f::write(int f, int indent)
{
    RET_ONERROR( mywritef(f, "%g %g %g %g\n  %g %g %g %g\n  %g %g %g %g\n  %g %g %g %g\n", 
                       m_value[0], m_value[1], m_value[2], m_value[3], 
                       m_value[4], m_value[5], m_value[6], m_value[7], 
                       m_value[8], m_value[9], m_value[10], m_value[11],
                       m_value[12], m_value[13], m_value[14], m_value[15]) )
    TheApp->incSelectionLinenumber();
    TheApp->incSelectionLinenumber();
    TheApp->incSelectionLinenumber();
    return 0;
}

int
SFMatrix4f::writeC(int filedes, const char* variableName, int languageFlag)
{
    RET_ONERROR( mywritestr(filedes, "m_") )
    RET_ONERROR( mywritestr(filedes, variableName) )
    RET_ONERROR( mywritestr(filedes, "[") )
    if (languageFlag & C_SOURCE)
        RET_ONERROR( mywritestr(filedes, "16") )
    RET_ONERROR( mywritestr(filedes, "] = { ") )
    RET_ONERROR( mywritef(filedes, "%g, %g, %g, %g, ",
                          m_value[0], m_value[1], m_value[2], m_value[3]) )
    RET_ONERROR( mywritef(filedes, "%g, %g, %g, %g, ",
                          m_value[4], m_value[5], m_value[6], m_value[7]) )
    RET_ONERROR( mywritef(filedes, "%g, %g, %g, %g, ", 
                          m_value[8], m_value[9], m_value[10], m_value[11]) )
    RET_ONERROR( mywritef(filedes, "%g, %g, %g, %g, \n", 
                          m_value[12], m_value[13], m_value[14], m_value[15]) )
    RET_ONERROR( mywritestr(filedes, " };\n") )
    return 0;
}

int
SFMatrix4f::writeAc3d(int filedes, int indent) const
{
    // not needed yet
    return 0;
}

MyString
SFMatrix4f::getEcmaScriptComment(MyString name, int flags) const
{
    const char *indent = ((FieldValue *)this)->getEcmaScriptIndent(flags);
    MyString ret;
    ret += indent;
    ret += "not implemented yet";
    return ret;
}

FieldValue *
SFMatrix4f::getRandom(Scene *scene, int nodeType)
{
    int size = 16;
    float *array = new float[size];
    for (int i = 0; i < size; i++)
        array[i] = FLOAT_RAND();
    return new SFMatrix4f(array);
}

