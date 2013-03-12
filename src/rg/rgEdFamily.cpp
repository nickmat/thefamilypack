/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        src/rg/rgEdFamily.cpp
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Edit database Family entity dialog.
 * Author:      Nick Matthews
 * Modified by:
 * Website:     http://thefamilypack.org
 * Created:     9 October 2010
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

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <rec/recIndividual.h>
#include <rec/recEvent.h>
#include <rg/rgDialogs.h>

#include "rgEdFamily.h"

bool rgEditFamily( wxWindow* parent, idt famID )
{
    const wxString savepoint = recDb::GetSavepointStr();
    recDb::Savepoint( savepoint );
    bool ret = false;

    rgDlgEditFamily* dialog = new rgDlgEditFamily( parent, famID );

    if( dialog->ShowModal() == wxID_OK ) {
        recDb::ReleaseSavepoint( savepoint );
        ret = true;
    } else {
        recDb::Rollback( savepoint );
    }
    dialog->Destroy();
    return ret;
}

//============================================================================
//-------------------------[ rgDlgEditFamily ]--------------------------------
//============================================================================

IMPLEMENT_CLASS( rgDlgEditFamily, wxDialog )

BEGIN_EVENT_TABLE( rgDlgEditFamily, wxDialog )
    EVT_MENU( tfpID_DLGEDFAM_EDIT, rgDlgEditFamily::OnEditID )
    EVT_MENU( tfpID_DLGEDFAM_REMOVE, rgDlgEditFamily::OnRemoveID )
    EVT_MENU( tfpID_DLGEDFAM_DELETE, rgDlgEditFamily::OnDeleteID )
    EVT_MENU( tfpID_DLGEDFAM_ADDNEW, rgDlgEditFamily::OnEditID )
    EVT_MENU( tfpID_DLGEDFAM_ADDEXIST, rgDlgEditFamily::OnAddExistID )

    EVT_MENU( tfpID_DLGEDFAM_ADDNEWSON, rgDlgEditFamily::OnAddChild )
    EVT_MENU( tfpID_DLGEDFAM_ADDNEWDAUR, rgDlgEditFamily::OnAddChild )
    EVT_MENU( tfpID_DLGEDFAM_ADDEXISTSON, rgDlgEditFamily::OnAddChild )
    EVT_MENU( tfpID_DLGEDFAM_ADDEXISTDAUR, rgDlgEditFamily::OnAddChild )

    EVT_MENU( tfpID_DLGEDFAM_NEW_EVENT,   rgDlgEditFamily::OnNewEvent )
    EVT_MENU( tfpID_DLGEDFAM_EXIST_EVENT, rgDlgEditFamily::OnExistingEvent )
END_EVENT_TABLE()

rgDlgEditFamily::rgDlgEditFamily( wxWindow* parent, idt famID ) 
    : m_family(famID), m_child(0), m_editbutton(EDBUT_Husb), fbRgEditFamily( parent )
{
    m_listEvent->InsertColumn( EC_Number, _("Number") );
    m_listEvent->InsertColumn( EC_Title, _("Title") );
    m_listEvent->InsertColumn( EC_Date, _("Date") );
    m_listEvent->InsertColumn( EC_Place, _("Place") );
}

bool rgDlgEditFamily::TransferDataToWindow()
{
    wxASSERT( m_family.f_id != 0 );
    if( m_child > 0 ) {
        recFamilyIndividual fi;
        fi.Clear();
        fi.f_fam_id = m_family.f_id;
        fi.f_ind_id = m_child;
        fi.f_seq_child = 1;
        fi.f_seq_parent = 1;
        fi.Save();
    }

    wxString str;

    str << wxT("F") << m_family.f_id;
    m_staticFamID->SetLabel( str  );

    str = recIndividual::GetFullName( m_family.f_husb_id );
    m_staticHusbName->SetLabel( str  );

    str = recIndividual::GetFullName( m_family.f_wife_id );
    m_staticWifeName->SetLabel( str  );

    m_childlinks = m_family.GetChildLinks();
    wxArrayString list;
    if( m_childlinks.size() > 0 )
    {
        for( size_t i = 0 ; i < m_childlinks.size() ; i++ )
        {
            list.Add( recIndividual::GetFullName( m_childlinks[i].f_ind_id ) );
        }
        m_listChild->InsertItems( list, 0 );
    }
    m_fes = m_family.GetEvents();
    for( size_t i = 0 ; i < m_fes.size() ; i++ ) {
        idt eveID = m_fes[i].FGetEventID();
        m_listEvent->InsertItem( i, recEvent::GetIdStr( eveID ) );
        m_listEvent->SetItem( i, EC_Title, recEvent::GetTitle( eveID ) );
        m_listEvent->SetItem( i, EC_Date, recEvent::GetDateStr( eveID ) );
        m_listEvent->SetItem( i, EC_Place, recEvent::GetAddressStr( eveID ) );
    }
    return true;
}

