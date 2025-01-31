#ifndef SCALAR_FUNCTION_HPP
#define SCALAR_FUNCTION_HPP

class ScalarFunction 
{
    public:
        [[nodiscard]] virtual double operator()(double position) = 0;

    ScalarFunction(){}
};

#endif