/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        include/rec/recGalleryMedia.h
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Manage the SQLite3 GalleryMedia record header.
 * Author:      Nick Matthews
 * Website:     http://thefamilypack.org
 * Created:     19th September 2018
 * Copyright:   Copyright (c) 2018, Nick Matthews.
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

#ifndef RECGALLERYMEDIA_H
#define RECGALLERYMEDIA_H

#include <rec/recDatabase.h>
#include <rec/recMedia.h>

class recGalleryMedia : public recDb
{
public:
    recGalleryMedia() {}
    recGalleryMedia( idt id ) : recDb( id ) { Read(); }
    recGalleryMedia( const recGalleryMedia& name );
    recGalleryMedia( idt galID, idt medID ) { ReadGalleryMedia( galID, medID ); }

    void Clear();
    void Save();
    bool Read();
    TABLE_NAME_MEMBERS( "GalleryMedia" );
    bool Equivalent( const recGalleryMedia& r2 ) const;

    wxString FGetTitle() const { return f_title; }
    idt FGetGalID() const { return f_gal_id; }
    idt FGetMedID() const { return f_med_id; }
    int FGetMedSeq() const { return f_med_seq; }

    void FSetTitle( const wxString& title ) { f_title = title; }
    void FSetGalID( idt galID ) { f_gal_id = galID; }
    void FSetMedID( idt medID ) { f_med_id = medID; }
    void FSetMedSeq( int seq ) { f_med_seq = seq; }

    bool ReadGalleryMedia( idt galID, idt medID );

    void SetNextMedSequence( idt galID );

    static wxString GetTitle( idt galID, idt medID );

private:
    wxString f_title;
    idt      f_gal_id;
    idt      f_med_id;
    int      f_med_seq;
};

inline bool operator==( const recGalleryMedia& r1, const recGalleryMedia& r2 )
{
    return r1.Equivalent( r2 ) && r1.EqualID( r2 );
}

inline bool operator!=( const recGalleryMedia& r1, const recGalleryMedia& r2 )
{
    return !( r1 == r2 );
}

using  recGalleryMediaVec = std::vector< recGalleryMedia >;

class recGalleryMediaMedia
{
public:
    recGalleryMediaMedia() : m_gm( 0 ), m_med( 0 ) {}
    recGalleryMediaMedia( idt galID, idt medID )
        : m_gm( galID, medID ), m_med( medID ) {}

    recGalleryMedia& GetGalleryMedia() { return m_gm; }
    recMedia& GetMedia() { return m_med; }

    idt GetMedID() const { return m_med.FGetID(); }
    wxString GetMedIdStr() const { return m_med.GetIdStr(); }
    wxString GetTitle() const;

private:
    recGalleryMedia m_gm;
    recMedia        m_med;
};

#endif // RECGALLERYMEDIA_H
