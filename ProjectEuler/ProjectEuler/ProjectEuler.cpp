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

int64_t quadratic_primes()
{
    constexpr auto LIMIT = 1000u;
    auto sieve = PrimeSieve(13 * LIMIT);
    Int max_n = 40;
    int64_t ab = 41;
    int64_t b = 1;

    // By solving for n = 0 and n = 1, we can set conditions on a and b
    while ((b = sieve.next_prime(b)) < LIMIT)
    {
        int64_t p = 1;
        while ((p = sieve.next_prime(p)) < LIMIT + 1 + b && b < LIMIT - 1 + p)
        {
            const int64_t a = p - b - 1;

            // Start at 2, since we already know 0 & 1.
            int64_t n = 2;
            while (true)
            {
                const int64_t p_test = n * n + a * n + b;
                if (p_test <= 1)
                    break;

                // From previous tests, we know we won't need to resize
                /*if (sieve.limit() < p_test)
                {
                    sieve.rebuild_integer_limit(p_test);
                }*/

                if (!sieve.is_prime(p_test))
                    break;
                ++n;
            }

            if (n > max_n)
            {
                max_n = n;
                ab = a * b;
            }
        }
    }

    return ab;
}

int main()
{
    std::cout << quadratic_primes() << std::endl;
    TimeFunction(quadratic_primes);

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
