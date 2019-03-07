#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>


/*Problem 7

10001st prime


By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10,001st prime number?


Answer:	104743
 */


unsigned problem_007() {

    const unsigned N = 10001;

    std::vector<unsigned> primes(N, 1);
    primes[0] = 2;
    primes[1] = 3;

    for(int i = 2; i < N; ++i) {

        unsigned testPrime = primes[i-1] + 2;

        while ( std::any_of(primes.begin(), primes.begin() + i, [testPrime] (int p) { return (testPrime % p == 0); } )) {
            testPrime += 2;
        }
        primes[i] = testPrime;
    }

	return primes[N-1] ;
}


int main() {
	
   	std::cout << problem_007() << std::endl;

    return 0;
}