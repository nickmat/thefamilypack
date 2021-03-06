/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        src/tfp/tfpExportGed.cpp
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Export GEDCOM data files.
 * Author:      Nick Matthews
 * Website:     http://thefamilypack.org
 * Created:     11th November 2015
 * Copyright:   Copyright (c) 2015, Nick Matthews.
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

#include "tfpExport.h"

#include <rec/recGedExport.h>

#include <wx/filename.h>
#include <wx/wfstream.h>


bool tfpExportGedcom( wxString& path )
{
    wxFileName fname( path );
    wxFFileOutputStream outfile( fname.GetFullPath() );
    if( !outfile.IsOk() ) return false;
    try {
        recGedExport ged( outfile );
        if( !ged.Export() ) {
            recMessage( _("Error Writing GEDCOM File"), _("Export") );
            return true;
        }

    } catch( wxSQLite3Exception& e ) {
        recDb::ErrorMessage( e );
        recDb::Rollback();
    }
    return true;
}

// End of src/tfp/tfpExportGed.cpp Source
