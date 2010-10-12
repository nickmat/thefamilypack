/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        tfpFrame.cpp
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     TfpFrame class source.
 * Author:      Nick Matthews
 * Modified by:
 * Created:     25 September 2010
 * RCS-ID:      $Id$
 * Copyright:   Copyright (c) 2010, Nick Matthews.
 * Website:     http://thefamilypack.org
 * Licence:     GNU GPLv3
 *
 *  The Family Pack is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  The Family Pack is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
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

#include <wx/html/htmlwin.h>
#include <wx/html/htmprint.h>

#include <rec/recIndividual.h>

#include "tfpFrame.h"
#include "tfpApp.h"
#include "tfpVersion.h"
#include "tfpEdit.h"
#include "tfpWr.h"

#include "img/forward.xpm"
#include "img/back.xpm"
#include "img/find.xpm"
#include "img/home.xpm"

BEGIN_EVENT_TABLE(TfpFrame, wxFrame)
    EVT_MENU( tfpID_NEW_WINDOW, TfpFrame::OnNewWindow )
    EVT_MENU( tfpID_NEW_FILE, TfpFrame::OnNewFile )
    EVT_MENU( tfpID_OPEN_FILE, TfpFrame::OnOpenFile )
    EVT_MENU( tfpID_CLOSE_FILE, TfpFrame::OnCloseFile )
    EVT_MENU( tfpID_IMPORT_GEDCOM, TfpFrame::OnImportGedcom )
    EVT_MENU( tfpID_EXPORT_HTML, TfpFrame::OnExportHtml )
    EVT_MENU( tfpID_PRINT, TfpFrame::OnPrint )
    EVT_MENU( tfpID_PREVIEW, TfpFrame::OnPreview )
    EVT_MENU( tfpID_PAGE_SETUP, TfpFrame::OnPageSetup )
    EVT_MENU( wxID_EXIT, TfpFrame::OnQuit )
    EVT_MENU( tfpID_EDIT_INDIVIDUAL, TfpFrame::OnEditIndividual )
    EVT_MENU( tfpID_EDIT_REFERENCE, TfpFrame::OnEditReference )
    EVT_MENU( tfpID_FIND_FAMILY_ID, TfpFrame::OnFindFamilyID )
    EVT_MENU( tfpID_FIND_INDIVIDUAL_ID, TfpFrame::OnFindIndividualID )
    EVT_MENU( tfpID_LIST_SURNAME_INDEX, TfpFrame::OnListIndex )
    EVT_MENU( tfpID_LIST_NAMES, TfpFrame::OnListNames )
    EVT_MENU( tfpID_LIST_INDIVIDUALS, TfpFrame::OnListIndividuals )
    EVT_MENU( tfpID_PED_CHART, TfpFrame::OnPedChart )
    EVT_MENU( tfpID_DESC_CHART, TfpFrame::OnDescChart )
    EVT_MENU( tfpID_HELP_WEB_HOME, TfpFrame::OnHelpWebHome )
    EVT_MENU( wxID_ABOUT, TfpFrame::OnAbout )
    EVT_MENU( tfpID_FIND_BACK, TfpFrame::OnFindBack )
    EVT_MENU( tfpID_FIND_FORWARD, TfpFrame::OnFindForward )
    EVT_MENU( tfpID_GOTO_HOME, TfpFrame::OnHome )
    EVT_HTML_LINK_CLICKED( wxID_ANY, TfpFrame::OnHtmlLinkClicked )
    EVT_MENU_RANGE( tfpID_HCTXMENU_BEG, tfpID_HCTXMENU_END, TfpFrame::OnHtmCtxMenu )
    EVT_CLOSE( TfpFrame::OnCloseWindow )
END_EVENT_TABLE()


/*! \brief Frame constructor.
 *
 *  Create the window Icon, Menu bar, Status bar and Html control.
 *  Set the window to display the splash screen.
 */
