#include "TestingFunctions.hpp"

void TestPolynomial()
{
    std::cout << "\nTesting Polynomial...\n";
    auto test1 = TestPolynomialSetAndGetCoefficients();
    auto test2 = TestPolynomialCallOperator();
    auto test_total = test1 + test2;
    std::cout << test_total << " Polynomial test(s) failed.\033[0m\n";
}

int TestPolynomialSetAndGetCoefficients()
{
    std::vector<double> coeffs = {43.0, 93.0, 12.0, -38.0};
    Polynomial poly;
    
    // Test the SetCoefficients method
    poly.SetCoefficients(coeffs); 
    
    // Test the GetCoefficients method
    std::vector<double> poly_coeffs = poly.GetCoefficients();

    for (int ii=0; ii<coeffs.size(); ii++)
    {
        if (std::abs(coeffs[ii] - poly_coeffs[ii]) < tol) {continue;}
        else {return 1;}
    }
    std::cout << "\033[32m" << "    SetCoefficients and ";
    std::cout << "GetCoefficients work." << "\033[0m\n";
    return 0;
}

int TestPolynomialCallOperator()
{
    std::vector<double> coeffs = {8.3, -2.9, 3.4};
    Polynomial poly(coeffs);
    double loc = 3.27;

    // Test the call operator
    double poly_val = poly(loc); 
    
    double exact_val = coeffs[0] + coeffs[1]*loc + coeffs[2]*loc*loc;
    if (std::abs(poly_val - exact_val) < tol)
    {
        std::cout << "\033[32m" << "    SetCoefficients and ";
        std::cout << "GetCoefficients work." << "\033[0m\n";
        return 0;
    }
    else 
    {
        std::cout << "\033[32m" << "    SetCoefficients or GetCoefficients ";
        std:: cout << "does not work." << "\033[0m\n";
        return 1;
    }
}

void TestIntegrationRule()
{
    std::cout << "\nTesting IntegrationRule...\n";
    auto test1 = TestIntegrationRuleSetAndGetPoints();
    auto test2 = TestIntegrationRuleSetAndGetWeights();
    auto test3 = TestIntegrationRuleGetPoint();
    auto test4 = TestIntegrationRuleGetWeight();
    auto test_total = test1 + test2 + test3 + test4;
    std::cout << test_total << " IntegrationRule test(s) failed.\033[0m\n";
}

int TestIntegrationRuleSetAndGetPoints()
{
    std::vector<double> points = {-0.1, 0.8, 0.4, 0.7};
    IntegrationRule int_rule;

    // Test the SetPoints method
    int_rule.SetPoints(points);

    // Test the GetPoints method
    std::vector<double> ir_points = int_rule.GetPoints();

    for (int ii=0; ii<points.size(); ii++)
    {
        if (std::abs(points[ii] - ir_points[ii]) < tol) {continue;}
        else 
        {
            std::cout << "\033[31m" << "    SetPoints or GetPoints ";
            std::cout << "does not work." << "\033[0m\n";
            return 1;
        }
    }
    std::cout << "\033[32m" << "    SetPoints and GetPoints ";
    std::cout << "work." << "\033[0m\n";
    return 0;
}

int TestIntegrationRuleSetAndGetWeights()
{
    std::vector<double> weights = {0.5, 0.5, 0.3, 0.7};
    IntegrationRule int_rule;

    // Test the SetWeights method
    int_rule.SetWeights(weights);

    // Test the GetWeights method
    std::vector<double> ir_weights = int_rule.GetWeights();
    
    for (int ii=0; ii<weights.size(); ii++)
    {
        if (std::abs(weights[ii] - ir_weights[ii]) < tol) {continue;}
        else 
        {
            std::cout << "\033[31m" << "    SetWeights or GetWeights ";
            std::cout << "does not work." << "\033[0m\n";
            return 1;
        }
    }
    std::cout << "\033[32m" << "    SetWeights and GetWeights ";
    std::cout << "work." << "\033[0m\n";
    return 0;
}

