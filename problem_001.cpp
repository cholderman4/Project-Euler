#include <iostream>

/*Problem 1

Multiples of 3 and 5

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

Answer:	233168
 */

int sumMultiples(int n) {
	
    int sum = 0;
    for (int i=n; i<1000; i+=n) {
	    sum = sum + i;
    }

    return sum;
}

int problem_001() {
	
	return sumMultiples(3) + sumMultiples(5) - sumMultiples(15);
}

int main() {
	
   	std::cout << problem_001() << '\n';

    return 0;
}
