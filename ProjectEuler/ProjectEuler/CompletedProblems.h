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

}