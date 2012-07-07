/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        dlgEdRole.h
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Edit database Event Role entity dialog header.
 * Author:      Nick Matthews
 * Modified by:
 * Website:     http://thefamilypack.org
 * Created:     22 October 2010
 * RCS-ID:      $Id$
 * Copyright:   Copyright (c) 2010, Nick Matthews.
 * Licence:     GNU GPLv3
 *
 *  The Family Pack is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  The Family Pack is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with The Family Pack.  If not, see <http://www.gnu.org/licenses/>.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

*/

#ifndef DLGEDROLE_H
#define DLGEDROLE_H

#include <rec/recEvent.h>

#include "fbDlg.h"
#include "dlgEdReference.h"

//============================================================================
//-------------------------[ dlgEditRole ]------------------------------------
//============================================================================

class dlgEditRole : public fbDlgEditRole
{
    DECLARE_CLASS( dlgEditRole )
    DECLARE_EVENT_TABLE()

public:
    dlgEditRole( wxWindow* parent, idt eventID, idt epID = 0 );

    void SetRefID( idt id ) { m_refID = id; }

    recEventPersona* GetEventPersona() { return &m_pe; }

private:
    bool TransferDataToWindow();
    bool TransferDataFromWindow();

    void OnPersonaButton( wxCommandEvent& event );
    void OnRoleButton( wxCommandEvent& event );
    void OnRoleSelect( wxCommandEvent& event );

    recEventPersona     m_pe;
    recEvent            m_event;

    idt                 m_refID;
    recEventTypeRoleVec m_roles;
};

//============================================================================
//-------------------------[ dlgEditIndRole ]---------------------------------
//============================================================================

class dlgEditIndRole : public fbDlgEditIndRole
{
public:
    dlgEditIndRole( wxWindow* parent, idt epID );

    recEventPersona* GetEventPersona() { return &m_ep; }
    idt GetRoleID() const { return m_ep.FGetRoleID(); }

private:
    bool TransferDataToWindow();
    bool TransferDataFromWindow();
    void SetRoleList( idt selection );

    void OnButtonAddClick( wxCommandEvent& event );


    recEventPersona     m_ep;

    recEvent            m_event;
    recEventType        m_et;
    recEventTypeRoleVec m_roles;
};

//============================================================================
//-------------------------[ dlgCreateRole ]---------------------------------
//============================================================================

class dlgCreateRole : public fbDlgCreateRole
{
public:
    dlgCreateRole( wxWindow* parent, idt etID );

    idt GetRoleID() const { return m_role.FGetID(); }
   
private:
    bool TransferDataToWindow();
    bool TransferDataFromWindow();

    void OnSelectPrime( wxCommandEvent& event );

    recEventType     m_et;
    recEventTypeRole m_role;
};

#endif // DLGEDROLE_H
