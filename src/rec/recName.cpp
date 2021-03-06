/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        recName.cpp
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Manage SQLite3 Name, NamePart, NamePartType and NameStyle records.
 * Author:      Nick Matthews
 * Website:     http://thefamilypack.org
 * Created:     22 November 2010
 * Copyright:   Copyright (c) 2010 ~ 2017, Nick Matthews.
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

#include <rec/recName.h>

#include <rec/recPersona.h>

#include <wx/tokenzr.h>


//============================================================================
//-------------------------[ recName ]----------------------------------------
//============================================================================

recName::recName( const recName& n )
{
    f_id       = n.f_id;
    f_ind_id   = n.f_ind_id;
    f_per_id   = n.f_per_id;
    f_style_id = n.f_style_id;
    f_sequence = n.f_sequence;
}

void recName::Clear()
{
    f_id       = 0;
    f_ind_id   = 0;
    f_per_id   = 0;
    f_style_id = 0;
    f_sequence = 0;
}

void recName::Save()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 )
    {
        // Add new record
        sql.Format(
            "INSERT INTO Name (ind_id, per_id, style_id, sequence)"
            "VALUES (" ID ", " ID ", " ID ", %d);",
            f_ind_id, f_per_id, f_style_id, f_sequence
        );
        s_db->ExecuteUpdate( sql );
        f_id = GET_ID( s_db->GetLastRowId() );
    } else {
        // Does record exist
        if( !Exists() )
        {
            // Add new record
            sql.Format(
                "INSERT INTO Name (id, ind_id, per_id, style_id, sequence)"
                "VALUES (" ID ", " ID ", " ID ", " ID ", %d);",
                f_id, f_ind_id, f_per_id, f_style_id, f_sequence
            );
        } else {
            // Update existing record
            sql.Format(
                "UPDATE Name SET ind_id=" ID ", per_id=" ID ", style_id=" ID ", sequence=%d WHERE id=" ID ";",
                f_ind_id, f_per_id, f_style_id, f_sequence, f_id
            );
        }
        s_db->ExecuteUpdate( sql );
    }
}

bool recName::Read()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 ) {
        Clear();
        return false;
    }

    sql.Format(
        "SELECT ind_id, per_id, style_id, sequence "
        "FROM Name WHERE id=" ID ";",
        f_id
    );
    result = s_db->GetTable( sql );

    if( result.GetRowCount() != 1 )
    {
        Clear();
        return false;
    }
    result.SetRow( 0 );
    f_ind_id   = GET_ID( result.GetInt64( 0 ) );
    f_per_id   = GET_ID( result.GetInt64( 1 ) );
    f_style_id = GET_ID( result.GetInt64( 2 ) );
    f_sequence = result.GetInt( 3 );
    return true;
}

idt recName::GetIndID( idt nameID )
{
    return ExecuteID( "SELECT ind_id FROM Name WHERE id=" ID ";", nameID );
}

idt recName::GetPerID( idt nameID )
{
    return ExecuteID( "SELECT per_id FROM Name WHERE id=" ID ";", nameID );
}

idt recName::CreateName( const wxString& nameStr, idt style )
{
    recName name(0);
    name.f_style_id = style;
    name.Save();
    name.AddNameParts( nameStr );
    return name.f_id;
}

idt recName::Create( const wxString& nameStr, idt indID, idt perID, idt style, int* pseq )
{
    assert( pseq != NULL ); // TODO: Allow for NULL
    recName name(0);
    name.f_ind_id = indID;
    name.f_per_id = perID;
    name.f_style_id = style;
    name.f_sequence = ++(*pseq);
    name.Save();
    name.AddNameParts( nameStr );
    return name.f_id;
}

int recName::AddNameParts( const wxString& nameStr, recStdNameType type, int seq ) const
{
    recNamePart part(0);
    part.f_name_id = f_id;
    part.f_sequence = seq;

    wxStringTokenizer tk( nameStr );
    if( type == NAME_TYPE_Unstated ) {
        // TODO: Action should depend on naming conventions
        while( tk.HasMoreTokens() ) {
            part.f_id = 0;
            part.f_val = tk.GetNextToken();
            part.f_type_id = tk.HasMoreTokens() ? NAME_TYPE_Given_name : NAME_TYPE_Surname;
            ++part.f_sequence;
            part.Save();
        }
    } else {
        part.f_type_id = type;
        while( tk.HasMoreTokens() ) {
            part.f_id = 0;
            part.f_val = tk.GetNextToken();
            ++part.f_sequence;
            part.Save();
        }
    }
    return part.f_sequence;
}

