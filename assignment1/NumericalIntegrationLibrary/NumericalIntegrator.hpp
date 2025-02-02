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
        NumericalIntegrator(IntegrationRule &int_rule){SetIntegrationRule(int_rule);}

        /**
         * Set the IntegrationRule to be used by the NumericalIntegrator.
         */
        void SetIntegrationRule(IntegrationRule &int_rule) {ir = int_rule;}

        /**
         * Get the IntegrationRule used by the NumericalIntegrator.
         */
        IntegrationRule &GetIntegrationRule() {return ir;}
        
        /**
         * Numerically computes the integral of Polynomial func on the interval [a,b].
         * 
         * Note: This function will ignore the interval provided [a,b] if the QuadratureType
         * of the IntegrationRule is ChebyshevType1 or ChebyshevType2 because linear mapping
         * is not valid.
         */
        [[nodiscard]] double ComputeIntegral(Polynomial &func, double a, double b);
};

#endif 