TfpFrame::TfpFrame( const wxString& title, const wxPoint& pos, const wxSize& size )
    : wxFrame( (wxFrame*) NULL, wxID_ANY, title, pos, size )
{
    // Set frames Icon
    SetIcon( wxIcon( "tfp" ) );

    // create a menu bar for use with an open database
    wxMenu *menuFile = new wxMenu;
    menuFile->Append( tfpID_NEW_WINDOW, _("New &Window\tCtrl-W") );
    menuFile->AppendSeparator();
    menuFile->Append( tfpID_NEW_FILE, _("&New Database\tCtrl-N") );
    menuFile->Append( tfpID_OPEN_FILE, _("&Open Database\tCtrl-O") );
    menuFile->Append( tfpID_CLOSE_FILE, _("&Close Database") );
    menuFile->AppendSeparator();
    menuFile->Append( tfpID_IMPORT_GEDCOM, _("&Import GEDCOM file") );
    menuFile->AppendSeparator();
    menuFile->Append( tfpID_EXPORT_HTML, _("&Export HTML files") );
    menuFile->AppendSeparator();
    menuFile->Append( tfpID_PRINT, _("&Print...\tCtrl-P") );
    menuFile->Append( tfpID_PREVIEW, _("Pre&view\tCtrl-Shift-P") );
    menuFile->Append( tfpID_PAGE_SETUP, _("Page Set&up...") );
    menuFile->AppendSeparator();
    menuFile->Append( wxID_EXIT, _("E&xit") );

    wxMenu* menuEdit = new wxMenu;
    menuEdit->Append( tfpID_EDIT_INDIVIDUAL, _("&Individual") );
    menuEdit->Append( tfpID_EDIT_REFERENCE, _("&Reference") );

    wxMenu* menuFind = new wxMenu;
    menuFind->Append( tfpID_FIND_FAMILY_ID, _("&Family ID...") );
    menuFind->Append( tfpID_FIND_INDIVIDUAL_ID, _("&Individual ID...") );

    wxMenu* menuList = new wxMenu;
    menuList->Append( tfpID_LIST_SURNAME_INDEX, _("&Surname Index\tCtrl-I") );
    menuList->Append( tfpID_LIST_NAMES, _("&Names\tCtrl-N") );
    menuList->Append( tfpID_LIST_INDIVIDUALS, _("&Individuals\tCtrl-N") );

    wxMenu* menuChart = new wxMenu;
    menuChart->Append( tfpID_PED_CHART, _("&Pedigree...") );
    menuChart->Append( tfpID_DESC_CHART, _("&Descendant...") );

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append( tfpID_HELP_WEB_HOME, _("The Family Pack &Website") );
    menuHelp->Append( wxID_ABOUT, _("&About \"The Family Pack\"") );

    m_menuOpenDB = new wxMenuBar;
    m_menuOpenDB->Append( menuFile, _("&File") );
    m_menuOpenDB->Append( menuEdit, _("&Edit") );
    m_menuOpenDB->Append( menuFind, _("F&ind") );
    m_menuOpenDB->Append( menuList, _("&List") );
    m_menuOpenDB->Append( menuChart, _("&Chart") );
    m_menuOpenDB->Append( menuHelp, _("&Help") );

    // Menu bar for use with closed database
    wxMenu *menuInitFile = new wxMenu;
    menuInitFile->Append( tfpID_NEW_FILE, _("&New File\tCtrl-N") );
    menuInitFile->Append( tfpID_OPEN_FILE, _("&Open File\tCtrl-O") );
    menuInitFile->AppendSeparator();
    menuInitFile->Append( tfpID_IMPORT_GEDCOM, _("&Import GEDCOM file") );
    menuInitFile->AppendSeparator();
    menuInitFile->Append( wxID_EXIT, _("E&xit") );

    wxMenu *menuInitHelp = new wxMenu;
    menuInitHelp->Append( tfpID_HELP_WEB_HOME, _("The Family Pack &Website") );
    menuInitHelp->Append( wxID_ABOUT, _("&About \"The Family Pack\"") );

    m_menuClosedDB = new wxMenuBar;
    m_menuClosedDB->Append( menuInitFile, _("&File") );
    m_menuClosedDB->Append( menuInitHelp, _("&Help") );
    SetMenuBar( m_menuClosedDB );

    // Add toolbar
    m_toolbar = new wxToolBar( this, wxID_ANY );
    wxBitmap bmpForward( forward_xpm );
    wxBitmap bmpBack( back_xpm );
    wxBitmap bmpFind( find_xpm );
    wxBitmap bmpHome( home_xpm );
    m_toolbar->AddTool( tfpID_FIND_BACK, _("Back"), bmpBack );
    m_toolbar->AddTool( tfpID_FIND_FORWARD, _("Forward"), bmpForward );
    m_toolbar->AddSeparator();
    m_toolbar->AddTool( tfpID_LIST_SURNAME_INDEX, _("Index"), bmpFind );
    m_toolbar->AddSeparator();
    m_toolbar->AddTool( tfpID_GOTO_HOME, _("Home"), bmpHome );
    m_toolbar->Realize();
    SetToolBar( m_toolbar );

    CreateStatusBar();

    m_html = new wxHtmlWindow( this );
    m_html->SetRelatedStatusBar( 0 );

    m_dbname = wxEmptyString;
    SetDatabaseOpen( m_dbname, false );

    m_prn = new wxHtmlEasyPrinting( _("Easy Printing Demo"), this );

    m_html->LoadPage( "memory:startup.htm" );
}

