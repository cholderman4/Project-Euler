#include <iostream>


/*Problem 6

Sum square difference


The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.



Answer:	25164150
 */
 


unsigned problem_006() {	

    const int N = 100;

    unsigned sum = 0;
    unsigned rowSum = 0;

    /* for (int i = 1; i <= N; ++i) {
        rowSum += i;
    } */

    rowSum = N*(N+1)/2;

    for (int i = 1; i <= N-1; ++i) {
        rowSum -= i;
        sum += 2*i*rowSum;
    }

    return sum;	
}

int main() {
	
   	std::cout << problem_006() << std::endl;

    return 0;
}