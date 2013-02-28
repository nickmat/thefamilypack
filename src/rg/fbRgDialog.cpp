///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif


#include "rgTableCtrl.h"

#include "fbRgDialog.h"

#include "../img/ed/copy.xpm"
#include "../img/ed/cut.xpm"
#include "../img/ed/paste.xpm"
#include "../img/ed/redo.xpm"
#include "../img/ed/undo.xpm"

///////////////////////////////////////////////////////////////////////////

fbRgCreateName::fbRgCreateName( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Type:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer7->Add( m_staticText1, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_choiceTypeChoices;
	m_choiceType = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceTypeChoices, 0 );
	m_choiceType->SetSelection( 0 );
	fgSizer7->Add( m_choiceType, 0, wxALL, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Given Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer7->Add( m_staticText2, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlGiven = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 250,-1 ), 0 );
	fgSizer7->Add( m_textCtrlGiven, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, _("Surname:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer7->Add( m_staticText3, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlSurname = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 250,-1 ), 0 );
	fgSizer7->Add( m_textCtrlSurname, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer1->Add( fgSizer7, 0, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline1, 0, wxALL|wxEXPAND, 0 );
	
	wxBoxSizer* bSizerDismiss;
	bSizerDismiss = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticNameID = new wxStaticText( this, wxID_ANY, _("N0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticNameID->Wrap( -1 );
	m_staticNameID->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxT("Times New Roman") ) );
	
	bSizerDismiss->Add( m_staticNameID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDismiss->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonSave = new wxButton( this, wxID_OK, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonSave, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonCancel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer1->Add( bSizerDismiss, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
}

fbRgCreateName::~fbRgCreateName()
{
}

fbRgEditContact::fbRgEditContact( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer11->AddGrowableCol( 1 );
	fgSizer11->AddGrowableRow( 1 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, _("Type:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer11->Add( m_staticText3, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );
	
	wxArrayString m_choiceTypeChoices;
	m_choiceType = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceTypeChoices, 0 );
	m_choiceType->SetSelection( 2 );
	fgSizer11->Add( m_choiceType, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Value:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer11->Add( m_staticText4, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	m_textCtrlValue = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 250,80 ), wxTE_MULTILINE );
	fgSizer11->Add( m_textCtrlValue, 1, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	bSizer42->Add( fgSizer11, 1, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer42->Add( m_staticline1, 0, wxEXPAND|wxALL, 0 );
	
	wxBoxSizer* bSizerDismiss;
	bSizerDismiss = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticContactID = new wxStaticText( this, wxID_ANY, _("C0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticContactID->Wrap( -1 );
	m_staticContactID->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxT("Times New Roman") ) );
	
	bSizerDismiss->Add( m_staticContactID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDismiss->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonSave1 = new wxButton( this, wxID_OK, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonSave1, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_buttonCancel1 = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonCancel1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer42->Add( bSizerDismiss, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer42 );
	this->Layout();
	bSizer42->Fit( this );
}

fbRgEditContact::~fbRgEditContact()
{
}

fbRgEditDate::fbRgEditDate( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Output:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer11->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_staticOutput = new wxStaticText( this, wxID_ANY, _("Date String"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticOutput->Wrap( -1 );
	m_staticOutput->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	fgSizer11->Add( m_staticOutput, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Calendar:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer11->Add( m_staticText2, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_choiceDisplayChoices[] = { _("Unstated"), _("Julian Day Number"), _("Julian"), _("Gregorian"), _("French Revolutionary") };
	int m_choiceDisplayNChoices = sizeof( m_choiceDisplayChoices ) / sizeof( wxString );
	m_choiceDisplay = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceDisplayNChoices, m_choiceDisplayChoices, 0 );
	m_choiceDisplay->SetSelection( 3 );
	fgSizer11->Add( m_choiceDisplay, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, _("Precision:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer11->Add( m_staticText3, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_choiceTypeChoices[] = { _("After"), _("On"), _("On or after"), _("Before"), _("Not"), _("On or before"), _("About") };
	int m_choiceTypeNChoices = sizeof( m_choiceTypeChoices ) / sizeof( wxString );
	m_choiceType = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceTypeNChoices, m_choiceTypeChoices, 0 );
	m_choiceType->SetSelection( 1 );
	fgSizer11->Add( m_choiceType, 0, wxALL, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Input Date:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer11->Add( m_staticText4, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDate = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 250,-1 ), 0 );
	fgSizer11->Add( m_textCtrlDate, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, _("Calendar:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	fgSizer11->Add( m_staticText5, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_choiceInputChoices[] = { _("Unstated"), _("Julian Day Number"), _("Julian"), _("Gregorian"), _("French Revolutionary") };
	int m_choiceInputNChoices = sizeof( m_choiceInputChoices ) / sizeof( wxString );
	m_choiceInput = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceInputNChoices, m_choiceInputChoices, 0 );
	m_choiceInput->SetSelection( 3 );
	fgSizer11->Add( m_choiceInput, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer1->Add( fgSizer11, 0, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline1, 0, wxEXPAND | wxALL, 0 );
	
	wxBoxSizer* bSizerDismiss;
	bSizerDismiss = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticDateID = new wxStaticText( this, wxID_ANY, _("R0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticDateID->Wrap( -1 );
	m_staticDateID->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxT("Times New Roman") ) );
	
	bSizerDismiss->Add( m_staticDateID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDismiss->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonSave = new wxButton( this, wxID_OK, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonSave, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonCancel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer1->Add( bSizerDismiss, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_IDLE, wxIdleEventHandler( fbRgEditDate::OnIdle ) );
}

fbRgEditDate::~fbRgEditDate()
{
	// Disconnect Events
	this->Disconnect( wxEVT_IDLE, wxIdleEventHandler( fbRgEditDate::OnIdle ) );
	
}

fbRgEditEvent::fbRgEditEvent( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_splitter1 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3DSASH|wxSP_LIVE_UPDATE|wxSP_NO_XP_THEME );
	m_splitter1->Connect( wxEVT_IDLE, wxIdleEventHandler( fbRgEditEvent::m_splitter1OnIdle ), NULL, this );
	m_splitter1->SetMinimumPaneSize( 1 );
	
	m_panel1 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer10;
	fgSizer10 = new wxFlexGridSizer( 6, 2, 0, 0 );
	fgSizer10->AddGrowableCol( 1 );
	fgSizer10->AddGrowableRow( 5 );
	fgSizer10->SetFlexibleDirection( wxBOTH );
	fgSizer10->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_ALL );
	
	m_staticText1 = new wxStaticText( m_panel1, wxID_ANY, _("Event Type:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer10->Add( m_staticText1, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticType = new wxStaticText( m_panel1, wxID_ANY, _("Birth"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticType->Wrap( -1 );
	m_staticType->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	fgSizer10->Add( m_staticType, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText2 = new wxStaticText( m_panel1, wxID_ANY, _("Title:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer10->Add( m_staticText2, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlTitle = new wxTextCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer10->Add( m_textCtrlTitle, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_buttonDate1 = new wxButton( m_panel1, wxID_ANY, _("Date:"), wxDefaultPosition, wxDefaultSize, wxBU_RIGHT );
	fgSizer10->Add( m_buttonDate1, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDate1 = new wxTextCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer10->Add( m_textCtrlDate1, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_buttonDate2 = new wxButton( m_panel1, wxID_ANY, _("End Date:"), wxDefaultPosition, wxDefaultSize, wxBU_RIGHT );
	fgSizer10->Add( m_buttonDate2, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlDate2 = new wxTextCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer10->Add( m_textCtrlDate2, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_buttonPlace = new wxButton( m_panel1, wxID_ANY, _("Place:"), wxDefaultPosition, wxDefaultSize, wxBU_RIGHT );
	fgSizer10->Add( m_buttonPlace, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlPlace = new wxTextCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer10->Add( m_textCtrlPlace, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_staticText6 = new wxStaticText( m_panel1, wxID_ANY, _("Note:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer10->Add( m_staticText6, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	m_textCtrlNote = new wxTextCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,100 ), wxTE_MULTILINE );
	fgSizer10->Add( m_textCtrlNote, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	m_panel1->SetSizer( fgSizer10 );
	m_panel1->Layout();
	fgSizer10->Fit( m_panel1 );
	m_panel2 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );
	
	m_listPersona = new wxListCtrl( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	m_listPersona->SetMinSize( wxSize( 400,100 ) );
	
	bSizer21->Add( m_listPersona, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer211;
	bSizer211 = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonAdd = new wxButton( m_panel2, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer211->Add( m_buttonAdd, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonEdit = new wxButton( m_panel2, wxID_ANY, _("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer211->Add( m_buttonEdit, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_buttonDelete = new wxButton( m_panel2, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer211->Add( m_buttonDelete, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer21->Add( bSizer211, 0, wxEXPAND, 5 );
	
	
	m_panel2->SetSizer( bSizer21 );
	m_panel2->Layout();
	bSizer21->Fit( m_panel2 );
	m_splitter1->SplitHorizontally( m_panel1, m_panel2, 0 );
	bSizer1->Add( m_splitter1, 1, wxEXPAND, 5 );
	
	m_staticline12 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline12, 0, wxEXPAND | wxALL, 0 );
	
	wxBoxSizer* bSizerDismiss;
	bSizerDismiss = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticEventID = new wxStaticText( this, wxID_ANY, _("E0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticEventID->Wrap( -1 );
	m_staticEventID->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxT("Times New Roman") ) );
	
	bSizerDismiss->Add( m_staticEventID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDismiss->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonSave = new wxButton( this, wxID_OK, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonSave, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonCancel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer1->Add( bSizerDismiss, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_buttonDate1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditEvent::OnDate1Button ), NULL, this );
	m_buttonDate2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditEvent::OnDate2Button ), NULL, this );
	m_buttonPlace->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditEvent::OnPlaceButton ), NULL, this );
	m_buttonAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditEvent::OnAddButton ), NULL, this );
	m_buttonEdit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditEvent::OnEditButton ), NULL, this );
	m_buttonDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditEvent::OnDeleteButton ), NULL, this );
}

fbRgEditEvent::~fbRgEditEvent()
{
	// Disconnect Events
	m_buttonDate1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditEvent::OnDate1Button ), NULL, this );
	m_buttonDate2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditEvent::OnDate2Button ), NULL, this );
	m_buttonPlace->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditEvent::OnPlaceButton ), NULL, this );
	m_buttonAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditEvent::OnAddButton ), NULL, this );
	m_buttonEdit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditEvent::OnEditButton ), NULL, this );
	m_buttonDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditEvent::OnDeleteButton ), NULL, this );
	
}

fbRgEditEventType::fbRgEditEventType( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer11->AddGrowableCol( 1 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Group:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText4->Wrap( -1 );
	fgSizer11->Add( m_staticText4, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	wxArrayString m_choiceGroupChoices;
	m_choiceGroup = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceGroupChoices, 0 );
	m_choiceGroup->SetSelection( 0 );
	fgSizer11->Add( m_choiceGroup, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, _("Name:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText3->Wrap( -1 );
	fgSizer11->Add( m_staticText3, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );
	
	m_textCtrlValue = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlValue->SetMaxLength( 0 ); 
	fgSizer11->Add( m_textCtrlValue, 1, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	bSizer1->Add( fgSizer11, 0, wxEXPAND, 5 );
	
	m_listRole = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxSize( 300,150 ), wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL );
	bSizer1->Add( m_listRole, 1, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonRoleAdd = new wxButton( this, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_buttonRoleAdd, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonRoleEdit = new wxButton( this, wxID_ANY, _("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_buttonRoleEdit, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonRoleDelete = new wxButton( this, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_buttonRoleDelete, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer1->Add( bSizer16, 0, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline1, 0, wxEXPAND|wxALL, 0 );
	
	wxBoxSizer* bSizerDismiss;
	bSizerDismiss = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTypeID = new wxStaticText( this, wxID_ANY, _("ET0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTypeID->Wrap( -1 );
	m_staticTypeID->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxT("Times New Roman") ) );
	
	bSizerDismiss->Add( m_staticTypeID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDismiss->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonSave = new wxButton( this, wxID_OK, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonSave, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonCancel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer1->Add( bSizerDismiss, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	// Connect Events
	m_buttonRoleAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditEventType::OnButtonRoleAdd ), NULL, this );
	m_buttonRoleEdit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditEventType::OnButtonRoleEdit ), NULL, this );
	m_buttonRoleDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditEventType::OnButtonRoleDelete ), NULL, this );
}

fbRgEditEventType::~fbRgEditEventType()
{
	// Disconnect Events
	m_buttonRoleAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditEventType::OnButtonRoleAdd ), NULL, this );
	m_buttonRoleEdit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditEventType::OnButtonRoleEdit ), NULL, this );
	m_buttonRoleDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditEventType::OnButtonRoleDelete ), NULL, this );
	
}

fbRgEditName::fbRgEditName( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer11->Add( m_staticText1, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticName = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticName->Wrap( -1 );
	m_staticName->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	fgSizer11->Add( m_staticName, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Type:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer11->Add( m_staticText2, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_choiceTypeChoices;
	m_choiceType = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceTypeChoices, 0 );
	m_choiceType->SetSelection( 0 );
	fgSizer11->Add( m_choiceType, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer1->Add( fgSizer11, 0, 0, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	m_listNamePart = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	m_listNamePart->SetMinSize( wxSize( 300,150 ) );
	
	bSizer12->Add( m_listNamePart, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxVERTICAL );
	
	m_buttonPartAdd = new wxButton( this, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer37->Add( m_buttonPartAdd, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_buttonPartEdit = new wxButton( this, wxID_ANY, _("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer37->Add( m_buttonPartEdit, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_buttonPartDel = new wxButton( this, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer37->Add( m_buttonPartDel, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonPartUp = new wxButton( this, wxID_ANY, _("Up"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonPartUp->SetMinSize( wxSize( 35,-1 ) );
	
	bSizer38->Add( m_buttonPartUp, 1, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_buttonPartDown = new wxButton( this, wxID_ANY, _("Down"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonPartDown->SetMinSize( wxSize( 35,-1 ) );
	
	bSizer38->Add( m_buttonPartDown, 1, wxBOTTOM|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer37->Add( bSizer38, 0, wxEXPAND, 5 );
	
	
	bSizer12->Add( bSizer37, 0, wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer12, 1, wxEXPAND, 5 );
	
	m_staticline12 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline12, 0, wxEXPAND | wxALL, 0 );
	
	wxBoxSizer* bSizerDismiss;
	bSizerDismiss = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticNameID = new wxStaticText( this, wxID_ANY, _("N0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticNameID->Wrap( -1 );
	m_staticNameID->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxT("Times New Roman") ) );
	
	bSizerDismiss->Add( m_staticNameID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDismiss->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonSave = new wxButton( this, wxID_OK, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonSave, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonCancel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer1->Add( bSizerDismiss, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_buttonPartAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditName::OnPartAddButton ), NULL, this );
	m_buttonPartEdit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditName::OnPartEditButton ), NULL, this );
	m_buttonPartDel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditName::OnPartDeleteButton ), NULL, this );
	m_buttonPartUp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditName::OnPartUpButton ), NULL, this );
	m_buttonPartDown->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditName::OnPartDownButton ), NULL, this );
}

fbRgEditName::~fbRgEditName()
{
	// Disconnect Events
	m_buttonPartAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditName::OnPartAddButton ), NULL, this );
	m_buttonPartEdit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditName::OnPartEditButton ), NULL, this );
	m_buttonPartDel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditName::OnPartDeleteButton ), NULL, this );
	m_buttonPartUp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditName::OnPartUpButton ), NULL, this );
	m_buttonPartDown->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditName::OnPartDownButton ), NULL, this );
	
}

fbRgEditNamePart::fbRgEditNamePart( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Type:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer7->Add( m_staticText1, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_choiceTypeChoices;
	m_choiceType = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceTypeChoices, 0 );
	m_choiceType->SetSelection( 0 );
	fgSizer7->Add( m_choiceType, 0, wxALL, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Value:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer7->Add( m_staticText2, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlValue = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 250,-1 ), 0 );
	fgSizer7->Add( m_textCtrlValue, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer1->Add( fgSizer7, 0, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline1, 0, wxALL|wxEXPAND, 0 );
	
	wxBoxSizer* bSizerDismiss;
	bSizerDismiss = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticNamePartID = new wxStaticText( this, wxID_ANY, _("NP0:N0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticNamePartID->Wrap( -1 );
	m_staticNamePartID->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxT("Times New Roman") ) );
	
	bSizerDismiss->Add( m_staticNamePartID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDismiss->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonSave = new wxButton( this, wxID_OK, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonSave, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonCancel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer1->Add( bSizerDismiss, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
}

fbRgEditNamePart::~fbRgEditNamePart()
{
}

fbRgEditPlace::fbRgEditPlace( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Place:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer11->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlAddr = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 250,-1 ), 0 );
	m_textCtrlAddr->SetMaxLength( 0 ); 
	bSizer11->Add( m_textCtrlAddr, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer1->Add( bSizer11, 1, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline1, 0, wxEXPAND | wxALL, 0 );
	
	wxBoxSizer* bSizerDismiss;
	bSizerDismiss = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticPlaceID = new wxStaticText( this, wxID_ANY, _("P0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticPlaceID->Wrap( -1 );
	m_staticPlaceID->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxT("Times New Roman") ) );
	
	bSizerDismiss->Add( m_staticPlaceID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDismiss->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonSave = new wxButton( this, wxID_OK, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonSave, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonCancel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer1->Add( bSizerDismiss, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
}

fbRgEditPlace::~fbRgEditPlace()
{
}

fbRgEditReference::fbRgEditReference( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer49;
	bSizer49 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText401 = new wxStaticText( this, wxID_ANY, _("Title:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText401->Wrap( -1 );
	bSizer51->Add( m_staticText401, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlTitle = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlTitle->SetMaxLength( 0 ); 
	bSizer51->Add( m_textCtrlTitle, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer49->Add( bSizer51, 0, wxEXPAND, 5 );
	
	m_splitter1 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_3DSASH|wxSP_NO_XP_THEME );
	m_splitter1->SetSashGravity( 0.75 );
	m_splitter1->Connect( wxEVT_IDLE, wxIdleEventHandler( fbRgEditReference::m_splitter1OnIdle ), NULL, this );
	
	m_panel7 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxVERTICAL );
	
	m_notebookTop = new wxNotebook( m_panel7, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_BOTTOM );
	m_panelSource = new wxPanel( m_notebookTop, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxVERTICAL );
	
	m_toolBar1 = new wxToolBar( m_panelSource, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL ); 
	m_toolBar1->AddTool( tfpID_EDREF_OnCut, _("Cut"), wxBitmap( cut_xpm ), wxNullBitmap, wxITEM_NORMAL, _("Cut"), wxEmptyString, NULL ); 
	
	m_toolBar1->AddTool( tfpID_EDREF_OnCopy, _("Copy"), wxBitmap( copy_xpm ), wxNullBitmap, wxITEM_NORMAL, _("Copy"), wxEmptyString, NULL ); 
	
	m_toolBar1->AddTool( tfpID_EDREF_OnPaste, _("Paste"), wxBitmap( paste_xpm ), wxNullBitmap, wxITEM_NORMAL, _("Paste"), wxEmptyString, NULL ); 
	
	m_toolBar1->AddSeparator(); 
	
	m_toolBar1->AddTool( tfpID_EDREF_OnUndo, _("Undo"), wxBitmap( undo_xpm ), wxNullBitmap, wxITEM_NORMAL, _("Undo"), wxEmptyString, NULL ); 
	
	m_toolBar1->AddTool( tfpID_EDREF_OnRedo, _("Redo"), wxBitmap( redo_xpm ), wxNullBitmap, wxITEM_NORMAL, _("Redo"), wxEmptyString, NULL ); 
	
	m_toolBar1->Realize(); 
	
	bSizer53->Add( m_toolBar1, 0, wxEXPAND, 5 );
	
	m_textCtrlStatement = new wxTextCtrl( m_panelSource, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 600,150 ), wxTE_DONTWRAP|wxTE_MULTILINE|wxHSCROLL );
	m_textCtrlStatement->SetMaxLength( 0 ); 
	m_textCtrlStatement->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 76, 90, 90, false, wxEmptyString ) );
	
	bSizer53->Add( m_textCtrlStatement, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panelSource->SetSizer( bSizer53 );
	m_panelSource->Layout();
	bSizer53->Fit( m_panelSource );
	m_notebookTop->AddPage( m_panelSource, _("Source"), true );
	m_panelView = new wxPanel( m_notebookTop, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxVERTICAL );
	
	m_webview = wxWebView::New(m_panelView, wxID_ANY);
	bSizer54->Add( m_webview, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panelView->SetSizer( bSizer54 );
	m_panelView->Layout();
	bSizer54->Fit( m_panelView );
	m_notebookTop->AddPage( m_panelView, _("View"), false );
	
	bSizer52->Add( m_notebookTop, 1, wxEXPAND|wxALL, 5 );
	
	
	m_panel7->SetSizer( bSizer52 );
	m_panel7->Layout();
	bSizer52->Fit( m_panel7 );
	m_panel11 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxVERTICAL );
	
	m_notebookBottom = new wxNotebook( m_panel11, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panelPersona = new wxPanel( m_notebookBottom, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxHORIZONTAL );
	
	m_listPersona = new wxListCtrl( m_panelPersona, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	bSizer56->Add( m_listPersona, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer( wxVERTICAL );
	
	m_buttonPersonaAdd = new wxButton( m_panelPersona, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer57->Add( m_buttonPersonaAdd, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_buttonPersonaEdit = new wxButton( m_panelPersona, wxID_ANY, _("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer57->Add( m_buttonPersonaEdit, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_buttonPersonaDel = new wxButton( m_panelPersona, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer57->Add( m_buttonPersonaDel, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizer56->Add( bSizer57, 0, wxEXPAND, 5 );
	
	
	m_panelPersona->SetSizer( bSizer56 );
	m_panelPersona->Layout();
	bSizer56->Fit( m_panelPersona );
	m_notebookBottom->AddPage( m_panelPersona, _("Persona"), false );
	m_panelEntities = new wxPanel( m_notebookBottom, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer58;
	bSizer58 = new wxBoxSizer( wxHORIZONTAL );
	
	m_listEntities = new wxListCtrl( m_panelEntities, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	m_listEntities->SetMinSize( wxSize( -1,150 ) );
	
	bSizer58->Add( m_listEntities, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxVERTICAL );
	
	m_buttonAdd = new wxButton( m_panelEntities, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer59->Add( m_buttonAdd, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_buttonEdit = new wxButton( m_panelEntities, wxID_ANY, _("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer59->Add( m_buttonEdit, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_buttonDel = new wxButton( m_panelEntities, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer59->Add( m_buttonDel, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer60;
	bSizer60 = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonUp = new wxButton( m_panelEntities, wxID_ANY, _("Up"), wxDefaultPosition, wxSize( 35,-1 ), 0 );
	bSizer60->Add( m_buttonUp, 0, wxBOTTOM|wxLEFT, 5 );
	
	
	bSizer60->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonDn = new wxButton( m_panelEntities, wxID_ANY, _("Down"), wxDefaultPosition, wxSize( 35,-1 ), 0 );
	bSizer60->Add( m_buttonDn, 0, wxBOTTOM|wxRIGHT, 5 );
	
	
	bSizer59->Add( bSizer60, 1, wxEXPAND, 5 );
	
	
	bSizer58->Add( bSizer59, 0, wxEXPAND, 5 );
	
	
	m_panelEntities->SetSizer( bSizer58 );
	m_panelEntities->Layout();
	bSizer58->Fit( m_panelEntities );
	m_notebookBottom->AddPage( m_panelEntities, _("Entities"), true );
	
	bSizer55->Add( m_notebookBottom, 1, wxEXPAND|wxALL, 5 );
	
	
	m_panel11->SetSizer( bSizer55 );
	m_panel11->Layout();
	bSizer55->Fit( m_panel11 );
	m_splitter1->SplitHorizontally( m_panel7, m_panel11, 265 );
	bSizer49->Add( m_splitter1, 1, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer49->Add( m_staticline1, 0, wxEXPAND|wxALL, 0 );
	
	wxBoxSizer* bSizerDismiss;
	bSizerDismiss = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticRefID = new wxStaticText( this, wxID_ANY, _("R0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticRefID->Wrap( -1 );
	m_staticRefID->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxT("Times New Roman") ) );
	
	bSizerDismiss->Add( m_staticRefID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDismiss->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonSave1 = new wxButton( this, wxID_OK, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonSave1, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_buttonCancel1 = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonCancel1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer49->Add( bSizerDismiss, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer49 );
	this->Layout();
	bSizer49->Fit( this );
	
	// Connect Events
	m_notebookTop->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING, wxNotebookEventHandler( fbRgEditReference::OnStatementViewChanging ), NULL, this );
	this->Connect( tfpID_EDREF_OnCut, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( fbRgEditReference::OnTool ) );
	this->Connect( tfpID_EDREF_OnCopy, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( fbRgEditReference::OnTool ) );
	this->Connect( tfpID_EDREF_OnPaste, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( fbRgEditReference::OnTool ) );
	this->Connect( tfpID_EDREF_OnUndo, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( fbRgEditReference::OnTool ) );
	this->Connect( tfpID_EDREF_OnRedo, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( fbRgEditReference::OnTool ) );
	m_buttonPersonaAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditReference::OnPersonaAddButton ), NULL, this );
	m_buttonPersonaEdit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditReference::OnPersonaEditButton ), NULL, this );
	m_buttonPersonaDel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditReference::OnPersonaDeleteButton ), NULL, this );
	m_buttonAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditReference::OnAddEntityButton ), NULL, this );
	m_buttonEdit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditReference::OnEditEntityButton ), NULL, this );
	m_buttonDel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditReference::OnDeleteEntityButton ), NULL, this );
	m_buttonUp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditReference::OnUpEntityButton ), NULL, this );
	m_buttonDn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditReference::OnDownEntityButton ), NULL, this );
}

fbRgEditReference::~fbRgEditReference()
{
	// Disconnect Events
	m_notebookTop->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING, wxNotebookEventHandler( fbRgEditReference::OnStatementViewChanging ), NULL, this );
	this->Disconnect( tfpID_EDREF_OnCut, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( fbRgEditReference::OnTool ) );
	this->Disconnect( tfpID_EDREF_OnCopy, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( fbRgEditReference::OnTool ) );
	this->Disconnect( tfpID_EDREF_OnPaste, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( fbRgEditReference::OnTool ) );
	this->Disconnect( tfpID_EDREF_OnUndo, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( fbRgEditReference::OnTool ) );
	this->Disconnect( tfpID_EDREF_OnRedo, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( fbRgEditReference::OnTool ) );
	m_buttonPersonaAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditReference::OnPersonaAddButton ), NULL, this );
	m_buttonPersonaEdit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditReference::OnPersonaEditButton ), NULL, this );
	m_buttonPersonaDel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditReference::OnPersonaDeleteButton ), NULL, this );
	m_buttonAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditReference::OnAddEntityButton ), NULL, this );
	m_buttonEdit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditReference::OnEditEntityButton ), NULL, this );
	m_buttonDel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditReference::OnDeleteEntityButton ), NULL, this );
	m_buttonUp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditReference::OnUpEntityButton ), NULL, this );
	m_buttonDn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditReference::OnDownEntityButton ), NULL, this );
	
}