/*! \brief Frame destructor.
 */
TfpFrame::~TfpFrame()
{
    wxDELETE( m_prn );
	if( GetMenuBar() != m_menuOpenDB ) {
        wxDELETE( m_menuOpenDB );
	}
	if( GetMenuBar() != m_menuClosedDB ) {
		wxDELETE( m_menuClosedDB );
	}
}

/*! \brief Called on a New Window menu option event.
 */
void TfpFrame::OnNewWindow( wxCommandEvent& event )
{
    wxMessageBox( wxT("Not yet implimented"), wxT("OnNewWindow") );
}

/*! \brief Called on a New File menu option event.
 */
void TfpFrame::OnNewFile( wxCommandEvent& event )
{
    NewFile();
}

/*! \brief Called on an Open File menu option event.
 */
void TfpFrame::OnOpenFile( wxCommandEvent& event )
{
    OpenFile();
}

/*! \brief Called on a Close File menu option event.
 */
void TfpFrame::OnCloseFile( wxCommandEvent& event )
{
    recDb::CloseDb();
    m_dbname = wxEmptyString;
    SetDatabaseOpen( m_dbname, false );
    m_html->LoadPage( wxT("memory:startup.htm") );
}

/*! \brief Called on a Inport GEDCOM File menu option event.
 */
void TfpFrame::OnImportGedcom( wxCommandEvent& event )
{
    ImportGedcom();
}

/*! \brief Called on a Export Html menu option event.
 */
void TfpFrame::OnExportHtml( wxCommandEvent& event )
{
    wxMessageBox( wxT("Not yet implimented"), wxT("OnExportHtml") );
}

/*! \brief Called on a Print menu option event.
 */
void TfpFrame::OnPrint( wxCommandEvent& event )
{
    wxMessageBox( wxT("Not yet implimented"), wxT("OnPrint") );
}

/*! \brief Called on a Print Preview menu option event.
 */
void TfpFrame::OnPreview( wxCommandEvent& event )
{
    wxMessageBox( wxT("Not yet implimented"), wxT("OnPreview") );
}

/*! \brief Called on a  Page Setup menu option event.
 */
void TfpFrame::OnPageSetup( wxCommandEvent& event )
{
    wxMessageBox( wxT("Not yet implimented"), wxT("OnPageSetup") );
}

/*! \brief Called on an Exit Application menu option event.
 */
void TfpFrame::OnQuit( wxCommandEvent& event )
{
    // true is to force the frame to close
    Close( true );
}

/*! \brief Called on a Edit Individual menu option event.
 */