bool rgDlgEditFamily::TransferDataFromWindow()
{
    m_family.Save();
    recIndividual ind(m_family.f_husb_id);
    if( ind.f_fam_id == 0 ) {
        ind.f_fam_id = m_family.f_id;
        ind.Save();
    }
    ind.ReadID( m_family.f_wife_id );
    if( ind.f_fam_id == 0 ) {
        ind.f_fam_id = m_family.f_id;
        ind.Save();
    }

    for( size_t i = 0 ; i < m_childlinks.size() ; i++ ) {
        m_childlinks[i].fSetSeqChild( i+1 );
        m_childlinks[i].Save();
    }

    for( size_t i = 0 ; i < m_fes.size() ; i++ ) {
        if( m_fes[i].FGetFamSeq() != i+1 ) {
            m_fes[i].FSetFamSeq( i+1 );
            m_fes[i].Save();
        }
    }
    return true;
}

void rgDlgEditFamily::OnHusbButton( wxCommandEvent& event )
{
    m_editbutton = EDBUT_Husb;
    EditSpouseMenu( m_family.f_husb_id );
}

void rgDlgEditFamily::OnWifeButton( wxCommandEvent& event )
{
    m_editbutton = EDBUT_Wife;
    EditSpouseMenu( m_family.f_wife_id );
}

void rgDlgEditFamily::EditSpouseMenu( idt indID )
{
    wxMenu* menu = new wxMenu;

    if( indID != 0 )
    {
        menu->Append( tfpID_DLGEDFAM_EDIT,     _("&Edit") );
        menu->Append( tfpID_DLGEDFAM_REMOVE,   _("&Remove") );
        menu->Append( tfpID_DLGEDFAM_DELETE,   _("&Delete") );
        if( m_family.f_husb_id == 0 || m_family.f_wife_id == 0 ) {
            menu->Enable( tfpID_DLGEDFAM_REMOVE, false );
            menu->Enable( tfpID_DLGEDFAM_DELETE, false );
        }
    } else {
        menu->Append( tfpID_DLGEDFAM_ADDNEW,   _("Add &New") );
        menu->Append( tfpID_DLGEDFAM_ADDEXIST, _("Add &Existing") );
    }
    PopupMenu( menu );
    delete menu;
}

void rgDlgEditFamily::OnEditID( wxCommandEvent& event )
{
    idt indID;
    Sex sex;

    if( m_editbutton == EDBUT_Husb ) {
        indID = m_family.f_husb_id;
        sex = SEX_Male;
    } else {  // m_editbutton == EDBUT_Wife
        indID = m_family.f_wife_id;
        sex = SEX_Female;
    }

    if( indID == 0 ) {
        indID = rgAddNewIndividual( this, sex, "", m_family.f_id );
        if( m_editbutton == EDBUT_Husb ) {
            m_family.f_husb_id = indID;
        } else {
            m_family.f_wife_id = indID;
        }
    } else {
        rgEditIndividual( this, indID );
    }

    m_staticHusbName->SetLabel( recIndividual::GetFullName( m_family.f_husb_id ) );
    m_staticWifeName->SetLabel( recIndividual::GetFullName( m_family.f_wife_id ) );
}

void rgDlgEditFamily::OnRemoveID( wxCommandEvent& event )
{
    idt indID;

    if( m_editbutton == EDBUT_Husb ) {
        if( m_family.f_wife_id == 0 ) {
            return;  // Can't remove both spouses
        }
        indID = m_family.f_husb_id;
        m_family.f_husb_id = 0;
        m_staticHusbName->SetLabel( wxEmptyString );
    } else {
        if( m_family.f_husb_id == 0 ) {
            return;  // Can't remove both spouses
        }
        indID = m_family.f_wife_id;
        m_family.f_wife_id = 0;
        m_staticWifeName->SetLabel( wxEmptyString );
    }
    m_family.Save();
    m_family.RemoveFromEvents( indID );
    recIndividual::Update( indID );
    recIndividual::CreateMissingFamilies();
}

void rgDlgEditFamily::OnDeleteID( wxCommandEvent& event )
{
    if( m_editbutton == EDBUT_Husb ) {
        if( rgDeleteIndividual( this, m_family.f_husb_id ) ) {
            m_family.f_husb_id = 0;
            m_staticHusbName->SetLabel( wxEmptyString );
        }
    } else {
        if( rgDeleteIndividual( this, m_family.f_wife_id ) ) {
            m_family.f_wife_id = 0;
            m_staticWifeName->SetLabel( wxEmptyString );
        }
    }
}

