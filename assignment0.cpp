#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include "mat.hpp"
#include "mult.hpp"

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

	matrix mat;
	mat.PopulateFromFile("test_mat.mm");

	matrix eye_mat;
	eye_mat.PopulateFromFile("eye_mat.mm");

	int dim = mat.GetNRows();

	if (comp_type == 0)
	{
		std::vector<double> vec(dim); 
		std::vector<double> result_vec(dim);
		Mult(mat, vec, result_vec);
	}
	else if (comp_type == 1)
	{
		matrix result_mat(dim, dim);
		Mult(mat, eye_mat, result_mat);
		result_mat.PrintMM("result_mat.mm");
	}

	return 0;
}
