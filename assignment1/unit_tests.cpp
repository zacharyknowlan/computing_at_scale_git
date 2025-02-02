#include "TestingFunctions.hpp"

int main(int argc, char* argv[])
{
    // Testing is split up according to classes within each of the below functions
    
    // Test the member functions of the Polynomial class
    TestPolynomial();
    
    // Test all member functions of the IntegrationRule class
    TestIntegrationRule();
    
    // Test all member functions of the NumericalIntegrator class
    TestNumericalIntegrator();

    return 0;
}