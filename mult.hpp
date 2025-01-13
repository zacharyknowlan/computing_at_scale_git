#ifndef MULT_HPP
#define MULT_HPP

#include <cassert>
#include <vector>
#include <string>
#include "mat.hpp"

void Mult(matrix &mat, std::vector<double> &vec, std::vector<double> &result);

void Mult(matrix &mat1, matrix &mat2, matrix &result);

#endif