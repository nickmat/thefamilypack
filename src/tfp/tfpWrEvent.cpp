/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        tfpWrEvent.cpp
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Functions to write to screen and compare Events.
 * Author:      Nick Matthews
 * Website:     http://thefamilypack.org
 * Created:     24 October 2010
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

#include "tfpWr.h"

#include <rec/recEvent.h>
#include <rec/recEventa.h>
#include <rec/recIndividual.h>
#include <rec/recPersona.h>

#include <rg/rgCompareEvent.h>

wxString tfpWriteEventPage( idt eventID, rgCompareEvent* ce )
{
    wxString htm;
    recEvent eve(eventID);
    if( eve.FGetID() == 0 ) return htm;
    wxASSERT( ce != NULL );
    ce->Reset( eventID );

    htm <<
        tfpWrHeadTfp( "Event " + eve.GetIdStr() ) <<

        "<h1>Event " << eve.GetIdStr() << ": " << eve.f_title << "</h1>\n"
        "<table class='data'>\n"
        "<tr>\n<td>"
        "<b>Type:</b> " << eve.GetTypeStr() <<
        " &nbsp; <b>Group:</b> " << recEventType::GetGroupStr( eve.FGetTypeID() ) <<
        "</td>\n</tr>\n"
        "<tr>\n<td>"
    ;
    if( eve.FGetDate1ID() ) {
        htm <<
            "<b><a href='tfpi:D" << eve.FGetDate1ID() <<
            "'>Date</a>: </b>" << eve.GetDateStr()
        ;
    } else {
        htm << "<b>Date:</b>";
    }
    htm << "</td>\n</tr>\n<tr>\n<td>";
    if( eve.FGetPlaceID() ) {
        htm <<
            "<b><a href='tfpi:P" << eve.FGetPlaceID() <<
            "'>Place</a>: </b>" << eve.GetAddressStr()
        ;
    } else {
        htm << "<b>Place:</b>";
    }
    if( eve.FGetHigherID() ) {
        htm <<
            "</td>\n</tr>\n<tr>\n"
            "<td><b><a href='tfp:E" << eve.FGetHigherID() <<
            "'>Part of: " << recEvent::GetIdStr( eve.FGetHigherID() ) <<
            "</a></b> " << recEvent::GetTitle( eve.FGetHigherID() )
        ;
    }
    htm <<
        "</td>\n</tr>\n"
        "<tr>\n<td><b>Note: </b>" << eve.FGetNote() << "</td>\n</tr>\n"
        "<tr>\n<td><b>User Ref: </b>" << eve.FGetUserRef() << "</td>\n</tr>\n"
        "</table>\n"
    ;

    recIndEventVec ies = eve.GetIndividualEvents();
    if( !ies.empty() ) {
        htm << "<table class='data'>\n<tr>\n"
               "<th>Role</th>\n<th colspan='2'>Individual</th>\n<th>Note</th>\n<th>Link</th>\n</tr>\n";
        for( size_t i = 0 ; i < ies.size() ; i++ ) {
            recIndividual ind(ies[i].FGetIndID());
            htm
                << "<tr>\n<td>" << recEventTypeRole::GetName( ies[i].FGetRoleID() )
                << "</td>\n<td><a href='tfp:I" << ind.FGetID()
                << "'><b>" << ind.GetIdStr() 
                << "</b></a></td>\n<td class='" << tfpGetIndSexClass( ind.FGetID() )
                << "'>\n<b><a href='tfp:F" << ind.FGetFamID()
                << "'>" << ind.FGetName()
                << "</a></b>"
                << " <a href='tfpc:MR" << ind.FGetID()
                << "'><img src='memory:fam.png' alt='Family'></a>"
                << "</td>\n<td>" << ies[i].FGetNote()
                << "</td>\n"
            ;
            if( ies[i].FGetHigherID() != 0 ) {
                recIndividualEvent higher_e( ies[i].FGetHigherID() );
                htm
                    << "<td><a href='tfp:E" << higher_e.FGetEventID()
                    << "'><b>" << recEvent::GetIdStr( higher_e.FGetEventID() ) 
                    << "</b></a></td>\n"
                ;
            } else {
                htm << "<td> </td>\n";
            }
            htm << "</tr>\n";
            recIndEventVec lower_ies = ies[i].GetLowerIndEvents();
            for( size_t j = 0 ; j < lower_ies.size() ; j++ ) {
                recEvent lower_e(lower_ies[j].FGetEventID());
                htm
                    << "<tr>\n<td>" << recEventTypeRole::GetName( lower_ies[j].FGetRoleID() )
                    << "</td>\n<td> </td>\n<td>" << lower_e.FGetTitle()
                    << "</td>\n<td>" << lower_e.FGetNote()
                    << "</td>\n<td><a href='tfp:E" << lower_e.FGetID()
                    << "'><b>" << lower_e.GetIdStr() 
                    << "</b></a></td>\n</tr>\n"
                ;
            }
        }
        htm << "</table>\n";
    }

    recEventEventaVec eeas = eve.GetEventEventas();
    if( eeas.size() ) {
        htm <<
            "<table class='data'>\n<tr>\n"
            "<th colspan='2'>Reference Document</th>\n"
            "<th colspan='2'>Eventa</th>\n"
            "<th>Conf</th>\n</tr>\n"
        ;
        for( size_t i = 0 ; i < eeas.size() ; i++ ) {
            idt eaID = eeas[i].FGetEventaID();
            idt refID = recEventa::GetRefID( eaID );
            wxString refTitle = recReference::GetTitle( refID );
            htm <<
                "<tr>\n"
                "<td><b><a href='tfp:R" << refID <<
                "'>" << recReference::GetIdStr( refID ) << "</a></b></td>\n"
                "<td>" << refTitle << "</td>\n"
                "<td><b><a href='tfp:Ea" << eaID <<
                "'>" <<  recEventa::GetIdStr( eaID ) << "</a></b></td>\n"
                "<td>" << recEventa::GetTitle( eaID ) << "</td>\n"
                "<td>" << eeas[i].FGetConf() << "</td>\n"
                "</tr>\n"
            ;
        }
        htm << "</table>\n";
    }

    // List lower (included) events
    recEventVec es = eve.GetLowerEvents();
    if( es.size() ) {
        htm <<
            "<table class='data'>\n<tr>\n"
            "<th colspan='3'>Included Events</th>\n";
        for( size_t i = 0 ; i < es.size() ; i++ ) {
            wxString cat1, cat2, dStr, pStr;
            if( es[i].FGetDate1ID() || es[i].FGetPlaceID() ) {
                cat1 = "<br>\n";
            }
            if( es[i].FGetDate1ID() && es[i].FGetPlaceID() ) {
                cat2 = ", ";
            }
            if( es[i].FGetDate1ID() ) {
                dStr <<
                    "<a href='tfpi:D" << es[i].FGetDate1ID() <<
                    "'>" << es[i].GetDateStr() <<
                    "</a>"
                ;
            }
            if( es[i].FGetPlaceID() ) {
                pStr <<
                    "<a href='tfpi:P" << es[i].FGetPlaceID() <<
                    "'>" << es[i].GetAddressStr() <<
                    "</a>"
                ;
            }
            htm <<
                "</tr>\n<tr>\n" <<
                "<td><b><a href='tfp:E" << es[i].FGetID() <<
                "'>" << es[i].GetIdStr() <<
                "</a></b></td>\n<td>" << es[i].GetTypeStr() <<
                "</td><td>" << es[i].FGetTitle() <<
                cat1 << dStr << cat2 << pStr
            ;
            if( es[i].FGetNote().size() ) {
                htm << "<br>\n" << ies[i].FGetNote();
            }
            htm << "</td>\n";
        }
        htm << "</tr>\n</table>\n";
    }

    htm << ce->GetRefDatesTable() << ce->GetRefPlacesTable() << tfpWrTailTfp();

    return htm;
}

// End of tfpWrEvent.cpp Source
