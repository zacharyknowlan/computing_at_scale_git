Question 3 - Zachary Knowlan

- (a) Code has been tested using functions that compare an expected output of the function with the actual output of the function.
- (b) The matrix market format is not an efficient way to store data as it requires significant space to store all of the row indices, column indices, and data.
- (c) Knowing the size of the matrix at compile time allows for the matrix to be statically allocated which can improve performance.
- (d) My matrices are stored using a row-major approach. I decided this based on the logicality of the index ordering. This will make grabbing an entire row faster as it can all be loaded at once while grabbing a column will be less efficient because its the first entry of each row as opposed to its own vector.
- (e) Documentation for the driver program is in a README.md file. Documentation for the functions is provided in the header files vec.hpp, mat.hpp, and mult.hpp.
- (f) My code is not robust to errors in the input file. Possible permutations that are not accounted for include: total number of rows/columns are incorrect, total number of entries incorrect, indicies perscribed as a float value, indices and values delimited by something other than spaces.
- (g) The main limitations of this implemention have to do with the ability to read the matrix-market files. In theory, I could parse through all the possible errors I can think of and build guards in such that the errors will be flagged and the functions will tell the user what the problem is. The maximum size of the matrix I can handle is capped size of the stack memory less the amount of memory required for all miscelanous indicies, values etc. The maximum matrix I could handle would be any combination of dimensions that when mutliplied are less than total avialable memory / 8 bytes (double).
- (h) Figure out how to parallelize the matrix multiplication functions.
