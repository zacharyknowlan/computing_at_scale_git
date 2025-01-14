#ifndef MULT_HPP
#define MULT_HPP

#include <cassert>
#include <vector>
#include <string>
#include "mat.hpp"
#include "vec.hpp"

void Mult(Matrix &mat, Vector &vec, Vector &result);

void Mult(Vector &vec, Matrix &mat, Vector &result);

void Mult(Matrix &mat1, Matrix &mat2, Matrix &result);

#endif