#ifndef POLYNOMIAL1_H
#define POLYNOMIAL1_H

#include <cstdlib>

class polynomial
{
    public:
        typedef double value_type;
        typedef size_t size_type;
        static const size_type MAXDEGREE = 30;

        polynomial();
        virtual ~polynomial();

        void addTerm(value_type coefficent, size_type degree);
        void operator +=(const polynomial& addend);

        value_type evaluate(const value_type& x) const;

    private:
        value_type coefficients[MAXDEGREE];

};

#endif // POLYNOMIAL1_H
