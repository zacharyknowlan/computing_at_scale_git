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
		
		// default constructor
		Matrix(){}

		/**
         * Construct the vector with size rows, cols.
         */
		Matrix(const std::size_t rows, const std::size_t cols);

		/**
         * Set the size of the matrix to have rows rows and cols columns.
         */
		void SetSize(const std::size_t rows, const std::size_t cols);

		/**
         * Get the number of columns the matrix has.
         */
		inline const int GetNRows() {return mat.size();}

		/**
         * Get the number of rows the matrix has.
         */
		inline const int GetNCols() {return mat[0].size();}

		// operator set to allow mat[ii][jj] indexing
		std::vector<double> &operator[](int ii) {return mat[ii];}

		/**
         * Populates mat from a given matrix market (.mm) file.
         */
		void PopulateFromFile(std::string filename);

		/**
         * Prints the contents of mat to a matrix market (.mm) file.
         */
		void PrintMM(std::string filename);
};

#endif