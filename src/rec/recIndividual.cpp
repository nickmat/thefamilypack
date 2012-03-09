/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        recIndividual.cpp
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Manage SQLite3 Family, FamilyIndividual and Individual records.
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

#include <rec/recIndividual.h>
#include <rec/recDate.h>
#include <rec/recPlace.h>
#include <rec/recEvent.h>
#include <rec/recPersona.h>
#include <rec/recName.h>


recIndividual::recIndividual( const recIndividual& i )
{
    f_id          = i.f_id;
    f_surname     = i.f_surname;
    f_given       = i.f_given;
    f_epitaph     = i.f_epitaph;
    f_fam_id      = i.f_fam_id;
    f_per_id      = i.f_per_id;
}

void recIndividual::Clear()
{
    f_id          = 0;
    f_surname     = wxEmptyString;
    f_given       = wxEmptyString;
    f_epitaph     = wxEmptyString;
    f_fam_id      = 0;
    f_per_id      = 0;
}

void recIndividual::Save()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    UpdateDateEpitaph(); // Ensure date epitaph is up todate

    if( f_id == 0 )
    {
        // Add new record
        sql.Format(
            "INSERT INTO Individual (surname, given, epitaph, "
            "fam_id, per_id) VALUES "
            "('%q', '%q', '%q', "ID", "ID");",
            UTF8_(f_surname), UTF8_(f_given), UTF8_(f_epitaph),
            f_fam_id, f_per_id
        );
        s_db->ExecuteUpdate( sql );
        f_id = GET_ID( s_db->GetLastRowId() );
    } else {
        // Does record exist
        if( !Exists() )
        {
            // Add new record
            sql.Format(
                "INSERT INTO Individual (id, surname, given, epitaph, "
                "fam_id, per_id) "
                "VALUES ("ID", '%q', '%q', '%q', "ID", "ID");",
                f_id, UTF8_(f_surname), UTF8_(f_given), UTF8_(f_epitaph),
                f_fam_id, f_per_id
            );
        } else {
            // Update existing record
            sql.Format(
                "UPDATE Individual SET surname='%q', given='%q', "
                "epitaph='%q', fam_id="ID", per_id="ID" WHERE id="ID";",
                UTF8_(f_surname), UTF8_(f_given), UTF8_(f_epitaph),
                f_fam_id, f_per_id, f_id
            );
        }
        s_db->ExecuteUpdate( sql );
    }
}

bool recIndividual::Read()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 ) {
        Clear();
        return false;
    }

    sql.Format(
        "SELECT surname, given, epitaph, fam_id, per_id "
        "FROM Individual WHERE id="ID";", f_id
    );
    result = s_db->GetTable( sql );

    if( result.GetRowCount() != 1 )
    {
        Clear();
        return false;
    }
    result.SetRow( 0 );
    f_surname     = result.GetAsString( 0 );
    f_given       = result.GetAsString( 1 );
    f_epitaph     = result.GetAsString( 2 );
    f_fam_id      = GET_ID( result.GetInt64( 3 ) );
    f_per_id      = GET_ID( result.GetInt64( 4 ) );
    return true;
}

bool recIndividual::ReadPersona( idt perID )
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 ) {
        Clear();
        return false;
    }

    sql.Format(
        "SELECT id, surname, given, epitaph, fam_id "
        "FROM Individual WHERE per_id="ID";", perID
    );
    result = s_db->GetTable( sql );

    if( result.GetRowCount() != 1 )
    {
        Clear();
        return false;
    }
    f_per_id = perID;
    result.SetRow( 0 );
    f_id          = GET_ID( result.GetInt64( 0 ) );
    f_surname     = result.GetAsString( 1 );
    f_given       = result.GetAsString( 2 );
    f_epitaph     = result.GetAsString( 3 );
    f_fam_id      = GET_ID( result.GetInt64( 4 ) );
    return true;
}

void recIndividual::UpdateDateEpitaph()
{
    f_epitaph = recPersona::GetDateEpitaph( f_per_id );
}

void recIndividual::UpdateNames()
{
    if( f_per_id == 0 ) return;

    idt nameID = recPersona::GetDefaultNameID( f_per_id );
    f_surname = recName::GetSurname( nameID );
    if( f_surname.length() == 0 ) f_surname = "?";
    f_given = recName::GetNamePartStr( nameID, NAME_TYPE_Given_name );
    if( f_given.length() == 0 ) f_given = "?";
}

