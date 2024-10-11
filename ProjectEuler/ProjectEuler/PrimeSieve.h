#pragma once

#include <vector>

class PrimeSieve
{
	using Int = uint64_t;
public:
	PrimeSieve(const Int N);

	bool is_prime(const Int n) const;
	Int limit() const { return maxN; };
	Int next_prime(Int n) const;
	//void rebuild_prime_limit(const Int p);
	void rebuild_integer_limit(const Int n);
	void print() const;

private:
	std::vector<uint8_t> sieve;
	Int maxN;
};

