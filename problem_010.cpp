#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

/*Problem 10

Summation of primes


The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.


Answer:	142913828922

 */ 
 

unsigned long problem_010() {


    const unsigned LIMIT = 2000000;
    const unsigned ODD_NUM_COUNT = LIMIT/2 - 1;
    const double ROOT = sqrt(LIMIT);

    std::vector<unsigned> isPrime(ODD_NUM_COUNT, 1);

    
    // Only including odds, so start with sum at 2.
    unsigned long sum = 2;

    for (auto it = isPrime.begin(); it != isPrime.end(); ++it ) {

        // Find the next prime in the list.
        it = std::find(it, isPrime.end(), 1);


        // Check that we are not at the end of our list.
        if ( it == isPrime.end() ) {
            break;
        }

        // Index arithmetic to get the value of the prime number.
        unsigned i = std::distance(isPrime.begin(), it);
        unsigned p = 2*i + 3;

        // Add the prime number to the total.
        sum += p;
 
        if (p < ROOT) {
            // Scan through and mark off all multiples of p.
            unsigned p2 = (2*i + 3)*(2*i + 3);

            // Start at p^2.
            for (auto j = i + (p2 - p)/2; j < ODD_NUM_COUNT; j += p) {
                isPrime[j] = 0;
            }
        }  
    }

    return sum;	
}

int main() {
	
   	std::cout << problem_010() << std::endl;

    return 0;
}