void TfpFrame::OnEditIndividual( wxCommandEvent& event )
{
//    wxMessageBox( wxT("Not yet implimented"), wxT("OnEditIndividual") );
    id_t id = 0;
    recDb::Begin();
    try {
        id = tfpAddIndividual( 0, SEX_Male );
        if( id != 0 ) {
            recDb::Commit();
            wxString str;
            str << "FI" << id;
            DisplayHtmPage( str );
        } else {
            recDb::Rollback();
        }
    } catch( wxSQLite3Exception& e ) {
        recDb::ErrorMessage( e );
        recDb::Rollback();
    }
}

/*! \brief Called on a Edit Reference menu option event.
 */
void TfpFrame::OnEditReference( wxCommandEvent& event )
{
    wxMessageBox( wxT("Not yet implimented"), wxT("OnEditReference") );
}

/*! \brief Called on a Find Family ID menu option event.
 */
void TfpFrame::OnFindFamilyID( wxCommandEvent& event )
{
    wxMessageBox( wxT("Not yet implimented"), wxT("OnFindFamilyID") );
}

/*! \brief Called on a Find Individual ID menu option event.
 */
void TfpFrame::OnFindIndividualID( wxCommandEvent& event )
{
    wxMessageBox( wxT("Not yet implimented"), wxT("OnFindIndividualID") );
}

/*! \brief Called on a List Index menu option event.
 */
void TfpFrame::OnListIndex( wxCommandEvent& event )
{
//    wxMessageBox( wxT("Not yet implimented"), wxT("OnListIndex") );
    DisplayHtmPage( "N" );
}

/*! \brief Called on a List Names menu option event.
 */
void TfpFrame::OnListNames( wxCommandEvent& event )
{
    wxMessageBox( wxT("Not yet implimented"), wxT("OnListNames") );
}

/*! \brief Called on a  List Individuals menu option event.
 */
void TfpFrame::OnListIndividuals( wxCommandEvent& event )
{
    wxMessageBox( wxT("Not yet implimented"), wxT("OnListIndividuals") );
}

/*! \brief Called on a Pedigree Chart menu option event.
 */
void TfpFrame::OnPedChart( wxCommandEvent& event )
{
    wxMessageBox( wxT("Not yet implimented"), wxT("OnPedChart") );
}

/*! \brief Called on a Descendant Chart menu option event.
 */
void TfpFrame::OnDescChart( wxCommandEvent& event )
{
    wxMessageBox( wxT("Not yet implimented"), wxT("OnDescChart") );
}

/*! \brief Called on a Help, TFP Website menu option event.
 *
 */
void TfpFrame::OnHelpWebHome( wxCommandEvent& event )
{
    wxLaunchDefaultBrowser( "http://thefamilypack.org" );
}

/*! \brief Called on a Help, About menu option event.
 *
 *  Displays a message box with the current TFP version number,
 *  wxWidgets version number, the compiler name and version and
 *  operating system description.
 *
 */
void TfpFrame::OnAbout( wxCommandEvent& event )
{
    wxMessageBox(
        wxString::Format(
            _("%s"
            "Built with %s and SQLite %s\n"
            "by %s\n"
            "running under %s."),

            tfpTitle,
            wxVERSION_STRING,
            wxSQLite3Database::GetVersion(),
            tfpGetCompilerVersion(),
            wxGetOsDescription().c_str()
        ),
        _("About The Family Pack"),
        wxOK | wxICON_INFORMATION,
        this
    );
}

/*! \brief Called on a Find Back button option event.
 */
void TfpFrame::OnFindBack( wxCommandEvent& event )
{
    size_t ind = m_back.size();

    if( ind > 1 ) {
        --ind;
        m_forward.push_back( m_back[ind] );
        m_toolbar->EnableTool( tfpID_FIND_FORWARD, true );
        m_back.pop_back();
        if( ind == 1 ) {
            m_toolbar->EnableTool( tfpID_FIND_BACK, false );
        }
        RefreshHtmPage();
    }
}

/*! \brief Called on a Find Forward button option event.
 */
