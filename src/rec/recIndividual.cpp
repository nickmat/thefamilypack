/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        recIndividual.cpp
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Manage SQLite3 Family, FamilyIndividual and Individual records.
 * Author:      Nick Matthews
 * Website:     http://thefamilypack.org
 * Created:     3 October 2010
 * Copyright:   Copyright (c) 2010 ~ 2018, Nick Matthews.
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

#include <wx/tokenzr.h>


//============================================================================
//-------------------------[ recIndividual ]----------------------------------
//============================================================================

recIndividual::recIndividual( const recIndividual& i )
{
    f_id      = i.f_id;
    f_sex     = i.f_sex;
    f_fam_id  = i.f_fam_id;
    f_note    = i.f_note;
    f_privacy = i.f_privacy;
    f_name    = i.f_name;
    f_surname = i.f_surname;
    f_epitaph = i.f_epitaph;
}

void recIndividual::Clear()
{
    f_id      = 0;
    f_sex     = SEX_Unstated;
    f_fam_id  = 0;
    f_note    = wxEmptyString;
    f_privacy = 0;
    f_name    = wxEmptyString;
    f_surname = wxEmptyString;
    f_epitaph = wxEmptyString;
}

void recIndividual::Save()
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    UpdateEpitaph(); // Ensure date epitaph is up todate

    if( f_id == 0 )
    {
        // Add new record
        sql.Format(
            "INSERT INTO Individual"
            " (sex, fam_id, note, privacy, name, surname, epitaph)"
            " VALUES (%u, " ID ", '%q', %d, '%q', '%q', '%q');",
            f_sex, f_fam_id, UTF8_(f_note), f_privacy,
            UTF8_(f_name), UTF8_(f_surname), UTF8_(f_epitaph)
        );
        s_db->ExecuteUpdate( sql );
        f_id = GET_ID( s_db->GetLastRowId() );
    } else {
        // Does record exist
        if( !Exists() )
        {
            // Add new record
            sql.Format(
                "INSERT INTO Individual"
                " (id, sex, fam_id, note, privacy, name, surname, epitaph)"
                " VALUES (" ID ", %u, " ID ", '%q', %d, '%q', '%q', '%q');",
                f_id, f_sex, f_fam_id, UTF8_(f_note), f_privacy,
                UTF8_(f_name), UTF8_(f_surname), UTF8_(f_epitaph)
            );
        } else {
            // Update existing record
            sql.Format(
                "UPDATE Individual"
                " SET sex=%u, fam_id=" ID ", note='%q', privacy=%d,"
                " name='%q', surname='%q', epitaph='%q'"
                " WHERE id=" ID ";",
                f_sex, f_fam_id, UTF8_(f_note), f_privacy,
                UTF8_(f_name), UTF8_(f_surname), UTF8_(f_epitaph), f_id
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
        "SELECT sex, fam_id, note, privacy, name, surname, epitaph"
        " FROM Individual WHERE id=" ID ";", f_id
    );
    result = s_db->GetTable( sql );

    if( result.GetRowCount() != 1 )
    {
        Clear();
        return false;
    }
    result.SetRow( 0 );
    f_sex     = (Sex) result.GetInt( 0 );
    f_fam_id  = GET_ID( result.GetInt64( 1 ) );
    f_note    = result.GetAsString( 2 );
    f_privacy = result.GetInt( 3 );
    f_name    = result.GetAsString( 4 );
    f_surname = result.GetAsString( 5 );
    f_epitaph = result.GetAsString( 6 );
    return true;
}

recIndividualVec recIndividual::ReadVec( unsigned sexfilter )
{
    wxString query =
        "SELECT id, sex, fam_id, note, privacy, name, surname, epitaph FROM ";
    wxString queryMid = "Individual WHERE ";
    if( sexfilter == recInd_FILTER_SexAll ) {
        query << "Individual ";
    } else if( sexfilter == recInd_FILTER_SexMalePlus ) {
        query << queryMid << "NOT sex=2 ";
    } else if( sexfilter == recInd_FILTER_SexFemalePlus ) {
        query << queryMid << "NOT sex=1 ";
    } else {
        bool started = false;
        query << queryMid;
        if( sexfilter & recInd_FILTER_SexUnstated ) {
            if( started ) query << "OR "; else started = true;
            query << "sex=0 ";
        }
        if( sexfilter & recInd_FILTER_SexMale ) {
            if( started ) query << "OR "; else started = true;
            query << "sex=1 ";
        }
        if( sexfilter & recInd_FILTER_SexFemale ) {
            if( started ) query << "OR "; else started = true;
            query << "sex=2 ";
        }
        if( sexfilter & recInd_FILTER_SexUnknown ) {
            if( started ) query << "OR "; else started = true;
            query << "sex=3 ";
        }
    }
    query << "ORDER BY surname, name, epitaph, id;";

    wxSQLite3ResultSet result = s_db->ExecuteQuery( query );

    recIndividual ind;
    recIndividualVec inds;
    while( result.NextRow() ) {
        ind.f_id      = GET_ID( result.GetInt64( 0 ) );
        ind.f_sex     = (Sex) result.GetInt( 1 );
        ind.f_fam_id  = GET_ID( result.GetInt64( 2 ) );
        ind.f_note    = result.GetAsString( 3 );
        ind.f_privacy = result.GetInt( 4 );
        ind.f_name    = result.GetAsString( 5 );
        ind.f_surname = result.GetAsString( 6 );
        ind.f_epitaph = result.GetAsString( 7 );
        inds.push_back( ind );
    }
    return inds;
}

recIdVec recIndividual::GetIdVec()
{
    return ExecuteIdVec( "SELECT id FROM Individual ORDER BY id;", 0 );
}

wxString recIndividual::GetDescriptionStr( idt indID )
{
    recIndividual ind(indID);
    if( ind.FGetID() == 0 ) {
        return wxEmptyString;
    }
    wxString name = ind.FGetName();
    if( name.size() == 0 ) {
        name = "? ?";
    }
    if( ind.FGetEpitaph().size() ) {
        return name + " " + ind.FGetEpitaph();
    }
    return name;
}

void recIndividual::UpdateEpitaph( idt indID )
{
    recIndividual ind(indID);
    ind.UpdateEpitaph();
    ind.Save();
}

void recIndividual::UpdateEpitaph()
{
    idt bDateID, dDateID;

    bDateID = recEvent::GetDate1ID( GetBirthEvent() );
    if( bDateID == 0 ) {
        bDateID = recEvent::GetDate1ID( GetNrBirthEvent() );
    }
    dDateID = recEvent::GetDate1ID( GetDeathEvent() );
    if( dDateID == 0 ) {
        dDateID = recEvent::GetDate1ID( GetNrDeathEvent() );
    }
    if( bDateID == 0 && dDateID == 0 ) {
        f_epitaph = wxEmptyString;
        return;
    }

    f_epitaph = "(";
    if( bDateID ) {
        f_epitaph << recDate::GetYear( bDateID );
    } else {
        f_epitaph << " ";
    }
    f_epitaph << " - ";
    if( dDateID ) {
        f_epitaph << recDate::GetYear( dDateID );
    } else {
        f_epitaph << " ";
    }
    f_epitaph << ")";
}

void recIndividual::UpdateNames()
{
    idt nameID = GetNameID();
    f_surname = recName::GetSurname( nameID );
    if( f_surname.length() == 0 ) f_surname = "?";
    f_name = recName::GetNameStr( nameID );
    if( f_name.length() == 0 ) f_name = "? ?";
}

void recIndividual::UpdateDefaultFamily()
{
    recFamilyVec families = GetFamilyList();
    if( families.size() == 0 ) {
        // Create a new family.
        recFamily fam( 0 );
        if ( f_sex == SEX_Female ) {
            fam.FSetWifeID( f_id );
        } else {
            fam.FSetHusbID( f_id );
        }
        fam.Save();
        f_fam_id = fam.FGetID();
        return;
    }
    for( size_t i = 0 ; i < families.size() ; i++ ) {
        if( families[i].FGetID() == f_fam_id ) {
            return;
        }
    }
    f_fam_id = families[0].FGetID();
}

void recIndividual::Update()
{
    UpdateDefaultFamily();
    UpdateNames();
    UpdateEpitaph();
}

void recIndividual::Update( idt indID )
{
    if( indID ) {
        recIndividual ind(indID);
        ind.Update();
        ind.Save();
    }
}

Sex recIndividual::GetSex( idt indID )
{
    if( indID == 0 ) {
        return SEX_Unstated;
    }
    int i = ExecuteInt( "SELECT sex FROM Individual WHERE id=" ID ";", indID );
    wxASSERT( i >= 0 && i <= SEX_Unknown );
    return Sex( i );
}

idt recIndividual::GetFamilyID( idt indID )
{
    if( indID == 0 ) {
        return 0;
    }
    return ExecuteID( "SELECT fam_id FROM Individual WHERE id=" ID ";", indID );
}

int recIndividual::GetPrivacy( idt indID )
{
    if( indID == 0 ) {
        return 0;
    }
    return ExecuteInt( "SELECT privacy FROM Individual WHERE id=" ID ";", indID );
}

wxString recIndividual::GetName( idt indID )
{
    if( indID == 0 ) {
        return wxEmptyString;
    }
    return ExecuteStr( "SELECT name FROM Individual WHERE id=" ID ";", indID );
}

wxString recIndividual::GetSurname( idt indID )
{
    if( indID == 0 ) {
        return wxEmptyString;
    }
    return ExecuteStr( "SELECT surname FROM Individual WHERE id=" ID ";", indID );
}

wxString recIndividual::GetEpitaph( idt indID )
{
    if( indID == 0 ) {
        return wxEmptyString;
    }
    return ExecuteStr( "SELECT epitaph FROM Individual WHERE id=" ID ";", indID );
}

idt recIndividual::FindEvent( idt indID, idt roleID )
{
    if( indID == 0 || roleID == 0 ) return 0;

    wxSQLite3StatementBuffer sql;
    sql.Format(
        "SELECT event_id FROM IndividualEvent WHERE ind_id=" ID " AND role_id=" ID ";",
        indID, roleID
    );
    return ExecuteID( sql );
}

idt recIndividual::FindGroupEvent( idt indID, recET_GRP grp )
{
    if( indID == 0 || grp == recET_GRP_Unstated ) return 0;

    wxSQLite3StatementBuffer sql;
    sql.Format(
        "SELECT IE.event_id FROM IndividualEvent IE "
        "INNER JOIN "
        "(SELECT R.id AS rid FROM EventTypeRole R "
        "  INNER JOIN "
        "  EventType T ON R.type_id=T.id "
        "  WHERE T.grp=%d AND R.prime=1) "
        "ON rid=IE.role_id WHERE IE.ind_id=" ID " "
        "ORDER BY IE.ind_seq;",
        grp, indID
    );
    return ExecuteID( sql );
}

recIdVec recIndividual::FindEvents( idt indID, idt roleID )
{
    if ( indID == 0 || roleID == 0 ) return recIdVec();

    wxSQLite3StatementBuffer sql;
    sql.Format(
        "SELECT event_id FROM IndividualEvent WHERE ind_id=" ID " AND role_id=" ID ";",
        indID, roleID
    );
    return ExecuteIdVec( sql );
}

recIdVec recIndividual::FindGroupEvents( idt indID, recET_GRP grp )
{
    recIdVec eIDs;
    if( indID == 0 || grp == recET_GRP_Unstated ) {
        return eIDs;
    }

    wxSQLite3StatementBuffer sql;
    sql.Format(
        "SELECT IE.event_id FROM IndividualEvent IE "
        "INNER JOIN "
        "(SELECT R.id AS rid FROM EventTypeRole R "
        "  INNER JOIN "
        "  EventType T ON R.type_id=T.id "
        "  WHERE T.grp=%d AND R.prime=1) "
        "ON rid=IE.role_id WHERE IE.ind_id=" ID " "
        "ORDER BY IE.ind_seq;",
        grp, indID
    );

    wxSQLite3ResultSet result = s_db->ExecuteQuery( sql );
    while( result.NextRow() ) {
        eIDs.push_back( GET_ID( result.GetInt64( 0 ) ) );
    }
    return eIDs;
}

idt recIndividual::GetPersonalSummaryIE( idt indID, idt etID )
{
    if( indID == 0 || etID == 0 ) return 0;

    wxSQLite3StatementBuffer sql;
    sql.Format(
        "SELECT IE.id FROM IndividualEvent IE, EventTypeRole ET"
        " WHERE IE.role_id=ET.id AND IE.ind_id=" ID
        " AND ET.type_id=" ID " AND IE.higher_id=0;",
        indID, etID
    );
    return ExecuteID( sql );
}

idt recIndividual::GetPersonalSummaryEvent( idt indID, idt etID )
{
    if( indID == 0 || etID == 0 ) return 0;

    wxSQLite3StatementBuffer sql;
    sql.Format(
        "SELECT IE.event_id FROM IndividualEvent IE, EventTypeRole ET"
        " WHERE IE.role_id=ET.id AND IE.ind_id=" ID
        " AND ET.type_id=" ID " AND IE.higher_id=0;",
        indID, etID
    );
    return ExecuteID( sql );
}

idt recIndividual::CreateBirthDate( idt indID )
{
    recDate::TypePrefix prefix = recDate::PREF_Unstated;
    recEvent e( GetBirthEvent( indID ) );
    if( e.FGetID() == 0 ) {
        e.ReadID( GetNrBirthEvent( indID ) );
        prefix = recDate::PREF_OrBefore;
    }
    if( e.FGetDate1ID() == 0 ) {
        return 0; // No event or date found
    }
    recDate date( e.FGetDate1ID() );
    date.FSetID( 0 );
    date.FSetType( date.FGetType() | prefix );
    date.Save();
    return date.FGetID();
}

idt recIndividual::CreateDeathDate( idt indID )
{
    recDate::TypePrefix prefix = recDate::PREF_Unstated;
    recEvent e( GetDeathEvent( indID ) );
    if( e.FGetID() == 0 ) {
        e.ReadID( GetNrDeathEvent( indID ) );
        prefix = recDate::PREF_OrBefore;
    }
    if( e.FGetDate1ID() == 0 ) {
        return 0; // No event or date found
    }
    recDate date( e.FGetDate1ID() );
    date.FSetID( 0 );
    date.FSetType( date.FGetType() | prefix );
    date.Save();
    return date.FGetID();
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
        "WHERE husb_id=" ID " OR wife_id=" ID ";",
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
        "WHERE F.id=FI.fam_id AND FI.ind_id=" ID ";",
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

recIndEventVec recIndividual::GetEvents( idt indID, recEventOrder order )
{
    recIndEventVec list;
    recIndividualEvent record;
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( indID == 0 ) {
        return list;
    }
    wxString orderStr;
    switch( order )
    {
    case recEO_DatePt:
        orderStr = "date_pt, IE.ind_seq";
        break;
    case recEO_PerSeq:
        orderStr = "IE.ind_seq, date_pt";
        break;
    default:
        wxASSERT( false ); // Shouldn't be here
    }

    sql.Format(
        "SELECT IE.id, event_id, role_id, IE.note, ind_seq FROM IndividualEvent IE"
        " INNER JOIN Event E ON E.id=event_id"
        " WHERE IE.higher_id=0 AND ind_id=" ID " ORDER BY %s;",
        indID, UTF8_(orderStr)
    );
    result = s_db->GetTable( sql );

    list.reserve( result.GetRowCount() );
    record.f_ind_id = indID;
    record.f_higher_id = 0;
    for( int i = 0 ; i < result.GetRowCount() ; i++ )
    {
        result.SetRow( i );
        record.f_id       = GET_ID( result.GetInt64( 0 ) );
        record.f_event_id = GET_ID( result.GetInt64( 1 ) );
        record.f_role_id  = GET_ID( result.GetInt64( 2 ) );
        record.f_note     = result.GetAsString( 3 );
        record.f_ind_seq  = result.GetInt( 4 );
        list.push_back( record );
    }
    return list;
}

wxSQLite3ResultSet recIndividual::GetEventaSet( idt indID )
{
    wxSQLite3StatementBuffer sql;

    sql.Format(
        "SELECT eventa_id, role_id FROM"
        "   (SELECT DISTINCT eventa_id, role_id FROM EventaPersona EP"
        "  INNER JOIN"
        "   (SELECT per_id AS ip_per_id FROM IndividualPersona WHERE ind_id=" ID ")"
        "  ON EP.per_id=ip_per_id)"
        " INNER JOIN Eventa WHERE id=eventa_id"
        " ORDER BY date_pt;",
        indID
    );
    return s_db->ExecuteQuery( sql );
}

wxSQLite3ResultSet recIndividual::GetReferenceSet( idt indID )
{
    wxSQLite3StatementBuffer sql;

    sql.Format(
        "SELECT R.id, R.title "
        "FROM IndividualPersona IP, Persona P, Reference R "
        "WHERE IP.ind_id=" ID " AND IP.per_id=P.id AND P.ref_id=R.id;",
        indID
    );
    return s_db->ExecuteQuery( sql );
}

wxSQLite3ResultSet recIndividual::GetNameSet()
{
    return s_db->ExecuteQuery(
        "SELECT name, epitaph, id FROM Individual"
        " ORDER BY surname, name, epitaph;"
    );
}

recIndRelVec recIndividual::GetIndRelationships( idt indID )
{
    recIndRelVec rels;
    recIndRelationship rel(indID);

    recFamilyVec fams = GetParentList( indID );
    for( size_t i = 0 ; i < fams.size() ; i++ ) {
        rel.SetFamily( fams[i].FGetID() );
        if( fams[i].f_husb_id ) {
            rel.SetIndividual2( fams[i].f_husb_id );
            rel.SetType( recIndRelationship::IRT_Father );
            rels.push_back( rel );
        }
        if( fams[i].f_wife_id ) {
            rel.SetIndividual2( fams[i].f_wife_id );
            rel.SetType( recIndRelationship::IRT_Mother );
            rels.push_back( rel );
        }
    }
    fams = GetFamilyList( indID );
    rel.SetType( recIndRelationship::IRT_Child );
    for( size_t i = 0 ; i < fams.size() ; i++ ) {
        rel.SetFamily( fams[i].FGetID() );
        recIdVec children = fams[i].GetChildrenIds( fams[i].FGetID() );
        for( size_t j = 0 ; j < children.size() ; j++ ) {
            rel.SetIndividual2( children[j] );
            rels.push_back( rel );
        }
    }
    return rels;
}

int recIndividual::GetMaxEventSeqNumber( idt indID )
{
    wxSQLite3StatementBuffer sql;

    sql.Format(
        "SELECT MAX(ind_seq) FROM IndividualEvent WHERE ind_id=" ID ";",
        indID
    );
    return s_db->ExecuteScalar( sql );
}

bool recIndividual::CreateMissingFamilies()
{
    wxSQLite3ResultSet result =
        s_db->ExecuteQuery( "SELECT id, sex FROM Individual WHERE fam_id=0;" );

    while( result.NextRow() ) {
        idt indID = GET_ID( result.GetInt64( 0 ) );
        if( indID <= 0 ) continue;
        Sex sex = (Sex) result.GetInt( 1 );
        recFamily fam(0);
        if( sex == SEX_Female ) {
            fam.f_wife_id = indID;
        } else {
            fam.f_husb_id = indID;
        }
        fam.Save();
        recIndividual ind(indID);
        ind.f_fam_id = fam.FGetID();
        ind.Save();
    }
    return true;
}

void recIndividual::RemoveFromDatabase( idt indID )
{
    // TODO: Delete orphaned EventType and/or EventTypeRole
    // TODO: Remove ContactList if orphaned
    if( indID <= 0 ) {
        return;
    }

    recNameVec names = GetNames( indID );
    for ( size_t i = 0; i < names.size(); i++ ) {
        names[i].RemoveFromDatabase();
    }

    recFamilyVec families = GetFamilyList( indID );
    for ( size_t i = 0; i < families.size(); i++ ) {
        if ( families[i].f_husb_id == indID ) {
            families[i].f_husb_id = 0;
        }
        if ( families[i].f_wife_id == indID ) {
            families[i].f_wife_id = 0;
        }
        if ( families[i].f_husb_id == 0 && families[i].f_wife_id == 0 ) {
            families[i].RemoveFromDatabase();
        } else {
            families[i].Save();
        }
    }

    wxSQLite3StatementBuffer sql;
    sql.Format(
        "DELETE FROM FamilyIndividual WHERE ind_id=" ID " ;"
        "DELETE FROM IndividualEvent WHERE ind_id=" ID ";"
        "DELETE FROM IndividualPersona WHERE ind_id=" ID ";",
        indID, indID, indID
    );
    s_db->ExecuteUpdate( sql );

    Delete( indID );
}

//============================================================================
//-------------------------[ recFamily ]--------------------------------------
//============================================================================

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
            "VALUES (" ID ", " ID ");",
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
                "VALUES (" ID ", " ID ", " ID ");",
                f_id, f_husb_id, f_wife_id
            );
        } else {
            // Update existing record
            sql.Format(
                "UPDATE Family SET husb_id=" ID ", wife_id=" ID " "
                "WHERE id=" ID ";",
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
        "SELECT husb_id, wife_id FROM Family WHERE id=" ID ";",
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

recIdVec recFamily::GetCoupleAsIdVec() const
{
    recIdVec ids;
    if( f_husb_id ) {
        ids.push_back( f_husb_id );
    }
    if( f_wife_id ) {
        ids.push_back( f_wife_id );
    }
    return ids;
}

recIdVec recFamily::GetCoupleAsIdVec( idt famID )
{
    recFamily fam(famID);
    return fam.GetCoupleAsIdVec();
}

recIdVec recFamily::GetFamilyIdVec()
{
    recIdVec famIDs;
    wxSQLite3ResultSet result;

    result = s_db->ExecuteQuery( "SELECT id FROM Family;" );
    while( result.NextRow() ) {
        famIDs.push_back( GET_ID( result.GetInt64( 0 ) ) );
    }
    return famIDs;
}

recFamilyVec recFamily::GetFamilyVec()
{
    recFamilyVec fams;
    wxSQLite3ResultSet result;

    result = s_db->ExecuteQuery( "SELECT id, husb_id, wife_id FROM Family;" );

    recFamily fam(0);
    while( result.NextRow() ) {
        fam.f_id = GET_ID( result.GetInt64( 0 ) );
        fam.f_husb_id = GET_ID( result.GetInt64( 1 ) );
        fam.f_wife_id = GET_ID( result.GetInt64( 2 ) );
        fams.push_back( fam );
    }
    return fams;
}

// Decode the string which is in the form "Fx1" or
// "Fx1,x2,x3" where x1 is the Family id
// x2 is the husband id and x3 the wife id.
// or else string has the form FIx where x
// is a recIndividual id.
// Returns true if successful.
bool recFamily::Decode( const wxString& str )
{
    if( str.StartsWith( "FI" ) ) {
        idt indID = recGetID( str.Mid( 2 ) );
        f_id = recIndividual::GetFamilyID( indID );
        Read();
        if( f_id == 0 ) {
            Sex sex = recIndividual::GetSex( indID );
            if( sex == SEX_Female ) {
                f_wife_id = indID;
            } else {
                f_husb_id = indID;
            }
        }
    } else {
        wxStringTokenizer tk( str.Mid(1), "," );

        if( !tk.HasMoreTokens() ) return false;
        f_id = recGetID( tk.GetNextToken() );

        if( tk.HasMoreTokens() ) {
            f_husb_id = recGetID( tk.GetNextToken() );

            if( !tk.HasMoreTokens() ) return false;
            f_wife_id = recGetID( tk.GetNextToken() );
        } else {
            Read();
        }
    }
    return true;
}

idt recFamily::GetUnionEvent( idt famID )
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3ResultSet result;

    sql.Format(
        "SELECT FE.event_id FROM FamilyEvent FE, Event E, EventType ET"
        " WHERE FE.fam_id=" ID " AND FE.event_id=E.id AND E.type_id=ET.id"
        " AND ET.grp=3 ORDER BY FE.fam_seq",
        famID
    );
    result = s_db->ExecuteQuery( sql );
    if( result.NextRow() ) {
        return GET_ID( result.GetInt64( 0 ) );
    }
    return 0;
}

idt recFamily::GetSpouseID( idt indID ) const
{
    if( indID == f_husb_id ) {
        return f_wife_id;
    }
    if( indID == f_wife_id ) {
        return f_husb_id;
    }
    return 0;
}

idt recFamily::Find( idt ind1ID, idt ind2ID )
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3ResultSet result;

    sql.Format(
        "SELECT id FROM Family"
        " WHERE (husb_id=" ID " AND wife_id=" ID ") OR (husb_id=" ID " AND wife_id=" ID ");",
        ind1ID, ind2ID, ind2ID, ind1ID
    );
    result = s_db->ExecuteQuery( sql );
    if( result.NextRow() ) {
        return GET_ID( result.GetInt64( 0 ) );
    }
    return 0;
}

