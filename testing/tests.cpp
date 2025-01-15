#include "tests.hpp"

bool CompareVectors(Vector &vec1, Vector &vec2)
{
    double tol = 1e-10;
    double diff;
    bool test = true;

    for (int ii=0; ii<vec1.size(); ii++)
    {
        diff = std::abs(vec1[ii] - vec2[ii]);
        if (diff < tol) {continue;}
        else
        {
            test = false;
            break;
        }
    }
    if (test) {return true;}
    else {return false;}
}

bool CompareMatrices(Matrix &mat1, Matrix &mat2)
{
    double tol = 1e-10;
    double diff;
    bool test = true;

    for (int ii=0; ii<mat1.GetNRows(); ii++)
        for (int jj=0; jj<mat1.GetNCols(); jj++)
        {
            diff = std::abs(mat1[ii][jj] - mat2[ii][jj]);
            if (diff < tol) {continue;}
            else
            {
                test = false;
                break;
            }
        }
    if (test) {return true;}
    else {return false;}
}

void TestMatrix()
{
    std::cout << "\nTesting Matrix functions.\n";

    bool test1 = TestMatrixSetSize();
    bool test2 = TestMatrixGetNRows();
    bool test3 = TestMatrixGetNCols();
    bool test4 = TestMatrixOperator();
    bool test5 = TestMatrixPopulateFromFile();
    bool test6 = TestMatrixPrintMM();

    if (test1 && test2 && test3 && test4 && test5 && test6)
    {
        std::cout << "\nAll Matrix functions work correctly.\n";
    }
    else
    {
        std::cout << "\nMatrix function testing failed.\n";
    }
}

bool TestMatrixSetSize()
{
    Matrix mat;
    
    int rows = 12;
    int cols = 18;
    mat.SetSize(rows, cols);

    bool test1 = (mat.GetNRows() == rows);
    
    bool test2 = (mat.GetNCols() == cols);

    rows = 23;
    cols = 9;
    mat.SetSize(rows, cols);

    bool test3 = (mat.GetNRows() == rows);

    bool test4 = (mat.GetNCols() == cols);

    if (test1 && test2 && test3 && test4)
    {
        std::cout << "\n    \033[32mMatrix::SetSize() passed.\033[0m\n";
        return true;
    }
    else
    {
        std::cout << "\n    \033[31mMatrix::SetSize() failed.\033[0m\n";
        return false;
    }
}

bool TestMatrixGetNRows()
{
    int rows = 28;
    int cols = 13;
    Matrix mat(rows, cols);

    bool test1 = (mat.GetNRows() == rows);

    rows = 4;
    mat.SetSize(rows, cols);

    bool test2 = (mat.GetNRows() == rows);

    if (test1 && test2)
    {
        std::cout << "\n    \033[32mMatrix::GetNRows() passed.\033[0m\n";
        return true;
    }
    else
    {
        std::cout << "\n    \033[31mMatrix::GetNRows() failed.\033[0m\n";
        return false;
    }
}

bool TestMatrixGetNCols()
{
    int rows = 17;
    int cols = 12;
    Matrix mat(rows, cols);
    
    bool test1 = (mat.GetNCols() == cols);

    cols = 28;
    mat.SetSize(rows, cols);

    bool test2 = (mat.GetNCols() == cols);

    if (test1 && test2)
    {
        std::cout << "\n    \033[32mMatrix::GetNCols() passed.\033[0m\n";
        return true;
    }
    else
    {
        std::cout << "\n    \033[31mMatrix::GetNCols() failed.\033[0m\n";
        return false;
    }
}

