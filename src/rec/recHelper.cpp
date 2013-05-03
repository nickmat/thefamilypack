/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        src/rec/recHelper.cpp
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     General helper classes and functions
 * Author:      Nick Matthews
 * Website:     http://thefamilypack.org
 * Created:     30th April 2013
 * RCS-ID:      $Id$
 * Copyright:   Copyright (c) 2013, Nick Matthews.
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

#include <rec/recHelper.h>

idt recGetID( const wxString& str )
{
    idt id = 0;
    str.ToLongLong( &id );  
    return id;
}

wxString recGetSexStr( Sex sex )
{
    static wxString sexarray[] = {
        _("Unstated"), _("Male"), _("Female"), _("Unknown")
    };
    return sexarray[sex];
}

wxString recHTMLifyStr( const wxString& str )
{
    wxString htm;
    wxString::const_iterator it;
    for( it = str.begin() ; it != str.end() ; it++ ) {
        switch( (*it).GetValue() )
        {
        case '\n':
            htm << "<br>";
            break;
        case '&':
            htm << "&amp;";
            break;
        case '<':
            htm << "&lt;";
            break;
        case '>':
            htm << "&gt;";
            break;
        default:
            htm << *it;
        }
    }
    return htm;
}

bool recCheckIDsAreEqual( const recCheckIdVec& ids )
{
    for( size_t i = 0 ; i < ids.size() ; i++ ) {
        if( ids[i].GetFirstID() == 0 || ids[i].GetSecondID() == 0 ) {
            return false;
        }
    }
    return true;
}

bool recCheckIDsHaveAdditionalFirst( const recCheckIdVec& ids )
{
    for( size_t i = 0 ; i < ids.size() ; i++ ) {
        if( ids[i].GetSecondID() == 0 ) {
            return true;
        }
    }
    return false;
}

bool recCheckIDsHaveAdditionalSecond( const recCheckIdVec& ids )
{
    for( size_t i = 0 ; i < ids.size() ; i++ ) {
        if( ids[i].GetFirstID() == 0 ) {
            return true;
        }
    }
    return false;
}



// End of recDatabase.cpp file
