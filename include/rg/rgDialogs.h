/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        include/rg/rgDialogs.h
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Various Database Dialog function prototypes, GUI only.
 * Author:      Nick Matthews
 * Modified by:
 * Website:     http://thefamilypack.org
 * Created:     21 November 2012
 * RCS-ID:      $Id$
 * Copyright:   Copyright (c) 2012, Nick Matthews.
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

#ifndef RGDIALOGS_H
#define RGDIALOGS_H

#include <rec/recFilterEvent.h>
#include <rec/recIndividual.h>

class rgDlgEditReference;

extern bool rgEditDate( idt dateID );
extern idt rgCreateDate( const wxString& dateStr = wxEmptyString );
extern bool rgEditRelativeDate( idt dateID );
extern idt rgCreateRelativeDate( idt baseID, long value = 0 );
extern bool rgEditPlace( idt placeID );
extern idt rgCreatePlace( const wxString& placeStr = wxEmptyString );
extern bool rgEditEventType( idt etID );
extern idt rgCreateEventType();
extern bool rgEditRole( idt roleID );
extern idt rgCreateRole( idt etID );

enum {
    rgSELSTYLE_None       = 0x0000,
    rgSELSTYLE_Create     = 0x0001,   // Show Create button
    rgSELSTYLE_Filter     = 0x0002,   // Show Filter button
    rgSELSTYLE_Unknown    = 0x0004,   // Show Unknown button (for Unknown value)
    rgSELSTYLE_SelList    = 0x0100    // Selects the full list
};
extern idt rgSelectDate( 
    unsigned flag = rgSELSTYLE_Create, unsigned* retbutton = NULL,
    unsigned filter = 0, idt = 0 );
extern idt rgSelectPlace( 
    unsigned flag = rgSELSTYLE_Create, unsigned* retbutton = NULL,
    unsigned filter = 0, idt = 0 );
extern idt rgSelectEventType( 
    unsigned flag = rgSELSTYLE_Create, unsigned* retbutton = NULL,
    unsigned grpfilter = recET_FILTER_GrpAll );
extern bool rgSelectIndEventList( recFilterEvent* exfilter );
extern idt rgSelectIndEvent( 
    unsigned flag = rgSELSTYLE_None, 
    recFilterEvent* filter = NULL,
    bool* ok = NULL,
    idt indID = 0 );
extern idt rgSelectIndividual( 
    unsigned flag = rgSELSTYLE_Create, unsigned* retbutton = NULL,
    unsigned sexfilter = recInd_FILTER_SexAll );
extern idt rgSelectCreatePersona( wxWindow* parent, idt refID );

// See src/rg/rgEdContact.cpp
extern bool rgEditContact( idt conID );
extern idt rgCreateContact( idt clID );

// See src/rg/rgEdEvent.cpp
extern bool rgEditEvent( idt eveID );
extern idt rgCreateIndEvent( idt ind1ID, idt ind2ID = 0 );

// See src/rg/rgEdEvidEvent.cpp
extern bool rgEditEvidEvent( rgDlgEditReference* parent, idt eveID );
extern idt rgCreateEvidEvent( rgDlgEditReference* parent );
extern idt rgCreateEvidPerEvent( rgDlgEditReference* parent, const wxString& role );

// See src/rg/rgEdName.cpp
extern bool rgEditName( idt nameID );

// See src/rg/rgCrName.cpp
enum {
    rgCRNAME_Default   = 0x000, // Use default settings to decode name1 string.
    rgCRNAME_Sur_Given = 0x001  // If given, name1 is surname, name2 is given name.
};
extern idt rgCreateName( idt perID,
    unsigned flags = rgCRNAME_Default, 
    const wxString& name1 = wxEmptyString,
    const wxString& name2 = wxEmptyString,
    recNameStyle::Style type = recNameStyle::NS_Default );

// See src/rg/rgEdNamePart.cpp
extern bool rgEditNamePart( idt npID );
extern idt rgCreateNamePart( idt nameID, const wxString& npStr = wxEmptyString );

// See src/rg/rgEdPerIndEvent.cpp
enum rgSHOWROLE {
    rgSHOWROLE_All,
    rgSHOWROLE_PrimeAll,
    rgSHOWROLE_PrimeMale,
    rgSHOWROLE_PrimeFemale
};
extern bool rgEditIndEventRole( idt ieID, rgSHOWROLE filter = rgSHOWROLE_All );
extern bool rgCreateIndEventRole( idt indID, idt eveID, idt roleID );
extern bool rgEditPerEventRole( idt epID, rgSHOWROLE filter = rgSHOWROLE_All );
extern bool rgCreatePerEventRole( idt perID, idt eveID, idt roleID );

// See src/rg/rgEdPersona.cpp
extern bool rgEditPersona( wxWindow* parent, idt perID );
//extern idt rgCreatePersona( wxWindow* parent );

// See src/rg/rgEdReference.cpp
extern bool rgEditReference( wxWindow* parent, idt refID );
extern idt rgCreateReference( wxWindow* parent );

// See src/rg/rgEdRelationship.cpp
extern bool rgEditPerRelationship( rgDlgEditReference* parent, idt relID );
extern idt rgCreatePerRelationship( 
    rgDlgEditReference* parent, const wxString& descrip = wxEmptyString );

// See src/rg/rgEdResearcher.cpp
extern bool rgEditResearcher( idt conID );
extern idt rgCreateResearcher();

// See src/rg/rgEdSystem.cpp
extern bool rgEditSystemSettings( wxWindow* parent );

// See src/rg/rgEdUser.cpp
extern bool rgEditUserSettings( wxWindow* parent );

#endif // RGDIALOGS_H
