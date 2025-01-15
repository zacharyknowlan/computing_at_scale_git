#include <iostream>
#include "../mat.hpp"
#include "../mult.hpp"
#include "../vec.hpp"
#include "tests.hpp"

int main(int argc, char* argv[])
{
    TestMatrix();

    TestVector();

    TestMult();

    std::cout << "\n";

    return 0;
}