int TestIntegrationRuleGetPoint()
{
    IntegrationRule int_rule(IntegrationRule::QuadratureType::GaussLegendre, 2);

    // Test the GetPoint method
    double test_point = int_rule.GetPoint(0);

    if (std::abs(test_point + 1./std::sqrt(3.)) < tol) 
    {
        std::cout << "\033[32m" << "    GetPoint ";
        std::cout << "works." << "\033[0m\n";
        return 0;
    }
    else 
    {
        std::cout << "\033[31m" << "    GetPoint ";
        std::cout << "does not work." << "\033[0m\n";
        return 1;
    }
}

int TestIntegrationRuleGetWeight()
{
    IntegrationRule int_rule(IntegrationRule::QuadratureType::GaussLobatto, 3);

    // Test the GetWeight method
    double test_weight = int_rule.GetWeight(1);

    if (std::abs(test_weight - 4./3.) < tol) 
    {
        std::cout << "\033[32m" << "    GetWeight ";
        std::cout << "works." << "\033[0m\n";
        return 0;
    }
    else 
    {
        std::cout << "\033[31m" << "    GetWeight ";
        std::cout << "does not work." << "\033[0m\n";
        return 1;
    }
}

int TestIntegrationRuleGetQuadratureType()
{
    IntegrationRule int_rule(IntegrationRule::QuadratureType::Custom, 3);
    if (int_rule.GetQuadratureType() == IntegrationRule::QuadratureType::Custom)
    {
        std::cout << "\033[32m" << "    The GetQuadratureType ";
        std::cout << "works." << "\033[0m\n";
        return 0;
    }
    else 
    {
        std::cout << "\033[31m" << "    GetQuadratureType ";
        std::cout << "does not work." << "\033[0m\n";
        return 1;
    }
}

void TestNumericalIntegrator()
{
    std::cout << "\nTesting NumericalIntegrator...\n";
    auto test1 = TestNumericalIntegratorSetAndGetIntegrationRule();
    auto test2 = TestNumericalIntegratorComputeIntegral();
    auto test_total = test1 + test2;
    std::cout << test_total << " NumericalIntegrator test(s) failed.\n\n";
}

int TestNumericalIntegratorSetAndGetIntegrationRule()
{
    NumericalIntegrator num_integ;
    IntegrationRule int_rule(IntegrationRule::QuadratureType::GaussLegendre, 4);
    
    // Test the SetIntegrationRule method
    num_integ.SetIntegrationRule(int_rule);

    // Test the GetIntegrationRule method
    IntegrationRule num_integ_int_rule = num_integ.GetIntegrationRule();

    for (int ii=0; ii<int_rule.GetPoints().size(); ii++)
    {
        if (std::abs(num_integ_int_rule.GetPoint(ii) - int_rule.GetPoint(ii)) < tol) {continue;}
        else 
        {
            std::cout << "\033[31m" << "    SetIntegrationRule or GetIntegrationRule";
            std::cout << "does not work." << "\033[0m\n";
            return 1;
        }
        if (std::abs(num_integ_int_rule.GetWeight(ii) - int_rule.GetWeight(ii)) < tol) {continue;}
        else 
        {
            std::cout << "\033[31m" << "    SetIntegrationRule or GetIntegrationRule";
            std::cout << "does not work." << "\033[0m\n";
            return 1;
        }
    }
    std::cout << "\033[32m" << "    SetIntegrationRule and ";
    std::cout << "GetIntegrationRule work." << "\033[0m\n";
    return 0;
}

