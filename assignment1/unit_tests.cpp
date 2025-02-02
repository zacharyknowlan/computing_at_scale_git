#include "TestingFunctions.hpp"

int main(int argc, char* argv[])
{
    // Testing is split up according to classes within each of the below functions
    
    // Test the member functions of the Polynomial class
    int poly_tests = TestPolynomial();
    
    // Test all member functions of the IntegrationRule class
    int int_rule_tests = TestIntegrationRule();
    
    // Test all member functions of the NumericalIntegrator class
    int num_integ_tests = TestNumericalIntegrator();

    return poly_tests + int_rule_tests + num_integ_tests;
}