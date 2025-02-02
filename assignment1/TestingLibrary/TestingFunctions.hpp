#ifndef TESTING_FUNCTIONS_HPP
#define TESTING_FUNCTIONS_HPP

#include "Polynomial.hpp"
#include "IntegrationRule.hpp"
#include "NumericalIntegrator.hpp"
#include <iostream>
#include <cmath>

// This tolerance applies to most tests
const double tol = 1e-10; 

// This tolerance is used for testing Chebyshev quadrature rules only
const double tol_cbyshv = 1e-4; 

/**
 * Runs all of the test cases for the Polynomial class.
 * Prints the number of the Polynomial tests that failed to the terminal.
 */
void TestPolynomial();

/**
 * Tests the Polynomial::SetCoefficients(std::vector<double> &coeffs)
 * and the Polynomial::GetCoefficients() methods.
 * Prints the test results to the terminal.
 * Returns 1 if the test fails and 0 if the test passes.
 */
[[nodiscard]] int TestPolynomialSetAndGetCoefficients();

/**
 * Tests the Polynomial::operator()(double position) method. 
 * Prints the test results to the terminal.
 * Returns 1 if the test fails and 0 if the test passes.
 */
[[nodiscard]] int TestPolynomialCallOperator();

/**
 * Runs all of the test cases for the IntegrationRule class.
 * Prints the number of tests that failed to the terminal.
 */
void TestIntegrationRule();

/**
 * Tests the IntegrationRule::SetPoints() function 
 * Prints the test results to the terminal.
 * Returns 1 if the test fails and 0 if the test passes.
 */
[[nodiscard]] int TestIntegrationRuleSetAndGetPoints();

/**
 * Tests the IntegrationRule::SetWeights() function 
 * Prints the test results to the terminal.
 * Returns 1 if the test fails and 0 if the test passes.
 */
[[nodiscard]] int TestIntegrationRuleSetAndGetWeights();

/**
 * Tests the IntegrationRule::GetPoints() function. 
 * Prints the test results to the terminal.
 * Returns 1 if the test fails and 0 if the test passes.
 */
[[nodiscard]] int TestIntegrationRuleGetPoint();

/**
 * Tests the IntegrationRule::GetWeights() function.
 * Prints the test results to the terminal.
 * Returns 1 if the test fails and 0 if the test passes.
 */
[[nodiscard]] int TestIntegrationRuleGetWeight();

/**
 * Runs all the test cases for the NumericalIntegrator class.
 * Prints the number of tests that fail to the terminal.
 */
void TestNumericalIntegrator();

/**
 * Tests the NumericalIntegrator::SetIntegrationRule(IntegrationRule &int_rule) method. 
 * Prints the results of the test to the terminal.
 * Returns 1 if the test fails and 0 if the test passes.
 */
[[nodiscard]] int TestNumericalIntegratorSetAndGetIntegrationRule();

/**
 * Tests the NumericalIntegator::ComputeIntegral(Polynomial &poly, double a, double b) function. 
 * Prints the results of the test to the terminal.
 * Returns 1 if the test fails and 0 if the test passes. 
 * 
 * Note: This also serves as a test for all of the implemented QuadratureTypes within 
 * the IntegrationRule of the NumericalIntegrator object.
 */
[[nodiscard]] int TestNumericalIntegratorComputeIntegral();

#endif