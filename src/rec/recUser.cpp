/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        recUser.cpp
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Manage the SQLite3 User records.
 * Author:      Nick Matthews
 * Modified by:
 * Website:     http://thefamilypack.org
 * Created:     25 February 2011
 * RCS-ID:      $Id$
 * Copyright:   Copyright (c) 2011, Nick Matthews.
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

#include <rec/recUser.h>

//============================================================================
//                 recUser
//============================================================================

recUser::recUser( const recUser& s )
{
    f_id     = s.f_id;
    f_res_id = s.f_res_id;
    f_fam_id = s.f_fam_id;
}

void recUser::Clear()
{
    f_id     = 0;
    f_res_id = 0;
    f_fam_id = 0;
}

void recUser::Save()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 )
    {
        // Add new record
        sql.Format(
            "INSERT INTO User (res_id, fam_id) "
            "VALUES ("ID", "ID");",
            f_res_id, f_fam_id
        );
        s_db->ExecuteUpdate( sql );
        f_id = GET_ID( s_db->GetLastRowId() );
    } else {
        // Does record exist
        if( !Exists() )
        {
            // Add new record
            sql.Format(
                "INSERT INTO User (id, res_id, fam_id) "
                "VALUES ("ID", "ID", "ID");",
                f_id, f_res_id, f_fam_id
            );
        } else {
            // Update existing record
            sql.Format(
                "UPDATE User SET res_id="ID", fam_id="ID" "
                "WHERE id="ID";",
                f_res_id, f_fam_id, f_id
            );
        }
        s_db->ExecuteUpdate( sql );
    }
}

bool recUser::Read()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 ) {
        Clear();
        return false;
    }

    sql.Format(
        "SELECT res_id, fam_id "
        "FROM User WHERE id="ID";",
        f_id
    );
    result = s_db->GetTable( sql );

    if( result.GetRowCount() != 1 )
    {
        Clear();
        return false;
    }
    result.SetRow( 0 );
    f_res_id = GET_ID( result.GetInt64( 0 ) );
    f_fam_id = GET_ID( result.GetInt64( 1 ) );
    return true;
}

// End of recUser.cpp file