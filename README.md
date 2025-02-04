To run the assignment1 code use the following commands:
1. `git clone git@github.com:zacharyknowlan/computing_at_scale_git.git -b assignment1`
2. `cd computing_at_scale_git/assignment1/`
3. `cmake -S . -B build`
4. `cd build/`
5. `make`
6. To run the executable for polynomial_integrate.cpp: `./main` and include command line options
7. To run the executable for unit_tests.cpp: `./tests` (no command line options for testing)

The following command line options are available for polynomial_intagrate.cpp:
1. `-ir QuadratureType NumPoints` specifies the integration rule where either `GaussLegendre` `GaussLobatto` `ChebyshevType1` `ChebyshevType2` `Custom` is used in place of QuadratureType and an integer number of points is used in place of NumPoints. Note. if `Custom` is used, the user will have to edit the vectors of points and weights within the `polynomial_integrate.cpp` file and then recompile the code. An example would look like `-ir GaussLegendre 3`
2. `-l a b` specifies the limits of integration where a is the lower bound and b is the upper bound. Note that when using any of the Chebyshev rules a and b will be ignored. An example would look like `-l -2. 2.`.
3. `-c coeffs` allows the user to define the coefficients of the polynomial where $y = \text{coeffs[0]} + \text{coeffs[1]}*x + \text{coeffs[2]}*x^2$... Any number of coefficients can be given. An example would be `-c 1. 2. 3. 4.`.

Together an example command line for the polynomial_integrate.cpp executable:
- `./main -ir GaussLegendre 3 -l -2. 2. -c 1. 2. 3. 4.`