#include "Polynomial.hpp"

double Polynomial::operator()(double position)
{
    double func_val = 0;
    // Loop through all coefficients and compute function value
    for (int ii=0; ii<this->C.size(); ii++)
    {
        func_val += this->C[ii] * std::pow(position, ii);
    }
    return func_val;
}