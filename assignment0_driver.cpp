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
	std::string vec_filename;
	std::string mat_filename;
	std::string mat2_filename;

	for (int ii=0; ii<argc; ii++)
	{
		std::string arg = argv[ii];
		if (arg == "-c" || arg == "--comp_type") {comp_type = std::stoi(argv[ii+1]);} 
		else if (arg == "-vf" || arg == "--vec_filename") {vec_filename = argv[ii+1];}
		else if (arg == "-mf" || arg == "--mat_filename") {mat_filename = argv[ii+1];}
		else if (arg == "-m2f" || arg == "--mat2_filename") {mat2_filename = argv[ii+1];}
	}
	
	if (comp_type != 0 && comp_type != 1)
	{
		std::cout << "Use -c 0 for matrix vector multiplication \n";
		std::cout << "or -c 1 for matrix matrix multiplication. \n";
		return 1;
	}
	else if (comp_type == 0)
	{
		Vector vec;
		vec.PopulateFromFile(vec_filename);

		Matrix mat;
		mat.PopulateFromFile(mat_filename);

		Vector result_vec;

		if (vec.GetVecType())
		{
			Mult(mat, vec, result_vec);
		}
		else if (!vec.GetVecType())
		{
			Mult(vec, mat, result_vec);
		}

		result_vec.PrintMM("result_vec.mm");
	}
	else if (comp_type == 1)
	{
		Matrix mat1;
		mat1.PopulateFromFile(mat_filename);
		
		Matrix mat2;
		mat2.PopulateFromFile(mat2_filename);

		Matrix result_mat;

		Mult(mat1, mat2, result_mat);

		result_mat.PrintMM("result_mat.mm");
	}

	return 0;
}