void TfpFrame::OnFindForward( wxCommandEvent& event )
{
//    wxMessageBox( wxT("Not yet implimented"), wxT("OnFindForward") );
    size_t ind = m_forward.size();
    if( ind > 0 )
    {
        --ind;
        m_back.push_back( m_forward[ind] );
        if( m_back.size() > 1 ) {
            m_toolbar->EnableTool( tfpID_FIND_BACK, true );
        }
        m_forward.pop_back();
        if( ind == 0 ) {
            m_toolbar->EnableTool( tfpID_FIND_FORWARD, false );
        }
        RefreshHtmPage();
    }
}

/*! \brief Called on a Home button option event.
 */
void TfpFrame::OnHome( wxCommandEvent& event )
{
    DisplayHtmPage( "F1" );
}

/*! \brief Called on a link in the html control being clicked.
 *
 *  Decodes the href string of the clicked link. If the first
 *  character of the href string is:-
 *
 *  ':' then the remainder of the string is a command.
 *
 *  '!' then the remainder of the string is a web address to be
 *  passed to the default external browser.
 *  
 */
void TfpFrame::OnHtmlLinkClicked( wxHtmlLinkEvent& event )
{
    wxString href = event.GetLinkInfo().GetHref().c_str();

    switch( (wxChar) href.GetChar( 0 ) )
    {
    case ':': // Program Commands
        if( href == ":New" ) {
            NewFile();
        } else if( href == ":Open" ) {
            OpenFile();
        } else if( href == ":Import" ) {
            ImportGedcom();
        } else {
            wxMessageBox( _("Error: Invalid Command"), _("Link Error") );
        }
        break;
    case '$':  // Context Commands
        switch( (wxChar) href.GetChar( 1 ) )
        {
        case 'I': // Edit the given individual (create if 0)
            switch( (wxChar) href.GetChar( 2 ) )
            {
            case 'H': case 'W':
                AddNewSpouse( href.Mid(2) );
                break;
            case 'F': case 'M':
                AddNewParent( href.Mid(2) );
                break;
            }
            break;
        case 'M': // Create a popup menu
            DoHtmCtxMenu( href.Mid(2) );
            break;
        }
        break;
    case '!':  // Display in external browser
        wxLaunchDefaultBrowser( href.Mid( 1 ) );
        break;
    default:   // Display the given reference
        DisplayHtmPage( href );
    }
}

void TfpFrame::OnHtmCtxMenu( wxCommandEvent& event )
{
    bool ret = false;
    Sex sex;
    wxLongLong_t id;
    m_ctxmenuref.Mid(1).ToLongLong( &id );

    recDb::Begin();
    try {
        switch( event.GetId() )
        {
        case tfpID_HCTXMENU_EDIT_FAMILY:
            ret = tfpEditFamily( id );
            break;
        case tfpID_HCTXMENU_EDIT_INDIVIDUAL:
            ret = tfpEditIndividual( id );
            break;
        case tfpID_HCTXMENU_EDIT_NEW_SON:
            if( tfpAddNewChild( id, SEX_Male ) != 0 ) ret = true;
            break;
        case tfpID_HCTXMENU_EDIT_NEW_DAUR:
            if( tfpAddNewChild( id, SEX_Female ) != 0 ) ret = true;
            break;
        case tfpID_HCTXMENU_EDIT_EXIST_SON:
            ret = tfpAddExistChild( id, SEX_Male );
            break;
        case tfpID_HCTXMENU_EDIT_EXIST_DAUR:
            ret = tfpAddExistChild( id, SEX_Female );
            break;
        case tfpID_HCTXMENU_EDIT_NEW_SPOUSE:
            sex = ( m_ctxmenuref.GetChar(0) == 'H' ) ? SEX_Female : SEX_Male;
            ret = tfpAddNewSpouse( id, sex );
            break;
        case tfpID_HCTXMENU_EDIT_EXIST_SPOUSE:
            sex = ( m_ctxmenuref.GetChar(0) == 'H' ) ? SEX_Female : SEX_Male;
            ret = tfpAddExistSpouse( id, sex );
            break;
        }
        if( ret == true ) {
            recDb::Commit();
            RefreshHtmPage();
        } else {
            recDb::Rollback();
        }
    } catch( wxSQLite3Exception& e ) {
        recDb::ErrorMessage( e );
        recDb::Rollback();
    }
}

