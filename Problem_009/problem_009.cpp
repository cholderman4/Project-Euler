#include <iostream>
#include <cmath>

/*Problem 9

Special Pythagorean triplet


A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
			a^2 + b^2 = c^2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.


Answer:	31875000
 */
 
 

 bool isInteger(float n) {
    return std::floor(n) == n;
}

unsigned problem_009() {
	
	for (int a=1; a<=250; ++a) {

        float b = static_cast<float>(1000)*(500-a)/static_cast<float>(1000-a);

        if ( isInteger(b) ) {
            return a*b*(1000 - (a+b));
        }
    }

    return 0;	
}

int main() {
	
   	std::cout << problem_009() << std::endl;

    return 0;
}
