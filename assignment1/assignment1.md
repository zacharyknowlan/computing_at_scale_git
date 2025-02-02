Question 2 Reponses

(a) How did you test your code? What are the limitations of your testing?
- My code is tested with a series of functions that perform the operations to be tested and compare outputs. One limitation of this approach is that the "Set" and "Get" functions used within each class cannot be independently evaluated because of private attributes.

(b) What approach did you take to document your functions and driver program?
- The functions are documented in the form of docstrings, which can be found above each function in the header files of the testing, numerical integration, and function libraries.

(c) How did you handle errors? How did you test your error handling strategy?
- Errors are handled by throwing an exception. This error handling strategy is specific to each function, but in general it was tested by inputing known incompatible arguments.

(d) Is your code robust to errors in the input files? How did you test this?
- The code does not use any input files. If the command line options are wrong, the code will use default settings. This was tested giving the code incorrect inputs.

(e) Are there any limitations in your implementation that you are aware of? Do you have ideas as to how to address them?
- This code only works for 1D functions. To address this the polynomial class would have to consider many more coefficients and the integration routines would also have to use completely different rules for multiple dimensions.

(f) If you wanted to optimize the performance of your code, what approach would you take?
- I would measure the exectution time of each function and find the bottleneck of my program i.e. the function that takes the most amount of time, and then focus on optimizing that function first before investigating other parts of the implementation.

(g) How would you extend your code to two or more dimensions.
- All of the integration rules would have either be changed to be valid in or generalized to multiple dimensions. Additionally the polynomial function would have to use a coefficient structure corresponding to a complete polynomial on pascals triangle as opposed to its current 1D form.

(h) Explain how you would handle a user defined function that takes additional parameters.
- I believe one answer would be to provide an operator() definition in a derived class that takes more than one arguments (in this case the position + something else).

(i) Are there any ways you could handle arbritrary functions that are defined at runtime by the user for example in an input file?
- Yes, a "Function" template could be used that would use the information in an input file to create an function object at runtime.