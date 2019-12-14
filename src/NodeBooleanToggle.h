/*
 * NodeBooleanToggle.h
 *
 * Copyright (C) 1999 Stephen F. White, 2008 J. "MUFTI" Scheurich
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

#include "ExternTheApp.h"
#include "Node.h"
#include "ProtoMacros.h"
#include "Proto.h"
#include "SFMFTypes.h"

class ProtoBooleanToggle : public Proto {
public:
                    ProtoBooleanToggle(Scene *scene);
    virtual Node   *create(Scene *scene);

    virtual int     getType() const { return X3D_BOOLEAN_TOGGLE; }

    virtual bool    isX3dInternalProto(void) { return true; }

    FieldIndex set_boolean;
    FieldIndex toggle;
};

class NodeBooleanToggle : public Node {
public:
                    NodeBooleanToggle(Scene *scene, Proto *proto);
                    NodeBooleanToggle(NodeBooleanToggle &node);
    virtual        ~NodeBooleanToggle();

    virtual const char* getComponentName(void) const;
    virtual int         getComponentLevel(void) const;
    virtual int     getX3dVersion(void) const { return 0; }
    virtual Node   *copy() { return new NodeBooleanToggle(m_scene, m_proto); }

    virtual int     writeProto(int f) { return writeX3dProto(f); }

    fieldMacros(SFBool, toggle, ProtoBooleanToggle)
};

