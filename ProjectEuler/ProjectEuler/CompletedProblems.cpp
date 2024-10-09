#include "CompletedProblems.h"

#include <vector>

#include "UtilityHelpers.h"

namespace completed
{
    using namespace util;

    // Problem 19
    Int count_sundays()
    {
        int year = 1900;
        int month = 1;
        int day = 1;
        int weekDay = 1; // Sunday = 0
        int sundays = 0;

        while (year <= 2000 && month <= 12 && day <= 31)
        {
            // Check the problem conditions
            if (day == 1
                && weekDay == 0 // sunday
                && year >= 1901
                && year <= 2000)
            {
                ++sundays;
            }

            // Advance the weekday
            ++weekDay;
            if (weekDay == 7)
                weekDay = 0;

            // Advance the day
            ++day;
            if (day < 29) // no new month/year
                continue;

            if (month == 2)
            {
                // No leap year
                if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))
                {
                    day = 1;
                    ++month;
                    continue;
                }
                else if (day == 30)
                {
                    day = 1;
                    ++month;
                    continue;
                }
            }

            // Check 30 day months
            if (day == 31
                && (month == 4
                    || month == 6
                    || month == 9
                    || month == 11))
            {
                day = 1;
                ++month;
                continue;
            }

            if (day == 32)
            {
                day = 1;
                ++month;
                if (month == 13)
                {
                    month = 1;
                    ++year;
                }
                continue;
            }
        }

        return sundays;
    }

    // Problem 20
    Int factorial_digit_sum()
    {
        using LargeDigit = std::vector<uint64_t>;

        constexpr uint64_t maxDigit = 100000000000000000;
        LargeDigit product;
        product.reserve(100);
        product.push_back(1);

        constexpr int max = 100;
        for (uint64_t i = 1; i <= max; ++i)
        {
            //const auto factor = (i % 10 == 0) ? (i / 10) : i;

            // Multiply
            uint64_t carry = 0;
            for (auto& d : product)
            {
                d *= i;
                d += carry;
                carry = 0;
                if (d > maxDigit)
                {
                    carry = d / maxDigit;
                    d = d % maxDigit;
                }
            }
            if (carry > 0)
                product.push_back(carry);

            /*std::cout << "i: " << i << std::endl;
            std::cout << "size: " << product.size() << std::endl;*/
        }

        //std::cout << "size: " << product.size() << std::endl;

        uint64_t sum = 0;
        for (auto&& d : product)
        {
            sum += sum_digits(d);
            //std::cout << d << std::endl;
        }

        return sum;
    }

    // Problem 21
    Int sum_amicable_numbers()
    {
        constexpr Int MAX_N = 10000;
        auto foundDivisors = std::vector<bool>(MAX_N, false);
        Int sumAmicableNumbers = 0;
        for (auto n = 1; n <= MAX_N; ++n)
        {
            if (foundDivisors[n - 1] == true)
                continue;

            foundDivisors[n - 1] = true;

            const auto sum1 = sum_divisors(n);
            if (sum1 > MAX_N || foundDivisors[sum1 - 1] == true)
                continue;

            foundDivisors[sum1 - 1] = true;
            const auto sum2 = sum_divisors(sum1);
            if (sum2 == n)
            {
                sumAmicableNumbers += sum1;
                sumAmicableNumbers += sum2;
            }
        }

        return sumAmicableNumbers;
    }

    // Problem 23
    bool has_abundant_sum(const int n, const std::vector<int8_t>& isAbundant)
    {
        // Check pairs
        for (auto s1 = 1; s1 <= n / 2; ++s1)
        {
            const auto s2 = n - s1;
            if (isAbundant[s1 - 1] == 1 && isAbundant[s2 - 1] == 1)
                return true;
        }

        return false;
    }

    Int non_abundant_sums()
    {
        constexpr Int LIMIT = 28123;

        // -1 for non-abundant (deficient or abundant)
        // +1 for abundant
        auto isAbundant = std::vector<int8_t>(LIMIT, 0);

        // We know 12 is the smallest abundant number
        std::fill(isAbundant.begin(), isAbundant.begin() + 11, -1);
        isAbundant[11] = 1;

#pragma omp parallel for
        for (auto n = 13; n <= LIMIT; ++n)
        {
            isAbundant[n - 1] = (sum_divisors(n) > n) ? 1 : -1;
        }

        Int sumNonAbundantSum = 12 * 23;
#pragma omp parallel for reduction(+:sumNonAbundantSum)
        for (auto n = 25; n <= LIMIT; ++n)
        {
            if (!has_abundant_sum(n, isAbundant))
            {
                sumNonAbundantSum += n;
            }
        }

        return sumNonAbundantSum;
    }
}
