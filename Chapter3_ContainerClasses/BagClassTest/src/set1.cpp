// FILE: set1.cpp
// Function implementation of class set (Implementation documentation see set1.h)
// INVARIANT of class set
//      1. The number of items is stored in the member variable used.
//      2. For an empty set, we do not care what is stored in any of data; for a nonempty
//      set, the items are stored in their set ordered from data[0] through data[used-1].
//      We do not care what is stored in any of rest of the data.
//      3. The items inside the set should be distinguished from each other, which means
//      a unique value should not appear more than once.

#include "set1.h"
#include <cassert>

set::set()
{
    used = 0;
}

set::~set()
{
    //dtor
}

void set::insert(const value_type& entry)
{
    if (!contains(entry) && size() < CAPACITY)
        data[used++] = entry;
}

void set::remove(const value_type& target)
{
    if (!contains(target))
        return;
    size_type index;
    for (index = 0; index < used; index++)
        if (data[index] == target)
            break;

    for (; index < used-1; index++)
        data[index] = data[index+1];

    --used;
}

void set::operator +=(const set& addend)
{
    assert(union_size(addend) <= CAPACITY);

    for (size_type i = 0; i < addend.size(); i++)
        if (!contains(addend.data[i]))
            insert(addend.data[i]);
}

void set::operator -=(const set& minusend)
{
    for (size_type i = 0; i < minusend.size(); i++)
        if (contains(minusend.data[i]))
            remove(minusend.data[i]);
}


bool set::contains(const value_type& target) const
{
    for (size_type i = 0; i < used; i++)
        if (data[i] == target)
            return true;
    return false;
}

set::size_type set::size() const
{
    return used;
}

set::size_type set::union_size(const set& other) const
{
    size_type sum = size();
    for (size_type i = 0; i < other.size(); i++)
        if (!contains(other.data[i]))
            ++sum;
    return sum;
}

set::value_type set::operator [](size_type& index) const
{
    assert(index < size());
    return data[index];
}


set operator +(const set& s1, const set& s2)
{
    assert(s1.union_size(s2) <= set::CAPACITY);

    set s;
    s += s1;
    s += s2;
    return s;
}

set operator -(const set& s1, const set& s2)
{
    set s;
    s += s1;
    s -= s2;
    return s;
}
