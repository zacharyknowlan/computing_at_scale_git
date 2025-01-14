#include "vec.hpp"

Vector::Vector(const std::size_t entries)
{
    this->resize(entries);
}

void Vector::PopulateFromFile(std::string filename)
{
    std::ifstream infile(filename);
    std::string line;
    bool key_line = true;
    double data;
    int idx;

    if (infile.is_open())
    {
        while (std::getline(infile, line))
        {
            if (line[0] == '%') // skip comments
            {
                continue;
            }
            else
            {
                std::istringstream iss(line);
                std::vector<std::string> params;
                std::string p;
                while (std::getline(iss, p, ' ')) 
                {
                    if (!p.empty())
                    {
                        params.push_back(p);
                    }
                }
                if (key_line) // size vector and determine vector type from key line
                {
                    const std::size_t N_rows = std::stoi(params[0]);
                    const std::size_t N_cols = std::stoi(params[1]);

                    assert(N_rows == 1 || N_cols == 1);

                    if (N_rows > N_cols)
                    {
                        this->resize(N_rows);
                    }
                    else
                    {
                        this->resize(N_cols);
                        this->vec_type = false;
                    }
                    key_line = false;
                }
                else
                {
                    data = std::stod(params[2]);
                    if (this->vec_type) {idx = (std::stoi(params[0]) - 1);}
                    else {idx = (std::stoi(params[1]) - 1);}
                    (*this)[idx] = data;
                }
            }
        }
        infile.close();
    }
    else
    {
        std::cout << "Error opening file: " << filename << "\n";
    }			
}

void Vector::PrintMM(std::string filename)
{
    std::ofstream outfile(filename);

    if (outfile.is_open())
    {
        outfile << "% MatrixMarket matrix coordinate real general\n";

        int nonzero_count = 0;
        double tol = 1e-10;

        for (int ii=0; ii<this->size(); ii++)
            {
                if (std::abs((*this)[ii]) > tol)
                {
                    nonzero_count++;
                }
            }
            
        if (this->vec_type) // determine how to write file from vec_type
        {    
            outfile << size() << " " << 1;
        }
        else
        {
            outfile << 1 << " " << size();
        }
        outfile << " " << nonzero_count;

        for (int jj=0; jj<this->size(); jj++)
        {
            if (std::abs((*this)[jj]) > tol) // write only non-zero entries to file
            {
                if (this->vec_type) // determine how to write file from vec_type
                {
                    outfile << "\n" << (jj+1) << ' ' << 1;
                }
                else
                {
                    outfile << "\n" << 1 << ' ' << (jj+1);
                }
                outfile << ' ' << std::scientific << (*this)[jj];
            }
        }
        outfile.close();
    }
}