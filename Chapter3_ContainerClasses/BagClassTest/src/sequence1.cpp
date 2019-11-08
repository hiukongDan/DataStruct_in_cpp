// FILE: sequence1.cpp
// CLASS IMPLEMENTATION: sequence (see sequence1.h for documentation)
// INVARIANT for the sequence class:
//      1. The number of items in the sequence is stored in the member variable used.
//      2. For an empty sequence, we do not care what is stored in any of data; for
//          a nonempty sequence, the items are stored in their sequence order from
//          data[0] to data[used-1], and we don't care what is stored in the rest of data.
//      3. If there is a current item, then it lies in data[current_index], if there is no
//          current item, then current_index equals used.

#include "sequence1.h"
#include <cassert>
#include <algorithm>

const sequence::size_type sequence::CAPACITY;

sequence::sequence()
{
    //ctor
    used = 0;
    current_index = 0;
}

sequence::~sequence()
{
    //dtor
}

void sequence::start()
{
    current_index = 0;
}

void sequence::advance()
{
    assert(is_item());

    current_index++;
}

void sequence::insert(const value_type& entry)
{
    assert(size() < CAPACITY);

    if (!is_item())
        current_index = 0;
    for (size_type i = used; i > current_index; i--)
    {
        data[i] = data[i-1];
    }
    data[current_index] = entry;
    used++;
}

void sequence::attach(const value_type& entry)
{
    assert(size() < CAPACITY);

    if (!is_item())
    {
        data[current_index] = entry;
    }
    else
    {
        current_index++;
        for (size_type i = used; i > current_index; i--)
            data[i] = data[i-1];
        data[current_index] = entry;
    }
    used++;
}

void sequence::remove_current()
{
    assert(is_item());

    for (size_type i = current_index; i < used-1; i++)
    {
        data[i] = data[i+1];
    }
    used--;
}

void sequence::remove_one(const value_type& target)
{
    for (start(); is_item(); advance())
    {
        if (data[current_index] == target)
            break;
    }

    remove_current();
}

sequence::size_type sequence::size() const
{
    return used;
}

bool sequence::is_item() const
{
    return current_index >= 0 && current_index < used;
}

sequence::value_type sequence::current() const
{
    return data[current_index];
}

void sequence::insert_front(const value_type& entry)
{
    start();
    insert(entry);
}

void sequence::remove_front()
{
    start();
    remove_current();
}

void sequence::attach_end(const value_type& entry)
{
    current_index = used;
    attach(entry);
}

void sequence::remove_end()
{
    if (size() == 0)
        return;
    current_index = used -1;
    remove_current();
}

void sequence::operator +=(const sequence& addend)
{
    assert(size() + addend.size() <= CAPACITY);

    std::copy(addend.data, addend.data + addend.size(), data + size());
    used += addend.size();
}

sequence::value_type sequence::operator [](size_type index) const
{
    assert (index < size());

    return data[index];
}


sequence operator +(const sequence& s1, const sequence& s2)
{
    assert(s1.size() + s2.size() <= sequence::CAPACITY);

    sequence res;
    res += s1;
    res += s2;
    return res;
}