void recIndividual::Update()
{
    recPersona per( f_per_id );

    f_epitaph = per.GetDateEpitaph();

    idt nameID = per.GetDefaultNameID();
    f_surname = recName::GetSurname( nameID );
    if( f_surname.length() == 0 ) f_surname = "?";
    f_given = recName::GetNamePartStr( nameID, NAME_TYPE_Given_name );
    if( f_given.length() == 0 ) f_given = "?";
}

wxString recIndividual::GetFullName( idt id )
{
    wxString str;
    wxSQLite3StatementBuffer sql;
    wxSQLite3ResultSet result;

    sql.Format( "SELECT surname, given FROM Individual WHERE id="ID";", id );
    result = s_db->ExecuteQuery( sql );
    str << result.GetAsString( 1 ) << " " << result.GetAsString( 0 );
    return str;
}

wxString recIndividual::GetSurname( idt id )
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3ResultSet result;

    sql.Format( "SELECT surname FROM Individual WHERE id="ID";", id );
    result = s_db->ExecuteQuery( sql );
    return result.GetAsString( 0 );
}

wxString recIndividual::GetDateEpitaph( idt id )
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3ResultSet result;

    sql.Format( "SELECT epitaph FROM Individual WHERE id="ID";", id );
    result = s_db->ExecuteQuery( sql );
    return result.GetAsString( 0 );
}

wxString recIndividual::GetFullNameEpitaph( idt id )
{
    wxString str;
    wxSQLite3StatementBuffer sql;
    wxSQLite3ResultSet result;

    sql.Format( "SELECT surname, given, epitaph FROM Individual WHERE id="ID";", id );
    result = s_db->ExecuteQuery( sql );
    str << result.GetAsString( 1 ) << " " << result.GetAsString( 0 );
    wxString dates = result.GetAsString( 2 );
    if( !dates.IsEmpty() ) {
        str << " " << dates;
    }

    return str;
}


recFamilyVec recIndividual::GetFamilyList( idt ind )
{
    recFamilyVec families;
    recFamily family;
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( ind == 0 ) return families;

    sql.Format(
        "SELECT id, husb_id, wife_id FROM Family "
        "WHERE husb_id="ID" OR wife_id="ID";",
        ind, ind
    );
    result = s_db->GetTable( sql );

    for( int i = 0 ; i < result.GetRowCount() ; i++ ) {
        result.SetRow( i );
        family.f_id = GET_ID( result.GetInt64( 0 ) );
        family.f_husb_id = GET_ID( result.GetInt64( 1 ) );
        family.f_wife_id = GET_ID( result.GetInt64( 2 ) );
        families.push_back( family );
    }
    return families;
}

recFamilyVec recIndividual::GetParentList( idt indID )
{
    recFamily parent;
    recFamilyVec parents;
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( indID == 0 ) return parents;

    sql.Format(
        "SELECT F.id, F.husb_id, F.wife_id "
        "FROM Family F, FamilyIndividual FI "
        "WHERE F.id=FI.fam_id AND FI.ind_id="ID";",
        indID
    );
    result = s_db->GetTable( sql );

    for( int i = 0 ; i < result.GetRowCount() ; i++ ) {
        result.SetRow( i );
        parent.f_id = GET_ID( result.GetInt64( 0 ) );
        parent.f_husb_id = GET_ID( result.GetInt64( 1 ) );
        parent.f_wife_id = GET_ID( result.GetInt64( 2 ) );
        parents.push_back( parent );
    }
    return parents;
}

wxSQLite3Table recIndividual::GetRefEventsTable( idt perID )
{
    wxSQLite3StatementBuffer sql;

    sql.Format(
        "SELECT DISTINCT event_id, role_id FROM EventPersona "
        "INNER JOIN "
        "(SELECT ref_per_id FROM LinkPersona WHERE ind_per_id="ID") "
        "ON EventPersona.per_id=ref_per_id "
        "ORDER BY EventPersona.sequence;",
        perID
    );
    return s_db->GetTable( sql );
}

wxSQLite3Table recIndividual::GetRefAttributesTable( idt perID )
{
    wxSQLite3StatementBuffer sql;

    sql.Format(
        "SELECT DISTINCT id, type_id, val FROM Attribute "
        "INNER JOIN "
        "(SELECT ref_per_id FROM LinkPersona WHERE ind_per_id="ID") "
        "ON Attribute.per_id=ref_per_id;",
        perID
    );
    return s_db->GetTable( sql );
}

wxSQLite3Table recIndividual::GetReferencesTable( idt perID )
{
    wxSQLite3StatementBuffer sql;

    sql.Format(
        "SELECT R.id, R.title "
        "FROM LinkPersona LP, Persona P, Reference R "
        "WHERE LP.ind_per_id="ID" AND LP.ref_per_id=P.id AND P.ref_id=R.id;",
        perID
    );
    return s_db->GetTable( sql );
}

