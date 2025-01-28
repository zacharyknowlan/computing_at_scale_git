#ifndef TESTS_HPP
#define TEST_HPP

#include <iostream>
#include <string>
#include "../mat.hpp"
#include "../vec.hpp"
#include "../mult.hpp"

/**
 * Compares the entries of vec1 to vec2 with a tolerance of 1e-10.
 */
bool CompareVectors(Vector &vec1, Vector &vec2);

/**
 * Compares the entries of mat1 to mat2 with a tolerance of 1e-10.
 */
bool CompareMatrices(Matrix &mat1, Matrix &mat2);

/**
 * Runs all of test cases on Matrix member functions.
 */
void TestMatrix();

/**
 * Tests the Matrix::SetSize() function. 
 */
bool TestMatrixSetSize();

/**
 * Tests the Matrix::GetNRows() function.
 */
bool TestMatrixGetNRows();

/**
 * Tests the Matrix::GetNCols() function.
 */
bool TestMatrixGetNCols();

/**
 * Tests the Matrix::operator[] definition.
 */
bool TestMatrixOperator();

/**
 * Tests the Matrix::PopulateFromFile() function.
 */
bool TestMatrixPopulateFromFile();

/**
 * Tests the Matrix::PrintMM() function.
 */
bool TestMatrixPrintMM();

/**
 * Runs all of the tests on Vector member functions.
 */
void TestVector();

/**
 * Tests the Vector::PopulateFromFile() funtion.
 */
bool TestVectorPopulateFromFile();

/**
 * Tests the Vector::PrintMM() function. 
 */
bool TestVectorPrintMM();

/**
 * Tests the Vector::SetVecType() function.
 */
bool TestVectorSetVecType();

/**
 * Tests the Vector::GetVectorType() function.
 */
bool TestVectorGetVectorType();

/**
 * Tests all of the Matrix-Matrix and Matrix-Vector
 * Mult() overloads. 
 */
void TestMult();

/**
 * Tests the Mult(Matrix, Vector, Vector) overload.
 */
bool TestMatVecMult();

/**
 * Tests the Mult(Vector, Matrix, Vector) overload.
 */
bool TestVecMatMult();

/**
 * Tests the Mult(Matrix, Matrix, Matrix) overload.
 */
bool TestMatMatMult();


#endif 