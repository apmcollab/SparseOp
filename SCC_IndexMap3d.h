/*
 * SCC_IndexMap3d.h
 *
 *  Created on: Jan 15, 2023
 *      Author: anderson
 */
/*
#############################################################################
#
# Copyright  2023  Chris Anderson
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the Lesser GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# For a copy of the GNU General Public License see
# <http://www.gnu.org/licenses/>.
#
#############################################################################
*/
#ifndef INDEX_MAP_3D_
#define INDEX_MAP_3D_

namespace SCC
{
/*!
 *                       Class IndexMap3d
 * This class maps the 3d vector index associated with the rectangular grid data
 * values to the linear index associated with a matrix representation
 * of a linear operator on the grid data.
 *
 */
class IndexMap3d
{
public :

/*! Null Constructor.
*/
	IndexMap3d()
	{
	this->xDim = 0;
	this->yDim = 0;
	this->zDim = 0;
	}

/*! Copy Constructor.
*/
	IndexMap3d(const IndexMap3d& iMap)
	{
	this->xDim = iMap.xDim;
	this->yDim = iMap.yDim;
	this->zDim = iMap.zDim;
	}

/*! Constructs index map for a grid with xDim values in the first coordinate direction
    and yDmin values in the second coordinate direction and zDim values in the third
    coordinate direction
*/
	IndexMap3d(long xDim, long yDim,long zDim)
	{
	this->xDim = xDim;
	this->yDim = yDim;
	this->zDim = zDim;
	}

/*! Initialize index map for a grid with xDim values in the first coordinate direction
    and yDmin values in the second coordinate direction and zDim values in the third
    coordinate direction

*/
	void initialize(long xDim, long yDim, long zDim)
	{
	this->xDim = xDim;
	this->yDim = yDim;
	this->zDim = zDim;
	}

/*! Returns a linear index associated with the matrix representation
	based upon the three dimensional vector indices
	associated with the grid data values
*/

	long linearIndex(long i,long j, long k)
	{
		return k + zDim*(j + i*yDim);
	}

/*! Sets (i,j,k) to be the two dimensional vector index components associated with the
    linear index, linIndex, of the matrix representation of the operator.
*/
	void inverseIndex(long linIndex, long& i, long& j, long&k)
	{
	k = linIndex%zDim;
	j = ( (linIndex-k)/zDim)%yDim;
	i = (((linIndex-k)/zDim) - j)/yDim;
	}

	long xDim; long yDim; long zDim;
};
} // Namespace SCC

#endif