int recName::AddNamePart( const wxString& nameStr, recStdNameType type, int seq ) const
{
    recNamePart part(0);
    part.f_name_id = f_id;
    part.f_type_id = type;
    part.f_val = nameStr;
    part.f_sequence = ++seq;
    part.Save();
    return part.f_sequence;
}

idt recName::GetDefaultNameID( idt indID, idt perID )
{
    wxString str;
    wxSQLite3StatementBuffer sql;

    sql.Format(
        "SELECT id FROM Name WHERE ind_id=" ID " AND per_id=" ID " ORDER BY sequence;",
        indID, perID
    );
    wxSQLite3Table result = s_db->GetTable( sql );
    if( result.GetRowCount() > 0 ) {
        return GET_ID( result.GetInt64( 0 ) );
    }
    return 0;
}

wxString recName::GetDefaultNameStr( idt indID, idt perID )
{
    idt nameID = GetDefaultNameID( indID, perID );
    return GetNameStr( nameID );
}

recNameVec recName::GetNames( idt indID, idt perID )
{
    recNameVec list;
    recName name(0);
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( indID == 0 ) {
        return list;
    }

    sql.Format(
        "SELECT id, style_id, sequence FROM Name"
        " WHERE ind_id=" ID " AND per_id=" ID " ORDER BY sequence;",
        indID, perID
    );
    result = s_db->GetTable( sql );

    name.FSetIndID( indID );
    name.FSetPerID( perID );
    list.reserve( result.GetRowCount() );
    for( int i = 0 ; i < result.GetRowCount() ; i++ )
    {
        result.SetRow( i );
        name.FSetID( GET_ID( result.GetInt64( 0 ) ) );
        name.FSetTypeID( GET_ID( result.GetInt64( 1 ) ) );
        name.FSetSequence( result.GetInt( 2 ) );
        list.push_back( name );
    }
    return list;
}

void recName::RemoveFromDatabase( idt id )
{
    if( id == 0 ) return;

    // TODO: Consider making 2 functions, one for reference, one for individual.
    wxSQLite3StatementBuffer sql;

    // TODO: Ensure Event is removed from reference statement.
    sql.Format(
        "DELETE FROM NamePart WHERE name_id=" ID ";"
        "DELETE FROM ReferenceEntity "
             "WHERE entity_type=7 AND entity_id=" ID ";"
        "DELETE FROM Name WHERE id=" ID ";",
        id, id, id
    );
    s_db->ExecuteUpdate( sql );
}

wxString recName::GetNameStr( idt id )
{
    if( id == 0 ) return wxEmptyString;

    wxSQLite3StatementBuffer sql;
    sql.Format(
        "SELECT val FROM NamePart "
        "WHERE name_id=" ID " "
        "ORDER BY sequence;",
        id
    );
    wxSQLite3Table result = s_db->GetTable( sql );

    wxString str;
    for( int i = 0 ; i < result.GetRowCount() ; i++ ) {
        result.SetRow( i );
        if( i > 0 ) {
            str << " ";
        }
        str << result.GetAsString( 0 );
    }
    return str;
}

wxString recName::GetTypeStr() const
{
    return ExecuteStr(
        "SELECT name FROM NameStyle WHERE id=" ID ";",
        f_style_id
    );
}

wxString recName::GetTypeStr( idt id )
{
    return ExecuteStr(
        "SELECT NS.name FROM Name N, NameStyle NS"
        " WHERE N.id=" ID " AND N.style_id=NS.id;",
        id
    );
}

wxString recName::GetNamePartStr( idt nameID, idt partID )
{
    if( nameID == 0 ) return wxEmptyString;

    wxSQLite3StatementBuffer sql;
    sql.Format(
        "SELECT val FROM NamePart "
        "WHERE name_id=" ID " AND type_id=" ID " "
        "ORDER BY sequence;",
        nameID, partID
    );
    wxSQLite3Table result = s_db->GetTable( sql );

    wxString str;
    for( int i = 0 ; i < result.GetRowCount() ; i++ ) {
        result.SetRow( i );
        if( i > 0 ) {
            str << " ";
        }
        str << result.GetAsString( 0 );
    }
    return str;
}

wxSQLite3ResultSet recName::GetSurnameIndex( recSurnameGroup surnamegrp )
{
    const char* grp;
    switch ( surnamegrp ) {
    case recSG_Individual:
        grp = "per_id";
        break;
    case recSG_Persona:
        grp = "ind_id";
        break;
    default:
        return wxSQLite3ResultSet();
    }
    wxSQLite3StatementBuffer sql;
    sql.Format(
        "SELECT NP.val FROM NamePart NP, Name N"
        " WHERE N.%s=0 AND N.id=NP.name_id AND NP.type_id=-2"
        " GROUP BY NP.val;", grp
    );
    return s_db->ExecuteQuery( sql );
}

