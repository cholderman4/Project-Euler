// ProjectEuler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

#include "BigInt.h"
#include "CompletedProblems.h"
#include "PrimeSieve.h"
#include "UtilityHelpers.h"
#include "Timing.h"

using namespace util;
using namespace completed;

using Int = uint64_t;

Int number_spiral_diagonals()
{
    constexpr Int GRIDSIZE = 1001;
    constexpr Int GRID_RINGS = (GRIDSIZE - 1) / 2;

    Int sum = 1;
    Int n = 1;
    for (auto ring = 1; ring <= GRID_RINGS; ++ring)
    {
        for (auto i = 0; i < 4; ++i)
        {
            n += (2 * ring);
            sum += n;
        }
    }

    return sum;
}

int main()
{
    std::cout << number_spiral_diagonals() << std::endl;
    //TimeFunction(quadratic_primes);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
