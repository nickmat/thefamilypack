/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        recLink.cpp
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Manage SQLite3 Link records.
 * Author:      Nick Matthews
 * Modified by:
 * Website:     http://thefamilypack.org
 * Created:     3 October 2010
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

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <rec/recLink.h>

//============================================================================
//                 recLinkEvent
//============================================================================

recLinkEvent::recLinkEvent( const recLinkEvent& d )
{
    f_id          = d.f_id;
    f_ref_event_id  = d.f_ref_event_id;
    f_ind_event_id  = d.f_ind_event_id;
    f_comment     = d.f_comment;
}

void recLinkEvent::Clear()
{
    f_id          = 0;
    f_ref_event_id  = 0;
    f_ind_event_id  = 0;
    f_comment     = wxEmptyString;
}

void recLinkEvent::Save()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 )
    {
        // Add new record
        sql.Format(
            "INSERT INTO LinkEvent "
            "(ref_event_id, ind_event_id, comment) "
            "VALUES ("ID", "ID", '%q');",
            f_ref_event_id, f_ind_event_id, UTF8_(f_comment)
        );
        s_db->ExecuteUpdate( sql );
        f_id = GET_ID( s_db->GetLastRowId() );
    } else {
        // Does record exist
        if( !Exists() )
        {
            // Add new record
            sql.Format(
                "INSERT INTO LinkEvent "
                "(id, ref_event_id, ind_event_id, comment) "
                "VALUES ("ID", "ID", "ID", '%q');",
                f_id, f_ref_event_id, f_ind_event_id, f_comment
            );
        } else {
            // Update existing record
            sql.Format(
                "UPDATE LinkEvent SET ref_event_id="ID", ind_event_id="ID", "
                "comment='%q' "
                "WHERE id="ID";",
                f_ref_event_id, f_ind_event_id,
                UTF8_(f_comment), f_id
            );
        }
        s_db->ExecuteUpdate( sql );
    }
}

bool recLinkEvent::Read()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 ) {
        Clear();
        return false;
    }

    sql.Format(
        "SELECT ref_event_id, ind_event_id, comment "
        "FROM LinkEvent WHERE id="ID";",
        f_id
    );
    result = s_db->GetTable( sql );

    if( result.GetRowCount() != 1 )
    {
        Clear();
        return false;
    }
    result.SetRow( 0 );
    f_ref_event_id  = GET_ID( result.GetInt64( 0 ) );
    f_ind_event_id  = GET_ID( result.GetInt64( 1 ) );
    f_comment     = result.GetAsString( 2 );
    return true;
}

/*! Given the per_id and ind_id settings, find the matching record
 *  and read in the full record.
 */
bool recLinkEvent::Find()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_ind_event_id == 0 ) return false; // Only find single record

    sql.Format(
        "SELECT id, comment FROM LinkEvent "
        "WHERE ref_event_id="ID" AND ind_event_id="ID";",
        f_ref_event_id, f_ind_event_id
    );
    result = s_db->GetTable( sql );

    if( result.GetRowCount() != 1 ) return false;
    result.SetRow( 0 );
    f_id   = GET_ID( result.GetInt64( 0 ) );
    f_comment = result.GetAsString( 1 );
    return true;
}


//============================================================================
//                 recLinkPersona
//============================================================================

recLinkPersona::recLinkPersona( const recLinkPersona& d )
{
    f_id          = d.f_id;
    f_ref_per_id  = d.f_ref_per_id;
    f_ind_per_id  = d.f_ind_per_id;
    f_conf        = d.f_conf;
    f_comment     = d.f_comment;
}

void recLinkPersona::Clear()
{
    f_id          = 0;
    f_ref_per_id  = 0;
    f_ind_per_id  = 0;
    f_conf        = 0;
    f_comment     = wxEmptyString;
}

void recLinkPersona::Save()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 )
    {
        // Add new record
        sql.Format(
            "INSERT INTO LinkPersona "
            "(ref_per_id, ind_per_id, conf, comment) "
            "VALUES ("ID", "ID", %f, '%q');",
            f_ref_per_id, f_ind_per_id, f_conf, UTF8_(f_comment)
        );
        s_db->ExecuteUpdate( sql );
        f_id = GET_ID( s_db->GetLastRowId() );
    } else {
        // Does record exist
        if( !Exists() )
        {
            // Add new record
            sql.Format(
                "INSERT INTO LinkPersona "
                "(id, ref_per_id, ind_per_id, conf, comment) "
                "VALUES ("ID", "ID", "ID", %f, '%q');",
                f_id, f_ref_per_id, f_ind_per_id, f_conf, f_comment
            );
        } else {
            // Update existing record
            sql.Format(
                "UPDATE LinkPersona SET ref_per_id="ID", ind_per_id="ID", "
                "conf=%f, comment='%q' "
                "WHERE id="ID";",
                f_ref_per_id, f_ind_per_id, f_conf,
                UTF8_(f_comment), f_id
            );
        }
        s_db->ExecuteUpdate( sql );
    }
}

bool recLinkPersona::Read()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 ) {
        Clear();
        return false;
    }

    sql.Format(
        "SELECT ref_per_id, ind_per_id, conf, comment "
        "FROM LinkPersona WHERE id="ID";",
        f_id
    );
    result = s_db->GetTable( sql );

    if( result.GetRowCount() != 1 )
    {
        Clear();
        return false;
    }
    result.SetRow( 0 );
    f_ref_per_id  = GET_ID( result.GetInt64( 0 ) );
    f_ind_per_id  = GET_ID( result.GetInt64( 1 ) );
    f_conf        = result.GetDouble( 2 );
    f_comment     = result.GetAsString( 3 );
    return true;
}

/*! Given the per_id and ind_id settings, find the matching record
 *  and read in the full record.
 */
bool recLinkPersona::Find()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_ref_per_id == 0 || f_ind_per_id == 0 ) return false; // Only find single record

    sql.Format(
        "SELECT id, conf, comment FROM LinkPersona "
        "WHERE ref_per_id="ID" AND ind_per_id="ID";",
        f_ref_per_id, f_ind_per_id
    );
    result = s_db->GetTable( sql );

    if( result.GetRowCount() != 1 ) return false;
    result.SetRow( 0 );
    f_id   = GET_ID( result.GetInt64( 0 ) );
    f_conf = result.GetDouble( 1 );
    f_comment = result.GetAsString( 2 );
    return true;
}

// End of recLink.cpp file