recNameVec recName::GetNameList( const wxString& surname, recSurnameGroup sng )
{
    recNameVec list;

    const char* not_grp;
    switch ( sng ) {
    case recSG_Individual:
        not_grp = "per_id";
        break;
    case recSG_Persona:
        not_grp = "ind_id";
        break;
    default:
        return list;
    }

    wxSQLite3StatementBuffer sql;
    if ( surname.empty() ) {
        // Select all names for group.
        sql.Format(
            "SELECT N.id, N.ind_id, N.per_id, N.style_id, N.sequence"
            " FROM Name N, NamePart NP"
            " WHERE NP.type_id=-2 AND N.id=NP.name_id AND N.%s=0;",
            not_grp
        );
    } else {
        sql.Format(
            "SELECT N.id, N.ind_id, N.per_id, N.style_id, N.sequence"
            " FROM Name N, NamePart NP"
            " WHERE NP.type_id=-2 AND N.id=NP.name_id AND N.%s=0 AND NP.val='%q';",
            not_grp, UTF8_( surname )
        );
    }
    wxSQLite3Table result = s_db->GetTable( sql );

    recName name( 0 );
    list.reserve( result.GetRowCount() );
    for ( int i = 0; i < result.GetRowCount(); i++ )
    {
        result.SetRow( i );
        name.FSetID( GET_ID( result.GetInt64( 0 ) ) );
        name.FSetIndID( GET_ID( result.GetInt64( 1 ) ) );
        name.FSetPerID( GET_ID( result.GetInt64( 2 ) ) );
        name.FSetTypeID( GET_ID( result.GetInt64( 3 ) ) );
        name.FSetSequence( result.GetInt( 4 ) );
        list.push_back( name );
    }
    return list;
}

int recName::GetNextSequence( idt indID, idt perID )
{
    const char* owner;
    if( indID ) {
        owner = "ind_id";
    } else if( perID ) {
        owner = "per_id";
    } else {
        return 1;
    }
    wxSQLite3StatementBuffer sql;
    sql.Format( "SELECT MAX(sequence) FROM Name WHERE %s=" ID ";", owner, perID );
    return s_db->ExecuteScalar( sql ) + 1;
}

idt recName::CreateIndNameFromPersona( idt indID, idt perID )
{
    if( indID == 0 || perID == 0 ) {
        return 0;
    }
    idt pnID = recPersona::GetNameID( perID );
    if( pnID == 0 ) {
        return 0;
    }
    recName pn(pnID);
    recName name(0);
    name.FSetIndID( indID );
    name.FSetTypeID( pn.FGetTypeID() );
    name.SetNextSequence();
    name.Save();

    recNamePartVec parts = pn.GetParts();
    for( size_t i = 0 ; i < parts.size() ; i++ ) {
        recNamePart p(parts[i]);
        p.FSetID( 0 );
        p.FSetNameID( name.FGetID() );
        p.FSetValue( p.FGetValue().Capitalize() );
        p.Save();
    }
    return name.FGetID();
}

bool recName::FindPersona( idt perID, idt styleID )
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    sql.Format(
        "SELECT id FROM Name WHERE per_id=" ID " AND style_id=" ID " "
        "ORDER BY sequence;",
        perID, styleID
    );
    result = s_db->GetTable( sql );

    if( result.GetRowCount() != 1 )
    {
        Clear();
        return false;
    }
    result.SetRow( 0 );
    f_id   = GET_ID( result.GetInt64( 0 ) );
    Read();
    return true;
}

recNamePartVec recName::GetParts( idt nameID )
{
    recNamePartVec list;
    recNamePart part;
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( nameID == 0 ) {
        return list;
    }

    sql.Format(
        "SELECT id, type_id, val, sequence FROM NamePart "
        "WHERE name_id=" ID " ORDER BY sequence;",
        nameID
    );
    result = s_db->GetTable( sql );

    part.f_name_id = nameID;
    for( int i = 0 ; i < result.GetRowCount() ; i++ )
    {
        result.SetRow( i );
        part.f_id = GET_ID( result.GetInt64( 0 ) );
        part.f_type_id = GET_ID( result.GetInt64( 1 ) );
        part.f_val      = result.GetAsString( 2 );
        part.f_sequence = (unsigned) result.GetInt( 3 );
        list.push_back( part );
    }
    return list;
}