wxArrayString recIndividual::GetEventIdStrList( idt perID, idt etrID )
{
    wxArrayString list;
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( perID == 0 ) return list;

    sql.Format(
        "SELECT id, title, date1_id, place_id FROM Event "
        "WHERE id=("
        "SELECT event_id FROM EventPersona INNER JOIN "
        "(SELECT ref_per_id AS ipp FROM LinkPersona WHERE ind_per_id="ID") Mip "
        "ON per_id=Mip.ipp WHERE role_id=%d"
        ");",
        perID, etrID
    );
    result = s_db->GetTable( sql );

    for( int i = 0 ; i < result.GetRowCount() ; i++ ) {
        result.SetRow( i );
        list.Add( result.GetAsString( 0 ) );
        list.Add( result.GetAsString( 1 ) );
        list.Add( recDate::GetStr( GET_ID( result.GetInt64( 2 ) ) ) );
        list.Add( recPlace::GetAddressStr( GET_ID( result.GetInt64( 3 ) ) ) );
    }
    return list;
}

wxSQLite3ResultSet recIndividual::GetNameList( wxString surname )
{
    wxSQLite3StatementBuffer sql;

    if( surname.length() == 0 ) {
        // Full list
        sql.Format(
            "SELECT surname, given, epitaph, fam_id FROM Individual "
            "ORDER BY surname, given;"
        );
    } else if( surname.length() == 1 ) {
        // Name beginning with letter
        wxString name = surname + wxT("%");
        sql.Format(
            "SELECT surname, given, epitaph, fam_id FROM Individual "
            "WHERE surname LIKE '%q' ORDER BY surname, given;",
            UTF8_(name)
        );
    } else {
        // All matching the given surname
        sql.Format(
            "SELECT surname, given, epitaph, fam_id FROM Individual "
            "WHERE surname='%q' ORDER BY surname, given;",
            UTF8_(surname)
        );
    }
    return s_db->ExecuteQuery( sql );
}

wxSQLite3Table recIndividual::GetNameTable( Sex sex )
{
    wxSQLite3StatementBuffer sql;

    if( sex == SEX_Unstated ) {
        sql.Format(
            "SELECT id, surname, given, epitaph FROM Individual "
            "ORDER BY surname, given;"
        );
    } else {
        sql.Format(
            "SELECT I.id, surname, given, epitaph FROM Individual I, Persona P "
            "WHERE I.per_id=P.id AND P.sex=%d ORDER BY surname, given;", sex
        );
    }
    return s_db->GetTable( sql );
}

void recIndividual::AddMissingFamilies()
{
    wxSQLite3ResultSet result;
    recFamily fam(0);
    recIndividual ind;
    recPersona per;

    result = s_db->ExecuteQuery( "SELECT id FROM Individual WHERE fam_id=0;" );
    while( result.NextRow() ) {
        ind.f_id = GET_ID( result.GetInt64( 0 ) );
        ind.Read();
        per.f_id = ind.f_per_id;
        per.Read();
        fam.f_id = 0;
        if( per.f_sex == SEX_Female ) {
            fam.f_husb_id = 0;
            fam.f_wife_id = ind.f_id;
        } else {
            fam.f_husb_id = ind.f_id;
            fam.f_wife_id = 0;
        }
        fam.Save();
        ind.f_fam_id = fam.f_id;
        ind.Save();
    }
}

//----------------------------------------------------------

recFamily::recFamily( const recFamily& f )
{
    f_id       = f.f_id;
    f_husb_id  = f.f_husb_id;
    f_wife_id  = f.f_wife_id;
}

void recFamily::Clear()
{
    f_id       = 0;
    f_husb_id  = 0;
    f_wife_id  = 0;
}

void recFamily::Save()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 )
    {
        // Add new record
        sql.Format(
            "INSERT INTO Family (husb_id, wife_id) "
            "VALUES ("ID", "ID");",
            f_husb_id, f_wife_id
        );
        s_db->ExecuteUpdate( sql );
        f_id = GET_ID( s_db->GetLastRowId() );
    } else {
        // Does record exist
        if( !Exists() )
        {
            // Add new record
            sql.Format(
                "INSERT INTO Family (id, husb_id, wife_id) "
                "VALUES ("ID", "ID", "ID");",
                f_id, f_husb_id, f_wife_id
            );
        } else {
            // Update existing record
            sql.Format(
                "UPDATE Family SET husb_id="ID", wife_id="ID" "
                "WHERE id="ID";",
                f_husb_id, f_wife_id, f_id
            );
        }
        s_db->ExecuteUpdate( sql );
    }
}

