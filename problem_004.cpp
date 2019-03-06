#include "problem_004.h"
#include <cmath>


/*Problem 4

Largest palindrome product


A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.


Answer:	906609
 */
 
bool isPalindrome(int n) {
	int temp = n;
	int digits = log10(n);
	
	int nReverse = 0;
	
	for (int p = 0; p <= digits; ++p) {
		int d = temp % 10;
		nReverse += pow(10, digits-p)*d;
		
		temp -= d;
		temp = temp / 10;		
	}
	
	return (n == nReverse);
}


unsigned problem_004() {
	
	unsigned largestPalindrome = 0;
	
	for (int a = 999; a >= 100; --a) {
		int b = 999;
		int db = 1;
		
		if (a % 11 != 0) {
			// a is not a multiple of 11, so b must be.
			b = 990;
			db = 11;
		}
		
		while (b >= a) {
			if (a*b <= largestPalindrome) {
				break;
			}
			if (isPalindrome(a*b)) {
					largestPalindrome = a*b;
			}
			
			b -= db;
		}
		
	}
	
	return largestPalindrome;
}