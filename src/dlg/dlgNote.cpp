/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        dlgNote.cpp
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Display html text as a note.
 * Author:      Nick Matthews
 * Website:     http://thefamilypack.org
 * Created:     21 January 2012
 * RCS-ID:      $Id$
 * Copyright:   Copyright (c) 2012 - 2013, Nick Matthews.
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

#include <wx/webview.h>
#include "webviewfshandler.h"

#include <rec/recDatabase.h>
#include "tfpFrame.h"
#include "dlgNote.h"
#include "tfpWr.h"


dlgNote::dlgNote( TfpFrame* parent, const wxString& name )
    : wxDialog(
        (wxWindow*) parent, wxID_ANY, "Note "+name, wxDefaultPosition, wxDefaultSize,
        wxCAPTION | wxCLOSE_BOX | wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER
    )
{
    m_frame = parent;
    SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* bSizer1 = new wxBoxSizer( wxVERTICAL );

    m_browser = wxWebView::New( this, tfpID_BROWSER );
    bSizer1->Add( m_browser, 1, wxALL|wxEXPAND, 0 );

    SetSizer( bSizer1 );
    Layout();

    m_name = name;
    m_cond = recDb::GetChange();
    SetPosition( wxGetMousePosition() );

    // Connect Events
    Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( dlgNote::OnClose ) );
    Connect( wxEVT_IDLE, wxIdleEventHandler( dlgNote::OnIdle ) );
}

dlgNote::~dlgNote()
{
    // Disconnect Events
    Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( dlgNote::OnClose ) );
    Disconnect( wxEVT_IDLE, wxIdleEventHandler( dlgNote::OnIdle ) );
}

bool dlgNote::TransferDataToWindow()
{
    m_browser->SetPage( m_frame->GetDisplayText( m_name ), "" );
    return true;
}

void dlgNote::OnIdle( wxIdleEvent& event )
{
    if( m_cond != recDb::GetChange() ) {
        m_browser->SetPage( m_frame->GetDisplayText( m_name ), "" );
        m_cond = recDb::GetChange();
    }
}

void dlgNote::OnClose( wxCloseEvent& event )
{
    Destroy();
}

// End of dlgNote.cpp file
