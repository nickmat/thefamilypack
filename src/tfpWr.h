/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        tfpWr.h
 * Project:     The Family Pack: Genealogy data storage and display program.
 * Purpose:     Write screen page functions.
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

#ifndef TFPWR_H
#define TFPWR_H

#include <rec/recDatabase.h>

// See tfpWrName.cpp
enum WrIndex { WrIndex_Individual, WrIndex_Persona };
extern wxString tfpWritePersonIndex( WrIndex type = WrIndex_Individual );
extern wxString tfpWritePersonList( 
	const wxString& surname, WrIndex type = WrIndex_Individual );

// See tfpWrFamily.cpp
extern wxString tfpWriteFamilyPage( id_t famID );
extern wxString tfpWriteIndFamilyPage( id_t indID );

// See tfpWrIndividual.cpp
extern wxString tfpWriteIndividualPage( id_t indID );

// See tfpWrChart.cpp
extern wxString tfpCreatePedChart( id_t indID );
extern wxString tfpCreateDescChart( id_t indID );

// See tfpWrReference.cpp
extern wxString tfpWriteReferenceIndex();
extern wxString tfpWriteReferencePage( id_t refID );

#endif // TFPWR_H
