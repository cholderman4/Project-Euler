#include "PrimeSieve.h"

#include <iostream>

PrimeSieve::PrimeSieve(const Int N) : sieve(N, 1), maxN{ N }
{
    sieve[0] = 0;
    Int p = 2;
    while (p * p <= maxN)
    {
        // Mark off all multiples of p
        // Start at 2p, since p is prime
        for (auto i = 2 * p; i <= maxN; i += p)
            sieve[i - 1] = 0;

        // Find next prime
        while (++p <= maxN)
        {
            if (sieve[p - 1] == 1)
                break;
        }
    }
}

bool PrimeSieve::is_prime(const Int n) const
{
    if (n > maxN) return false;

    return sieve[n-1] == 1;
}

PrimeSieve::Int PrimeSieve::next_prime(Int n) const
{
    Int p = n;
    // Find next prime
    while (++p <= maxN)
    {
        if (sieve[p - 1] == 1)
            return p;
    }

    return 0;
}

//void PrimeSieve::rebuild_prime_limit(const Int p)
//{
//    rebuild_integer_limit(p * p);
//}

void PrimeSieve::rebuild_integer_limit(const Int n)
{
    if (n <= maxN) return;

    maxN = n;
    sieve.resize(maxN, 1);
    Int p = 2;
    while (p * p <= maxN)
    {
        // Mark off all multiples of p
        // Start at 2p, since p is prime
        for (auto i = 2 * p; i <= maxN; i += p)
            sieve[i - 1] = 0;

        // Find next prime
        while (++p <= maxN)
        {
            if (sieve[p - 1] == 1)
                break;
        }
    }
}

void PrimeSieve::print() const
{
    for (auto i = 1; i <= sieve.size(); ++i)
    {
        if (sieve[i - 1] == 1)
            std::cout << i << std::endl;
    }
}
