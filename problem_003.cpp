#include <iostream>
#include <cmath>

/*Problem 3

Largest prime factor


The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?


Answer:	6857
 */


unsigned long problem_003() {
	
	
 	unsigned long n = 600851475143;
	
	/* First divide out all the 2's. */
	while (n % 2 == 0) {
		n = n / 2;
	}
	
	unsigned long testFactor = 3;
	
	while ( testFactor < sqrt(n) ) {
		
		while (n % testFactor == 0) {
			n = n / testFactor;
		}
		
		testFactor += 2;		
	}
	
	return n;
}


int main() {
	
   	std::cout << problem_003() << std::endl;

    return 0;
}