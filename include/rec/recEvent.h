/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        recEvent.h
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Manage SQLite3 Event, EventTypes, EventTypeRole and 
 *              RecPersonaEvent records.
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

#ifndef RECEVENT_H
#define RECEVENT_H

#include <rec/recDatabase.h>

class recEvent : public recDb {
public:
    id_t     f_type_id;
    wxString f_val;
    id_t     f_date1_id;
    id_t     f_date2_id;
    id_t     f_place_id;

    recEvent() {}
    recEvent( id_t id ) : recDb(id) {}

	void Clear();
    void Save();
    bool Read();
    TABLE_NAME_MEMBERS( "Event" );
};

inline bool recEquivalent( const recEvent& r1, const recEvent& r2 )
{
    return
        r1.f_type_id  == r2.f_type_id  &&
        r1.f_val      == r2.f_val      &&
        r1.f_date1_id == r2.f_date1_id &&
        r1.f_date2_id == r2.f_date2_id &&
        r1.f_place_id == r2.f_place_id;
}

inline bool operator==( const recEvent& r1, const recEvent& r2 )
{
    return recEquivalent( r1, r2 ) && r1.f_id == r2.f_id;
}

inline bool operator!=( const recEvent& r1, const recEvent& r2 )
{
    return !(r1 == r2);
}


class recEventType : public recDb {
public:
	enum ETYPE_Grp {
		ETYPE_Grp_Unstated, ETYPE_Grp_Birth, ETYPE_Grp_Nr_Birth, 
		ETYPE_Grp_Union, ETYPE_Grp_Family, ETYPE_Grp_Death, 
        ETYPE_Grp_Nr_Death, ETYPE_Grp_Other
	};

    ETYPE_Grp f_grp;
    wxString  f_name;

    recEventType() {}
    recEventType( id_t id ) : recDb(id) {}

	void Clear();
    void Save();
    bool Read();
    TABLE_NAME_MEMBERS( "EventType" );
};

inline bool recEquivalent( const recEventType& r1, const recEventType& r2 )
{
    return
        r1.f_grp  == r2.f_grp  &&
        r1.f_name == r2.f_name;
}

inline bool operator==( const recEventType& r1, const recEventType& r2 )
{
    return recEquivalent( r1, r2 ) && r1.f_id == r2.f_id;
}

inline bool operator!=( const recEventType& r1, const recEventType& r2 )
{
    return !(r1 == r2);
}


class recEventTypeRole : public recDb {
public:
    id_t      f_type_id;
    wxString  f_name;

    recEventTypeRole() {}
    recEventTypeRole( id_t id ) : recDb(id) {}

	void Clear();
    void Save();
    bool Read();
    TABLE_NAME_MEMBERS( "EventTypeRole" );
};

inline bool recEquivalent( const recEventTypeRole& r1, const recEventTypeRole& r2 )
{
    return
        r1.f_type_id == r2.f_type_id &&
        r1.f_name    == r2.f_name;
}

inline bool operator==( const recEventTypeRole& r1, const recEventTypeRole& r2 )
{
    return recEquivalent( r1, r2 ) && r1.f_id == r2.f_id;
}

inline bool operator!=( const recEventTypeRole& r1, const recEventTypeRole& r2 )
{
    return !(r1 == r2);
}

class recPersonaEvent : public recDb {
public:
    id_t     f_per_id;
    id_t     f_event_id;
    id_t     f_role_id;
    wxString f_note;

    recPersonaEvent() {}
    recPersonaEvent( id_t id ) : recDb(id) {}

	void Clear();
    void Save();
    bool Read();
    TABLE_NAME_MEMBERS( "PersonaEvent" );
};

inline bool recEquivalent( const recPersonaEvent& r1, const recPersonaEvent& r2 )
{
    return
        r1.f_per_id   == r2.f_per_id   &&
        r1.f_event_id == r2.f_event_id &&
        r1.f_role_id  == r2.f_role_id  &&
        r1.f_note     == r2.f_note;
}

inline bool operator==( const recPersonaEvent& r1, const recPersonaEvent& r2 )
{
    return recEquivalent( r1, r2 ) && r1.f_id == r2.f_id;
}

inline bool operator!=( const recPersonaEvent& r1, const recPersonaEvent& r2 )
{
    return !(r1 == r2);
}


#endif // RECEVENT_H