#ifndef TESTS_HPP
#define TEST_HPP

#include <iostream>
#include <string>
#include "../mat.hpp"
#include "../vec.hpp"
#include "../mult.hpp"

bool CompareVectors(Vector &vec1, Vector &vec2);

bool CompareMatrices(Matrix &mat1, Matrix &mat2);

void TestMatrix();

bool TestMatrixSetSize();

bool TestMatrixGetNRows();

bool TestMatrixGetNCols();

bool TestMatrixOperator();

bool TestMatrixPopulateFromFile();

bool TestMatrixPrintMM();

void TestVector();

bool TestVectorPopulateFromFile();

bool TestVectorPrintMM();

bool TestVectorSetVecType();

bool TestVectorGetVectorType();

void TestMult();

bool TestMatVecMult();

bool TestVecMatMult();

bool TestMatMatMult();


#endif 