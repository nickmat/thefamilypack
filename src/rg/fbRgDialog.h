///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __FBRGDIALOG_H__
#define __FBRGDIALOG_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
class rgStrTableCtrl;

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/listctrl.h>
#include <wx/button.h>
#include <wx/statline.h>
#include <wx/dialog.h>
#include <wx/checkbox.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class fbRgEditEventType
///////////////////////////////////////////////////////////////////////////////
class fbRgEditEventType : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText4;
		wxChoice* m_choiceGroup;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_textCtrlValue;
		wxListCtrl* m_listRole;
		wxButton* m_buttonRoleAdd;
		wxButton* m_buttonRoleEdit;
		wxButton* m_buttonRoleDelete;
		wxStaticLine* m_staticline1;
		wxStaticText* m_staticTypeID;
		wxButton* m_buttonSave;
		wxButton* m_buttonCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonRoleAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonRoleEdit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonRoleDelete( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		fbRgEditEventType( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Edit Event Type"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 350,300 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER ); 
		~fbRgEditEventType();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class fbRgEditRole
///////////////////////////////////////////////////////////////////////////////
class fbRgEditRole : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxStaticText* m_staticEventType;
		wxStaticText* m_staticEventTypeID;
		wxStaticText* m_staticText2;
		wxStaticText* m_staticTypeGroup;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_textCtrlValue;
		wxStaticText* m_staticText4;
		wxChoice* m_choicePrime;
		wxCheckBox* m_checkOfficial;
		wxStaticLine* m_staticline1;
		wxStaticText* m_staticRoleID;
		wxButton* m_buttonSave;
		wxButton* m_buttonCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChoicePrime( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		fbRgEditRole( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Edit Role"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 300,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER ); 
		~fbRgEditRole();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class fbRgSelect
///////////////////////////////////////////////////////////////////////////////
class fbRgSelect : public wxDialog 
{
	private:
	
	protected:
		rgStrTableCtrl* m_listCtrl;
		wxStaticLine* m_staticline;
		wxButton* m_buttonCreate;
		wxButton* m_buttonFilter;
		wxButton* m_buttonUnknown;
		wxButton* m_buttonSelect;
		wxButton* m_buttonCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnIdle( wxIdleEvent& event ) { event.Skip(); }
		virtual void OnCreateButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFilterButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUnknownButton( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		fbRgSelect( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Select"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 410,289 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER ); 
		~fbRgSelect();
	
};

#endif //__FBRGDIALOG_H__