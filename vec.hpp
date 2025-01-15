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

        // default constructor
        Vector(){}

        /**
         * @brief construct the vector with size() == entries.
         */
        Vector(const std::size_t entries);

        /**
         * @brief Populates the vector from a matrix market file indexed as 
         * either a row or column vector and sets vec_type accordingly.
         */
		void PopulateFromFile(std::string filename);

        /**
         * @brief Prints the contents of the vector into a matrix market format
         * within filename. Will index row or column wise depending on vec_type.
         */
		void PrintMM(std::string filename);

        /**
         * @brief Overrides the vec_type to be either column (true) or row (false).
         */
        inline void SetVecType(bool column_vector){vec_type = column_vector;}

        /**
         * @brief Returns the vector type set for a given Vector instance.
         */
        inline bool GetVecType(){return vec_type;}
};

#endif