/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        src/rg/rgEdEventa.h
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Edit database Eventa entity dialog header.
 * Author:      Nick Matthews
 * Website:     http://thefamilypack.org
 * Created:     25th February 2013
 * Copyright:   Copyright (c) 2013, Nick Matthews.
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

#ifndef RG_RGEDEVENTA_H
#define RG_RGEDEVENTA_H

#include <rec/recEventa.h>
#include <rec/recReference.h>

#include "fbRgDialog.h"

//============================================================================
//--------------------------[ rgDlgEditEventa]--------------------------------
//============================================================================

/** Implementing rgDlgEditEventa */
class rgDlgEditEventa : public fbRgEditEventa
{
    DECLARE_EVENT_TABLE()
public:
    rgDlgEditEventa( wxWindow* parent, idt eventID );
private:
    enum ColPer {
        COL_PerID, COL_Name, COL_Role, COL_Note, COL_MAX
    };
    enum ColEvent {
        COL_EveID, COL_EveTitle
    };
    enum {
        ID_EDEE_OPTN_EDIT = 1500,
        ID_EDEE_OPTN_UNLINK,
        ID_EDEE_OPTN_CREATE,
        ID_EDEE_OPTN_CREATE_REL
    };

    bool TransferDataToWindow();
    void ListLinkedPersona();
    void ListEvents();
    bool TransferDataFromWindow();

    void OnDate1Button( wxCommandEvent& event );
    void OnDate2Button( wxCommandEvent& event );
    void OnPlaceButton( wxCommandEvent& event );

    void OnOptnEdit( wxCommandEvent& event );
    void OnOptnUnlink( wxCommandEvent& event );
    void OnOptnCreate( wxCommandEvent& event );
    void OnOptnCreateRel( wxCommandEvent& event );

    void OnAddPer( wxCommandEvent& event );
    void OnEditPer( wxCommandEvent& event );
    void OnDeletePer( wxCommandEvent& event );

    void OnAddCon( wxCommandEvent& event );
    void OnEditCon( wxCommandEvent& event );
    void OnDeleteCon( wxCommandEvent& event );

    idt            m_refID;
    recEventa      m_event;
    idt            m_date1ID;
    idt            m_date2ID;
    idt            m_placeID;

    enum Button {
        EEEB_Date1, EEEB_Date2, EEEB_Place
    };
    Button               m_button;
    recEventaPersonaVec  m_eps;
    recPersonaVec        m_personas;
    recEventEventaVec    m_eers;
};

#endif // RG_RGEDEVENTA_H
