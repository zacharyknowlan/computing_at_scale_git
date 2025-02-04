#include "Polynomial.hpp"
#include "NumericalIntegrator.hpp"
#include "IntegrationRule.hpp"
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
    // Initialize all arrays and provide defaults
    std::vector<double> coeffs = {0, 1};
    std::string quad_type = "GaussLegendre";
    int num_points = 4;
    double a = -1.;
    double b = 1.;

    // Parse all command line options
    for (int ii=0; ii<argc; ii++)
	{
		std::string arg = argv[ii];
		if (arg == "-ir" || arg == "--int_rule") 
        {
            quad_type = std::string(argv[ii+1]);
            num_points = std::stoi(argv[ii+2]);
        } 
		else if (arg == "-l" || arg == "--limits") 
        {
            a = std::stod(argv[ii+1]);
            b = std::stod(argv[ii+2]); 
        }
		else if (arg == "-c" || arg == "--coeffs") // Find when coefficients start
        {
            coeffs.resize(0);
            for (int jj=1; (ii+jj)<argc; jj++) // Process all coefficients until next command line option
            {
                std::string sub_arg = argv[ii+jj];
                if (sub_arg != "-ir" && sub_arg != "--int_rule" && sub_arg != "-l" && sub_arg != "--limits")
                {
                    coeffs.push_back(std::stod(sub_arg));
                }
                else {break;}
            }
        }
	}

    IntegrationRule integ_rule; // Set IntegrationRule based on command line options

    if (quad_type == "GaussLegendre")
    {
        integ_rule = IntegrationRule(IntegrationRule::QuadratureType::GaussLegendre, num_points);
    }
    else if (quad_type == "GaussLobatto")
    {
        integ_rule = IntegrationRule(IntegrationRule::QuadratureType::GaussLobatto, num_points);
    }
    else if (quad_type == "ChebyshevType1")
    {
        integ_rule = IntegrationRule(IntegrationRule::QuadratureType::ChebyshevType1, num_points);
    }
    else if (quad_type == "ChebyshevType2")
    {
        integ_rule = IntegrationRule(IntegrationRule::QuadratureType::ChebyshevType2, num_points);
    }
    else if (quad_type == "Custom")
    {
        integ_rule = IntegrationRule(IntegrationRule::QuadratureType::Custom, num_points);
        std::vector<double> points; // = EDIT HERE
        integ_rule.SetPoints(points);
        std::vector<double> weights; // = EDIT HERE 
        integ_rule.SetWeights(weights);
    }


    auto poly = Polynomial(coeffs); // Define polynomial coeffs[0] + coeffs[1]*x + coeffs[2]*x^2 ...
    auto num_integ = NumericalIntegrator(integ_rule); // Create numerical integrator object
    double integ_val = num_integ.ComputeIntegral(poly, a, b); // Evaluate the integral of poly on interval [a,b]
    
    std::cout << "\nFunction Integral: " << integ_val << "\n\n"; // Print out result

    return 0;
}