recIdVec recFamily::FindVec( const recIdVec& ind1IDs, const recIdVec& ind2IDs )
{
    recIdVec famIDs;
    for( size_t i = 0 ; i < ind1IDs.size() ; i++ ) {
        for( size_t j = 0 ; j < ind2IDs.size() ; j++ ) {
            idt famID;

            famID = recFamily::Find( ind1IDs[i], 0 );
            recIdVecAddIfUnique( famIDs, famID );
            famID = recFamily::Find( 0, ind2IDs[j] );
            recIdVecAddIfUnique( famIDs, famID );

            famID = recFamily::Find( ind1IDs[i], ind2IDs[j] );
            recIdVecAddIfUnique( famIDs, famID );
        }
    }
    return famIDs;
}


bool recFamily::ReadParents( idt ind )
{
    wxSQLite3StatementBuffer sql;
    wxSQLite3ResultSet result;

    sql.Format(
        "SELECT fam_id FROM FamilyIndividual WHERE ind_id=" ID ";", ind
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
        "SELECT ind_id FROM FamilyIndividual WHERE fam_id=" ID " "
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

recIdVec recFamily::GetChildrenIds( idt fam )
{
    recIdVec children;
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( fam == 0 ) return children;

    sql.Format(
        "SELECT ind_id FROM FamilyIndividual WHERE fam_id=" ID " "
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

int recFamily::GetChildCount( idt famID )
{
    wxSQLite3StatementBuffer sql;

    sql.Format(
        "SELECT COUNT(*) FROM FamilyIndividual WHERE fam_id=" ID ";",
        famID
    );
    return s_db->ExecuteScalar( sql );
}

int recFamily::GetChildNextSequence( idt famID )
{
    wxSQLite3StatementBuffer sql;

    sql.Format(
        "SELECT MAX(seq_child) FROM FamilyIndividual WHERE fam_id=" ID ";",
        famID
    );
    return s_db->ExecuteScalar( sql ) + 1;
}

int recFamily::GetParentNextSequence( idt indID )
{
    wxSQLite3StatementBuffer sql;

    sql.Format(
        "SELECT MAX(seq_parent) FROM FamilyIndividual WHERE ind_id=" ID ";",
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
        " WHERE fam_id=" ID " ORDER BY seq_child ASC;", famID
    );
    result = s_db->GetTable( sql );

    fi.FSetFamID( famID );
    for( int i = 0 ; i < result.GetRowCount() ; i++ )
    {
        result.SetRow( i );
        fi.FSetID( GET_ID( result.GetInt64( 0 ) ) );
        fi.FSetIndID( GET_ID( result.GetInt64( 1 ) ) );
        fi.FSetSeqChild( result.GetInt( 2 ) );
        fi.FSetSeqParent( result.GetInt( 3 ) );
        ChildLinks.push_back( fi );
    }
    return ChildLinks;
}

recFamilyEventVec recFamily::GetEvents( idt famID )
{
    recFamilyEventVec fes;
    recFamilyEvent fe;
    wxSQLite3StatementBuffer sql;
    wxSQLite3Table result;

    if( famID == 0 ) return fes;

    sql.Format(
        "SELECT id, event_id, note, fam_seq FROM FamilyEvent"
        " WHERE fam_id=" ID " ORDER BY fam_seq;", famID
    );
    result = s_db->GetTable( sql );

    fe.FSetFamID( famID );
    for( int i = 0 ; i < result.GetRowCount() ; i++ )
    {
        result.SetRow( i );
        fe.FSetID( GET_ID( result.GetInt64( 0 ) ) );
        fe.FSetEventID( GET_ID( result.GetInt64( 1 ) ) );
        fe.FSetNote( result.GetAsString( 2 ) );
        fe.FSetFamSeq( result.GetInt( 3 ) );
        fes.push_back( fe );
    }
    return fes;
}

recIdVec recFamily::GetEventIDs( idt famID )
{
    const char* fmt =
        "SELECT event_id FROM FamilyEvent"
        " WHERE fam_id=" ID
        " ORDER BY fam_seq;"
    ;
    return ExecuteIdVec( fmt, famID );
}

int recFamily::GetMaxEventSeqNumber( idt famID )
{
    wxSQLite3StatementBuffer sql;

    sql.Format(
        "SELECT MAX(fam_seq) FROM FamilyEvent WHERE fam_id=" ID ";",
        famID
    );
    return s_db->ExecuteScalar( sql );
}

// A singleton family is one without a partner, attached children
// or FamilyEvent's.
bool recFamily::IsSingleton() const
{
    if( FGetHusbID() && FGetWifeID() ) {
        return false;
    }
    if( GetChildCount() != 0 ) {
        return false;
    }
    recFamilyEventVec es = GetEvents();
    if( es.size() ) {
        return false;
    }
    return true;
}

// We will find, modify or create a family for these two individuals.
idt recFamily::FindOrCreate( idt ind1ID, idt ind2ID )
{
    idt famID = recFamily::Find( ind1ID, ind2ID );
    if( famID ) {
        // The family exists already.
        return famID;
    }
    famID = recIndividual::GetFamilyID( ind1ID );
    if( recFamily::IsSingleton( famID ) ) {
        // We will use this family
        idt fam2ID = recIndividual::GetFamilyID( ind2ID );
        if( recFamily::IsSingleton( fam2ID ) ) {
            recIndividual ind2(ind2ID);
            ind2.FSetFamID( famID );
            ind2.Save();
            // This is no longer needed
            recFamily::Delete( fam2ID );
        }
        recFamily fam(famID);
        if( fam.FGetWifeID() == 0 ) {
            fam.FSetWifeID( ind2ID );
        } else {
            assert( fam.FGetHusbID() == 0 );
            fam.FSetHusbID( ind2ID );
        }
        fam.Save();
        return fam.FGetID();
    }
    return 0;
}

void recFamily::RemoveFromEvents( idt famID, idt indID )
{
    if( famID == 0 || indID == 0 ) return;

    wxSQLite3StatementBuffer sql;
    recFamilyEventVec fes = GetEvents( famID );
    for( size_t i = 0 ; i < fes.size() ; i++ ) {
        sql.Format(
            "DELETE FROM IndividualEvent WHERE ind_id=" ID " AND event_id=" ID ";",
            indID, fes[i].FGetEventID()
        );
        s_db->ExecuteUpdate( sql );
    }
}

void recFamily::RemoveFromDatabase( idt famID )
{
    // We are not responsible for deleting the Individuals.
    wxSQLite3StatementBuffer sql;
    sql.Format(
        "DELETE FROM FamilyIndividual WHERE fam_id=" ID " ;"
        "DELETE FROM FamilyEventa WHERE fam_id=" ID " ;"
        "DELETE FROM FamilyEvent WHERE fam_id=" ID " ;",
        famID, famID, famID
    );
    s_db->ExecuteUpdate( sql );
    Delete( famID );
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
            " VALUES (" ID ", " ID ", %d, %d);",
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
                " VALUES (" ID ", " ID ", " ID ", %d, %d);",
                f_id, f_fam_id, f_ind_id, f_seq_child, f_seq_parent
            );
        } else {
            // Update existing record
            sql.Format(
                "UPDATE FamilyIndividual SET fam_id=" ID ", ind_id=" ID ","
                " seq_child=%d, seq_parent=%d"
                " WHERE id=" ID ";",
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
        "WHERE id=" ID ";", f_id
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
        "WHERE fam_id=" ID " AND ind_id=" ID ";",
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

//============================================================================
//-------------------------[ recIndRelationship ]-----------------------------
//============================================================================

const wxString recIndRelationship::s_TypeStr[recIndRelationship::IRT_MAX] = {
    _("Unstated"),       // IRT_Unstated
    _("Father"),         // IRT_Father
    _("Mother"),         // IRT_Mother
    _("Child")           // IRT_Child
};

wxString recIndRelationship::GetTypeStr() const
{
    if( m_type < 0 || m_type >= IRT_MAX ) {
        return _("Unknown");
    }
    return s_TypeStr[m_type];
}

// End of recIndividual.cpp file