/*! \brief Called on a Close Window event.
 */
void TfpFrame::OnCloseWindow( wxCloseEvent& event )
{
    this->Destroy();
}


void TfpFrame::NewFile()
{
    wxString caption = _("Create TFP Database");
    wxString wildcard = _("TFP Database (*.tfpd)|*.tfpd");
    wxString defaultDir = ".";
    wxString defaultFName = wxEmptyString;

    wxFileDialog dialog( this, caption, defaultDir, defaultFName, wildcard, wxFD_OPEN );
    if( dialog.ShowModal() == wxID_OK )
    {
        wxString path = dialog.GetPath();
        unsigned flags = recDb::CREATE_DB_STD_EXT | recDb::CREATE_DB_ENUM_FN;
        if( recDb::CreateDb( path, flags ) == true )
        {
            SetDatabaseOpen( path, true );
            DisplayHtmPage( "F1" );
        }
    }
}

void TfpFrame::OpenFile()
{
//    wxMessageBox( wxT("Not yet implimented"), wxT("OpenFile") );
    wxString caption = _("Select TFP Database");
    wxString wildcard = _("TFP Database (*.tfpd)|*.tfpd");
    wxString defaultDir = ".";
    wxString defaultFName = wxEmptyString;

    wxFileDialog dialog( this, caption, defaultDir, defaultFName, wildcard, wxFD_OPEN );
    if( dialog.ShowModal() == wxID_OK )
    {
        wxString path = dialog.GetPath();
        if( recDb::OpenDb( path ) == true )
        {
            SetDatabaseOpen( path, true );
            DisplayHtmPage( wxT("F1") );
        }
    }
}

void TfpFrame::ImportGedcom()
{
    wxMessageBox( wxT("Not yet implimented"), wxT("ImportGedcom") );
}

void TfpFrame::SetDatabaseOpen( wxString& path, bool open )
{
    if( open ) {
        wxFileName dbfile( path );
        m_dbname = wxString::Format( "TFP: %s, %%s", dbfile.GetName().c_str() );
        m_html->SetRelatedFrame( this, m_dbname );
        SetMenuBar( m_menuOpenDB );
        m_toolbar->EnableTool( tfpID_LIST_SURNAME_INDEX, true );
        m_toolbar->EnableTool( tfpID_GOTO_HOME, true );
    } else {
        m_dbname = wxEmptyString;
        m_html->SetRelatedFrame( this, "The Family Pack" );
        SetMenuBar( m_menuClosedDB );
        m_toolbar->EnableTool( tfpID_LIST_SURNAME_INDEX, false );
        m_toolbar->EnableTool( tfpID_GOTO_HOME, false );
        m_back.clear();
        m_toolbar->EnableTool( tfpID_FIND_BACK, false );
        m_forward.clear();
        m_toolbar->EnableTool( tfpID_FIND_FORWARD, false );
    }
}

bool TfpFrame::DisplayHtmPage( const wxString& name )
{
    wxString text = GetDisplayText( name );
    if( text != wxEmptyString )
    {
        m_back.push_back( name );
        if( m_back.size() > 1 ) {
            m_toolbar->EnableTool( tfpID_FIND_BACK, true );
        }
        if( m_forward.size() != 0 ) {
            m_forward.clear();
            m_toolbar->EnableTool( tfpID_FIND_FORWARD, false );
        }
        m_html->SetPage( text );
        return true;
    }
    return false;
}

