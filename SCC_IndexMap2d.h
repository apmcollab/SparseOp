#ifndef _IndexMap2d_
#define _IndexMap2d_


namespace SCC
{
/*!
 *                       Class IndexMap2d
 * This class maps the 2d vector index associated with the rectangular grid data
 * values to the linear index associated with a matrix representation
 * of a linear operator on the grid data.
 *
 */
class IndexMap2d
{
public :

/*! Null Constructor.
*/
	IndexMap2d()
	{
	this->xDim = 0;
	this->yDim = 0;
	}

/*! Copy Constructor.
*/
	IndexMap2d(const IndexMap2d& iMap)
	{
	this->xDim = iMap.xDim;
	this->yDim = iMap.yDim;
	}

/*! Constructs index map for a grid with xDim values in the first coordinate direction and yDmin values in the second coordinate direction.
*/
	IndexMap2d(long xDim, long yDim)
	{
	this->xDim = xDim;
	this->yDim = yDim;
	}

/*! Initialize index map for a grid with xDim values in the first coordinate direction and yDmin values in the second coordinate direction.
*/
	void initialize(long xDim, long yDim)
	{
	this->xDim = xDim;
	this->yDim = yDim;
	}

/*! Returns a linear index associated with the matrix representation
	based upon the two dimensional vector indices
	associated with the grid data values
*/

	long linearIndex(long i,long j)
	{
		return j + i*yDim;
	}

/*! Sets i and j to be the two dimensional vector index components associated with the 
    linear index, k, of the matrix representation of the operator.  
*/
	void inverseIndex(long k, long& i, long& j)
	{
	j = k%yDim;
	i =(k - j)/yDim;
	}

	long xDim; long yDim;
};
}
#endif
