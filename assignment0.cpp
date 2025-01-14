#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include "mat.hpp"
#include "mult.hpp"
#include "vec.hpp"

int main(int argc, char *argv[])
{
	int comp_type = 0; // default set to matrix vector multiplication

	if (argc > 1)
	{
		std::string arg = argv[1];
		if (arg == "-c" || arg == "--comp_type") 
		{
			comp_type = std::stoi(argv[2]);
		} 
	}
	
	if (comp_type != 0 && comp_type != 1)
	{
		std::cout << "Use -c 0 for matrix vector multiplication \n";
		std::cout << "or -c 1 for matrix matrix multiplication. \n";
		return 1;
	}

	Matrix mat;
	mat.PopulateFromFile("test_mat.mm");

	Matrix eye_mat;
	eye_mat.PopulateFromFile("eye_mat.mm");

	int dim = std::size_t(mat.GetNRows());

	if (comp_type == 0)
	{
		Vector col_vec(dim);
		col_vec.PopulateFromFile("test_col_vec.mm");
		Vector result_col_vec(dim);
		Mult(mat, col_vec, result_col_vec);
		result_col_vec.PrintMM("result_col_vec.mm");

		Vector row_vec(dim);
		row_vec.PopulateFromFile("test_row_vec.mm");
		Vector result_row_vec(dim);
		Mult(row_vec, mat, result_row_vec);
		result_row_vec.PrintMM("result_row_vec.mm");
	}
	else if (comp_type == 1)
	{
		Matrix result_mat(dim, dim);
		Mult(mat, eye_mat, result_mat);
		result_mat.PrintMM("result_mat.mm");
	}

	return 0;
}
