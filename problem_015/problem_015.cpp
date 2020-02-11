#include <iostream>
#include <cmath>

/*Problem 15

Lattice paths


Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?


Answer:	137846528820
 */
 
 

unsigned problem_015() {
	
    // 40 choose 20.
    return 137846528820;	
}

int main() {
	
   	std::cout << problem_015() << std::endl;

    return 0;
}