bool recFamily::Read()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 ) {
        Clear();
        return false;
    }

    sql.Format(
        "SELECT husb_id, wife_id FROM Family WHERE id="ID";",
        f_id
    );
    result = s_db->GetTable( sql );

    if( result.GetRowCount() != 1 )
    {
        Clear();
        return false;
    }
    result.SetRow( 0 );
    f_husb_id  = GET_ID( result.GetInt64( 0 ) );
    f_wife_id  = GET_ID( result.GetInt64( 1 ) );
    return true;
}

idt recFamily::GetMarriageEvent() const
{
    return recPersona::GetMarriageEvent(
        recIndividual::GetPersona( f_husb_id ),
        recIndividual::GetPersona( f_wife_id )
    );
}

bool recFamily::ReadParents( idt ind )
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3ResultSet result;

    sql.Format(
        "SELECT fam_id FROM FamilyIndividual WHERE ind_id="ID";", ind
    );
    result = s_db->ExecuteQuery( sql );
    f_id =  GET_ID( result.GetInt64( 0 ) );
    return Read();
}

recIndividualList recFamily::GetChildren( idt fam )
{
    recIndividualList children;
    recIndividual ind;
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( fam == 0 ) return children;

    sql.Format(
        "SELECT ind_id FROM FamilyIndividual WHERE fam_id="ID" "
        "ORDER BY seq_child ASC;", fam
    );
    result = s_db->GetTable( sql );

    for( int i = 0 ; i < result.GetRowCount() ; i++ )
    {
        result.SetRow( i );
        ind.f_id = GET_ID( result.GetInt64( 0 ) );
        ind.Read();
        children.push_back( ind );
    }
    return children;
}

recIdList recFamily::GetChildrenIds( idt fam )
{
    recIdList children;
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( fam == 0 ) return children;

    sql.Format(
        "SELECT ind_id FROM FamilyIndividual WHERE fam_id="ID" "
        "ORDER BY seq_child ASC;", fam
    );
    result = s_db->GetTable( sql );

    for( int i = 0 ; i < result.GetRowCount() ; i++ )
    {
        result.SetRow( i );
        children.push_back( GET_ID( result.GetInt64( 0 ) ) );
    }
    return children;
}

int recFamily::GetChildNextSequence( idt famID )
{
    wxSQLite3StatementBuffer sql;

    sql.Format(
        "SELECT MAX(seq_child) FROM FamilyIndividual WHERE fam_id="ID";",
        famID
    );
    return s_db->ExecuteScalar( sql ) + 1;
}

int recFamily::GetParentNextSequence( idt indID )
{
    wxSQLite3StatementBuffer sql;

    sql.Format(
        "SELECT MAX(seq_parent) FROM FamilyIndividual WHERE ind_id="ID";",
        indID
    );
    return s_db->ExecuteScalar( sql ) + 1;
}

recFamIndVec recFamily::GetChildLinks( idt famID )
{
    recFamIndVec ChildLinks;
    recFamilyIndividual fi;
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( famID == 0 ) return ChildLinks;

    sql.Format(
        "SELECT id, ind_id, seq_child, seq_parent FROM FamilyIndividual"
        " WHERE fam_id="ID" ORDER BY seq_child ASC;", famID
    );
    result = s_db->GetTable( sql );

    fi.fSetFamID( famID );
    for( int i = 0 ; i < result.GetRowCount() ; i++ )
    {
        result.SetRow( i );
        fi.fSetID( GET_ID( result.GetInt64( 0 ) ) );
        fi.fSetIndID( GET_ID( result.GetInt64( 1 ) ) );
        fi.fSetSeqChild( result.GetInt( 2 ) );
        fi.fSetSeqParent( result.GetInt( 3 ) );
        ChildLinks.push_back( fi );
    }
    return ChildLinks;
}