//============================================================================
//-------------------------[ recNamePart ]------------------------------------
//============================================================================

recNamePart::recNamePart( const recNamePart& n )
{
    f_id       = n.f_id;
    f_name_id  = n.f_name_id;
    f_type_id  = n.f_type_id;
    f_val      = n.f_val;
    f_sequence = n.f_sequence;
}

void recNamePart::Clear()
{
    f_id       = 0;
    f_name_id  = 0;
    f_type_id  = 0;
    f_val      = wxEmptyString;
    f_sequence = 0;
}

void recNamePart::Save()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 )
    {
        // Add new record
        sql.Format(
            "INSERT INTO NamePart (name_id, type_id, val, sequence)"
            "VALUES (" ID ", " ID ", '%q', %d);",
            f_name_id, f_type_id, UTF8_(f_val), f_sequence
        );
        s_db->ExecuteUpdate( sql );
        f_id = GET_ID( s_db->GetLastRowId() );
    } else {
        // Does record exist
        if( !Exists() )
        {
            // Add new record
            sql.Format(
                "INSERT INTO NamePart (id, name_id, type_id, val, sequence)"
                "VALUES (" ID ", " ID ", " ID ", '%q', %d);",
                f_id, f_name_id, f_type_id, UTF8_(f_val), f_sequence
            );
        } else {
            // Update existing record
            sql.Format(
                "UPDATE NamePart SET name_id=" ID ", type_id=" ID ", val='%q', sequence=%d "
                "WHERE id=" ID ";",
                f_name_id, f_type_id, UTF8_(f_val), f_sequence, f_id
            );
        }
        s_db->ExecuteUpdate( sql );
    }
}

bool recNamePart::Read()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 ) {
        Clear();
        return false;
    }

    sql.Format(
        "SELECT name_id, type_id, val, sequence "
        "FROM NamePart WHERE id=" ID ";",
        f_id
    );
    result = s_db->GetTable( sql );

    if( result.GetRowCount() != 1 )
    {
        Clear();
        return false;
    }
    result.SetRow( 0 );
    f_name_id  = GET_ID( result.GetInt64( 0 ) );
    f_type_id  = GET_ID( result.GetInt64( 1 ) );
    f_val      = result.GetAsString( 2 );
    f_sequence = (unsigned) result.GetInt( 3 );
    return true;
}

wxString recNamePart::GetValue( idt id )
{
    if( id == 0 ) return wxEmptyString;

    wxSQLite3StatementBuffer sql;
    sql.Format( "SELECT val FROM NamePart WHERE id=" ID ";", id );
    wxSQLite3Table result = s_db->GetTable( sql );

    if( result.GetRowCount() == 0 )
    {
        return wxEmptyString;
    }
    return result.GetAsString( 0 );
}

/*! Takes a space delimited list from str and converts it to a list of
 *  of Attributes in sequencial order of given type.
 */
recNamePartVec recNamePart::ConvertStrToList(
    const wxString& str, idt type )
{
    recNamePartVec list;
    recNamePart name(0);
    name.f_type_id = type;

    wxStringTokenizer tk( str );
    while( tk.HasMoreTokens() ) {
        name.f_val = tk.GetNextToken();
        ++name.f_sequence;
        list.push_back( name );
    }
    return list;
}


//============================================================================
//-------------------------[ recNamePartType ]--------------------------------
//============================================================================

recNamePartType::recNamePartType( const recNamePartType& at )
{
    f_id   = at.f_id;
    f_grp  = at.f_grp;
    f_name = at.f_name;
}

void recNamePartType::Clear()
{
    f_id   = 0;
    f_grp  = NTYPE_Grp_Unstated;
    f_name = wxEmptyString;
}

void recNamePartType::Save()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 )
    {
        // Add new record
        sql.Format(
            "INSERT INTO NamePartType (grp, name) VALUES (%d, '%q');",
            f_grp, UTF8_(f_name)
        );
        s_db->ExecuteUpdate( sql );
        f_id = GET_ID( s_db->GetLastRowId() );
    } else {
        // Does record exist
        if( !Exists() )
        {
            // Add new record
            sql.Format(
                "INSERT INTO NamePartType (id, grp, name) "
                "VALUES (" ID ", %d, '%q');",
                f_id, f_grp, UTF8_(f_name)
            );
        } else {
            // Update existing record
            sql.Format(
                "UPDATE NamePartType SET grp=%d, name='%q' WHERE id=" ID ";",
                f_grp, UTF8_(f_name), f_id
            );
        }
        s_db->ExecuteUpdate( sql );
    }
}

