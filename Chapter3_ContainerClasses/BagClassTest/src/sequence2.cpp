#include "sequence2.h"

#include <cassert>

sorted_sequence::sorted_sequence()
{
    //ctor
    current_index = 0;
    used = 0;
}
sorted_sequence::~sorted_sequence()
{
    //dtor
}

void sorted_sequence::start()
{
    current_index = 0;
}

void sorted_sequence::advance()
{
    if(is_item())
        ++current_index;
}

void sorted_sequence::insert(const value_type& entry)
{
    for (start(); is_item() && (entry > current()); advance())
        ;
    _insert(entry);
}

void sorted_sequence::_insert(const value_type& entry)
{
    assert(size() < CAPACITY);

    if (!is_item() && (size() == 0))
        current_index = 0;
    for (size_type i = used; i > current_index; i--)
    {
        data[i] = data[i-1];
    }
    data[current_index] = entry;
    used++;
}

void sorted_sequence::remove_current()
{
    assert(is_item());

    for (size_type i = current_index; i < used-1; i++)
        data[i] = data[i+1];

    used--;
}

sorted_sequence::size_type sorted_sequence::size() const
{
    return used;
}

bool sorted_sequence::is_item() const
{
    return current_index < used;
}

sorted_sequence::value_type sorted_sequence::current() const
{
    assert(is_item());
    return data[current_index];
}
