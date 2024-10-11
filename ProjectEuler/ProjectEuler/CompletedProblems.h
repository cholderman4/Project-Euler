#pragma once

//#include "stdint.h"

#include "UtilityHelpers.h"

#include <vector>


namespace completed
{
	using Int = uint64_t;

	// Problem 19
	Int count_sundays();

	// Problem 20
	Int factorial_digit_sum();

	// Problem 21
	Int sum_amicable_numbers();

	// Problem 23
	bool has_abundant_sum(const int n, const std::vector<int8_t>& isAbundant);
	Int non_abundant_sums();

	// Problem 25
	Int fibonacci_1000_digit();

	// Problem 26
	Int reciprocal_cycles_slow();
	bool is_reptend_prime(const Int p);
	Int reciprocal_cycles_fast();
}