bool recNamePartType::Read()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 ) {
        Clear();
        return false;
    }

    sql.Format( "SELECT grp, name FROM NamePartType WHERE id=" ID ";", f_id );
    result = s_db->GetTable( sql );

    if( result.GetRowCount() != 1 )
    {
        Clear();
        return false;
    }
    result.SetRow( 0 );
    f_grp  = (NTYPE_Grp) result.GetInt( 0 );
    f_name = result.GetAsString( 1 );
    return true;
}

wxString recNamePartType::GetTypeStr( idt id )
{
    recNamePartType npt( id );
    return npt.f_name;
}

recNamePartTypeVec recNamePartType::GetTypeList()
{
    recNamePartType at;
    recNamePartTypeVec list;
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;
    int i;

    // Put standard entries in list.
    sql.Format(
        "SELECT id, grp, name FROM NamePartType "
        "WHERE id<0 ORDER BY id DESC;"
    );
    result = s_db->GetTable( sql );

    for( i = 0 ; i < result.GetRowCount() ; i++ ) {
        result.SetRow( i );
        at.f_id = GET_ID( result.GetInt64( 0 ) );
        at.f_grp = (NTYPE_Grp) result.GetInt( 1 );
        at.f_name = result.GetAsString( 2 );
        list.push_back( at );
    }

    // Put user entries in list.
    sql.Format(
        "SELECT id, grp, name FROM NamePartType "
        "WHERE id>0 ORDER BY id ASC;"
    );
    result = s_db->GetTable( sql );

    for( i = 0 ; i < result.GetRowCount() ; i++ ) {
        result.SetRow( i );
        at.f_id = GET_ID( result.GetInt64( 0 ) );
        at.f_grp = (NTYPE_Grp) result.GetInt( 1 );
        at.f_name = result.GetAsString( 2 );
        list.push_back( at );
    }

    return list;
}


//============================================================================
//-------------------------[ recNameStyle ]-----------------------------------
//============================================================================

recNameStyle::recNameStyle( const recNameStyle& at )
{
    f_id   = at.f_id;
    f_name = at.f_name;
}

void recNameStyle::Clear()
{
    f_id   = 0;
    f_name = wxEmptyString;
}

void recNameStyle::Save()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 )
    {
        // Add new record
        sql.Format(
            "INSERT INTO NameStyle (name) VALUES ('%q');",
            UTF8_(f_name)
        );
        s_db->ExecuteUpdate( sql );
        f_id = GET_ID( s_db->GetLastRowId() );
    } else {
        // Does record exist
        if( !Exists() )
        {
            // Add new record
            sql.Format(
                "INSERT INTO NameStyle (id, name) "
                "VALUES (" ID ", '%q');",
                f_id, UTF8_(f_name)
            );
        } else {
            // Update existing record
            sql.Format(
                "UPDATE NameStyle SET name='%q' WHERE id=" ID ";",
                UTF8_(f_name), f_id
            );
        }
        s_db->ExecuteUpdate( sql );
    }
}

bool recNameStyle::Read()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 ) {
        Clear();
        return false;
    }

    sql.Format( "SELECT name FROM NameStyle WHERE id=" ID ";", f_id );
    result = s_db->GetTable( sql );

    if( result.GetRowCount() != 1 )
    {
        Clear();
        return false;
    }
    result.SetRow( 0 );
    f_name = result.GetAsString( 0 );
    return true;
}

wxString recNameStyle::GetStyleStr( idt id )
{
    recNameStyle at( id );
    return at.f_name;
}

recNameStyleVec recNameStyle::GetStyleList()
{
    recNameStyle at;
    recNameStyleVec list;
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;
    int i;

    // Put standard entries in list.
    sql.Format(
        "SELECT id, name FROM NameStyle "
        "WHERE id<=0 ORDER BY id DESC;"
    );
    result = s_db->GetTable( sql );

    for( i = 0 ; i < result.GetRowCount() ; i++ ) {
        result.SetRow( i );
        at.f_id = GET_ID( result.GetInt64( 0 ) );
        at.f_name = result.GetAsString( 1 );
        list.push_back( at );
    }

    // Put user entries in list.
    sql.Format(
        "SELECT id, name FROM NameStyle "
        "WHERE id>0 ORDER BY id ASC;"
    );
    result = s_db->GetTable( sql );

    for( i = 0 ; i < result.GetRowCount() ; i++ ) {
        result.SetRow( i );
        at.f_id = GET_ID( result.GetInt64( 0 ) );
        at.f_name = result.GetAsString( 1 );
        list.push_back( at );
    }

    return list;
}


// End of src/rec/recName.cpp file
