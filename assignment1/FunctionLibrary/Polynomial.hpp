#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP 

#include "ScalarFunction.hpp"
#include <vector>
#include <cmath>

class Polynomial : ScalarFunction
{
    private:
        std::vector<double> C; // polynomial coeficients

    public:
        Polynomial(){}

        Polynomial(std::vector<double> &coeffs) : C(coeffs) {}

        [[nodiscard]] double operator()(double position) override;

};

#endif