wxArrayString recFamily::GetMarriageEventTable() const
{
    wxArrayString list;
    if( f_id == 0 ) return list;
    if( f_husb_id == 0 && f_wife_id == 0 ) return list;
    idt husbPerID = recIndividual::GetPersona( f_husb_id );
    idt wifePerID = recIndividual::GetPersona( f_wife_id );
    if( husbPerID == 0 ) {
        return recIndividual::GetEventIdStrList( wifePerID, recEventTypeRole::ROLE_Marriage_Bride );
    }
    if( wifePerID == 0 ) {
        return recIndividual::GetEventIdStrList( husbPerID, recEventTypeRole::ROLE_Marriage_Groom );
    }

    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;
    sql.Format(
        "SELECT id, title, date1_id, place_id FROM Event "
        "WHERE id=("
        "SELECT event_id FROM EventPersona WHERE per_id="ID" AND role_id=%d "
        "INTERSECT "
        "SELECT event_id FROM EventPersona WHERE per_id="ID" AND role_id=%d "
        ");",
        husbPerID, recEventTypeRole::ROLE_Marriage_Groom,
        wifePerID, recEventTypeRole::ROLE_Marriage_Bride
    );
    result = s_db->GetTable( sql );

    for( int i = 0 ; i < result.GetRowCount() ; i++ )
    {
        result.SetRow( i );
        list.Add( result.GetAsString( 0 ) );
        list.Add( result.GetAsString( 1 ) );
        list.Add( recDate::GetStr( GET_ID( result.GetInt64( 2 ) ) ) );
        list.Add( recPlace::GetAddressStr( GET_ID( result.GetInt64( 3 ) ) ) );
    }
    return list;
}

//============================================================================
//-------------------------[ recFamilyIndividual ]----------------------------
//============================================================================

recFamilyIndividual::recFamilyIndividual( const recFamilyIndividual& fi )
{
    f_id         = fi.f_id;
    f_ind_id     = fi.f_ind_id;
    f_fam_id     = fi.f_fam_id;
    f_seq_child  = fi.f_seq_child;
    f_seq_parent = fi.f_seq_parent;
}

void recFamilyIndividual::Clear()
{
    f_id         = 0;
    f_ind_id     = 0;
    f_fam_id     = 0;
    f_seq_child  = 0;
    f_seq_parent = 0;
}

void recFamilyIndividual::Save()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 )
    {
        // Add new record
        sql.Format(
            "INSERT INTO FamilyIndividual (fam_id, ind_id, seq_child, seq_parent)"
            " VALUES ("ID", "ID", %d, %d);",
            f_fam_id, f_ind_id, f_seq_child, f_seq_parent
        );
        s_db->ExecuteUpdate( sql );
        f_id = GET_ID( s_db->GetLastRowId() );
    } else {
        // Does record exist
        if( !Exists() )
        {
            // Add new record
            sql.Format(
                "INSERT INTO FamilyIndividual (id, fam_id, ind_id, seq_child, seq_parent)"
                " VALUES ("ID", "ID", "ID", %d, %d);",
                f_id, f_fam_id, f_ind_id, f_seq_child, f_seq_parent
            );
        } else {
            // Update existing record
            sql.Format(
                "UPDATE FamilyIndividual SET fam_id="ID", ind_id="ID","
                " seq_child=%d, seq_parent=%d"
                " WHERE id="ID";",
                f_fam_id, f_ind_id, f_seq_child, f_seq_parent, f_id
            );
        }
        s_db->ExecuteUpdate( sql );
    }
}

bool recFamilyIndividual::Read()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_id == 0 ) {
        Clear();
        return false;
    }

    sql.Format(
        "SELECT ind_id, fam_id, seq_child, seq_parent FROM FamilyIndividual "
        "WHERE id="ID";", f_id
    );
    result = s_db->GetTable( sql );

    if( result.GetRowCount() != 1 )
    {
        Clear();
        return false;
    }
    result.SetRow( 0 );
    f_ind_id     = GET_ID( result.GetInt64( 0 ) );
    f_fam_id     = GET_ID( result.GetInt64( 1 ) );
    f_seq_child  = result.GetInt( 2 );
    f_seq_parent = result.GetInt( 3 );
    return true;
}

bool recFamilyIndividual::Find()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( f_fam_id == 0 || f_ind_id == 0 ) return false; // Only find single record

    sql.Format(
        "SELECT id, seq_child, seq_parent FROM FamilyIndividual "
        "WHERE fam_id="ID" AND ind_id="ID";",
        f_fam_id, f_ind_id
    );
    result = s_db->GetTable( sql );

    if( result.GetRowCount() == 0 ) {
        f_id = 0;
        f_seq_child = 0;
        f_seq_parent = 0;
        return true;
    }
    result.SetRow( 0 );
    f_id         = GET_ID( result.GetInt64( 0 ) );
    f_seq_child  = result.GetInt( 1 );
    f_seq_parent = result.GetInt( 2 );
    if( result.GetRowCount() != 1 ) return false;
    return true;
}

// End of recIndividual.cpp file
