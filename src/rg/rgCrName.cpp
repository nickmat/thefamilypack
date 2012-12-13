/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        src/rg/rgCrName.cpp
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Create database Name entity dialog.
 * Author:      Nick Matthews
 * Modified by:
 * Website:     http://thefamilypack.org
 * Created:     12th December 2012
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

#include "rgCrName.h"
#include "rg/rgDialogs.h"

idt rgCreateName( 
    idt perID,
    unsigned flags, 
    const wxString& name1,
    const wxString& name2,
    recNameStyle::Style type
) {
    const wxString savepoint = recDb::GetSavepointStr();
    recDb::Savepoint( savepoint );
    idt nameID = 0;

    rgDlgCreateName* dialog = new rgDlgCreateName( NULL );
    dialog->SetPersonaID( perID );
    if( flags & rgCRNAME_Sur_Given ) {
        dialog->SetSurname( name1 );
        dialog->SetGiven( name2 );
    } else if( name1.size() ) {
        wxString surname;
        wxString given = name1.BeforeLast( ' ', &surname );
        dialog->SetSurname( surname );
        dialog->SetGiven( given );
    }
    dialog->SetType( type );

    if( dialog->ShowModal() == wxID_OK ) {
        recDb::ReleaseSavepoint( savepoint );
        nameID = dialog->GetNameID();
    } else {
        recDb::Rollback( savepoint );
    }
    dialog->Destroy();
    return nameID;
}

//============================================================================
//-------------------------[ rgDlgCreateName ]--------------------------------
//============================================================================

bool rgDlgCreateName::TransferDataToWindow()
{
    wxASSERT( m_name.FGetID() == 0 );
    m_name.Save();
    m_types = recNameStyle::GetStyleList();
    for( size_t i = 0 ; i < m_types.size() ; i++ ) {
        m_choiceType->Append( m_types[i].f_name );
        if( m_name.f_style_id == m_types[i].f_id ) {
            m_choiceType->SetSelection( (int) i );
        }
    }
    m_textCtrlGiven->SetValue( m_given );
    m_textCtrlSurname->SetValue( m_surname );
    m_staticNameID->SetLabel( m_name.GetIdStr() );
    return true;
}

bool rgDlgCreateName::TransferDataFromWindow()
{
    int i = m_choiceType->GetSelection();
    m_name.f_style_id = m_types[i].f_id;
    m_name.Save();

    int seq = m_name.AddNameParts( m_textCtrlGiven->GetValue(), NAME_TYPE_Given_name, 0 );
    m_name.AddNamePart( m_textCtrlSurname->GetValue(), NAME_TYPE_Surname, seq );
    return true;
}

// End of src/rg/rgCrName.cpp file