wxString TfpFrame::GetDisplayText( const wxString& name )
{
    wxLongLong_t num;
    bool success;
    wxString text;

    switch( (wxChar) name.GetChar( 0 ) )
    {
    case 'F':  // Family reference
        if( name.GetChar( 1 ) == 'I' ) {
            success = name.Mid(2).ToLongLong( &num );
            if( !success || num < 1 ) {
                wxMessageBox( _("Error: Invalid Individual ID link"), _("Family Link") );
                return wxEmptyString;
            }
            text = tfpWriteIndFamilyPage( num );
            break;
        }
        success = name.Mid(1).ToLongLong( &num );
        if( !success || num < 1 ) {
            wxMessageBox( _("Error: Invalid Family ID link"), _("Family Link") );
            return wxEmptyString;
        }
        text = tfpWriteFamilyPage( num );
        break;
    case 'I':  // Individual reference
        success = name.Mid(1).ToLongLong( &num );
        if( !success || num < 1 ) {
            wxMessageBox( wxT("Error: Invalid Individual ID link"), wxT("Family Link") );
            return wxEmptyString;
        }
        text = tfpWriteIndividualPage( num );
        break;
    case 'N':  // Name index
        if( name == wxT("N") ) {
            text = tfpWritePersonIndex();
        } else if( name == wxT("N*") ) {
            text = tfpWritePersonList( wxEmptyString );
        } else {
            text = tfpWritePersonList( name.Mid( 1 ) );
        }
        break;
    case 'C':  // Chart reference
        name.Mid(2).ToLongLong( &num );
        switch( (wxChar) name.GetChar( 1 ) )
        {
        case 'D':
            text = tfpCreateDescChart( (unsigned) num );
            break;
        case 'P':
            text = tfpCreatePedChart( (unsigned) num );
            break;
        default:
            wxMessageBox( wxT("Error: Invalid Chart link reference"), wxT("Link Error") );
            return wxEmptyString;
        }
        break;
	case 'R':  // Reference Document
        success = name.Mid(1).ToLongLong( &num );
        if( !success || num < 1 ) {
            wxMessageBox( wxT("Error: Invalid Reference Document ID link"), wxT("Link Error") );
            return wxEmptyString;
        }
        wxMessageBox( wxT("Error: Invalid Chart link reference"), wxT("Link Error") );
        return wxEmptyString;
    default:
        wxMessageBox( _("Not yet implimented ")+name, _("tfpWriteReferencePage") );
        return wxEmptyString;
    }
    return text;
}

void TfpFrame::RefreshHtmPage()
{
    size_t cnt = m_back.GetCount();
    if( cnt > 0 ) {
        wxString name = m_back[ cnt - 1 ];
        m_html->SetPage( GetDisplayText( name ) );
    }
}


void TfpFrame::DoHtmCtxMenu( const wxString& ref )
{
//    wxMessageBox( _("Not yet implimented ")+ref, _("DoHtmCtxMenu") );
    int count;
    m_ctxmenuref = ref;
    wxMenu* menu = new wxMenu;

    switch( (wxChar) ref.GetChar( 0 ) )
    {
    case 'F': // Edit family record or children
        menu->Append( tfpID_HCTXMENU_EDIT_FAMILY, wxT("Edit Family") );
        menu->AppendSeparator();
        menu->Append( tfpID_HCTXMENU_EDIT_NEW_SON, wxT("Add new Son") );
        menu->Append( tfpID_HCTXMENU_EDIT_NEW_DAUR, wxT("Add new Daughter") );
        menu->AppendSeparator();
        menu->Append( tfpID_HCTXMENU_EDIT_EXIST_SON, wxT("Add existing son") );
        menu->Append( tfpID_HCTXMENU_EDIT_EXIST_DAUR, wxT("Add existing Daughter") );
        break;
    case 'H': case 'W': // Edit a Husb or Wife Individual
        menu->Append( tfpID_HCTXMENU_EDIT_INDIVIDUAL, wxT("Edit Individual") );
        menu->AppendSeparator();
        menu->Append( tfpID_HCTXMENU_EDIT_NEW_SPOUSE, wxT("Add new spouse") );
        menu->Append( tfpID_HCTXMENU_EDIT_EXIST_SPOUSE, wxT("Add existing spouse") );
        break;
    case 'R':
        // Parents, Spouses (Marriage), Siblings, and Children
        // List individuals and jump to the selected individuals family
        m_ctxmenuIDs.empty();
        count = AddFamiliesToMenu( ref, menu, tfpID_INDMENU_BEG );
        break;
    default:
        delete menu;
        wxMessageBox( wxT("Error: \"") + ref + wxT("\" Unknown Menu"), wxT("Link Error") );
        return;
    }

    PopupMenu( menu );
    delete menu;
}

