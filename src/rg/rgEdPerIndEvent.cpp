/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        src/rg/rgEdPerIndEvent.cpp
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Edit an EventPersona or IndividualEvent record dialog.
 * Author:      Nick Matthews
 * Modified by:
 * Website:     http://thefamilypack.org
 * Created:     23 November 2012
 * RCS-ID:      $Id$
 * Copyright:   Copyright (c) 2012, Nick Matthews.
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

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <rec/recIndividual.h>

#include "rgEdPerIndEvent.h"
//#include "rg/rgDialogs.h"


bool rgEditIndEventRole( idt ieID, rgSHOWROLE filter )
{
    wxASSERT( ieID != 0 );
    const wxString savepoint = recDb::GetSavepointStr();
    bool ret = false;
    rgDlgIndEvent* dialog = new rgDlgIndEvent( NULL, ieID, filter );

    recDb::Savepoint( savepoint );
    if( dialog->ShowModal() == wxID_OK )
    {
        recDb::ReleaseSavepoint( savepoint );
        ret = true;
    } else {
        recDb::Rollback( savepoint );
    }
    dialog->Destroy();
    return ret;
}

bool rgCreateIndEventRole( idt indID, idt eveID, idt roleID )
{
    wxASSERT( eveID != 0 ); // TODO: Select an Event from list
    const wxString savepoint = recDb::GetSavepointStr();
    recDb::Savepoint( savepoint );

    if( indID == 0 ) {
        indID = rgSelectIndividual( rgSELSTYLE_None );
        if( indID == 0 ) {
            recDb::Rollback( savepoint );
            return false;
        }
    }
    recIndividualEvent ie(0);
    ie.FSetIndID( indID );
    ie.FSetEventID( eveID );
    ie.FSetRoleID( roleID );
    ie.FSetIndSeq( recIndividual::GetMaxEventSeqNumber( indID ) );
    ie.Save();
    if( roleID == 0 ) {
        if( ! rgEditIndEventRole( ie.FGetID() ) ) {
            recDb::Rollback( savepoint );
            return false;
        }
    }
    recDb::ReleaseSavepoint( savepoint );
    return true;
}

bool rgEditPerEventRole( idt epID, rgSHOWROLE filter )
{
    wxASSERT( epID != 0 );
    const wxString savepoint = recDb::GetSavepointStr();
    bool ret = false;
    rgDlgPerEvent* dialog = new rgDlgPerEvent( NULL, epID, filter );

    recDb::Savepoint( savepoint );
    if( dialog->ShowModal() == wxID_OK )
    {
        recDb::ReleaseSavepoint( savepoint );
        ret = true;
    } else {
        recDb::Rollback( savepoint );
    }
    dialog->Destroy();
    return ret;
}

idt rgCreateIndEvent( idt indID )
{
    wxMessageBox( "Not yet implimented\nneed to rewrite dlgEditIndEvent", "rgCreateIndEvent" );
    return 0;
    // We need to rewrite dlgEditIndEvent for rg library
#if 0
    wxASSERT( indID != 0 );
    const wxString savepoint = recDb::GetSavepointStr();
    recDb::Savepoint( savepoint );

    idt typeID = rgSelectEventType();
    if( typeID == 0 ) {
        recDb::Rollback( savepoint );
        return 0;
    }

    recEvent eve(0);
    eve.f_type_id = typeID;
    eve.f_title = wxString::Format(
        _("%s of %s"), 
        recEventType::GetTypeStr( typeID ), 
        recIndividual::GetFullName( indID )
    );
    eve.Save();
    idt eveID = eve.GetID();

    recIndividualEvent ie(0);
    ie.FSetEventID( eveID );
    ie.FSetIndID( indID );
    ie.Save();

    if( ! rgEditIndEventRole( ie.FGetID(), rgSHOWROLE_PrimeAll )  ) {
        recDb::Rollback( savepoint );
        return 0;
    }

    dlgEditIndEvent* dialog = new dlgEditIndEvent( NULL, eve.GetID() );

    if( dialog->ShowModal() == wxID_OK )
    {
        recDb::ReleaseSavepoint( savepoint );
    } else {
        recDb::Rollback( savepoint );
        eveID = 0;
    }
    dialog->Destroy();
    return eveID;
#endif
}

//============================================================================
//-------------------------[ rgPerIndEvent ]----------------------------------
//============================================================================

void rgPerIndEvent::SetRoleList( idt selection )
{
    m_staticEvent->SetLabel( m_event.FGetTitle() );
    m_staticEventID->SetLabel( m_event.GetIdStr() );

    switch( m_filter )
    {
    case rgSHOWROLE_All:
        m_roles = recEventType::GetRoles( m_event.FGetTypeID() );
        break;
    case rgSHOWROLE_PrimeAll:
        m_roles = recEventType::GetPrimeRoles( m_event.FGetTypeID() );
        break;
    case rgSHOWROLE_PrimeMale:
        m_roles = recEventType::GetPrimeRoles( m_event.FGetTypeID(), -1 );
        break;
    case rgSHOWROLE_PrimeFemale:
        m_roles = recEventType::GetPrimeRoles( m_event.FGetTypeID(), -2 );
        break;
    default:
        wxASSERT( false );
    }

    wxArrayString roleStrs;
    int sel = 0;
    for( size_t i = 0 ; i < m_roles.size() ; i++ ) {
        roleStrs.push_back( m_roles[i].FGetName() );
        if( m_roles[i].FGetID() == selection ) {
            sel = i;
        }
    }
    m_choiceRole->Set( roleStrs );
    m_choiceRole->SetSelection( sel );
}

