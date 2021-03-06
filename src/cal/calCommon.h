/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name:        calCommon.h
 * Project:     Cal: A general purpose calendar library.
 * Purpose:     Common internal calendar functions
 * Author:      Nick Matthews
 * Modified by:
 * Created:     28 September 2010
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

#ifndef CALCOMMON_H
#define CALCOMMON_H

//! Integer function to return floor( a / b )
extern long FDiv( long a, long b );

//! Integer function to return positive value of ( a % b )
extern long PMod( long a, long b );

// See calJulian.cpp
extern int calLatinDiy[];
extern int calLatinLengthOfMonth[3][12];

/*! class to hold a day, month and year
 */
class DMYDate {
public:
    void SetDMY( int d, int m, int y ) { day = d; month = m; year = y; }

    int day; int month; int year;
};

inline bool operator==(const DMYDate& d1, const DMYDate& d2)
{
    return d1.day == d2.day && d1.month == d2.month && d1.year == d2.year;
}

inline bool operator!=(const DMYDate& d1, const DMYDate& d2)
{
    return !(d1 == d2);
}


#endif // CALCOMMON_H