int TestNumericalIntegratorComputeIntegral()
{
    {// Tests that GaussLegendre is able to integrate a polynomial of order 2(num_points)-1
        NumericalIntegrator num_integ;
        Polynomial poly;
        std::vector<double> coeffs = {4., 6.}; // Start as 1st order polynomial
        double integ_val;
        double integ_approx;

        // Define integration limits... non [-1,1] interval used to check linear mapping
        double a = -3.;
        double b = 4.;
        
        for (int ii=1; ii<5; ii++)
        {
            IntegrationRule int_rule(IntegrationRule::QuadratureType::GaussLegendre, ii);
            num_integ.SetIntegrationRule(int_rule);
            poly.SetCoefficients(coeffs);

            // Use the numerical integration routine
            integ_val = num_integ.ComputeIntegral(poly, a, b);

            // Compute analytical integral value
            integ_approx = 0.0;
            for (int jj=1; jj<(coeffs.size()+1); jj++)
            {
                integ_approx += (coeffs[(jj-1)]/jj) * std::pow(b,jj);
                integ_approx -= (coeffs[(jj-1)]/jj) * std::pow(a,jj);
            }

            if (std::abs(integ_approx - integ_val) > tol) 
            {
                std::cout << "\033[31m" << "    GaussLegendre ";
                std::cout << "quadrature does not work." << "\033[0m\n";
                return 1;
            }

            // Update coefficients to higher order polynomial for next iteration
            coeffs.push_back(2.);
            coeffs.push_back(3.);
        }
        std::cout << "\033[32m" << "    GaussLobatto quadrature works." << "\033[0m\n";
    }
    {// Tests that GaussLobatto is able to integrate a polynomial of order 2(num_points)-3
        NumericalIntegrator num_integ;
        Polynomial poly;
        std::vector<double> coeffs = {8., 9., 1.}; // Start as 2nd order polynomial
        double integ_approx;
        double integ_exact;

        // Define integration limits non [-1,1] interval used to check linear mapping 
        double a = -2.;
        double b = 1.;

        for (int ii=3; ii<6; ii++)
        {
            IntegrationRule int_rule(IntegrationRule::QuadratureType::GaussLobatto, ii);
            num_integ.SetIntegrationRule(int_rule);
            poly.SetCoefficients(coeffs);

            // Use the numerical integration routine
            integ_approx = num_integ.ComputeIntegral(poly, a, b);

            // Compute analytical integral value
            integ_approx = 0.0;
            for (int jj=1; jj<(coeffs.size()+1); jj++)
            {
                integ_approx += (coeffs[(jj-1)]/jj) * std::pow(b,jj);
                integ_approx -= (coeffs[(jj-1)]/jj) * std::pow(a,jj);
            }

            if (std::abs(integ_approx - integ_approx) > tol) 
            {
                std::cout << "\033[31m" << "    GaussLobatto ";
                std::cout << "quadrature does not work." << "\033[0m\n";
                return 1;
            }

            // Update coefficients to higher order polynomial for next iteration
            coeffs.push_back(2.);
            coeffs.push_back(3.);
        } 
        std::cout << "\033[32m" << "    GaussLobatto quadrature works." << "\033[0m\n";
    }
    { // Test the ChebyshevType1 based on the analytical integral of integral(-3x*sqrt(1-x^2))
    // which has an analytical solution of 0 on the domain [-1,1]
        IntegrationRule int_rule(IntegrationRule::QuadratureType::ChebyshevType1, 1e6);
        NumericalIntegrator num_integ(int_rule);
        std::vector<double> coeffs = {0., -3.};
        Polynomial poly(coeffs);

        // Function is not linearly mappable so use interval [-1,1]
        double integ_approx = num_integ.ComputeIntegral(poly, -1, 1);

        if (std::abs(integ_approx) > tol_cbyshv) 
        {
            std::cout << "\033[31m" << "    ChebyshevType1 ";
            std::cout << "quadrature does not work." << "\033[0m\n";
            return 1;
        }
        else
        {
            std::cout << "\033[32m" << "    ChebyshevType1 quadrature works." << "\033[0m\n";
        }
    }
    {// Test the ChebyshevType2 based on the analytical integral of integral(-2x/sqrt(1-x^2))
    // which has an analytical solution of 0 on the domain [-1,1]
        IntegrationRule int_rule(IntegrationRule::QuadratureType::ChebyshevType1, 1e6);
        NumericalIntegrator num_integ(int_rule);
        std::vector<double> coeffs = {0., -2.};
        Polynomial poly(coeffs);

        // Function is not linearly mappable so use interval [-1,1]
        double integ_approx = num_integ.ComputeIntegral(poly, -1, 1);

        if (std::abs(integ_approx) > tol_cbyshv) 
        {
            std::cout << "\033[31m" << "    ChebyshevType2 ";
            std::cout << "quadrature does not work." << "\033[0m\n";
            return 1;
        }
        else
        {
            std::cout << "\033[32m" << "    ChebyshevType2 ";
            std::cout << "quadrature works." << "\033[0m\n";
        }
    }

    return 0;
}