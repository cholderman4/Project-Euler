#pragma once

#include "stdint.h"

#include <vector>

class BigInt
{
	using Int = uint64_t;
public:
	BigInt();
	BigInt(Int val);
	//BigInt(size_t digits, Int val);

	
	//BigInt& operator+= (const BigInt& b);
	//BigInt& operator*= (const BigInt& b);
	BigInt& operator+= (const Int b);
	BigInt& operator*= (const Int b);

	uint32_t digits10();
	uint64_t sum_digits();

private:
	std::vector<uint64_t> num;
	const Int maxDigit = 1000000000000000;
};

//BigInt operator+ (const BigInt& a, const BigInt& b);
//BigInt operator* (const BigInt& a, const BigInt& b);

