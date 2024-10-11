#include <cmath>
#include <iostream>
#include <vector>

/*Problem 16

Power digit sum


2^16 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?


Answer:	
 */
 
 

unsigned problem_016() {

    // MAX_DIGITS = 1000*log_1000(2) ~ 301.02
    const unsigned MAX_DIGITS{305};

    std::vector<unsigned> product(MAX_DIGITS, 0);
    product[0]=1;
    unsigned currentDigits = 1;

    for (auto i=0; i<1000; ++i) {
        // Loop through multiplication by 2
        unsigned carry = 0;
        for (auto j = 0; j < currentDigits; ++j) {

        }

    }


	
    return 0;	
}

int main() {


	
   	std::cout << problem_016() << std::endl;

    return 0;
}
