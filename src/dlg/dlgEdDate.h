/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        dlgEdDate.h
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Edit database Date entity dialog header.
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

#ifndef DLGEDDATE_H
#define DLGEDDATE_H

#include <rec/recDate.h>

#include "fbDlg.h"


/*! dlgEditDateFromAge
 *  This dialog creates a new date from an old one plus an age value.
 *  It cannot be used to edit an existing date.
 */
class dlgEditDateFromAge : public fbDlgEditDateFromAge
{
public:
    static CalendarScheme scheme[];
    static int sch_list[CALENDAR_SCH_Max];
    static CalendarUnit unit[];

    dlgEditDateFromAge( wxWindow* parent, idt baseID, idt dateID = 0 );

    void SetText( const wxString& text ) { m_text = text; }

    recDate* GetDate() { return &m_date; }

private:
    bool TransferDataToWindow();
    bool TransferDataFromWindow();
    void SetStaticDate( wxIdleEvent& event );
    void CalcDate();

    recRelativeDate m_relative;
    recDate   m_base;
    recDate   m_date;
    wxString  m_text;
    wxString  m_basestr;
    wxString  m_output;
};

#endif // DLGEDDATE_H
