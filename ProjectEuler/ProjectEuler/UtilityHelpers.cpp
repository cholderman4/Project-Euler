#include "UtilityHelpers.h"

#include <cmath>

namespace util
{
    Int sum_digits(Int n)
    {
        uint64_t sum = 0;
        while (n > 0)
        {
            auto digit = n % 10;
            sum += digit;
            n /= 10;
        }

        return sum;
    }

    /*Int sum_divisors(const Int n)
    {
        Int sum = 1;
        for (auto d = 2; d * d <= n; ++d)
        {
            if (n % d == 0)
            {
                sum += d;
                if (d * d != n)
                    sum += Int(n / d);
            }
        }
        return sum;
    }*/

    // Faster version
    Int sum_divisors(const Int N) {
        auto n = N;
        Int prod = 1;
        for (int k = 2; k * k <= n; ++k) {
            int p = 1;
            while (n % k == 0) {
                p = p * k + 1;
                n /= k;
            }
            prod *= p;
        }
        if (n > 1)
            prod *= (1 + n);
        // Does not count N itself
        return prod - N;
    }
}
