/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        recSystem.h
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Manage the SQLite3 System record header.
 * Author:      Nick Matthews
 * Modified by:
 * Website:     http://thefamilypack.org
 * Created:     30 March 2012
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

#ifndef RECSYSTEM_H
#define RECSYSTEM_H

#include <rec/recDatabase.h>

class recSystem;
typedef std::vector< recSystem > recSystemVec;

//============================================================================
//                 recSystem
//============================================================================

class recSystem : public recDb
{
public:
    enum Property {
        SP_Unstated = 0,
        SP_CurrentUser = 1,
        SP_MAX
    };

    recSystem() {}
    recSystem( idt id ) : recDb(id) { Read(); }
    recSystem( const recSystem& user );

    void Clear();
    void Save();
    bool Read();
    TABLE_NAME_MEMBERS( "System" )
    bool Equivalent( const recSystem& r2 ) const;

    wxString FGetValue() const { return f_val; }

    void FSetValue( const wxString& val ) { f_val = val; }

    static wxString GetPropertyValue( Property sp );
    static idt GetPropertyValueID( Property sp );

    static void SetProperyValue( Property sp, const wxString& value );
    static void SetProperyValue( Property sp, idt id );

private:
    wxString f_val;
};

inline bool operator==( const recSystem& r1, const recSystem& r2 )
{
    return r1.Equivalent( r2 ) && r1.EqualID( r2 );
}

inline bool operator!=( const recSystem& r1, const recSystem& r2 )
{
    return !(r1 == r2);
}

inline void recSetCurrentUser( idt userID ) {
    recSystem::SetProperyValue( recSystem::SP_CurrentUser, userID );
}

inline idt recGetCurrentUser() {
    return recSystem::GetPropertyValueID( recSystem::SP_CurrentUser );
}

#endif // RECSYSTEM_H
