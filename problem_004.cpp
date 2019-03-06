#include "problem_004.h"

/*Problem 4

Largest palindrome product



A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.



Answer:	906609
 */



int problem_004() {
	
	int sum = 0;
	
	const int limit = 400000;
	
	int a = 2;
	int b = 8;
	int c = 4*b + a;
	
	sum = (a + b);
	
	while (c < limit) {
		// Add the next term to the sum.
		sum += c;
		
		// Advance each term forward one.
		a = b;
		b = c;
		c = 4*b + a;
	}
	
}
