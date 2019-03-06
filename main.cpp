#include <iostream>
#include <cmath>

using namespace std;

int sumMultiples(int n)
{
    int sum = 0;
    for (int i=n; i<1000; i+=n)
    {
        sum = sum + i;
        //std::cout << i << endl;;
    }

    return sum;
}

bool isInteger(float k)
{
    return std::floor(k) == k;
}

void problem1()
{
    std::cout << sumMultiples(3) + sumMultiples(5) - sumMultiples(15);
}

int main()
{
    for (int i=1; i<250; i++)
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

    }

    return 0;
}