fbRgEditRelationship::fbRgEditRelationship( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer13;
	fgSizer13 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer13->AddGrowableCol( 1 );
	fgSizer13->AddGrowableRow( 1 );
	fgSizer13->SetFlexibleDirection( wxBOTH );
	fgSizer13->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_buttonPerson1 = new wxButton( this, wxID_ANY, _("Persona:"), wxDefaultPosition, wxDefaultSize, wxBU_RIGHT );
	fgSizer13->Add( m_buttonPerson1, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlPersona1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), wxTE_READONLY );
	m_textCtrlPersona1->SetMaxLength( 0 ); 
	m_textCtrlPersona1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer13->Add( m_textCtrlPersona1, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_staticText75 = new wxStaticText( this, wxID_ANY, _("Is the:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText75->Wrap( -1 );
	fgSizer13->Add( m_staticText75, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	m_textCtrlDescrip = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,50 ), wxTE_MULTILINE|wxTE_WORDWRAP );
	fgSizer13->Add( m_textCtrlDescrip, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_buttonPersona2 = new wxButton( this, wxID_ANY, _("Of:"), wxDefaultPosition, wxDefaultSize, wxBU_RIGHT );
	fgSizer13->Add( m_buttonPersona2, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textCtrlPersona2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textCtrlPersona2->SetMaxLength( 0 ); 
	m_textCtrlPersona2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer13->Add( m_textCtrlPersona2, 1, wxALIGN_CENTER_VERTICAL|wxEXPAND|wxALL, 5 );
	
	
	bSizer1->Add( fgSizer13, 1, wxEXPAND, 5 );
	
	m_staticline18 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline18, 0, wxALL|wxEXPAND, 0 );
	
	wxBoxSizer* bSizerDismiss;
	bSizerDismiss = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticRsNumber = new wxStaticText( this, wxID_ANY, _("Rs0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticRsNumber->Wrap( -1 );
	m_staticRsNumber->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxT("Times New Roman") ) );
	
	bSizerDismiss->Add( m_staticRsNumber, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDismiss->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonSave = new wxButton( this, wxID_OK, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonSave, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonCancel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer1->Add( bSizerDismiss, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	// Connect Events
	m_buttonPerson1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditRelationship::OnPersona1Button ), NULL, this );
	m_buttonPersona2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditRelationship::OnPersona2Button ), NULL, this );
}

fbRgEditRelationship::~fbRgEditRelationship()
{
	// Disconnect Events
	m_buttonPerson1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditRelationship::OnPersona1Button ), NULL, this );
	m_buttonPersona2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditRelationship::OnPersona2Button ), NULL, this );
	
}

