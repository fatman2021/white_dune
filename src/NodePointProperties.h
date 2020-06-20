/*
 * NodePointProperties.h
 *
 * Copyright (C) 1999 Stephen F. White, 2020 J. "MUFTI" Scheurich
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

#include "Node.h"
#include "ProtoMacros.h"
#include "Proto.h"
#include "DuneApp.h"
#include "SFMFTypes.h"

class ProtoPointProperties : public Proto {
public:
                    ProtoPointProperties(Scene *scene);
    virtual Node   *create(Scene *scene);

    virtual int     getType() const { return X3D_POINT_PROPERTIES; }

    virtual bool    isX3dInternalProto(void) { return true; }

    FieldIndex pointSizeScaleFactor;
    FieldIndex pointSizeMinValue;
    FieldIndex pointSizeMaxValue;
    FieldIndex pointSizeAttenuation;
    FieldIndex colorMode;
};


class NodePointProperties : public Node {
public:
                    NodePointProperties(Scene *scene, Proto *proto);

    virtual const char* getComponentName(void) const { return "Shape"; }
    virtual int         getComponentLevel(void) const { return 5; }
    virtual int     getX3dVersion(void) const { return 0; }
    virtual Node   *copy() const { return new NodePointProperties(*this); }

    virtual bool    isInvalidChildNode(void) { return true; }

    virtual int     writeProto(int f) { return writeX3dProto(f); }


    fieldMacros(SFFloat,  pointSizeScaleFactor, ProtoPointProperties)
    fieldMacros(SFFloat,  pointSizeMinValue,    ProtoPointProperties)
    fieldMacros(SFFloat,  pointSizeMaxValue,    ProtoPointProperties)
    fieldMacros(MFFloat,  pointSizeAttenuation, ProtoPointProperties)
    fieldMacros(SFString, colorMode,            ProtoPointProperties)
};
