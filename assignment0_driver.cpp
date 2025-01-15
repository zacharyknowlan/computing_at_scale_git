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

	for (int ii=0; ii<argc; ii++) // parse command line options
	{
		std::string arg = argv[ii];
		if (arg == "-c" || arg == "--comp_type") {comp_type = std::stoi(argv[ii+1]);} 
		else if (arg == "-vf" || arg == "--vec_filename") {vec_filename = argv[ii+1];}
		else if (arg == "-mf" || arg == "--mat_filename") {mat_filename = argv[ii+1];}
		else if (arg == "-m2f" || arg == "--mat2_filename") {mat2_filename = argv[ii+1];}
	}
	
	if (comp_type == 0 && !vec_filename.empty() && !mat_filename.empty()) 
	{	// matrix-vector multiplication
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
	else if (comp_type == 1 && !mat_filename.empty() && !mat2_filename.empty())
	{	// matrix-matrix multiplication
		Matrix mat1;
		mat1.PopulateFromFile(mat_filename);
		
		Matrix mat2;
		mat2.PopulateFromFile(mat2_filename);

		Matrix result_mat;

		Mult(mat1, mat2, result_mat);

		result_mat.PrintMM("result_mat.mm");
	}
	else
	{
		std::cout << "\n\033[31mIncompatible arguments!\033[0m\n\n";	
		std::cout << "Use -c to specify operation type (0 = mat*vec, 1 = mat*mat)\n";
		std::cout << "Use -vf to specify vector filename.\n";
		std::cout << "Use -mf to specify matrix filename.\n";
		std::cout << "Use -m2f to specify 2nd matrix filename.\n\n";
		return 1;
	}

	return 0;
}
