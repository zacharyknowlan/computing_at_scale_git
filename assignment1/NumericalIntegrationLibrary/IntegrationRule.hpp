#ifndef INTEGRATION_RULE_HPP
#define INTEGRATION_RULE_HPP

#include <vector>
#include <stdexcept>
#include <cmath>
#include <iostream>

class IntegrationRule
{
    private:
        std::vector<double> w; // weights
        std::vector<double> x; // locations

    public:
        enum QuadratureType
        {
            GaussLegendre, // 1, 2, 3, and 4 point rules implemented
            GaussLobatto,  // 3, 4, and 5 point rules implemented
            ChebyshevType1, // For functions f(x)/sqrt(1-x^2)
            ChebyshevType2, // For functions g(x)*sqrt(1-x^2)
            Custom // Requires the user to call SetPoints() and SetWeights()
        };

        IntegrationRule(){}

        /**
         * Construct the IntegrationRule with a quadrature type and number of points
         */
        IntegrationRule(QuadratureType q_type, int num_points);

        /**
         * Set the points (sampling locations) for a Custom IntegrationRule. Note that
         * point[ii] corresponds to weight[ii]
         */
        inline void SetPoints(std::vector<double> &points) {this->x = points;}

        /**
         * Set the weights of the sampling locations. Note that weight[ii]
         * corresponds to point[ii]
         */
        inline void SetWeights(std::vector<double> &weights){this->w = weights;}

        /**
         * Get a reference to the vector of points (sampling locations) set.
         */
        [[nodiscard]] inline std::vector<double> &GetPoints() {return this->x;}

        /**
         * Get a reference to the vector of weights set.
         */
        [[nodiscard]] inline std::vector<double> &GetWeights() {return this->w;}
        
        /**
         * Returns the idx'th point of the IntegrationRule
         */
        [[nodiscard]] inline double GetPoint(int idx) {return this->x[idx];}

        /**
         * Returns the idx'th weight of the IntegrationRule
         */
        [[nodiscard]] inline double GetWeight(int idx) {return this->w[idx];}

};

#endif 