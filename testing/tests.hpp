#ifndef TESTS_HPP
#define TEST_HPP

#include <iostream>
#include <string>
#include "../mat.hpp"
#include "../vec.hpp"
#include "../mult.hpp"

/**
 * @brief Compares the entries of vec1 to vec2 with a tolerance of 1e-10.
 */
bool CompareVectors(Vector &vec1, Vector &vec2);

/**
 * @brief Compares the entries of mat1 to mat2 with a tolerance of 1e-10.
 */
bool CompareMatrices(Matrix &mat1, Matrix &mat2);

/**
 * @brief Runs all of test cases on Matrix member functions.
 */
void TestMatrix();

/**
 * @brief Tests the Matrix::SetSize() function. 
 */
bool TestMatrixSetSize();

/**
 * @brief Tests the Matrix::GetNRows() function.
 */
bool TestMatrixGetNRows();

/**
 * @brief Tests the Matrix::GetNCols() function.
 */
bool TestMatrixGetNCols();

/**
 * @brief Tests the Matrix::operator[] definition.
 */
bool TestMatrixOperator();

/**
 * @brief Tests the Matrix::PopulateFromFile() function.
 */
bool TestMatrixPopulateFromFile();

/**
 * @brief Tests the Matrix::PrintMM() function.
 */
bool TestMatrixPrintMM();

/**
 * @brief Runs all of the tests on Vector member functions.
 */
void TestVector();

/**
 * @brief Tests the Vector::PopulateFromFile() funtion.
 */
bool TestVectorPopulateFromFile();

/**
 * @brief Tests the Vector::PrintMM() function. 
 */
bool TestVectorPrintMM();

/**
 * @brief Tests the Vector::SetVecType() function.
 */
bool TestVectorSetVecType();

/**
 * @brief Tests the Vector::GetVectorType() function.
 */
bool TestVectorGetVectorType();

/**
 * @brief Tests all of the Matrix-Matrix and Matrix-Vector
 * Mult() overloads. 
 */
void TestMult();

/**
 * @brief Tests the Mult(Matrix, Vector, Vector) overload.
 */
bool TestMatVecMult();

/**
 * @brief Tests the Mult(Vector, Matrix, Vector) overload.
 */
bool TestVecMatMult();

/**
 * @brief Tests the Mult(Matrix, Matrix, Matrix) overload.
 */
bool TestMatMatMult();


#endif 