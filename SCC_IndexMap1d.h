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


#ifndef INDEX_MAP_1D_
#define INDEX_MAP_1D_


namespace SCC
{
/*!
 *                       Class IndexMap1d
 * This class maps the vector index associated with rectangular grid data
 * values to the linear index associated with a matrix representation
 * of a linear operator on the grid data. 
 *
 */
class IndexMap1d
{
public :

/*! Constructs index map for a grid with xDim values in the first coordinate direction.
*/
    IndexMap1d(long xDim)
    {
    this->xDim = xDim;
    }

/*! Returns the linear index associated with the matrix representation
    based upon the vector index associated with the grid data values
*/
    long linearIndex(long i)
    {
        return i;
    }

/*! Sets i to be the vector index associated with the 
    linear index, k, of the matrix representation of the operator.  
*/
	void inverseIndex(long k, long& i)
	{
    i = k;
    } 

    long xDim;
};
} // Namespace SCC 
#endif
