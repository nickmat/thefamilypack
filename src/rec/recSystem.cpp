/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        recSystem.cpp
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Manage the SQLite3 System records.
 * Author:      Nick Matthews
 * Website:     http://thefamilypack.org
 * Created:     30 March 2012
 * Copyright:   Copyright (c) 2012 ~ 2017, Nick Matthews.
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

#include <rec/recSystem.h>

//============================================================================
//                 recSystem
//============================================================================

recSystem::recSystem( const recSystem& r2 )
{
    f_id       = r2.f_id;
    f_val      = r2.f_val;
}

void recSystem::Clear()
{
    f_id       = 0;
    f_val      = wxEmptyString;
}

void recSystem::Save()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 ) {
        // Add new record
        sql.Format(
            "INSERT INTO System (val) VALUES ('%q');",
            UTF8_(f_val)
        );
        s_db->ExecuteUpdate( sql );
        f_id = GET_ID( s_db->GetLastRowId() );
    } else {
        // Does record exist
        if( !Exists() ) {
            // Add new record
            sql.Format(
                "INSERT INTO System (id, val)"
                " VALUES (" ID " '%q');",
                f_id, UTF8_(f_val)
            );
        } else {
            // Update existing record
            sql.Format(
                "UPDATE System SET val='%q' WHERE id=" ID ";",
                UTF8_(f_val), f_id
            );
        }
        s_db->ExecuteUpdate( sql );
    }
}

bool recSystem::Read()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 ) {
        Clear();
        return false;
    }

    sql.Format(
        "SELECT val FROM System WHERE id=" ID ";",
        f_id
    );
    result = s_db->GetTable( sql );

    if( result.GetRowCount() != 1 ) {
        Clear();
        return false;
    }
    result.SetRow( 0 );
    f_val = result.GetAsString( 0 );
    return true;
}

bool recSystem::Equivalent( const recSystem& r2 ) const
{ 
    return f_val == r2.f_val;
}

wxString recSystem::GetPropertyValue( Property sp )
{
    recSystem sys((idt) sp);
    return sys.FGetValue();
}

idt recSystem::GetPropertyValueID( Property sp )
{
    recSystem sys((idt) sp);
    return recGetID( sys.FGetValue() );
}

void recSystem::SetProperyValue( Property sp, const wxString& value )
{
    recSystem sys((idt) sp);
    sys.FSetValue( value );
    sys.Save();
}

void recSystem::SetProperyValue( Property sp, idt id )
{
    recSystem sys((idt) sp);
    sys.FSetValue( recGetStr( id ) );
    sys.Save();
}

// End of recSystem.cpp file
