#include "mult.hpp"

void Mult(matrix &mat, std::vector<double> &vec, std::vector<double> &result)
{
	assert(mat.GetNCols() == vec.size());

	for(int ii=0; ii<mat.GetNRows(); ii++)
		for(int jj=0; jj<mat.GetNCols(); jj++)
		{
			result[ii] += mat[ii][jj] * vec[jj];
		}
}

void Mult(matrix &mat1, matrix &mat2, matrix &result) 
{
	assert(mat1.GetNCols() == mat2.GetNRows());

	for(int ii=0; ii<mat1.GetNRows(); ii++)
		for(int jj=0; jj<mat2.GetNCols(); jj++)
			for(int kk=0; kk<mat1.GetNCols(); kk++)
			{
				result[ii][jj] += mat1[ii][kk] * mat2[kk][jj];
			}
}