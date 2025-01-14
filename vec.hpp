#ifndef VEC_HPP
#define VEC_HPP

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cassert>

class Vector : public std::vector<double>
{
    protected:
        
        /* 0 = column_vector and 1 = row_vector... this exists to
        appropriately print the matrix market format of a given vector */
        bool vec_type = true; 

    public:

        Vector(){}

        Vector(const std::size_t entries);

		void PopulateFromFile(std::string filename);

		void PrintMM(std::string filename);

        inline void SetVecType(bool column_vector){vec_type = column_vector;}

        inline bool GetVecType(){return vec_type;}
};

#endif