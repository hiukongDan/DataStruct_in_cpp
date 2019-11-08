// FILE: pokerhand.cpp
// CLASS IMPLEMENTATION: pokerhand
//
// INVARIANT of class pokerhand:
//      1.

#include "pokerhand.h"
#include <cassert>

const pokerhand::size_type pokerhand::CAPACITY;

pokerhand::pokerhand()
{
    //ctor
    used = 0;
}

pokerhand::~pokerhand()
{
    //dtor
}

void pokerhand::insert(const value_type& entry)
{
    assert(size() < CAPACITY);

    cards[used++] = entry;
}

void pokerhand::remove(const value_type& target)
{
    for (size_type i = 0; i < used; i++)
    {
        if (cards[i] == target)
        {
            for (size_type j = i; j < used-1; j++)
                cards[j] = cards[j+1];

            --used;
            break;
        }
    }
}

pokerhand::value_type pokerhand::value() const
{
    value_type value = 0;
    for (size_type i = 0; i < size(); i++)
    {
        switch(cards[i])
        {
        case 1:
            value += 12;
            break;
        case 2:
            value += 13;
            break;
        case 3:
            value += 1;
            break;
        case 4:
            value += 2;
            break;
        case 5:
            value += 3;
            break;
        case 6:
            value += 4;
            break;
        case 7:
            value += 5;
            break;
        case 8:
            value += 6;
            break;
        case 9:
            value += 7;
            break;
        case 10:
            value += 8;
            break;
        case 11:
            value += 9;
            break;
        case 12:
            value += 10;
            break;
        case 13:
            value += 11;
            break;
        default:
            break;
        }
    }
    return value;
}

pokerhand::size_type pokerhand::size() const
{
    return used;
}


bool operator >(const pokerhand& p1, const pokerhand& p2)
{
    return p1.value() > p2.value();
}

bool operator <(const pokerhand& p1, const pokerhand& p2)
{
    return p1.value() < p2.value();
}

bool operator >=(const pokerhand& p1, const pokerhand& p2)
{
    return p1.value() >= p2.value();
}

bool operator <=(const pokerhand& p1, const pokerhand& p2)
{
    return p1.value() <= p2.value();
}

bool operator ==(const pokerhand& p1, const pokerhand& p2)
{
    return p1.value() == p2.value();
}

bool operator !=(const pokerhand& p1, const pokerhand& p2)
{
    return p1.value() != p2.value();
}