void rgDlgEditFamily::OnAddExistID( wxCommandEvent& event )
{
    if( m_editbutton == EDBUT_Husb ) {
       rgAddExistSpouse( this, m_family.f_wife_id, SEX_Male );
    } else {
       rgAddExistSpouse( this, m_family.f_husb_id, SEX_Female );
    }
    m_family.Read();
    m_staticHusbName->SetLabel( recIndividual::GetFullName( m_family.f_husb_id ) );
    m_staticWifeName->SetLabel( recIndividual::GetFullName( m_family.f_wife_id ) );
}

void rgDlgEditFamily::OnChildAddButton( wxCommandEvent& event )
{
    wxMenu* menu = new wxMenu;

    menu->Append( tfpID_DLGEDFAM_ADDNEWSON,    _("Add New &Son") );
    menu->Append( tfpID_DLGEDFAM_ADDNEWDAUR,   _("Add New &Daughter") );
    menu->AppendSeparator();
    menu->Append( tfpID_DLGEDFAM_ADDEXISTSON,  _("Add &Existing Son") );
    menu->Append( tfpID_DLGEDFAM_ADDEXISTDAUR, _("Add E&xisting Daughter") );

    PopupMenu( menu );
    delete menu;
}

void rgDlgEditFamily::OnAddChild( wxCommandEvent& event )
{
    idt indID = 0;

    switch( event.GetId() )
    {
    case tfpID_DLGEDFAM_ADDNEWSON:
        indID = rgAddNewChild( this, m_family.f_id, SEX_Male );
        break;
    case tfpID_DLGEDFAM_ADDNEWDAUR:
        indID = rgAddNewChild( this, m_family.f_id, SEX_Female );
        break;
    case tfpID_DLGEDFAM_ADDEXISTSON:
        indID = rgAddExistChild( this, m_family.f_id, SEX_Male );
        break;
    case tfpID_DLGEDFAM_ADDEXISTDAUR:
        indID = rgAddExistChild( this, m_family.f_id, SEX_Female );
        break;
    }

    if( indID != 0 ) {
        recFamilyIndividual fi;
        fi.Clear();
        fi.f_fam_id = m_family.f_id;
        fi.f_ind_id = indID;
        fi.Find();
        m_childlinks.push_back( fi );
        m_listChild->Append( recIndividual::GetFullName( indID ) );
    }
}

void rgDlgEditFamily::OnChildEditButton( wxCommandEvent& event )
{
    int item = m_listChild->GetSelection();
    if( item == wxNOT_FOUND ) {
        wxMessageBox( _("Row not selected"), _("Edit Children") );
        return;
    }
    idt indID = m_childlinks[item].fGetIndID();
    rgEditIndividual( this, indID );
    m_listChild->SetString( item, recIndividual::GetFullName( indID ) );
}

void rgDlgEditFamily::OnChildDeleteButton( wxCommandEvent& event )
{
    int item = m_listChild->GetSelection();
    if( item == wxNOT_FOUND ) {
        wxMessageBox( _("Row not selected"), _("Remove Children") );
        return;
    }
    m_childlinks[item].Delete();
    m_childlinks.erase( m_childlinks.begin() + item );
    m_listChild->Delete( item );
}

void rgDlgEditFamily::OnChildUpButton( wxCommandEvent& event )
{
    int item = m_listChild->GetSelection();
    if( item == wxNOT_FOUND || item == 0 ) {
        return;
    }

    recFamilyIndividual fi = m_childlinks[item];
    m_childlinks[item] = m_childlinks[item-1];
    m_childlinks[item-1] = fi;

    m_listChild->Delete( item );
    m_listChild->Insert(
        recIndividual::GetFullName( m_childlinks[item-1].f_ind_id ), item - 1
    );
    m_listChild->SetSelection( item - 1 );
}

void rgDlgEditFamily::OnChildDownButton( wxCommandEvent& event )
{
    int item = m_listChild->GetSelection();
    if( item == wxNOT_FOUND || item == m_listChild->GetCount() - 1 ) {
        return;
    }

    recFamilyIndividual fi = m_childlinks[item];
    m_childlinks[item] = m_childlinks[item+1];
    m_childlinks[item+1] = fi;

    m_listChild->Delete( item );
    m_listChild->Insert(
        recIndividual::GetFullName( m_childlinks[item+1].f_ind_id ), item + 1
    );
    m_listChild->SetSelection( item + 1 );
}


void rgDlgEditFamily::OnEventAddButton( wxCommandEvent& event )
{
    wxMenu* menu = new wxMenu;
    menu->Append( tfpID_DLGEDFAM_NEW_EVENT, _("&New Event") );
    menu->Append( tfpID_DLGEDFAM_EXIST_EVENT, _("&Existing Event") );
    PopupMenu( menu );
    delete menu;
}

