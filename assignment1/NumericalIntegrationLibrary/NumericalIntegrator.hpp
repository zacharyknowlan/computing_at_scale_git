#ifndef NUMERICAL_INTEGRATOR_HPP
#define NUMERICAL_INTEGRATOR_HPP

#include <vector>
#include <stdexcept>
#include "IntegrationRule.hpp"
#include "Polynomial.hpp"

class NumericalIntegrator
{
    private:
        IntegrationRule ir; // IntegrationRule used to compute the integral
        
    public:

        NumericalIntegrator() {};
        
        /**
         * Construct the NumericalIntegrator with an IntegrationRule.
         */
        NumericalIntegrator(IntegrationRule &int_rule) : ir(int_rule) {}

        /**
         * Set the IntegrationRule to be used by the NumericalIntegrator.
         * This exists for convenience but in general the constructor that 
         * accepts the IntegrationRule should be used.
         */
        void SetIntegrationRule(IntegrationRule &int_rule) {ir = int_rule;}
        
        /**
         * Numerically computes the integral of Polynomial func on the interval [a,b].
         */
        [[nodiscard]] double ComputeIntegral(Polynomial &func, double a, double b);
};

#endif 