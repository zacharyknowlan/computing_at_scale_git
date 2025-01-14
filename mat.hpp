#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cassert>

class Matrix
{
	protected:
		
		std::vector<std::vector<double>> mat;

	public:
		
		Matrix(){}

		Matrix(const std::size_t rows, const std::size_t cols);

		void SetSize(const std::size_t rows, const std::size_t cols);

		inline const int GetNRows() {return mat.size();}

		inline const int GetNCols() {return mat[0].size();}

		std::vector<double> &operator[](int ii) {return mat[ii];}

		void PopulateFromFile(std::string filename);

		void PrintMM(std::string filename);
};

#endif