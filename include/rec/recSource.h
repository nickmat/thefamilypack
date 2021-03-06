/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        recSource.h
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Manage the SQLite3 Source record header.
 * Author:      Nick Matthews
 * Modified by:
 * Website:     http://thefamilypack.org
 * Created:     22 November 2010
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

#ifndef RECSOURCE_H
#define RECSOURCE_H

#include <rec/recDatabase.h>

class recSource;
class recCitationPartType;
typedef std::vector< recSource >  recSourceVec;
typedef std::vector< recCitationPartType >  recCitationPartTypeVec;

//============================================================================
//                 recSource
//============================================================================

class recSource : public recDb
{
public:
    idt     f_higher_id;
    idt     f_sub_date1_id;
    idt     f_sub_date2_id;
    idt     f_sub_place_id;
    idt     f_loc_place_id;
    idt     f_res_id;
    wxString f_comments;

    recSource() {}
    recSource( idt id ) : recDb(id) { Read(); }
    recSource( const recSource& source );

    void Clear();
    void Save();
    bool Read();
    TABLE_NAME_MEMBERS( "Source" );

    static void RemoveDates( idt dateID );
    static void RemovePlace( idt placeID );
};

inline bool recEquivalent( const recSource& r1, const recSource& r2 )
{
    return
        r1.f_higher_id    == r2.f_higher_id    &&
        r1.f_sub_date1_id == r2.f_sub_date1_id &&
        r1.f_sub_date2_id == r2.f_sub_date2_id &&
        r1.f_sub_place_id == r2.f_sub_place_id &&
        r1.f_loc_place_id == r2.f_loc_place_id &&
        r1.f_res_id       == r2.f_res_id       &&
        r1.f_comments     == r2.f_comments;
}

inline bool operator==( const recSource& r1, const recSource& r2 )
{
    return recEquivalent( r1, r2 ) && r1.f_id == r2.f_id;
}

inline bool operator!=( const recSource& r1, const recSource& r2 )
{
    return !(r1 == r2);
}

//============================================================================
//                 recCitationPart
//============================================================================

class recCitationPart : public recDb
{
public:
    idt     f_type_id;
    idt     f_source_id;
    wxString f_val;

    recCitationPart() {}
    recCitationPart( idt id ) : recDb(id) { Read(); }
    recCitationPart( const recCitationPart& source );

    void Clear();
    void Save();
    bool Read();
    TABLE_NAME_MEMBERS( "CitationPart" );

};

inline bool recEquivalent( const recCitationPart& r1, const recCitationPart& r2 )
{
    return
        r1.f_type_id   == r2.f_type_id   &&
        r1.f_source_id == r2.f_source_id &&
        r1.f_val       == r2.f_val;
}

inline bool operator==( const recCitationPart& r1, const recCitationPart& r2 )
{
    return recEquivalent( r1, r2 ) && r1.f_id == r2.f_id;
}

inline bool operator!=( const recCitationPart& r1, const recCitationPart& r2 )
{
    return !(r1 == r2);
}

//============================================================================
//                 recCitationPartType
//============================================================================

class recCitationPartType : public recDb
{
public:
    wxString  f_name;

    recCitationPartType() {}
    recCitationPartType( idt id ) : recDb(id) { Read(); }
    recCitationPartType( const recCitationPartType& at );

    void Clear();
    void Save();
    bool Read();
    TABLE_NAME_MEMBERS( "CitationPartType" );

    static wxString GetStr( idt id );

    static recCitationPartTypeVec GetList();
};

inline bool recEquivalent( const recCitationPartType& r1, const recCitationPartType& r2 )
{
    return
        r1.f_name == r2.f_name;
}

inline bool operator==( const recCitationPartType& r1, const recCitationPartType& r2 )
{
    return recEquivalent( r1, r2 ) && r1.f_id == r2.f_id;
}

inline bool operator!=( const recCitationPartType& r1, const recCitationPartType& r2 )
{
    return !(r1 == r2);
}


//============================================================================
//                 recRepository
//============================================================================

class recRepository : public recDb
{
public:
    wxString  f_name;
    wxString  f_access;
    wxString  f_comments;

    recRepository() {}
    recRepository( idt id ) : recDb(id) { Read(); }
    recRepository( const recRepository& at );

    void Clear();
    void Save();
    bool Read();
    TABLE_NAME_MEMBERS( "Repository" );
};

inline bool recEquivalent( const recRepository& r1, const recRepository& r2 )
{
    return
        r1.f_name     == r2.f_name    &&
        r1.f_access   == r2.f_access  &&
        r1.f_comments == r2.f_comments;
}

inline bool operator==( const recRepository& r1, const recRepository& r2 )
{
    return recEquivalent( r1, r2 ) && r1.f_id == r2.f_id;
}

inline bool operator!=( const recRepository& r1, const recRepository& r2 )
{
    return !(r1 == r2);
}


//============================================================================
//                 recRepositorySource
//============================================================================

class recRepositorySource : public recDb
{
public:
    idt      f_repos_id;
    idt      f_source_id;
    wxString  f_call_num;
    wxString  f_descrip;

    recRepositorySource() {}
    recRepositorySource( idt id ) : recDb(id) { Read(); }
    recRepositorySource( const recRepositorySource& at );

    void Clear();
    void Save();
    bool Read();
    TABLE_NAME_MEMBERS( "RepositorySource" );
};

inline bool recEquivalent( const recRepositorySource& r1, const recRepositorySource& r2 )
{
    return
        r1.f_repos_id  == r2.f_repos_id  &&
        r1.f_source_id == r2.f_source_id &&
        r1.f_call_num  == r2.f_call_num  &&
        r1.f_descrip   == r2.f_descrip;
}

inline bool operator==( const recRepositorySource& r1, const recRepositorySource& r2 )
{
    return recEquivalent( r1, r2 ) && r1.f_id == r2.f_id;
}

inline bool operator!=( const recRepositorySource& r1, const recRepositorySource& r2 )
{
    return !(r1 == r2);
}



#endif // RECSOURCE_H
