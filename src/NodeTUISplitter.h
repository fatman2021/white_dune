/*
 * NodeTUISplitter.h
 *
 * Copyright (C) 1999 Stephen F. White, 2006 J. "MUFTI" Scheurich
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
 * 
 * Implements the Cover/Covise TUISplitter node
 */

#ifndef _NODE_TUI_SPLITTER_H
#define _NODE_TUI_SPLITTER_H

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

#include "TUIElement.h"

class ProtoTUISplitter : public ProtoTUIElement {
public:
                    ProtoTUISplitter(Scene *scene);
    virtual Node   *create(Scene *scene);

    virtual int     getType() const { return COVER_TUI_SPLITTER; }
};

class NodeTUISplitter : public TUIElement {
public:
                    NodeTUISplitter(Scene *scene, Proto *proto);

    virtual int     getX3dVersion(void) const { return -1; }    
    virtual Node   *copy() { return new NodeTUISplitter(m_scene, m_proto); }
};

#endif // _NODE_TUI_SPLITTER_H
