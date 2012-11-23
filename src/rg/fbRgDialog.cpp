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

///////////////////////////////////////////////////////////////////////////

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
	
	m_listRole = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL );
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
	m_staticText1->SetFont( wxFont( 8, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
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
	m_staticText2->SetFont( wxFont( 8, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
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

fbRgSelect::fbRgSelect( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_listCtrl = new rgStrTableCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VIRTUAL|wxLC_VRULES|wxALWAYS_SHOW_SB|wxVSCROLL );
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
	
	
	bSizer3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonSelect = new wxButton( this, wxID_OK, _("Select"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_buttonSelect, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_buttonCancel, 0, wxALL, 5 );
	
	
	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
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