#include "NumericalIntegrator.hpp"

double NumericalIntegrator::ComputeIntegral(Polynomial &func, double a, double b)
{
    // Check if the IntegrationRule is even possibly valid
    if (this->ir.GetWeights().size() != this->ir.GetPoints().size())
    {
        throw std::invalid_argument("IntegrationRule number of weights doesn't match the number of points");
    }
    // Initialize and compute integral
    double integral = 0.0;
    for (int ii=0; ii<this->ir.GetPoints().size(); ii++)
    {
        // Compute integral for mapped value based on interval [a,b]
        integral += this->ir.GetWeight(ii) * func(((b-a)/2.)*this->ir.GetPoint(ii)+((a+b)/2.));
    }
    // Scale and correct integral value to interval [a,b]
    integral *= ((b-a)/2.);
    
    return integral;
}