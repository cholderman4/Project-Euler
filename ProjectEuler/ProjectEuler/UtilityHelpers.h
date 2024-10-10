#pragma once

#include "stdint.h"

namespace util
{
	using Int = uint64_t;

	Int sum_digits(Int n);

	Int sum_divisors(const Int n);

	uint32_t digits10(uint64_t v);
}