bool TestMatrixOperator()
{
    double row_val = 33.0;
    int rows = 10;
    int cols = 10;
    Matrix mat(rows,cols);
    Vector test_row(cols);
    Vector assigned_row(cols);

    test_row.assign(test_row.size(), row_val);
    mat[0] = test_row;
    for (int ii=0; ii<cols; ii++){assigned_row[ii] = mat[0][ii];}

    bool test1 = CompareVectors(test_row, assigned_row);
    
    if (test1)
    {
        std::cout << "\n    \033[32mMatrix::operator[] passed.\033[0m\n";
        return true;
    }
    else
    {
        std::cout << "\n    \033[31mMatrix::operator[] failed.\033[0m\n";
        return false;
    }
}

bool TestMatrixPopulateFromFile()
{ 
    bool test1; // square matrix case
    bool test2; // rectangular matrix case

    {
        Matrix mat1;
        Matrix mat2;

        mat1.PopulateFromFile("test_square_mat.mm");
        mat2.SetSize(mat1.GetNRows(), mat1.GetNCols());

        for (int ii=0; ii<mat2.GetNRows(); ii++)
            for (int jj=0; jj<mat2.GetNCols(); jj++)
            {
                mat2[ii][jj] = (10.0*(ii+1) + 1.0*(jj+1));
            }

        test1 = CompareMatrices(mat1, mat2);
    }
    {
        Matrix mat1;
        Matrix mat2;

        mat1.PopulateFromFile("test_rectangle_mat.mm");
        mat2.SetSize(mat1.GetNRows(), mat1.GetNCols());

        for (int ii=0; ii<mat2.GetNRows(); ii++)
            for (int jj=0; jj<mat2.GetNCols(); jj++)
            {
                mat2[ii][jj] = (10.0*(ii+1) + 1.0*(jj+1));
            }

        test2 = CompareMatrices(mat1, mat2);
    }
    
    if (test1 && test2)
    {
        std::cout << "\n    \033[32mMatrix::PopulateFromFile() passed.\033[0m\n";
        return true;
    }
    else
    {
        std::cout << "\n    \033[31mMatrix::PopulateFromFile() failed.\033[0m\n";
        return false;
    }    
}

bool TestMatrixPrintMM()
{
    int rows = 23;
    int cols = 14;
    std::string filename = "result_mat.mm";

    Matrix mat1(rows, cols);
    Matrix mat2;

    for (int ii=0; ii<mat1.GetNRows(); ii++)
        for (int jj=0; jj<mat1.GetNCols(); jj++)
        {
            mat1[ii][jj] = (double)(4*(ii+1) + 7*(jj+1));
        }

    mat1.PrintMM(filename);
    mat2.PopulateFromFile(filename);
    std::remove(filename.c_str());

    bool test1 = CompareMatrices(mat1, mat2);

    if (test1)
    {
        std::cout << "\n    \033[32mMatrix::PrintMM() passed.\033[0m\n";
        return true;
    }
    else
    {
        std::cout << "\n    \033[31mMatrix::PrintMM() failed.\033[0m\n";
        return false;
    }   
}

void TestVector()
{
    std::cout << "\nTesting Vector functions.\n";

    bool test1 = TestVectorPopulateFromFile();
    bool test2 = TestVectorPrintMM();
    bool test3 = TestVectorSetVecType();
    bool test4 = TestVectorGetVectorType();

    if (test1 && test2 && test3 && test4)
    {
        std::cout << "\nAll Vector functions work correctly.\n";
    }
    else
    {
        std::cout << "\nVector function testing failed.\n";
    }
}

