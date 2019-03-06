/* #include <iostream>
#include <cmath> */
#include "problem_002.h"



/* bool isInteger(float k)
{
    return std::floor(k) == k;
}
 */

int main()
{
    /* for (int i=1; i<250; i++)
    {
        float j = i;
        float k = (1000)*(500-j)/(1000-j);
//        std::cout << k << endl;
        if (isInteger(k))
        {
            std::cout << "a=" << j << ", b=" << k << ", c=" << 1000-(j+k) << endl;
            int64_t product = j*k*(1000 - (j+k));
            std::cout << "abc = " << product << endl;
        }

    } */
	
	std::cout << problem_002() << std::endl;

    return 0;
}
