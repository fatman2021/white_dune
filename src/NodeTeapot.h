/*
 * NodeTeapot.h
 *
 * Copyright (C) 2009 J. "MUFTI" Scheurich
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

#ifndef _NODE_TEAPOT_H
#define _NODE_TEAPOT_H

#ifndef _NODE_H
#include "ExternTheApp.h"
#include "Node.h"
#endif
#ifndef _PROTO_MACROS_H
#include "ProtoMacros.h"
#endif
#ifndef _PROTO_H
#include "Proto.h"
#endif

#include "SFMFTypes.h"
#include "KambiCommonFunctions.h"

class ProtoTeapot : public Proto {
public:
                    ProtoTeapot(Scene *scene);
    virtual Node   *create(Scene *scene);

    virtual int     getType() const { return KAMBI_TEAPOT; }

    FieldIndex size;
    FieldIndex solid;
    FieldIndex manifold;
    FieldIndex texCoord;

    virtual bool    isKambiProto(void) { return true; }
};

class NodeTeapot : public Node {
public:
                    NodeTeapot(Scene *scene, Proto *proto);

    virtual Node *copy() { return new NodeTeapot(m_scene, m_proto); }

    kambiCommonFunctions()

    fieldMacros(SFVec3f, size, ProtoTeapot);
    fieldMacros(SFBool, solid, ProtoTeapot);
    fieldMacros(SFBool, manifold, ProtoTeapot);
    fieldMacros(SFNode, texCoord, ProtoTeapot);
};

#endif