fbRgEditRelativeDate::fbRgEditRelativeDate( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Output:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer11->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_staticOutput = new wxStaticText( this, wxID_ANY, _("Date String"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticOutput->Wrap( -1 );
	m_staticOutput->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	fgSizer11->Add( m_staticOutput, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Output calendar:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer11->Add( m_staticText2, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_choiceDisplayChoices[] = { _("Unstated"), _("Julian Day Number"), _("Julian"), _("Gregorian"), _("French Revolutionary") };
	int m_choiceDisplayNChoices = sizeof( m_choiceDisplayChoices ) / sizeof( wxString );
	m_choiceDisplay = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceDisplayNChoices, m_choiceDisplayChoices, 0 );
	m_choiceDisplay->SetSelection( 3 );
	fgSizer11->Add( m_choiceDisplay, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, _("Calculation:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer11->Add( m_staticText3, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_choiceCalcChoices[] = { _("Age, round down"), _("Duration"), _("Add to start"), _("Add to end") };
	int m_choiceCalcNChoices = sizeof( m_choiceCalcChoices ) / sizeof( wxString );
	m_choiceCalc = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceCalcNChoices, m_choiceCalcChoices, 0 );
	m_choiceCalc->SetSelection( 0 );
	fgSizer11->Add( m_choiceCalc, 0, wxALL, 5 );
	
	m_buttonBase = new wxButton( this, wxID_ANY, _("Base Date:"), wxDefaultPosition, wxDefaultSize, wxBU_RIGHT );
	fgSizer11->Add( m_buttonBase, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlBase = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 250,-1 ), wxTE_READONLY );
	m_textCtrlBase->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer11->Add( m_textCtrlBase, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText3a = new wxStaticText( this, wxID_ANY, _("Precision:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3a->Wrap( -1 );
	fgSizer11->Add( m_staticText3a, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_choicePrecisionChoices[] = { _("After"), _("On"), _("On or after"), _("Before"), _("Not"), _("On or before"), _("About") };
	int m_choicePrecisionNChoices = sizeof( m_choicePrecisionChoices ) / sizeof( wxString );
	m_choicePrecision = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choicePrecisionNChoices, m_choicePrecisionChoices, 0 );
	m_choicePrecision->SetSelection( 1 );
	fgSizer11->Add( m_choicePrecision, 0, wxALL, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Value:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer11->Add( m_staticText4, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlAge = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer11->Add( m_textCtrlAge, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, _("Calendar:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	fgSizer11->Add( m_staticText5, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_choiceInputChoices[] = { _("Unstated"), _("Julian Day Number"), _("Julian"), _("Gregorian"), _("French Revolutionary") };
	int m_choiceInputNChoices = sizeof( m_choiceInputChoices ) / sizeof( wxString );
	m_choiceInput = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceInputNChoices, m_choiceInputChoices, 0 );
	m_choiceInput->SetSelection( 3 );
	fgSizer11->Add( m_choiceInput, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer1->Add( fgSizer11, 0, wxEXPAND, 5 );
	
	wxString m_radioUnitsChoices[] = { _("Years"), _("Months"), _("Weeks"), _("Days") };
	int m_radioUnitsNChoices = sizeof( m_radioUnitsChoices ) / sizeof( wxString );
	m_radioUnits = new wxRadioBox( this, wxID_ANY, _("Unit:"), wxDefaultPosition, wxDefaultSize, m_radioUnitsNChoices, m_radioUnitsChoices, 1, wxRA_SPECIFY_ROWS );
	m_radioUnits->SetSelection( 0 );
	bSizer1->Add( m_radioUnits, 0, wxALL, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline1, 0, wxEXPAND | wxALL, 0 );
	
	wxBoxSizer* bSizerDismiss;
	bSizerDismiss = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticDateID = new wxStaticText( this, wxID_ANY, _("R0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticDateID->Wrap( -1 );
	m_staticDateID->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxT("Times New Roman") ) );
	
	bSizerDismiss->Add( m_staticDateID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDismiss->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonSave = new wxButton( this, wxID_OK, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonSave, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonCancel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer1->Add( bSizerDismiss, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_IDLE, wxIdleEventHandler( fbRgEditRelativeDate::OnIdle ) );
	m_buttonBase->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditRelativeDate::OnBaseButton ), NULL, this );
}

fbRgEditRelativeDate::~fbRgEditRelativeDate()
{
	// Disconnect Events
	this->Disconnect( wxEVT_IDLE, wxIdleEventHandler( fbRgEditRelativeDate::OnIdle ) );
	m_buttonBase->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditRelativeDate::OnBaseButton ), NULL, this );
	
}

fbRgEditResearcher::fbRgEditResearcher( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer12->AddGrowableCol( 1 );
	fgSizer12->AddGrowableRow( 1 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText64 = new wxStaticText( this, wxID_ANY, _("Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText64->Wrap( -1 );
	fgSizer12->Add( m_staticText64, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer12->Add( m_textCtrlName, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_staticText65 = new wxStaticText( this, wxID_ANY, _("Comment:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText65->Wrap( -1 );
	fgSizer12->Add( m_staticText65, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	m_textCtrlComment = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_WORDWRAP );
	fgSizer12->Add( m_textCtrlComment, 1, wxALL|wxEXPAND, 5 );
	
	m_buttonInd = new wxButton( this, wxID_ANY, _("Individual:"), wxDefaultPosition, wxDefaultSize, wxBU_RIGHT );
	fgSizer12->Add( m_buttonInd, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticIndName = new wxStaticText( this, wxID_ANY, _("Individual"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticIndName->Wrap( -1 );
	m_staticIndName->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizer54->Add( m_staticIndName, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer54->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticIndID = new wxStaticText( this, wxID_ANY, _("I0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticIndID->Wrap( -1 );
	m_staticIndID->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxT("Times New Roman") ) );
	
	bSizer54->Add( m_staticIndID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer12->Add( bSizer54, 1, wxEXPAND, 5 );
	
	
	bSizer48->Add( fgSizer12, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer49;
	bSizer49 = new wxBoxSizer( wxHORIZONTAL );
	
	m_listContacts = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxSize( 300,125 ), wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	bSizer49->Add( m_listContacts, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer50;
	bSizer50 = new wxBoxSizer( wxVERTICAL );
	
	m_buttonAdd = new wxButton( this, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer50->Add( m_buttonAdd, 0, wxALL, 5 );
	
	m_buttonEdit = new wxButton( this, wxID_ANY, _("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer50->Add( m_buttonEdit, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_buttonDelete = new wxButton( this, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer50->Add( m_buttonDelete, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer49->Add( bSizer50, 0, wxEXPAND, 5 );
	
	
	bSizer48->Add( bSizer49, 1, wxEXPAND, 5 );
	
	m_staticline14 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer48->Add( m_staticline14, 0, wxEXPAND | wxALL, 0 );
	
	wxBoxSizer* bSizerDismiss;
	bSizerDismiss = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticResID = new wxStaticText( this, wxID_ANY, _("Re0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticResID->Wrap( -1 );
	m_staticResID->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxT("Times New Roman") ) );
	
	bSizerDismiss->Add( m_staticResID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_checkBoxUser = new wxCheckBox( this, wxID_ANY, _("User"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_checkBoxUser, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticUserID = new wxStaticText( this, wxID_ANY, _("U0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticUserID->Wrap( -1 );
	m_staticUserID->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxT("Times New Roman") ) );
	
	bSizerDismiss->Add( m_staticUserID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDismiss->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonSave1 = new wxButton( this, wxID_OK, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonSave1, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_buttonCancel1 = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonCancel1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer48->Add( bSizerDismiss, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer48 );
	this->Layout();
	bSizer48->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_buttonInd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditResearcher::OnButtonInd ), NULL, this );
	m_buttonAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditResearcher::OnButtonAdd ), NULL, this );
	m_buttonEdit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditResearcher::OnButtonEdit ), NULL, this );
	m_buttonDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditResearcher::OnButtonDelete ), NULL, this );
}

fbRgEditResearcher::~fbRgEditResearcher()
{
	// Disconnect Events
	m_buttonInd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditResearcher::OnButtonInd ), NULL, this );
	m_buttonAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditResearcher::OnButtonAdd ), NULL, this );
	m_buttonEdit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditResearcher::OnButtonEdit ), NULL, this );
	m_buttonDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgEditResearcher::OnButtonDelete ), NULL, this );
	
}

fbRgEditRole::fbRgEditRole( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer11->AddGrowableCol( 1 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Event:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	m_staticText1->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	fgSizer11->Add( m_staticText1, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 5 );
	
	wxBoxSizer* bSizer111;
	bSizer111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticEventType = new wxStaticText( this, wxID_ANY, _("Event Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticEventType->Wrap( -1 );
	m_staticEventType->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 90, 92, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer111->Add( m_staticEventType, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	
	bSizer111->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticEventTypeID = new wxStaticText( this, wxID_ANY, _("ET0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticEventTypeID->Wrap( -1 );
	m_staticEventTypeID->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxT("Times New Roman") ) );
	
	bSizer111->Add( m_staticEventTypeID, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	
	fgSizer11->Add( bSizer111, 1, wxEXPAND, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Group:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	fgSizer11->Add( m_staticText2, 0, wxALL, 5 );
	
	m_staticTypeGroup = new wxStaticText( this, wxID_ANY, _("Type Group"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTypeGroup->Wrap( -1 );
	m_staticTypeGroup->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 90, 92, false, wxT("MS Shell Dlg 2") ) );
	
	fgSizer11->Add( m_staticTypeGroup, 0, wxALL, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, _("Role:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText3->Wrap( -1 );
	fgSizer11->Add( m_staticText3, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );
	
	m_textCtrlValue = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlValue->SetMaxLength( 0 ); 
	fgSizer11->Add( m_textCtrlValue, 1, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Prime:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText4->Wrap( -1 );
	fgSizer11->Add( m_staticText4, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	wxBoxSizer* bSizer112;
	bSizer112 = new wxBoxSizer( wxHORIZONTAL );
	
	wxArrayString m_choicePrimeChoices;
	m_choicePrime = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choicePrimeChoices, 0 );
	m_choicePrime->SetSelection( 0 );
	bSizer112->Add( m_choicePrime, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_checkOfficial = new wxCheckBox( this, wxID_ANY, _("Official"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer112->Add( m_checkOfficial, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer112->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer11->Add( bSizer112, 1, wxEXPAND, 5 );
	
	
	bSizer1->Add( fgSizer11, 1, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline1, 0, wxEXPAND|wxALL, 0 );
	
	wxBoxSizer* bSizerDismiss;
	bSizerDismiss = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticRoleID = new wxStaticText( this, wxID_ANY, _("R0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticRoleID->Wrap( -1 );
	m_staticRoleID->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxT("Times New Roman") ) );
	
	bSizerDismiss->Add( m_staticRoleID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDismiss->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonSave = new wxButton( this, wxID_OK, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonSave, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonCancel, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer1->Add( bSizerDismiss, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	m_choicePrime->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( fbRgEditRole::OnChoicePrime ), NULL, this );
}

fbRgEditRole::~fbRgEditRole()
{
	// Disconnect Events
	m_choicePrime->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( fbRgEditRole::OnChoicePrime ), NULL, this );
	
}

fbRgPerIndEvent::fbRgPerIndEvent( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer3->AddGrowableCol( 1 );
	fgSizer3->AddGrowableRow( 3 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticPerInd = new wxStaticText( this, wxID_ANY, _("Individual:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticPerInd->Wrap( -1 );
	fgSizer3->Add( m_staticPerInd, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticName = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticName->Wrap( -1 );
	m_staticName->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizer12->Add( m_staticName, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer12->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticNameID = new wxStaticText( this, wxID_ANY, _("I0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticNameID->Wrap( -1 );
	m_staticNameID->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxEmptyString ) );
	
	bSizer12->Add( m_staticNameID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer3->Add( bSizer12, 1, wxEXPAND, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Event:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer3->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticEvent = new wxStaticText( this, wxID_ANY, _("Birth"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticEvent->Wrap( -1 );
	m_staticEvent->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizer13->Add( m_staticEvent, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer13->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticEventID = new wxStaticText( this, wxID_ANY, _("E0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticEventID->Wrap( -1 );
	m_staticEventID->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxEmptyString ) );
	
	bSizer13->Add( m_staticEventID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer3->Add( bSizer13, 1, wxEXPAND, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, _("Role:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer3->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );
	
	wxArrayString m_choiceRoleChoices;
	m_choiceRole = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceRoleChoices, 0 );
	m_choiceRole->SetSelection( 0 );
	bSizer14->Add( m_choiceRole, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer14->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonAdd = new wxButton( this, wxID_ANY, _("Add Role"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_buttonAdd, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer3->Add( bSizer14, 1, wxEXPAND, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Note:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer3->Add( m_staticText4, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	m_textCtrlNote = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_WORDWRAP );
	fgSizer3->Add( m_textCtrlNote, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer11->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer11->Add( m_staticline1, 0, wxEXPAND|wxALL, 0 );
	
	wxBoxSizer* bSizerDismiss;
	bSizerDismiss = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticRoleID = new wxStaticText( this, wxID_ANY, _("IE0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticRoleID->Wrap( -1 );
	m_staticRoleID->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 72, 90, 92, false, wxEmptyString ) );
	
	bSizerDismiss->Add( m_staticRoleID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDismiss->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonSave = new wxButton( this, wxID_OK, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonSave, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonCancel, 0, wxALL, 5 );
	
	
	bSizer11->Add( bSizerDismiss, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer11 );
	this->Layout();
	
	// Connect Events
	m_buttonAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgPerIndEvent::OnAddRoleButton ), NULL, this );
}

fbRgPerIndEvent::~fbRgPerIndEvent()
{
	// Disconnect Events
	m_buttonAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgPerIndEvent::OnAddRoleButton ), NULL, this );
	
}

fbRgSelect::fbRgSelect( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_listCtrl = new rgStrTableCtrl( this, wxID_ANY, wxDefaultPosition, wxSize( -1,300 ), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VIRTUAL|wxLC_VRULES|wxALWAYS_SHOW_SB|wxVSCROLL );
	bSizer2->Add( m_listCtrl, 1, wxEXPAND|wxALL, 5 );
	
	
	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );
	
	m_staticline = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline, 0, wxEXPAND | wxALL, 0 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonCreate = new wxButton( this, wxID_ANY, _("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_buttonCreate, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_buttonFilter = new wxButton( this, wxID_ANY, _("Filter"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_buttonFilter, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_buttonUnknown = new wxButton( this, wxID_ANY, _("Unknown"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_buttonUnknown, 0, wxALL, 5 );
	
	
	bSizer3->Add( 0, 0, 1, wxEXPAND, 10 );
	
	m_buttonSelect = new wxButton( this, wxID_OK, _("Select"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_buttonSelect, 0, wxALL, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_buttonCancel, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	// Connect Events
	this->Connect( wxEVT_IDLE, wxIdleEventHandler( fbRgSelect::OnIdle ) );
	m_buttonCreate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgSelect::OnCreateButton ), NULL, this );
	m_buttonFilter->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgSelect::OnFilterButton ), NULL, this );
	m_buttonUnknown->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgSelect::OnUnknownButton ), NULL, this );
}

fbRgSelect::~fbRgSelect()
{
	// Disconnect Events
	this->Disconnect( wxEVT_IDLE, wxIdleEventHandler( fbRgSelect::OnIdle ) );
	m_buttonCreate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgSelect::OnCreateButton ), NULL, this );
	m_buttonFilter->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgSelect::OnFilterButton ), NULL, this );
	m_buttonUnknown->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgSelect::OnUnknownButton ), NULL, this );
	
}

fbRgSelectIndEvent::fbRgSelectIndEvent( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Event Group") ), wxHORIZONTAL );
	
	wxArrayString m_checkListGrpChoices;
	m_checkListGrp = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxSize( -1,110 ), m_checkListGrpChoices, wxLB_NEEDED_SB );
	sbSizer1->Add( m_checkListGrp, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	m_buttonSelectGrp = new wxButton( this, wxID_ANY, _("Select All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_buttonSelectGrp, 0, wxALL, 5 );
	
	m_buttonClearGrp = new wxButton( this, wxID_ANY, _("Clear All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_buttonClearGrp, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	sbSizer1->Add( bSizer11, 1, wxEXPAND, 5 );
	
	
	bSizer28->Add( sbSizer1, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Date Points") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer13;
	fgSizer13 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer13->AddGrowableCol( 1 );
	fgSizer13->SetFlexibleDirection( wxBOTH );
	fgSizer13->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText37 = new wxStaticText( this, wxID_ANY, _("Dates After:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText37->Wrap( -1 );
	fgSizer13->Add( m_staticText37, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textCtrlBegDatePt = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer13->Add( m_textCtrlBegDatePt, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText38 = new wxStaticText( this, wxID_ANY, _("Dates Before:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText38->Wrap( -1 );
	fgSizer13->Add( m_staticText38, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textCtrlEndDatePt = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer13->Add( m_textCtrlEndDatePt, 0, wxALL|wxEXPAND, 5 );
	
	
	sbSizer3->Add( fgSizer13, 0, wxEXPAND, 5 );
	
	
	bSizer28->Add( sbSizer3, 0, wxEXPAND, 5 );
	
	
	bSizer27->Add( bSizer28, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Event Type") ), wxHORIZONTAL );
	
	wxArrayString m_checkListTypeChoices;
	m_checkListType = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxSize( -1,110 ), m_checkListTypeChoices, wxLB_NEEDED_SB );
	sbSizer2->Add( m_checkListType, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	m_buttonSelectType = new wxButton( this, wxID_ANY, _("Select All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_buttonSelectType, 0, wxALL, 5 );
	
	m_buttonClearType = new wxButton( this, wxID_ANY, _("Clear All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_buttonClearType, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	sbSizer2->Add( bSizer12, 1, wxEXPAND, 0 );
	
	
	bSizer27->Add( sbSizer2, 1, wxEXPAND|wxLEFT, 5 );
	
	
	bSizer1->Add( bSizer27, 1, wxEXPAND, 0 );
	
	m_listEvent = new rgRecEventTableCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VIRTUAL );
	bSizer1->Add( m_listEvent, 1, wxALL|wxEXPAND, 5 );
	
	m_staticline8 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline8, 0, wxEXPAND | wxALL, 0 );
	
	wxBoxSizer* bSizerDismiss;
	bSizerDismiss = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonCreate = new wxButton( this, wxID_ANY, _("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonCreate, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticEventCount = new wxStaticText( this, wxID_ANY, _("0 Events"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticEventCount->Wrap( -1 );
	bSizerDismiss->Add( m_staticEventCount, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizerDismiss->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonSelect = new wxButton( this, wxID_OK, _("Select"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonSelect, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerDismiss->Add( m_buttonCancel, 0, wxALL, 5 );
	
	
	bSizer1->Add( bSizerDismiss, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_IDLE, wxIdleEventHandler( fbRgSelectIndEvent::OnIdle ) );
	m_checkListGrp->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( fbRgSelectIndEvent::OnGroupCheckSelect ), NULL, this );
	m_checkListGrp->Connect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( fbRgSelectIndEvent::OnGroupCheckToggled ), NULL, this );
	m_buttonSelectGrp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgSelectIndEvent::OnButtonGroupSelectAll ), NULL, this );
	m_buttonClearGrp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgSelectIndEvent::OnButtonGroupClearAll ), NULL, this );
	m_textCtrlBegDatePt->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( fbRgSelectIndEvent::OnBegDateText ), NULL, this );
	m_textCtrlEndDatePt->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( fbRgSelectIndEvent::OnEndDateText ), NULL, this );
	m_checkListType->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( fbRgSelectIndEvent::OnTypeCheckSelect ), NULL, this );
	m_checkListType->Connect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( fbRgSelectIndEvent::OnTypeCheckToggled ), NULL, this );
	m_buttonSelectType->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgSelectIndEvent::OnButtonTypeSelectAll ), NULL, this );
	m_buttonClearType->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgSelectIndEvent::OnButtonTypeClearAll ), NULL, this );
	m_listEvent->Connect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( fbRgSelectIndEvent::OnListEventItemDeselected ), NULL, this );
	m_listEvent->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( fbRgSelectIndEvent::OnListEventItemSelected ), NULL, this );
	m_buttonCreate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgSelectIndEvent::OnCreateButton ), NULL, this );
}

fbRgSelectIndEvent::~fbRgSelectIndEvent()
{
	// Disconnect Events
	this->Disconnect( wxEVT_IDLE, wxIdleEventHandler( fbRgSelectIndEvent::OnIdle ) );
	m_checkListGrp->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( fbRgSelectIndEvent::OnGroupCheckSelect ), NULL, this );
	m_checkListGrp->Disconnect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( fbRgSelectIndEvent::OnGroupCheckToggled ), NULL, this );
	m_buttonSelectGrp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgSelectIndEvent::OnButtonGroupSelectAll ), NULL, this );
	m_buttonClearGrp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgSelectIndEvent::OnButtonGroupClearAll ), NULL, this );
	m_textCtrlBegDatePt->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( fbRgSelectIndEvent::OnBegDateText ), NULL, this );
	m_textCtrlEndDatePt->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( fbRgSelectIndEvent::OnEndDateText ), NULL, this );
	m_checkListType->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( fbRgSelectIndEvent::OnTypeCheckSelect ), NULL, this );
	m_checkListType->Disconnect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( fbRgSelectIndEvent::OnTypeCheckToggled ), NULL, this );
	m_buttonSelectType->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgSelectIndEvent::OnButtonTypeSelectAll ), NULL, this );
	m_buttonClearType->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgSelectIndEvent::OnButtonTypeClearAll ), NULL, this );
	m_listEvent->Disconnect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( fbRgSelectIndEvent::OnListEventItemDeselected ), NULL, this );
	m_listEvent->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( fbRgSelectIndEvent::OnListEventItemSelected ), NULL, this );
	m_buttonCreate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( fbRgSelectIndEvent::OnCreateButton ), NULL, this );
	
}
