/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        src/rg/rgEdDate.h
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Edit database Date dialog header.
 * Author:      Nick Matthews
 * Modified by:
 * Website:     http://thefamilypack.org
 * Created:     28th November 2012
 * RCS-ID:      $Id$
 * Copyright:   Copyright (c) 2012-2013, Nick Matthews.
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

#ifndef RGEDDATE_H
#define RGEDDATE_H

#include <rec/recDate.h>

#include "rg/rgDialogs.h"

#include "fbRgDialog.h"

namespace rgDate
{
    extern CalendarScheme scheme[];
    extern size_t SchemeListSize;
    extern int sch_list[CALENDAR_SCH_Max];
    extern CalendarUnit unit[];
    extern int unit_list[CALENDAR_UNIT_Max];
    extern recRelativeDate::Type calc[];
    extern int calc_list[recRelativeDate::TYPE_Max];
    extern wxArrayString GetCalendarList();
}

//============================================================================
//-------------------------[ rgDlgEditDate ]----------------------------------
//============================================================================

class rgDlgEditDate : public fbRgEditDate
{
public:
    rgDlgEditDate( wxWindow* parent, idt dateID );

private:
    bool TransferDataToWindow();
    bool TransferDataFromWindow();

    void OnIdle( wxIdleEvent& event );

    recDate   m_date;
    wxString  m_output;
};

#endif // RGEDDATE_H