bool TestVectorPopulateFromFile()
{
    bool test1 = true; // column vector reads as column vector
    bool test2 = true; // column vector entry values correct
    bool test3 = true; // row vector reads as row vector
    bool test4 = true; // row vector entry values correct

    {
        Vector vec1;
        Vector vec2;

        vec1.PopulateFromFile("test_col_vec.mm");

        if (!vec1.GetVecType()) {test1 = false;}

        vec2.resize(vec1.size());
        for (int ii=0; ii<vec1.size(); ii++) {vec2[ii] = (double)(ii+1);}

        test2 = CompareVectors(vec1, vec2);
    }
    {
        Vector vec1;
        Vector vec2;

        vec1.PopulateFromFile("test_row_vec.mm");

        if (vec1.GetVecType()) {test3 = false;}

        vec2.resize(vec1.size());
        for (int ii=0; ii<vec1.size(); ii++) {vec2[ii] = (double)(ii+1);}

        test4 = CompareVectors(vec1, vec2);
    }

    if (test1 && test2 && test3 && test4)
    {
        std::cout << "\n    \033[32mVector::PopulateFromFile() passed.\033[0m\n";
        return true;
    }
    else
    {
        std::cout << "\n    \033[31mVector::PopulateFromFile() failed.\033[0m\n";
        return false;
    }
}

bool TestVectorPrintMM()
{
    int entries = 47;
    std::string filename1 = "result_col_vec.mm";
    std::string filename2 = "result_row_vec.mm";

    bool test1 = true; // column vector prints as column vector
    bool test2 = true; // column vector entry values correct
    bool test3 = true; // row vector prints as row vector
    bool test4 = true; // row vector entry values correct

    {
        Vector vec1(entries);
        Vector vec2(entries);

        for (int ii=0; ii<vec1.size(); ii++) {vec1[ii] = (4.0*ii + 8.0);}
        vec1.PrintMM(filename1);

        vec2.PopulateFromFile(filename1);
        std::remove(filename1.c_str());

        if (!vec2.GetVecType()) {test1 = false;}

        test2 = CompareVectors(vec1, vec2);
    }
    {
        Vector vec1(entries);
        Vector vec2(entries);

        for (int ii=0; ii<vec1.size(); ii++) {vec1[ii] = (3.0*ii + 2.0);}
        vec1.SetVecType(false);
        vec1.PrintMM(filename2);

        vec2.PopulateFromFile(filename2);
        std::remove(filename2.c_str());

        if (vec2.GetVecType()) {test3 = false;}

        test4 = CompareVectors(vec1, vec2);
    }

    if (test1 && test2 && test3 && test4)
    {
        std::cout << "\n    \033[32mVector::PrintMM() passed.\033[0m\n";
        return true;
    }
    else
    {
        std::cout << "\n    \033[31mVector::PrintMM() failed.\033[0m\n";
        return false;
    }
}

bool TestVectorSetVecType()
{
    bool test1 = true; // column vector case
    bool test2 = true; // row vector case

    {  
        Vector vec;
        vec.SetVecType(true);
        if (!vec.GetVecType()){test1 = false;}
    }
    {
        Vector vec;
        vec.SetVecType(false);
        if (vec.GetVecType()){test2 = false;}
    }
    
    if (test1 && test2)
    {
        std::cout << "\n    \033[32mVector::SetVecType() passed.\033[0m\n";
        return true;
    }
    {
        std::cout << "\n    \033[31mVector::SetVecType() failed.\033[0m\n";
        return false;
    }
}

bool TestVectorGetVectorType()
{
    bool test1 = true; // column vector case
    bool test2 = true; // row vector case

    {  
        Vector vec;
        vec.SetVecType(true);
        if (!vec.GetVecType()){test1 = false;}
    }
    {
        Vector vec;
        vec.SetVecType(false);
        if (vec.GetVecType()){test2 = false;}
    }

    if (test1)
    {
        std::cout << "\n    \033[32mVector::GetVecType() passed.\033[0m\n";
        return true;
    }
    {
        std::cout << "\n    \033[31mVector::GetVecType() failed.\033[0m\n";
        return false;
    }
}

void TestMult()
{
    std:: cout << "\nTesting Mult functions.\n";

    bool test1 = TestMatVecMult();
    bool test2 = TestVecMatMult();
    bool test3 = TestMatMatMult();

    if (test1 && test2 && test3)
    {
        std::cout << "\nMult functions work correctly.\n";
    }
    else
    {
        std::cout << "\nMult function testing failed.\n";
    }
}

