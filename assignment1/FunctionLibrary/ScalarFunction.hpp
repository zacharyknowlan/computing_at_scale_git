#ifndef SCALAR_FUNCTION_HPP
#define SCALAR_FUNCTION_HPP

class ScalarFunction 
{
    public:

        /**
         * Assumes the function is continous on a given 1D interval [a,b]
         */
        [[nodiscard]] virtual double operator()(double position) = 0;

        virtual ~ScalarFunction() {}
};

#endif