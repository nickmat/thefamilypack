///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __fbDlg__
#define __fbDlg__

#include <wx/intl.h>

class tfpListCtrlIndividuals;

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/listbox.h>
#include <wx/statbox.h>
#include <wx/statline.h>
#include <wx/dialog.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/toolbar.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/splitter.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class fbDlgEditFamily
///////////////////////////////////////////////////////////////////////////////
class fbDlgEditFamily : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			tfpID_EDFAM_FAM_ID = 1000,
			tfpID_EDFAM_HUSB_BUT,
			tfpID_EDFAM_HUSB_NAM,
			tfpID_EDFAM_WIFE_BUT,
			tfpID_EDFAM_WIFE_NAM,
			tfpID_EDFAM_MARR_BUT,
			tfpID_EDFAM_MARR_EV,
			tfpID_EDFAM_CHILD_LIST,
			tfpID_EDFAM_ADD,
			tfpID_EDFAM_EDIT,
			tfpID_EDFAM_DELETE,
			tfpID_EDFAM_UP,
			tfpID_EDFAM_DOWN,
		};
		
		wxStaticText* m_staticText1;
		wxStaticText* m_staticFamID;
		wxButton* m_buttonHusbID;
		wxStaticText* m_staticText3;
		wxStaticText* m_staticHusbName;
		wxButton* m_buttonWife;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticWifeName;
		wxButton* m_buttonMarr;
		wxStaticText* m_staticText12;
		wxStaticText* m_staticMarrEvent;
		wxListBox* m_listChild;
		wxButton* m_buttonAdd;
		wxButton* m_buttonEdit;
		wxButton* m_buttonDel;
		wxButton* m_buttonUp;
		wxButton* m_button1Dn;
		wxStaticLine* m_staticline1;
		
		wxButton* m_buttonSave;
		wxButton* m_buttonCancel;
	
	public:
		
		fbDlgEditFamily( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Edit Family"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 414,354 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~fbDlgEditFamily();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class fbDlgEditIndividual
///////////////////////////////////////////////////////////////////////////////
class fbDlgEditIndividual : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			tfpID_EDIND_IND_ID = 1000,
			tfpID_EDIND_GIVEN,
			tfpID_EDIND_SEX,
			tfpID_EDIND_SURNAME,
			tfpID_EDIND_OCC,
			tfpID_EDIND_EVENTS,
		};
		
		wxStaticText* m_staticText1;
		wxStaticText* m_staticIndID;
		wxNotebook* m_notebook1;
		wxPanel* m_panel1;
		wxStaticText* m_staticText40;
		wxTextCtrl* m_textGiven;
		wxStaticText* m_staticText41;
		wxChoice* m_choiceSex;
		wxStaticText* m_staticText42;
		wxTextCtrl* m_textSurname;
		
		
		wxStaticText* m_staticText43;
		wxTextCtrl* m_textOccAttr;
		wxPanel* m_panel3;
		wxListCtrl* m_listCtrl;
		wxStaticLine* m_staticline1;
		
		wxButton* m_buttonSave;
		wxButton* m_buttonCancel;
	
	public:
		
		fbDlgEditIndividual( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Edit Individual"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxSYSTEM_MENU );
		~fbDlgEditIndividual();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class fbDlgEditIndEvent
///////////////////////////////////////////////////////////////////////////////
class fbDlgEditIndEvent : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			tfpID_EDINDEV_TYPE = 1000,
			tfpID_EDINDEV_DATE,
			tfpID_EDINDEV_DATE_BUT,
			tfpID_EDINDEV_ADDR,
			tfpID_EDINDEV_ADDR_BUT,
		};
		
		wxStaticText* m_staticText17;
		wxStaticText* m_staticTextType;
		
		wxStaticText* m_staticText15;
		wxTextCtrl* m_textCtrlDate;
		wxButton* m_buttonDate;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_textCtrlAddr;
		wxButton* m_buttonAddr;
		wxStaticLine* m_staticline1;
		
		wxButton* m_buttonSave;
		wxButton* m_buttonCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnDateButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddrButton( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		fbDlgEditIndEvent( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Edit Event"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~fbDlgEditIndEvent();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class fbDlgEditPersona
///////////////////////////////////////////////////////////////////////////////
class fbDlgEditPersona : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			tfpID_EDIND_IND_ID = 1000,
			tfpID_EDPER_SEX,
			tfpID_EDPER_NOTE,
			tfpID_EDPER_IND_LINK,
			tfpID_EDPER_IND_CREATE,
			tfpID_EDPER_ATTR_LIST,
			tfpID_EDPER_ATTR_ADD,
			tfpID_EDPER_ATTR_EDIT,
			tfpID_EDPER_ATTR_DELETE,
			tfpID_EDPER_ATTR_UP,
			tfpID_EDPER_ATTR_DOWN,
		};
		
		wxStaticText* m_staticText1;
		wxStaticText* m_staticPerName;
		
		wxStaticText* m_staticText411;
		wxChoice* m_choiceSex;
		wxStaticText* m_staticText11;
		wxTextCtrl* m_textCtrlNote;
		wxButton* m_buttonIndLink;
		wxButton* m_buttonIndCreate;
		wxStaticText* m_staticText12;
		wxStaticText* m_staticIndId;
		wxListCtrl* m_listAttr;
		wxButton* m_buttonAdd;
		wxButton* m_buttonEdit;
		wxButton* m_buttonDel;
		wxButton* m_buttonUp;
		wxButton* m_buttonDn;
		wxStaticLine* m_staticline1;
		
		wxButton* m_buttonSave;
		wxButton* m_buttonCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnIndLinkButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnIndCreateButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDownButton( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		fbDlgEditPersona( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Edit Persona"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~fbDlgEditPersona();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class fbDlgSelectIndividual
///////////////////////////////////////////////////////////////////////////////
class fbDlgSelectIndividual : public wxDialog 
{
	private:
	
	protected:
		tfpListCtrlIndividuals* m_listInd;
		wxStaticLine* m_staticline6;
		
		wxButton* m_buttonSave;
		wxButton* m_buttonCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnIdle( wxIdleEvent& event ) { event.Skip(); }
		virtual void OnIndividualSelected( wxListEvent& event ) { event.Skip(); }
		
	
	public:
		
		fbDlgSelectIndividual( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Select Individual"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 485,269 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~fbDlgSelectIndividual();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class fbDlgEditEvent
///////////////////////////////////////////////////////////////////////////////
class fbDlgEditEvent : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxStaticText* m_staticType;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_textCtrlTitle;
		wxButton* m_buttonDateBeg;
		wxTextCtrl* m_textCtrlDateBeg;
		wxButton* m_buttonDateEnd;
		wxTextCtrl* m_textCtrlDateEnd;
		wxButton* m_buttonPlace;
		wxTextCtrl* m_textCtrlPlace;
		wxListCtrl* m_listPersona;
		wxButton* m_buttonAdd;
		wxButton* m_buttonEdit;
		wxButton* m_buttonDel;
		wxButton* m_buttonUp;
		wxButton* m_buttonDn;
		wxStaticLine* m_staticline1;
		
		wxButton* m_buttonSave;
		wxButton* m_buttonCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnDateBegButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDateEndButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlaceButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDownButton( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		fbDlgEditEvent( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Edit Event"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~fbDlgEditEvent();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class fbDlgEditReference
///////////////////////////////////////////////////////////////////////////////
class fbDlgEditReference : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			tfpID_EDREF_OnCut = 1000,
			tfpID_EDREF_OnCopy,
			tfpID_EDREF_OnPaste,
			tfpID_EDREF_OnUndo,
			tfpID_EDREF_OnRedo,
			tfpID_EDREF_OnBold,
			tfpID_EDREF_OnItalic,
			tfpID_EDREF_OnUnderline,
			tfpID_EDREF_OnFont,
		};
		
		wxStaticText* m_staticText1;
		wxStaticText* m_staticRefID;
		wxStaticText* m_staticText401;
		wxTextCtrl* m_textCtrlTitle;
		wxToolBar* m_toolBar1;
		wxSplitterWindow* m_splitter1;
		wxPanel* m_panel7;
		wxRichTextCtrl* m_richText;
		wxPanel* m_panel8;
		wxListCtrl* m_listEntities;
		wxButton* m_buttonAdd;
		wxButton* m_buttonEdit;
		wxButton* m_buttonDel;
		wxButton* m_buttonUp;
		wxButton* m_buttonDn;
		wxStaticLine* m_staticline1;
		
		wxButton* m_buttonSave;
		wxButton* m_buttonCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnTool( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDownButton( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		fbDlgEditReference( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Edit Reference"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,500 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~fbDlgEditReference();
		
		void m_splitter1OnIdle( wxIdleEvent& )
		{
			m_splitter1->SetSashPosition( 186 );
			m_splitter1->Disconnect( wxEVT_IDLE, wxIdleEventHandler( fbDlgEditReference::m_splitter1OnIdle ), NULL, this );
		}
	
};

#endif //__fbDlg__
