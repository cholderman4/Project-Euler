#include <iostream>
#include <cmath>
#include <vector>

/*Problem 14

Longest Collatz sequence


The following iterative sequence is defined for the set of positive integers:

        n → n/2 (n is even)
        n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
        13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.


Answer:	837799
 */


unsigned problem_014() {

        const unsigned MEM_LIMIT = 1000000;
        std::vector<unsigned> collatzNumber(MEM_LIMIT,0);
        collatzNumber[0] = 1;
        const unsigned LIMIT = 1000000;

        
        unsigned maxSequenceLength = 1;
        unsigned maxStart = 1;

        for (unsigned n = 1; n < LIMIT; ++n) {

                std::vector<unsigned long> sequence(1, n);
                unsigned long currentNumber = n;
                unsigned sequenceLength = 0;

                bool checkNumber;
                if ( collatzNumber[currentNumber - 1] == 0 ) {
                        checkNumber = true;
                } else {
                        checkNumber = false;
                }
                // Checks that the current value hasn't been encountered in a previous sequence. 
                while (checkNumber) {                        
                        // Fill in the current sequence starting at n.
                        if (currentNumber % 2 == 0) {
                                currentNumber /= 2;
                        } else {
                                currentNumber = 3*currentNumber + 1;
                        }
                        ++sequenceLength;
                        sequence.push_back(currentNumber);

                        if (currentNumber <= MEM_LIMIT) {
                                if ( collatzNumber[currentNumber - 1] != 0 ) {
                                        checkNumber = false;
                                }
                        }
                }

                sequenceLength += collatzNumber[currentNumber-1];

                // Check for largest sequence length. 
                if (sequenceLength > maxSequenceLength) {
                        maxSequenceLength = sequenceLength;
                        maxStart = n;
                }

                // Loop through and fill in values further down the sequence. 
                for (auto iter = sequence.begin(); iter != sequence.end(); ++iter) {
                        if (*iter <= MEM_LIMIT) {
                                collatzNumber[*iter - 1] = sequenceLength;
                        }
                        --sequenceLength;
                }                
        }
       
    return maxStart;
}

int main() {
	
        std::cout << "Max start value: " << problem_014() << std::endl;

    return 0;
}
