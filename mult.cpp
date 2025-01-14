#include "mult.hpp"

void Mult(Matrix &mat, Vector &vec, Vector &result)
{
	assert(mat.GetNCols() == vec.size()); // check dim compatibility
	assert(vec.GetVecType() && "vec must be a column vector."); // check if column vector

	for(int ii=0; ii<mat.GetNRows(); ii++)
	{	
		result[ii] = 0.0; // initialize result element to 0.0
		for(int jj=0; jj<mat.GetNCols(); jj++)
		{
			result[ii] += mat[ii][jj] * vec[jj];
		}
	}
	result.SetVecType(true); // set result to be column vector
}

void Mult(Vector &vec, Matrix &mat, Vector &result)
{
	assert(mat.GetNRows() == vec.size()); // check dim compatibility
	assert(!vec.GetVecType() && "vec must be row vector."); // check if row vector

	for(int jj=0; jj<mat.GetNCols(); jj++)
	{	
		result[jj] = 0.0; // initialize result element to 0.0
		for(int ii=0; ii<mat.GetNRows(); ii++)
		{
			result[jj] += vec[ii] * mat[ii][jj];
		}
	}
	result.SetVecType(false); // set result to be row vector
}

void Mult(Matrix &mat1, Matrix &mat2, Matrix &result) 
{
	assert(mat1.GetNCols() == mat2.GetNRows()); // check dim compatibility

	for(int ii=0; ii<mat1.GetNRows(); ii++)
		for(int jj=0; jj<mat2.GetNCols(); jj++)
		{
			result[ii][jj] = 0.0; // initialize result element to 0.0
			for(int kk=0; kk<mat1.GetNCols(); kk++)
			{
				result[ii][jj] += mat1[ii][kk] * mat2[kk][jj];
			}
		}
}