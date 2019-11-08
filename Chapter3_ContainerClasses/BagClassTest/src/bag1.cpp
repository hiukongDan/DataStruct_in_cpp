// FILE: bag1.cpp
// CLASS IMPLEMENTATION: bag (see bag1.h for documentation)
// INVARIANT for the bag class:
//      1. The number of items in the bag is in the member variable used.
//      2. For an empty bag, we do not care what is stored in any of data; for a non-empty bag,
//         the items in the bag are stored in data[0] through data[used-1], and we don't care
//         what's in the rest of data.

#include "bag1.h"
#include <cassert>
#include <algorithm>

using namespace std;

const bag::size_type bag::CAPACITY;

bag::bag()
{
    //ctor
    used = 0;
}

bag::~bag()
{
    //dtor
}

void bag::insert(const value_type& entry)
{
    assert(size() < CAPACITY);
    data[used++] = entry;
}

bag::size_type bag::count(const value_type& target) const
{
    size_type answer;
    size_type i;
    answer = 0;
    for (i = 0; i < used; i++)
        if (target == data[i])
            answer++;
    return answer;
}
bool bag::erase_one(const value_type& target)
{
    size_type index;
    index = 0;
    while ((index < used) && (data[index] != target))
        ++index;

    if (index == used)
        return false;

    data[index] = data[--used];
    return true;
}

bag::size_type bag::erase(const value_type& target)
{
    size_type index = 0;
    size_type many_removed = 0;

    while(index < used)
    {
        if (data[index] == target)
        {
            data[index] = data[--used];
            many_removed++;
        }
        else
            index++;
    }

    return many_removed;
}

void bag::operator +=(const bag& addend)
{
    assert(size() + addend.size() <= CAPACITY);
    copy(addend.data, addend.data + addend.used, data + used);
    used += addend.used;
}

bag operator +(const bag& b1, const bag& b2)
{
    bag answer;
    assert(b1.size() + b2.size() <= bag::CAPACITY);

    answer += b1;
    answer += b2;

    return answer;
}

void bag::operator -=(const bag& minusend)
{
    for (size_type i = 0; i < minusend.size(); i++)
    {
        erase_one(minusend.data[i]);
    }
}

bag operator -(const bag& b1, const bag& b2)
{
    bag res;
    res += b1;
    res -= b2;

    return res;
}
