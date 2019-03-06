#include "problem_005.h"


/*Problem 5

Smallest multiple


2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?



Answer:	232792560
 */
 


unsigned problem_005() {
	
	
	/* Just need enough prime factors to cover everything from 1 to 20. */
	
	return 2*3*2*5*7*2*3*11*13*2*17*19;
}