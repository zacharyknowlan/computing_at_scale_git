#include "IntegrationRule.hpp"

IntegrationRule::IntegrationRule(QuadratureType q_type, int num_points)
{
    // Make sure the user provided a valid number of points
    if (num_points < 1) 
    {
        throw std::invalid_argument("Number of points must be greater than 0.");
    }

    // Set locations and weights and QuadratureType based on num_points
    this->x.resize(num_points); 
    this->w.resize(num_points);
    this->q = q_type;

    // Assign weights and points based on QuadratureType
    switch (q_type) 
    {
        case this->QuadratureType::GaussLegendre:
            if (num_points >= 5)
            {
                throw std::invalid_argument(std::to_string(num_points) 
                                            + " point Gauss-Legendre quadrature not implemented.");
            }
            // Assign weights and points based on num_points for GaussLegendre quadrature
            switch (num_points)
            {
                case 1:
                    x[0] = 0.;
                    w[0] = 2.;
                    break;
                case 2:
                    x[0] = -1./std::sqrt(3.);
                    x[1] = 1./std::sqrt(3.);
                    w[0] = 1.;
                    w[1] = 1.;
                    break;
                case 3:
                    x[0] = -std::sqrt(3./5.);
                    x[1] = 0.;
                    x[2] = std::sqrt(3./5.);
                    w[0] = 5./9.;
                    w[1] = 8./9.;
                    w[2] = 5./9.;
                    break;
                case 4:
                    x[0] = -std::sqrt(3./7. + 2./7.*std::sqrt(6./5.));
                    x[1] = -std::sqrt(3./7. - 2./7.*std::sqrt(6./5.));
                    x[2] = std::sqrt(3./7. - 2./7.*std::sqrt(6./5.));
                    x[3] = std::sqrt(3./7. + 2./7.*std::sqrt(6./5.));
                    w[0] = (18. - std::sqrt(30.))/36.;
                    w[1] = (18. + std::sqrt(30.))/36.;
                    w[2] = (18. + std::sqrt(30.))/36.;
                    w[3] = (18. - std::sqrt(30.))/36.;
                    break;                    
            }
            break;

        case this->QuadratureType::GaussLobatto:
            if (num_points >= 6 || num_points <= 2) // Make sure user provided a valid number of points
            {
                throw std::invalid_argument(std::to_string(num_points) 
                                            + " point Gauss-Legendre quadrature not implemented.");
            }
            // Assign weights and points based on num_points for GaussLobatto quadrature
            switch (num_points)
            {
                case 3:
                    x[0] = -1.;
                    x[1] = 0.;
                    x[2] = 1.;
                    w[0] = 1./3.;
                    w[1] = 4./3.;
                    w[2] = 1./3.;
                    break;
                case 4:
                    x[0] = -1.;
                    x[1] = -std::sqrt(1./5.);
                    x[2] = std::sqrt(1./5.);
                    x[3] = 1.;
                    w[0] = 1./6.;
                    w[1] = 5./6.;
                    w[2] = 5./6.;
                    w[3] = 1./6.;
                    break;                
                case 5:
                    x[0] = -1.;
                    x[1] = -std::sqrt(3./7.);
                    x[2] = 0.;
                    x[3] = std::sqrt(3./7.);
                    x[4] = 1.;
                    w[0] = 1./10.;
                    w[1] = 49./90.;
                    w[2] = 32./45.;
                    w[3] = 49./90.;
                    w[4] = 1./10.;
                    break;
            }
            break;

        case this->QuadratureType::ChebyshevType1:
            // Assign weights and points for num_points points for ChebyshevType1 quadrature
            for (int ii=0; ii<num_points; ii++)
            {
                x[ii] = std::cos((2.*ii-1.)*M_PI/(2.*num_points));
                w[ii] = M_PI/num_points;
            }
            break;

        case this->QuadratureType::ChebyshevType2:
            // Assign weights and points for numpoints_points for ChebyshevType1 quadrature
            for (int ii=0; ii<num_points; ii++)
            {
                x[ii] = std::cos(ii*M_PI/(num_points+1.));
                w[ii] = M_PI/(num_points+1.)*std::pow(std::sin(ii*M_PI/(num_points+1.)), 2);
            }
            break;
    }
}

void IntegrationRule::SetPoints(std::vector<double> &points)
{
    this->x = points;
    this->q = this->QuadratureType::Custom;
}

void IntegrationRule::SetWeights(std::vector<double> &weights)
{
    this->w= weights;
    this->q = this->QuadratureType::Custom;
}