idt rgPerIndEvent::GetRoleID() const
{
    int sel = m_choiceRole->GetSelection();
    if( sel >= 0 && sel < (int) m_roles.size() ) {
        return m_roles[sel].FGetID();
    }
    return 0;
}

void rgPerIndEvent::OnAddRoleButton( wxCommandEvent& event )
{
    idt roleID = rgCreateRole( m_event.FGetTypeID() );
    if( roleID ) {
        SetRoleList( roleID );
    }
}


//============================================================================
//-------------------------[ rgDlgIndEvent ]----------------------------------
//============================================================================

rgDlgIndEvent::rgDlgIndEvent( wxWindow* parent, idt ieID, rgSHOWROLE filter ) 
    : m_ie(ieID), rgPerIndEvent( parent, filter )
{
    SetEvent( m_ie.FGetEventID() );
}

bool rgDlgIndEvent::TransferDataToWindow()
{
    wxASSERT( m_ie.FGetID() != 0 );
    wxASSERT( m_ie.FGetEventID() != 0 );
    wxASSERT( m_ie.FGetIndID() != 0 );

    m_staticName->SetLabel( recIndividual::GetFullName( m_ie.FGetIndID() ) );
    m_staticNameID->SetLabel( recIndividual::GetIdStr( m_ie.FGetIndID() ) );

    SetRoleList( m_ie.FGetRoleID() );

    m_textCtrlNote->SetValue( m_ie.FGetNote() );
    m_staticRoleID->SetLabel( m_ie.GetIdStr() );
    return true;
}

bool rgDlgIndEvent::TransferDataFromWindow()
{
    m_ie.FSetRoleID( GetRoleID() );
    m_ie.FSetNote( m_textCtrlNote->GetValue() );

    m_ie.Save();
    return true;
}

//============================================================================
//-------------------------[ rgDlgPerEvent ]----------------------------------
//============================================================================

rgDlgPerEvent::rgDlgPerEvent( wxWindow* parent, idt epID, rgSHOWROLE filter ) 
    : m_ep(epID), rgPerIndEvent( parent, filter )
{
    SetEvent( m_ep.FGetEventID() );
}

bool rgDlgPerEvent::TransferDataToWindow()
{
    wxASSERT( m_ep.FGetID() != 0 );
    wxASSERT( m_ep.FGetEventID() != 0 );
    wxASSERT( m_ep.FGetPerID() != 0 );

    m_staticPerInd->SetLabel( "Persona:" );

    m_staticName->SetLabel( recPersona::GetNameStr( m_ep.FGetPerID() ) );
    m_staticNameID->SetLabel( recPersona::GetIdStr( m_ep.FGetPerID() ) );

    SetRoleList( m_ep.FGetRoleID() );

    m_textCtrlNote->SetValue( m_ep.FGetNote() );
    m_staticRoleID->SetLabel( m_ep.GetIdStr() );
    return true;
}

bool rgDlgPerEvent::TransferDataFromWindow()
{
    m_ep.FSetRoleID( GetRoleID() );
    m_ep.FSetNote( m_textCtrlNote->GetValue() );

    m_ep.Save();
    return true;
}


#if 0
//============================================================================
//-------------------------[ dlgCreateRole ]---------------------------------
//============================================================================

rgDlgEditRole::rgDlgEditRole( wxWindow* parent, idt etrID ) 
    : m_role(etrID), rgEdPerIndEvent(parent) 
{
    m_et.ReadID( m_role.FGetTypeID() );
}

bool rgDlgEditRole::TransferDataToWindow()
{
    wxASSERT( m_role.FGetID() != 0 );
    wxASSERT( m_et.FGetID() != 0 );
    m_staticEventType->SetLabel( m_et.FGetName() );
    m_staticEventTypeID->SetLabel( m_et.GetIdStr() );
    m_staticTypeGroup->SetLabel( m_et.GetGroupStr() );
    m_textCtrlValue->SetValue( m_role.FGetName() );

    wxArrayString primeList;
    primeList.push_back( _("No") );
    switch( m_et.FGetGrp() )
    {
    case recEventType::ETYPE_Grp_Birth:
    case recEventType::ETYPE_Grp_Nr_Birth:
    case recEventType::ETYPE_Grp_Death:
    case recEventType::ETYPE_Grp_Nr_Death:
    case recEventType::ETYPE_Grp_Other:
    case recEventType::ETYPE_Grp_Personal:
        primeList.push_back( _("Prime Role") );
        break;
    case recEventType::ETYPE_Grp_Union:
    case recEventType::ETYPE_Grp_Family:
        primeList.push_back( _("1st Prime Role") );
        primeList.push_back( _("2nd Prime Role") );
        primeList.push_back( _("Either Prime Role") );
        break;
    default:
        return false;
    }
    m_choicePrime->Set( primeList );
    m_choicePrime->SetSelection( m_role.FGetPrime() );
    m_checkOfficial->Enable( !m_role.FGetPrime() );
    m_staticRoleID->SetLabel( m_role.GetIdStr() );
    return true;
}

bool rgDlgEditRole::TransferDataFromWindow()
{
    m_role.FSetPrime( m_choicePrime->GetSelection() );
    if( !m_role.FGetPrime() ) {
        m_role.FSetOfficial( m_checkOfficial->GetValue() );
    } else {
        m_role.FSetOfficial( false );
    }
    m_role.FSetName( m_textCtrlValue->GetValue() );
    m_role.Save();
    return true;
}

void rgDlgEditRole::OnChoicePrime( wxCommandEvent& event )
{
    if( m_choicePrime->GetSelection() == 0 ) {
        m_checkOfficial->Enable( true );
    } else {
        m_checkOfficial->Enable( false );
    }
}
#endif

// End of src/rg/rgEdRole.cpp file
