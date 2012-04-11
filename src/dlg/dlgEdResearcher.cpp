/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        dlgEdResearcher.cpp
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Edit database Researcher dialog.
 * Author:      Nick Matthews
 * Modified by:
 * Website:     http://thefamilypack.org
 * Created:     4 April 2012
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

#include <rec/recSystem.h>
#include <rec/recIndividual.h>

#include "dlgEdResearcher.h"
#include "dlgEdContact.h"

dlgEditResearcher::dlgEditResearcher( wxWindow* parent, idt resID )
    : m_researcher(resID), m_user(0), fbDlgEditResearcher( parent )
{
    m_list.ReadID( m_researcher.FGetConListID() );
    m_prevIndID = m_list.FGetIndID();

    wxListItem itemCol;
    itemCol.SetText( _("ID") );
    m_listContacts->InsertColumn( COL_ConID, itemCol );
    itemCol.SetText( _("Type") );
    m_listContacts->InsertColumn( COL_Type, itemCol );
    itemCol.SetText( _("Value") );
    m_listContacts->InsertColumn( COL_Value, itemCol );
}

bool dlgEditResearcher::TransferDataToWindow()
{
    if( m_researcher.f_id == 0 ) {
        // Create a new ID
        m_researcher.Save();
        m_list.Save();
        m_researcher.FSetConListID( m_list.FGetID() );
    } else {
        // Check for User
        m_user.FSetID( m_user.FindFirst( m_researcher.FGetID() ) );
        m_user.Read();
    }

    m_staticResID->SetLabel( m_researcher.GetIdStr() );
    if( m_user.FGetResID() ) {
        m_staticUserID->SetLabel( m_user.GetIdStr() );
        m_checkBoxUser->SetValue( true );
    } else {
        m_staticUserID->SetLabel( wxEmptyString );
        m_checkBoxUser->SetValue( false );
    }

    m_textName->SetValue( m_researcher.FGetName() );
    m_textComment->SetValue( m_researcher.FGetComments() );
    m_textIndID->SetValue( recGetIDStr( m_list.FGetIndID() ) );
    m_staticIndName->SetLabel( recIndividual::GetFullName( m_list.FGetIndID() ) );

    m_contacts = m_researcher.GetContacts();
    for( size_t i = 0 ; i < m_contacts.size() ; i++ ) {
        m_listContacts->InsertItem( i, m_contacts[i].GetIdStr() );
        m_listContacts->SetItem( i, COL_Type, m_contacts[i].GetTypeStr() );
        m_listContacts->SetItem( i, COL_Value, m_contacts[i].FGetValue() );
    }

    return true;
}

bool dlgEditResearcher::TransferDataFromWindow()
{
    if( m_checkBoxUser->GetValue() == true ) {
        if( m_user.FGetID() == 0 ) {
            // Create a new user.
            m_user.FSetResID( m_researcher.FGetID() );
            m_user.Save();
        }
    } else {
        if( m_user.FGetID() != 0 ) {
            // Remove user if not current.
            if( m_user.FGetID() != recGetCurrentUser() ) {
                // TODO: Remove user's settings.
                m_user.Delete();
            }
        }
    }
    m_researcher.FSetName( m_textName->GetValue() );
    m_researcher.FSetComments( m_textComment->GetValue() );

    idt newIndID = recGetID( m_textIndID->GetValue() );
    if( newIndID != m_prevIndID ) {
        // Remove the contact list from the previous Individual
        m_list.FSetIndID( 0 );
        // Look for an existing list for the new Individual
        if( newIndID ) {
            // Is there an existing ContactList
            idt newCLID = recContactList::FindIndID( newIndID );
            if( newCLID ) {
                // Add Contacts 
                m_list.Assimilate( newCLID );
            }
            m_list.FSetIndID( newIndID );
        }
        m_list.Save();
    }

    m_researcher.Save();
    return true;
}

void dlgEditResearcher::OnButtonClickAdd( wxCommandEvent& event )
{
    const wxString savepoint = "ConAdd";
    recDb::Savepoint( savepoint );

    dlgEditContact* dialog = new dlgEditContact( NULL, 0 );
    recContact* con = dialog->GetContact();
    con->FSetListID( m_list.FGetID() );

    if( dialog->ShowModal() == wxID_OK ) {
        recDb::ReleaseSavepoint( savepoint );
        int row = m_contacts.size();
        m_listContacts->InsertItem( row, con->GetIdStr() );
        m_listContacts->SetItem( row, COL_Type, con->GetTypeStr() );
        m_listContacts->SetItem( row, COL_Value, con->FGetValue() );
        m_contacts.push_back( *con );
   } else {
        recDb::Rollback( savepoint );
    }
    dialog->Destroy();
}

void dlgEditResearcher::OnButtonClickEdit( wxCommandEvent& event )
{
    long row = m_listContacts->GetNextItem( -1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
    if( row < 0 ) {
        wxMessageBox( _("No row selected"), _("Edit Contact") );
        return;
    }

    const wxString savepoint = "ConEd";
    recDb::Savepoint( savepoint );

    dlgEditContact* dialog = new dlgEditContact( NULL, m_contacts[row].FGetID() );

    if( dialog->ShowModal() == wxID_OK ) {
        recDb::ReleaseSavepoint( savepoint );
        recContact* con = dialog->GetContact();
        m_listContacts->SetItem( row, COL_ConID, con->GetIdStr() );
        m_listContacts->SetItem( row, COL_Type, con->GetTypeStr() );
        m_listContacts->SetItem( row, COL_Value, con->FGetValue() );
        m_contacts[row] = *con;
    } else {
        recDb::Rollback( savepoint );
    }
    dialog->Destroy();
}

void dlgEditResearcher::OnButtonClickDelete( wxCommandEvent& event )
{
    long row = m_listContacts->GetNextItem( -1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
    if( row >= 0 ) {
        m_listContacts->DeleteItem( row );
        m_contacts[row].Delete();
        m_contacts.erase( m_contacts.begin() + row );
    } else {
        wxMessageBox( _("No row selected"), _("Delete Contact") );
    }
}

// End of dlgEdResearcher.cpp file