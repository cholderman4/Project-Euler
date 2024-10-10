// ProjectEuler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

#include "BigInt.h"
#include "CompletedProblems.h"
#include "UtilityHelpers.h"
#include "Timing.h"

using namespace util;
using namespace completed;

using Int = uint64_t;

Int fibonacci_1000_digit()
{
    constexpr auto MAX_DIGIT = 1000u;
    BigInt a = 1;
    BigInt b = 1;
    BigInt c = a + b;
    Int step = 3;
    while(c.digits10() < MAX_DIGIT)
    {
        a = b;
        b = c;
        c += a;
        ++step;
    }

    return step;
}


int main()
{
    std::cout << fibonacci_1000_digit() << std::endl;
    //std::cout << "sum: " << factorial_digit_sum() << std::endl;

    //TimeFunction(fibonacci_1000_digit);
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
