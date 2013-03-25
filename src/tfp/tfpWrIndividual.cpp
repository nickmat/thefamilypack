/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        tfpWrIndividual.cpp
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Write screen for a Individual function.
 * Author:      Nick Matthews
 * Modified by:
 * Website:     http://thefamilypack.org
 * Created:     7 October 2010
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
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
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
#include <rec/recEvent.h>
#include <rec/recPersona.h>
#include <rec/recName.h>
#include <rec/recReference.h>

#include "tfpWr.h"

wxString tfpWriteIndividualPage( idt indID )
{
    wxString htm;
    size_t i, j;
    recIndividual ind( indID );
    recPersona per( ind.f_per_id );
    recIndividual spouse;

    htm << 
        "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\""
        "\"http://www.w3.org/TR/html4/loose.dtd\">\n"
        "<html>\n<head>\n"
        "<title>Individual " << ind.GetIdStr() << "</title>\n"
        "<meta http-equiv='Content-Type' content='text/html;charset=utf-8'>\n"
        "<link rel='stylesheet' type='text/css' href='memory:tfp.css'>\n"
        "</head>\n<body>\n<div class='tfp'>\n"

        // Individual record
        "<table class='data'>\n<tr>\n"
        "<td>Name:</td><td class='subject " << GetSexClass( ind.FGetID() ) <<
        "'><a href='tfp:F" << ind.FGetFamID() << 
        "'>" << ind.FGetName() <<
        "</a> " << ind.FGetEpitaph() <<
        " <a href='tfpc:MR" << indID << "'><img src=memory:fam.png></a></td>"
        "</tr>\n<tr>\n"
        "<td>ID, Sex:</td><td>" << ind.GetIdStr() << 
        ", " << recGetSexStr( per.FGetSex() ) << "</td>\n"
        "</tr>\n<tr>\n"
        "<td>Note:</td><td>" << per.FGetNote() << "</td>\n"
        "</tr>\n</table>\n"
    ;
    // Names
    recNameVec names = per.ReadNames();
    htm << 
        "<table class='data'>\n<tr>\n"
        "<th colspan='3'>Names</th>";
    for( size_t i = 0 ; i < names.size() ; i++ ) {
        htm << "</tr>\n<tr>\n"
            "<td><b><a href='tfpi:N" << names[i].FGetID() <<
            "'>" << names[i].GetIdStr() <<
            "</a></b></td><td>" << recNameStyle::GetStyleStr( names[i].FGetTypeID() ) <<
            "</td><td>" << names[i].GetNameStr() <<
            "</td>";
    }
    // Parents
    recFamilyVec parents = ind.GetParentList();
    htm << 
        "</tr>\n<tr>\n"
        "<th colspan='3'>Parents</th>\n";
    for( size_t i = 0 ; i < parents.size() ; i++ ) {
        idt hID = parents[i].FGetHusbID();
        if( hID != 0 ) {
            htm << 
                "</tr>\n<tr>\n"
                "<td><b>" << recIndividual::GetIdStr( hID ) <<
                "</b></td>\n<td>Father:"
                "</td>\n<td class='" << GetSexClass( hID ) <<
                "'><a href='tfp:I" << hID << 
                "'>" << recIndividual::GetFullName( hID ) <<
                "</a> " << recIndividual::GetDateEpitaph( hID ) <<
                " <a href='tfpc:MR" << hID <<
                "'><img src=memory:fam.png></a></td>\n"
            ;
        }
        idt wID = parents[i].FGetWifeID();
        if( wID != 0 ) {
            htm << 
                "</tr>\n<tr>\n"
                "<td><b>" << recIndividual::GetIdStr( wID ) <<
                "</b></td>\n<td>Mother:"
                "</td>\n<td class='" << GetSexClass( wID ) <<
                "'><a href='tfp:I" << wID << 
                "'>" << recIndividual::GetFullName( wID ) <<
                "</a> " << recIndividual::GetDateEpitaph( wID ) <<
                " <a href='tfpc:MR" << wID <<
                "'><img src=memory:fam.png></a></td>\n"
            ;
        }
    }
    recFamilyVec families = recIndividual::GetFamilyList( indID );
    for( size_t i = 0 ; i < families.size() ; i++ ) {
        idt spouseID = families[i].FGetHusbID();
        if( spouseID == indID ) spouseID = 0;
        if( spouseID == 0 ) spouseID = families[i].FGetWifeID();
        idt famID = families[i].f_id;
        spouse.f_id = spouseID;
        spouse.Read();

        htm << 
            "</tr>\n<tr>\n"
            "<th colspan='3'>Family " << i+1 << "</th>\n"
            "</tr>\n<tr>\n" <<
            // Spouse name
            "<td><b><a href='tfp:I" << spouseID << 
            "'>" << recIndividual::GetIdStr( spouseID ) <<
            "</a></b></td>\n<td><a href='tfp:F" << famID << 
            "'>Spouse " << i+1 << "</a>:</td>\n"
            "<td class='" << GetSexClass( spouseID ) <<
            "'><a href='tfp:I" << spouseID <<
            "'>" << spouse.GetFullName() <<
            "</a></b> " << spouse.f_epitaph <<
            " <a href='tfpc:MR" << spouseID <<
            "'><img src=memory:fam.png></a></td>\n"
        ;
        // Union event (marriage)
        idt marEvID = families[i].GetUnionEvent();
        if( marEvID != 0 ) {
            htm <<
                "</tr>\n<tr>\n" <<
                "<td><b><a href='tfp:E" << marEvID <<
                "'>" << recEvent::GetIdStr( marEvID ) <<
                "</a></b></td>\n<td>" << recEvent::GetTypeStr( marEvID ) <<
                ":</td>\n<td><b>" << recEvent::GetDetailStr( marEvID ) <<
                "</b></td>\n"
            ;
        }
        // Children
        recIndividualList children = families[i].GetChildren();
        for( j = 0 ; j < children.size() ; j++ ) {
            idt cID = children[j].FGetID();
            htm <<
                "</tr>\n<tr>\n" <<
                "<td><b><a href='tfp:I" << cID <<
                "'>" << children[j].GetIdStr() <<
                "</a></b></td>\n"
            ;
            if( j == 0 ) {
                htm << 
                    "<td valign='top' rowspan='" << children.size() << 
                    "'>Children:</td>\n"
                ;
            }
            htm << 
                "<td class='" << GetSexClass( cID ) <<
                "'><a href='tfp:I" << cID <<
                "'>" << children[j].GetFullName() <<
                "</a> " << children[j].FGetEpitaph() <<
                " <a href='tfpc:MR" << cID <<
                "'><img src=memory:fam.png></a></td>\n"
            ;
        }
    }
    htm << "</tr>\n</table>\n";

    // All Events
    recIndEventVec ies = ind.GetEvents();
    htm << 
        "<table class='data'>\n<tr>\n"
        "<th colspan='4'>Conclusion Events</th>\n";
    for( i = 0 ; i < ies.size() ; i++ ) {
        idt eveID = ies[i].FGetEventID();
        recEvent eve( eveID );
        wxString cat1, cat2, dStr, pStr;
        if( eve.FGetDate1ID() || eve.FGetPlaceID() ) {
            cat1 = "<br>\n";
        }
        if( eve.FGetDate1ID() && eve.FGetPlaceID() ) {
            cat2 = ", ";
        }
        if( eve.FGetDate1ID() ) {
            dStr << 
                "<a href='tfpi:D" << eve.FGetDate1ID() <<
                "'>" << eve.GetDateStr() <<
                "</a>"
            ;
        }
        if( eve.FGetPlaceID() ) {
            pStr <<
                "<a href='tfpi:P" << eve.FGetPlaceID() <<
                "'>" << eve.GetAddressStr() <<
                "</a>"
            ;
        }
        htm <<
            "</tr>\n<tr>\n" <<
            "<td><b><a href='tfp:E" << eveID <<
            "'>" << eve.GetIdStr() <<
            "</a></b></td>\n<td>" << eve.GetTypeStr() <<
            ":</td>\n<td>" << recEventTypeRole::GetName( ies[i].FGetRoleID() ) <<
            "</td><td>" << eve.FGetTitle() << 
            cat1 << dStr << cat2 << pStr 
        ;
        if( !eve.FGetNote().IsEmpty() ) {
            htm << "<br>\n" << ies[i].FGetNote();
        }
        htm << "</td>\n";
    }
    htm << "</tr>\n</table>\n";

    // Get linked Persona Events
    wxSQLite3Table eTable = ind.GetRefEventsTable();
    htm << 
        "<table class='data'>\n<tr>\n"
        "<th colspan='4'>Evidence Events</th>\n";
    for( i = 0 ; i < (size_t) eTable.GetRowCount() ; i++ ) {
        eTable.SetRow( i );
        idt eveID = GET_ID( eTable.GetInt64( 0 ) );
        recEvent eve( eveID );
        idt roleID = GET_ID( eTable.GetInt64( 1 ) );
        idt refID = recEvent::FindReferenceID( eveID );

        wxString cat1, cat2, dStr, pStr;
        if( eve.FGetDate1ID() || eve.FGetPlaceID() ) {
            cat1 = "<br>\n";
        }
        if( eve.FGetDate1ID() && eve.FGetPlaceID() ) {
            cat2 = ", ";
        }
        if( eve.FGetDate1ID() ) {
            dStr << 
                "<a href='tfpi:D" << eve.FGetDate1ID() <<
                "'>" << eve.GetDateStr() <<
                "</a>"
            ;
        }
        if( eve.FGetPlaceID() ) {
            pStr <<
                "<a href='tfpi:P" << eve.FGetPlaceID() <<
                "'>" << eve.GetAddressStr() <<
                "</a>"
            ;
        }
        htm <<
            "</tr>\n<tr>\n" <<
            "<td><b><a href='tfp:R" << refID <<
            "'>" << recReference::GetIdStr( refID ) <<
            "</a>: <a href='tfp:E" << eveID <<
            "'>" << eve.GetIdStr() <<
            "</b></td>\n<td>" << eve.GetTypeStr() <<
            ":</td>\n<td>" << recEventTypeRole::GetName( roleID ) <<
            "</td><td>" << eve.FGetTitle() << 
            cat1 << dStr << cat2 << pStr 
        ;
//        if( !eve.FGetNote().IsEmpty() ) {
//            htm << "<br>\n" << ies[i].FGetNote();
//        }
        htm << "</td>\n";
    }
    htm << "</tr>\n</table>\n";


    // List all References for linked Personas
    eTable = ind.GetReferencesTable();
    htm << 
        "<table class='data'>\n<tr>\n"
        "<th colspan='2'>Reference Links</th>\n";
    for( i = 0 ; i < (size_t) eTable.GetRowCount() ; i++ ) {
        eTable.SetRow( i );
        idt refID = GET_ID( eTable.GetInt64( 0 ) );

        htm <<
            "</tr>\n<tr>\n" <<
            "<td><b><a href='tfp:R" << refID <<
            "'>" << recReference::GetIdStr( refID ) <<
            "</a></b></td>\n<td>" << eTable.GetAsString( 1 ) <<
            "</td>\n"
        ;
    }
    htm << "</tr>\n</table>\n</div>\n</body>\n</html>\n";

    return htm;
}


// End of tfpWrIndividual.cpp Source