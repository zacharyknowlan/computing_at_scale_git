#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP 

#include "ScalarFunction.hpp"
#include <vector>
#include <cmath>

class Polynomial : public ScalarFunction
{
    private:

        std::vector<double> C; // Polynomial coeficients

    public:

        Polynomial(){}

        /**
         * Constructor that initializes the Polynomial class with its coefficients
         * as a vector. The vector of coefficients results in a polynomial of the
         * form y = coeffs[0] + coeffs[1]*x + coeffs[2]*x^2 ...
         */
        Polynomial(std::vector<double> &coeffs){SetCoefficients(coeffs);}

        /**
         * The SetCoefficients() method sets the Polynomial class vector
         * of coefficients that results in a polynomial of the form
         * y = coeffs[0] + coeffs[1]*x + coeffs[2]*x^2 ...
         */
        void SetCoefficients(std::vector<double> &coeffs) {C = coeffs;}

        /**
         * Returns the vector of coefficients associated with the Polynomial object
         * where y = coeffs[0] + coeffs[1]*x + coeffs[2]*x^2 ...
         */
        std::vector<double> &GetCoefficients() {return C;}

        /**
         * operator() overrides from abstract class ScalarFunction and returns 
         * the value of the Polynomial function at location position
         */
        [[nodiscard]] double operator()(double position) override;

        ~Polynomial(){}
};

#endif