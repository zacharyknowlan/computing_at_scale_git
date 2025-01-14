#include "mat.hpp"

Matrix::Matrix(const std::size_t rows, const std::size_t cols)
{
    SetSize(rows, cols);
}

void Matrix::SetSize(const std::size_t rows, const std::size_t cols)
{
    assert(rows > 0 && cols > 0);
    mat.resize(rows);
    for(int row=0; row<rows; row++)
    {
        mat[row].resize(cols);
    }
}

void Matrix::PopulateFromFile(std::string filename)
{
    std::ifstream infile(filename);
    std::string line;
    bool key_line = true;

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
                if (key_line) // size matrix based on key line
                {
                    const std::size_t N_rows = std::stoi(params[0]);
                    const std::size_t N_cols = std::stoi(params[1]);
                    SetSize(N_rows, N_cols);
                    key_line = false;
                }
                else
                {
                    int row = (std::stoi(params[0]) - 1);
                    int col = (std::stoi(params[1]) - 1);
                    double data = std::stod(params[2]);
                    mat[row][col] = data;
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

void Matrix::PrintMM(std::string filename)
{
    std::ofstream outfile(filename);

    if (outfile.is_open())
    {
        outfile << "% MatrixMarket matrix coordinate real general\n";

        int nonzero_count = 0;
        double tol = 1e-10;

        for (int ii=0; ii<GetNRows(); ii++)
            for (int jj=0; jj<GetNCols(); jj++)
            {
                if (std::abs(mat[ii][jj]) > tol)
                {
                    nonzero_count++;
                }
            }
            
        outfile << GetNRows() << " " << GetNCols();
        outfile << " " << nonzero_count;

        for (int kk=0; kk<GetNRows(); kk++)
            for (int ll=0; ll<GetNCols(); ll++)
            {
                if (std::abs(mat[kk][ll]) > tol)
                {
                    outfile << "\n" << (kk+1) << ' ' << (ll+1);
                    outfile << ' ' << std::scientific << mat[kk][ll];
                }
            }
        outfile.close();
    }
}