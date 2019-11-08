#include "polynomial1.h"
#include <cassert>
#include <cmath>

const polynomial::size_type polynomial::MAXDEGREE;

polynomial::polynomial()
{
    //ctor
    for (size_type i = 0; i < MAXDEGREE; i++)
        coefficients[i] = 0;
}

polynomial::~polynomial()
{
    //dtor
}

void polynomial::addTerm(value_type coefficient, size_type degree)
{
    assert(degree < MAXDEGREE);
    coefficients[degree] += coefficient;
}

void polynomial::operator +=(const polynomial& addend)
{
    for (size_type i = 0; i < MAXDEGREE; i++)
        coefficients[i] += addend.coefficients[i];
}

polynomial::value_type polynomial::evaluate(const value_type& x) const
{
    value_type sum = 0;
    for (size_type i = 0; i < MAXDEGREE; i++)
        sum += coefficients[i] * std::pow((double)x, (double)i);
    return sum;
}
