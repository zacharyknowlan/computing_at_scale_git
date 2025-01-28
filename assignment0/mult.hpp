#ifndef MULT_HPP
#define MULT_HPP

#include <cassert>
#include <vector>
#include <string>
#include "mat.hpp"
#include "vec.hpp"

/**
 * Mutiplication between a matrix and vector assuming 
 * mat.GetNCols() == vec.size().
 */
void Mult(Matrix &mat, Vector &vec, Vector &result);

/**
 * Mutiplication between a matrix and vector assuming 
 * vec.size() == Matrix.GetNRows().
 */
void Mult(Vector &vec, Matrix &mat, Vector &result);

/**
 * Mutiplication between two matrices assuming 
 * mat1.GetNCols() == mat2.GetNRows()
 */
void Mult(Matrix &mat1, Matrix &mat2, Matrix &result);

#endif