bool TestMatVecMult()
{
    bool test1 = true; // result vector set to column
    bool test2 = true; // identity matrix mult entry values correct
    bool test3 = true; // result vector set to column
    bool test4 = true; // rectangular matrix mult entry values correct
    bool test5 = true; // result vector set to column
    bool test6 = true; // square matrix mult entry values correct

    {
        Matrix mat;
        Vector vec;
        Vector result_vec;
        
        mat.PopulateFromFile("test_identity_mat.mm");
        vec.PopulateFromFile("test_col_vec.mm");

        Mult(mat, vec, result_vec);

        if (!result_vec.GetVecType()) {test1 = false;}

        test2 = CompareVectors(vec, result_vec);
    }
    {
        Matrix mat;
        Vector vec;
        Vector result_vec;
        Vector ans_vec;

        mat.PopulateFromFile("test_rectangle_mat.mm");
        vec.PopulateFromFile("test_col_vec.mm");
    
        Mult(mat, vec, result_vec);

        if (!result_vec.GetVecType()) {test3 = false;}

        ans_vec.resize(result_vec.size());
        for (int ii=0; ii<result_vec.size(); ii++)
            for (int jj=0; jj<vec.size(); jj++)
            {
                ans_vec[ii] += (10.0*(ii+1) + 1.0*(jj+1)) * (jj+1);
            }  

        test4 = CompareVectors(result_vec, ans_vec);
    }
    { 
        Matrix mat;
        Vector vec;
        Vector result_vec;
        Vector ans_vec;

        mat.PopulateFromFile("test_square_mat.mm");
        vec.PopulateFromFile("test_col_vec.mm");

        Mult(mat, vec, result_vec);

        if (!result_vec.GetVecType()) {test5 = false;}

        ans_vec.resize(result_vec.size());
        for (int ii=0; ii<result_vec.size(); ii++)
            for (int jj=0; jj<vec.size(); jj++)
            {
                ans_vec[ii] += (10.0*(ii+1) + 1.0*(jj+1)) * (jj+1);
            }

        test6 = CompareVectors(result_vec, ans_vec);
    }
    
    if (test1 && test2 && test3 && test4 && test5 && test6)
    {
        std::cout << "\n    \033[32mMult(Matrix, Vector, Vector) passed.\033[0m\n";
        return true;
    }
    else
    {
        std::cout << "\n    \033[31mMult(Matrix, Vector, Vector) failed.\033[0m\n";
        return false;
    }
}