int TfpFrame::AddFamiliesToMenu( const wxString& ref, wxMenu* menu, int cmd_ID )
{
    recFamilyList families;
    size_t c = 0, i, j;
    recIndividualList inds;
    wxLongLong_t indID;
    ref.Mid( 1 ).ToLongLong( &indID );

    menu->Append( cmd_ID + c, wxT("Family") );
    m_ctxmenuIDs.push_back( recIndividual::GetDefaultFamily( indID ) );
    c++;

    wxMenu* parmenu = new wxMenu;
    menu->AppendSubMenu( parmenu, wxT("Parents") );
    families = recIndividual::GetParentList( indID );
    for( i = 0 ; i < families.size() ; i++ ) {
        if( families[i].f_husb_id != 0 ) {
            parmenu->Append( cmd_ID + c, recIndividual::GetFullName( families[i].f_husb_id ) );
        }
        if( families[i].f_wife_id != 0 ) {
            parmenu->Append( cmd_ID + c, recIndividual::GetFullName( families[i].f_wife_id ) );
        }
        m_ctxmenuIDs.push_back( families[i].f_id );
        c++;
    }

    wxMenu* sibmenu = new wxMenu;
    menu->AppendSubMenu( sibmenu, wxT("Siblings") );
    for( i = 0 ; i < families.size() ; i++ ) {
        inds = families[i].GetChildren();
        for( j = 0 ; j < inds.size() ; j++ ) {
            if( inds[j].f_id == indID ) continue;
            sibmenu->Append( cmd_ID + c, inds[j].GetFullName() );
            m_ctxmenuIDs.push_back( inds[j].f_fam_id );
            c++;
        }
        inds.empty();
    }

    wxMenu* marmenu = new wxMenu;
    menu->AppendSubMenu( marmenu, wxT("Spouses") );
    families.empty();
    families = recIndividual::GetFamilyList( indID );
    for( i = 0 ; i < families.size() ; i++ ) {
        if( families[i].f_husb_id != 0 && families[i].f_husb_id != indID ) {
            marmenu->Append( cmd_ID + c, recIndividual::GetFullName( families[i].f_husb_id ) );
        }
        if( families[i].f_wife_id != 0 && families[i].f_wife_id != indID ) {
            marmenu->Append( cmd_ID + c, recIndividual::GetFullName( families[i].f_wife_id ) );
        }
        m_ctxmenuIDs.push_back( families[i].f_id );
        c++;
    }

    wxMenu* kidmenu = new wxMenu;
    menu->AppendSubMenu( kidmenu, wxT("Children") );
    for( i = 0 ; i < families.size() ; i++ ) {
        inds.empty();
        inds = families[i].GetChildren();
        for( j = 0 ; j < inds.size() ; j++ ) {
            kidmenu->Append( cmd_ID + c, inds[j].GetFullName() );
            m_ctxmenuIDs.push_back( inds[j].f_fam_id );
            c++;
        }
    }
    families.clear();
    inds.clear();
    return c;
}

void TfpFrame::AddNewSpouse( const wxString& ref )
{
    wxLongLong_t indID;
    ref.Mid( 1 ).ToLongLong( &indID );
    Sex sex = ( ref.GetChar(0) == 'W' ) ? SEX_Female : SEX_Male;
    recDb::Begin();
    if( tfpAddNewSpouse( indID, sex ) == true ) {
        recDb::Commit();
        RefreshHtmPage();
    } else {
        recDb::Rollback();
    }
}

void TfpFrame::AddNewParent( const wxString& ref )
{
    wxLongLong_t indID;
    ref.Mid( 1 ).ToLongLong( &indID );
    Sex sex = ( ref.GetChar(0) == 'F' ) ? SEX_Female : SEX_Male;
    recDb::Begin();
    if( tfpAddNewParent( indID, sex ) == true ) {
        recDb::Commit();
        RefreshHtmPage();
    } else {
        recDb::Rollback();
    }
}


// End of tfpFrame.cpp file