void rgDlgEditFamily::OnNewEvent( wxCommandEvent& event )
{
    idt eveID; 
    if( m_family.f_husb_id == 0 ) {
        eveID = rgCreateIndEvent( this, m_family.f_wife_id, m_family.f_husb_id );
    } else {
        eveID = rgCreateIndEvent( this, m_family.f_husb_id, m_family.f_wife_id );
    }
    if( eveID ) {
        recFamilyEvent fe(0);
        fe.FSetFamID( m_family.FGetID() );
        fe.FSetEventID( eveID );
        fe.FSetFamSeq( m_family.GetMaxEventSeqNumber() );
        fe.Save();
        m_fes.push_back( fe );
        int row = m_fes.size();
        m_listEvent->InsertItem( row, recEvent::GetIdStr( eveID ) );
        m_listEvent->SetItem( row, EC_Title, recEvent::GetTitle( eveID ) );
        m_listEvent->SetItem( row, EC_Date, recEvent::GetDateStr( eveID ) );
        m_listEvent->SetItem( row, EC_Place, recEvent::GetAddressStr( eveID ) );
    }
}

void rgDlgEditFamily::OnExistingEvent( wxCommandEvent& event )
{
    // TODO:
    wxMessageBox( _("Not yet implimented"), _("OnExistingEvent") );
}

void rgDlgEditFamily::OnEventEditButton( wxCommandEvent& event )
{
    long row = m_listEvent->GetNextItem( -1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
    if( row < 0 ) {
        wxMessageBox( _("No row selected"), _("Edit Event") );
        return;
    }
    rgEditEvent( this, m_fes[row].FGetEventID() );
}

void rgDlgEditFamily::OnEventDeleteButton( wxCommandEvent& event )
{
    long row = m_listEvent->GetNextItem( -1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
    if( row >= 0 ) {
        int ans = wxMessageBox( 
            _("Remove Event completely from database?"), _("Delete Event"),
            wxYES_NO | wxCANCEL, this
        );
        if( ans != wxYES ) {
            return;
        }
        m_listEvent->DeleteItem( row );
        recEvent::RemoveIncOrphansFromDatabase( m_fes[row].FGetEventID() );
        m_fes.erase( m_fes.begin() + row );
    } else {
        wxMessageBox( _("No row selected"), _("Delete Event") );
    }
}

void rgDlgEditFamily::OnEventUpButton( wxCommandEvent& event )
{
    long row = m_listEvent->GetNextItem( -1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
    if( row < 0 ) {
        wxMessageBox( _("No row selected"), _("Move Event up") );
        return;
    }
    if( row != 0 ) {
        recFamilyEvent temp = m_fes[row];
        m_fes[row] = m_fes[row-1];
        m_fes[row-1] = temp;

        m_listEvent->DeleteItem( row );
        idt eveID = m_fes[row-1].FGetEventID();
        m_listEvent->InsertItem( row-1, recEvent::GetIdStr( eveID ) );
        m_listEvent->SetItem( row-1, EC_Title, recEvent::GetTitle( eveID ) );
        m_listEvent->SetItem( row-1, EC_Date, recEvent::GetDateStr( eveID ) );
        m_listEvent->SetItem( row-1, EC_Place, recEvent::GetAddressStr( eveID ) );

        long state = wxLIST_STATE_SELECTED;
        m_listEvent->SetItemState( row-1, state, state );
        m_listEvent->EnsureVisible( row-1 );
    }
}

void rgDlgEditFamily::OnEventDownButton( wxCommandEvent& event )
{
    long row = m_listEvent->GetNextItem( -1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
    if( row < 0 ) {
        wxMessageBox( _("No row selected"), _("Move Event down") );
        return;
    }
    if( row < m_listEvent->GetItemCount()-1 ) {
        recFamilyEvent temp = m_fes[row];
        m_fes[row] = m_fes[row+1];
        m_fes[row+1] = temp;

        m_listEvent->DeleteItem( row );
        idt eveID = m_fes[row+1].FGetEventID();
        m_listEvent->InsertItem( row+1, recEvent::GetIdStr( eveID ) );
        m_listEvent->SetItem( row+1, EC_Title, recEvent::GetTitle( eveID ) );
        m_listEvent->SetItem( row+1, EC_Date, recEvent::GetDateStr( eveID ) );
        m_listEvent->SetItem( row+1, EC_Place, recEvent::GetAddressStr( eveID ) );

        long state = wxLIST_STATE_SELECTED;
        m_listEvent->SetItemState( row+1, state, state );
        m_listEvent->EnsureVisible( row+1 );
    }
}



// End of src/rg/rgEdFamily.cpp