bool TestVecMatMult()
{
    bool test1 = true; // result vector set to row
    bool test2 = true; // identity matrix mult entry values correct
    bool test3 = true; // result vector set to row
    bool test4 = true; // rectangular matrix mult entry values correct
    bool test5 = true; // result vector set to row
    bool test6 = true; // square matrix mult entry values correct

    {
        Matrix mat;
        Vector vec;
        Vector result_vec;

        mat.PopulateFromFile("test_identity_mat.mm");
        vec.PopulateFromFile("test_col_vec.mm"); // read column vector
        vec.SetVecType(false); // change to row vector for this overload of Mult
        result_vec.SetVecType(false);
        
        Mult(vec, mat, result_vec);

        if (result_vec.GetVecType()) {test1 = false;}

        test2 = CompareVectors(vec, result_vec);
    }
    {
        Matrix mat;
        Vector vec;
        Vector result_vec;
        Vector ans_vec;

        mat.PopulateFromFile("test_rectangle_mat.mm");
        vec.PopulateFromFile("test_row_vec.mm");
        result_vec.SetVecType(false);

        Mult(vec, mat, result_vec);

        if (result_vec.GetVecType()) {test3 = false;}

        ans_vec.resize(result_vec.size());
        for (int ii=0; ii<result_vec.size(); ii++)
            for (int jj=0; jj<vec.size(); jj++)
            {
                ans_vec[ii] += (10.0*(jj+1) + 1.0*(ii+1)) * (jj+1);
            }
        
        test4 = CompareVectors(result_vec, ans_vec);
    }
    {
        Matrix mat;
        Vector vec;
        Vector result_vec;
        Vector ans_vec;

        mat.PopulateFromFile("test_square_mat.mm");
        vec.PopulateFromFile("test_col_vec.mm");
        vec.SetVecType(false);
        result_vec.SetVecType(false);

        Mult(vec, mat, result_vec);

        if (result_vec.GetVecType()) {test5 = false;}

        ans_vec.resize(result_vec.size());
        for (int ii=0; ii<result_vec.size(); ii++)
            for (int jj=0; jj<vec.size(); jj++)
            {
                ans_vec[ii] += (10.0*(jj+1) + 1.0*(ii+1)) * (jj+1);
            }

        test6 = CompareVectors(result_vec, ans_vec);
    }
    
    if (test1 && test2 && test3 && test4 && test5 && test6)
    {
        std::cout << "\n    \033[32mMult(Vector, Matrix, Vector) passed.\033[0m\n";
        return true;
    }
    else
    {
        std::cout << "\n    \033[31mMult(Vector, Matrix, Vector) failed.\033[0m\n";
        return false;
    }
}

bool TestMatMatMult()
{
    bool test1 = true; // identity matrix * matrix
    bool test2 = true; // rectangular matrix * square matrix
    bool test3 = true; // square matrix * square matrix

    {
        Matrix mat1;
        Matrix mat2;
        Matrix result_mat;

        mat1.PopulateFromFile("test_identity_mat.mm");
        mat2.PopulateFromFile("test_square_mat.mm");

        Mult(mat1, mat2, result_mat);

        test1 = CompareMatrices(mat2, result_mat);
    }
    {
        Matrix mat1;
        Matrix mat2;
        Matrix result_mat;
        Matrix ans_mat;

        mat1.PopulateFromFile("test_rectangle_mat.mm");
        mat2.PopulateFromFile("test_square_mat.mm");

        Mult(mat1, mat2, result_mat);

        ans_mat.SetSize(result_mat.GetNRows(), result_mat.GetNCols());
        for (int ii=0; ii<mat1.GetNRows(); ii++)
            for (int jj=0; jj<mat2.GetNCols(); jj++)
                for (int kk=0; kk<mat1.GetNCols(); kk++)
                {
                    ans_mat[ii][jj] += (10.0*(ii+1) + 1.0*(kk+1))*(10.0*(kk+1) + 1.0*(jj+1));
                }

        test2 = CompareMatrices(result_mat, ans_mat);
    }
    {
        Matrix mat1;
        Matrix mat2;
        Matrix result_mat;
        Matrix ans_mat;

        mat1.PopulateFromFile("test_square_mat.mm");
        mat2.PopulateFromFile("test_square_mat.mm");

        Mult(mat1, mat2, result_mat);

        ans_mat.SetSize(result_mat.GetNRows(), result_mat.GetNCols());
        for (int ii=0; ii<mat1.GetNRows(); ii++)
            for (int jj=0; jj<mat2.GetNCols(); jj++)
                for (int kk=0; kk<mat1.GetNCols(); kk++)
                {
                    ans_mat[ii][jj] += (10.0*(ii+1) + 1.0*(kk+1))*(10.0*(kk+1) + 1.0*(jj+1));
                }

        test3 = CompareMatrices(result_mat, ans_mat);
    }

    if (test1 && test2 && test3)
    {
        std::cout << "\n    \033[32mMult(Matrix, Matrix, Matrix) passed.\033[0m\n";
        return true;
    }
    else
    {
        std::cout << "\n    \033[31mMult(Matrix, Matrix, Matrix) failed.\033[0m\n";
        return false;
    } 
}
