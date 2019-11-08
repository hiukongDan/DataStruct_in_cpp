// FILE : big_number.h
// CLASS PROVIDED: big_number
//


#ifndef BIG_NUMBER_H
#define BIG_NUMBER_H

#include <cstdlib>
#include <iostream>

class big_number
{
    public:
        typedef size_t size_type;
        static const size_type DIGIT_CAPACITY = 100;

        big_number();
        big_number(int num);
        virtual ~big_number();

        char digitAt(size_type index) const;
        size_type numberOfDigits() const;

        void operator +=(const big_number& addend);
        void operator -=(const big_number& minend);

        friend std::ostream& operator <<(std::ostream& output, const big_number& num);
        friend std::istream& operator >>(std::istream& input, big_number& num);
        friend big_number operator +(const big_number& b1, const big_number& b2);
        friend big_number operator -(const big_number& b1, const big_number& b2);

        friend bool operator <(const big_number& b1, const big_number& b2);
        friend bool operator >(const big_number& b1, const big_number& b2);
        friend bool operator <=(const big_number& b1, const big_number& b2);
        friend bool operator >=(const big_number& b1, const big_number& b2);
        friend bool operator ==(const big_number& b1, const big_number& b2);
        friend bool operator !=(const big_number& b1, const big_number& b2);

        friend big_number abs(const big_number& num);

    protected:

    private:
        int sign;
        char data[DIGIT_CAPACITY];
};




#endif // BIG_NUMBER_H
