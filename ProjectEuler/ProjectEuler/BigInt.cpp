#include "BigInt.h"

#include "UtilityHelpers.h"

BigInt::BigInt() : num{ 0 }
{}

BigInt::BigInt(Int val) : num{ val }
{}

BigInt& BigInt::operator=(const BigInt& b)
{
    num = b.num;
    return *this;
}

BigInt& BigInt::operator+=(const BigInt& b)
{
    auto it_a = num.begin();
    auto it_b = b.num.begin();
    Int carry = 0;
    while (it_a != num.end() && it_b != b.num.end())
    {
        *it_a += carry;
        *it_a += (*it_b);
        carry = 0;
        if (*it_a > maxDigit)
        {
            carry = (*it_a) / maxDigit;
            *it_a = (*it_a) % maxDigit;
        }

        ++it_a;
        ++it_b;
    }

    // b is the larger number
    for (auto it = it_b; it != b.num.end(); ++it)
    {
        auto sum = (*it) + carry;
        carry = 0;
        if (sum > maxDigit)
        {
            carry = sum / maxDigit;
            sum = sum % maxDigit;
        }
        num.push_back(sum);
    }

    // a is the larger number
    while (it_a != num.end() && carry > 0)
    {
        *it_a += carry;
        carry = 0;
        if (*it_a > maxDigit)
        {
            carry = (*it_a) / maxDigit;
            *it_a = (*it_a) % maxDigit;
        }

        ++it_a;
    }

    // Either case may finish with this condition
    if (carry > 0)
        num.push_back(carry);

    return *this;
}

//BigInt& BigInt::operator*=(const BigInt& b)
//{
//    // TODO: insert return statement here
//}

BigInt& BigInt::operator+=(const Int b)
{
    auto carry = b;
    for (auto& n : num)
    {
        if (carry == 0) break;

        n += carry;
        carry = 0;
        if (n > maxDigit)
        {
            carry = n / maxDigit;
            n = n % maxDigit;
        }
    }
    if (carry > 0)
        num.push_back(carry);

    return *this;
}

BigInt& BigInt::operator*=(const Int b)
{
    uint64_t carry = 0;
    for (auto& n : num)
    {
        n *= b;
        n += carry;
        carry = 0;
        if (n > maxDigit)
        {
            carry = n / maxDigit;
            n = n % maxDigit;
        }
    }
    if (carry > 0)
        num.push_back(carry);

    return *this;
}

uint32_t BigInt::digits10()
{
    if (num.size() == 0) return 0;

    return 15u * uint32_t(num.size() - 1) + util::digits10(num.back());
}

uint64_t BigInt::sum_digits()
{
    uint64_t sum = 0;
    //#pragma omp parallel for reduction(+:sum)
    for (auto&& n : num)
        sum += util::sum_digits(n);

    return sum;
}

BigInt operator+(const BigInt& a, const BigInt& b)
{
    BigInt res = a;
    res += b;
    return res;
}

//BigInt operator*(const BigInt& a, const BigInt& b)
//{
//    BigInt res = a;
//    a *= b;
//    return res;
//}

std::ostream& operator<<(std::ostream& os, const BigInt& a)
{
    for (auto it = a.num.rbegin(); it != a.num.rend(); ++it)
        os << (*it);
    return os;
}
