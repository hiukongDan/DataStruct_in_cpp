// FILE: big_number.cpp
// CLASS IMPLEMENTATION: big_number
// INVARIANT of the class big_number:
//      1. The class big_number stores numbers in a big-ended array, which means the smallest
//      digit is stored in data[0] and so forth.
//

#include "big_number.h"

#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

big_number::big_number():big_number(0)
{

}

big_number::~big_number()
{
    //dtor
}

big_number::big_number(int num)
{
    sign = (num >= 0 ? 1 : -1);
    int remain = abs(num);
    int digit = remain % 10;
    size_type index = 0;

    while (remain > 0)
    {
        data[index++] = '0' + digit;
        remain /= 10;
        digit = remain % 10;
    }

    if (index == 0)
        data[index++] = '0';
    for (; index < DIGIT_CAPACITY; index++)
        data[index] = 0;
}

char big_number::digitAt(size_type index) const
{
    assert(index < DIGIT_CAPACITY);
    return data[index];
}

big_number::size_type big_number::numberOfDigits() const
{
    size_type index;
    for (index = 0; index < DIGIT_CAPACITY; index++)
        if (data[index] == 0)
            break;
    return index;
}

void big_number::operator +=(const big_number& addend)
{
    int addone = 0;
    int temp = 0;
    int num1, num2, numLess, numGreater;
    num1 = numberOfDigits();
    num2 = addend.numberOfDigits();
    numLess = num1 <= num2 ? num1 : num2;
    numGreater = num1 >= num2 ? num1 : num2;

    if (sign == addend.sign)
    {
        cout << "case 11: " << endl;
        int i;
        for (i = 0; i < numLess; i++)
        {
            temp = data[i] - '0' + addend.data[i] - '0' + addone;
            data[i] = temp % 10 + '0';
            addone = temp / 10;
        }
        for (; i < numGreater; i++)
        {
            temp = 0;
            temp += data[i] == 0 ? 0 : data[i] - '0';
            temp += addend.data[i] == 0 ? 0 : addend.data[i] - '0';
            temp += addone;
            data[i] = temp % 10 + '0';
            addone = temp / 10;
        }
    }
    else if (abs(*this) > abs(addend))
    {
        cout << "case 12: " << endl;
        int i;
        for (i = 0; i < numLess; i++)
        {
            temp = data[i] - addend.data[i] + 10 + addone;
            data[i] = temp % 10 + '0';
            addone = temp / 10 - 1;
        }
        for (; i < numGreater; i++)
        {
            temp = data[i] - '0' + addone + 10;
            data[i] = temp % 10 + '0';
            addone = temp / 10 - 1;
        }
        /* remove preceding zeros */
        for (; i > 0; i--)
            if (data[i] == '0')
                data[i] = 0;
            else
                break;
    }
    else if(abs(*this) < abs(addend))
    {
        cout << "case 13: " << endl;
        int i;
        for (i = 0; i < numLess; i++)
        {
            temp = addend.data[i] - data[i] + 10 + addone;
            data[i] = temp % 10 + '0';
            addone = temp / 10 - 1;
        }
        for (; i < numGreater; i++)
        {
            temp = addend.data[i] - '0' + addone + 10;
            data[i] = temp % 10 + '0';
            addone = temp / 10 - 1;
        }
        sign *= -1;
    }
    else    /* abs(*this) == abs(addend) */
    {
        cout << "case 14: " << endl;
        data[0] = '0';
        for (int i = 1; i < num1; i++)
            data[i] = 0;
    }
}

void big_number::operator -=(const big_number& minend)
{
    big_number temp = minend;
    temp.sign *= -1;
    *this += temp;
}

ostream& operator <<(ostream& output, const big_number& num)
{
    int index;
    for (index = 0; index < (int)big_number::DIGIT_CAPACITY; index++)
        if (num.digitAt(index) == 0)
            break;

    output << (num.sign > 0 ? '+' : '-');
    for (index--; index >= 0; index--)
        output << num.digitAt(index);

    return output;
}

istream& operator >>(istream& input, big_number& num)
{
    char in;
    input >> in;

    int newSign = 1;
    int index = 0;

    if (in == '+' || in == '-')
        newSign = in == '+' ? 1 : -1;
    else if (isdigit(in))
        num.data[index++] = in;
    input >> in;
    while (isdigit(in))
    {
        num.data[index++] =
        in;
        cin >> in;
    }

    for (int i = 0; i < index/2; i++)
    {
        char temp = num.data[i];
        num.data[i] = num.data[index-1-i];
        num.data[index-1-i] = temp;
    }

    for (; index < (int)big_number::DIGIT_CAPACITY; index++)
        num.data[index] = 0;
    num.sign = newSign;

    return input;
}

big_number operator +(const big_number& b1, const big_number& b2)
{
    big_number res;
    res += b1;
    res += b2;
    return res;
}

big_number operator -(const big_number& b1, const big_number& b2)
{
    big_number res;
    res -= b1;
    res -= b2;
    return res;
}

bool operator <(const big_number& b1, const big_number& b2)
{
    if (b1.sign < 0 && b2.sign > 0)
        return true;
    else if (b1.sign > 0 && b2.sign < 0)
        return false;

    else if (b1.sign > 0 && b2.sign > 0)
    {
        big_number::size_type num1, num2;
        num1 = b1.numberOfDigits();
        num2 = b2.numberOfDigits();
        if (num1 > num2)
            return false;
        else if (num1 < num2)
            return true;
        else    /* b2.numberOfDigits() == b2.numberOfdigits() */
        {
            for (big_number::size_type i = num1-1; i >= 0; --i)
            {
                if (b1.data[i] < b2.data[i])
                    return true;
                else if (b1.data[i] > b2.data[i])
                    return false;
            }
        }
    }
    else if (b1.sign < 0 && b2.sign < 0)
    {
        big_number::size_type num1, num2;
        num1 = b1.numberOfDigits();
        num2 = b2.numberOfDigits();
        if (num1 > num2)
            return true;
        else if (num1 < num2)
            return false;
        else    /* b2.numberOfDigits() == b2.numberOfdigits() */
        {
            for (big_number::size_type i = num1-1; i >= 0; --i)
            {
                if (b1.data[i] < b2.data[i])
                    return false;
                else if (b1.data[i] > b2.data[i])
                    return true;
            }
        }
    }
    return false;
}

bool operator >(const big_number& b1, const big_number& b2)
{
    return b2 < b1;
}

bool operator <=(const big_number& b1, const big_number& b2)
{
    return b1 < b2 || b1 == b2;
}

bool operator >=(const big_number& b1, const big_number& b2)
{
    return b2 <= b1;
}

bool operator ==(const big_number& b1, const big_number& b2)
{
    big_number num1, num2;
    num1 = b1.numberOfDigits();
    num2 = b2.numberOfDigits();
    if (b1.sign != b2.sign || num1 != num2)
        return false;
    for (big_number::size_type i = 0; i < num1; i++)
        if (b1.data[i] != b2.data[i])
            return false;
    return true;
}

bool operator !=(const big_number& b1, const big_number& b2)
{
    return !(b1 == b2);
}

big_number abs(const big_number& num)
{
    big_number res = num;
    res.sign = 1;
    return res;
}
