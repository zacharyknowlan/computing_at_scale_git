To download this repository in a directory of your choice use.
1. cd directory_of_your_choice/
2. git clone https://github.com/zacharyknowlan/computing_at_scale_git

To run this code using the driver function:
2. cd computing_at_scale_git/
3. make
4. ./assignment0 

NOTE: the following command line options are used when running the assignment0 binary
1. "-c" or "--comp_type" specifies matrix-vector or matrix-matrix multiplication.
2. "-vf" or "--vec_filename" specifies the filename of a vector to be mutliplied.
3. "-mf" or "--mat_filename" specifies the filename of a matrix to be multiplied.
4. "-m2f" or "--mat2_filename" specifies the filename of a 2nd matrix (matrix-matrix multiplication only).

To test this code using the implemented tests:

1. cd computing_at_scale_git/testing/
2. make
3. ./assignment0_tests

NOTE: there are no command line options for testing


File overview:

- mult.hpp/mult.cpp contains the files required for matrix-matrix and matrix-vector multiplcation
- mat.hpp/mat.cpp contains a class and member functions to create a matrix and populate that matrix from a .mm file, and write an existing matrix to .mm file.
- vec.hpp/vec.cpp contains a class with public functions inherited from std::vector that allows a vector to be populated by a .mm file and write to a .mm file.
- testing/ contains example matrices and vectors in the .mm format as well as test.hpp/test.cpp which are complied to test the code.

NOTE: pairs of matrices and vectors that are dimensionally compatible
- "-vf testing/test_row_vec.mm -mf testing/test_rectangle_mat.mm"
- "-vf testing/test_col_vec.mm -mf testing/test_square_mat.mm"
- "-vf testing/test_col_vec.mm -mf testing/test_identity_mat.mm"
- "-vf testing/test_col_vec.mm -mf testing/test_rectangle_mat.mm"
- "-mf testing/test_square_mat.mm -m2f testing/test_square_mat.mm"
- "-mf testing/test_square_mat.mm -m2f testing/test_rectangle_mat.mm"
- "-mf testing/test_square_mat.mm -m2f testing/test_identity_mat.mm"

All results will appear as "result_vec.mm" or "result_mat.mm".