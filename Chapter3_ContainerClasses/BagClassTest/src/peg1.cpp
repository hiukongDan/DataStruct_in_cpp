#include "peg1.h"

#include <cassert>
#include <iostream>


const peg_stacked_ring::size_type peg_stacked_ring::CAPACITY;

peg_stacked_ring::peg_stacked_ring(size_type n)
{
    for (size_type i = 0; i < n; i++)
        data[i] = n-i;
    used = n;
}

peg_stacked_ring::~peg_stacked_ring()
{

}

peg_stacked_ring::size_type peg_stacked_ring::size() const
{
    return used;
}

peg_stacked_ring::value_type peg_stacked_ring::topmost() const
{
    return data[used-1];
}

void peg_stacked_ring::push(const value_type& entry)
{
    assert(size() < CAPACITY);

    if (entry < data[used-1])
        data[used++] = entry;
}

peg_stacked_ring::value_type peg_stacked_ring::pop()
{
    assert(size() > 0);

    return data[--used];
}

std::ostream& operator <<(std::ostream& output, const peg_stacked_ring& peg)
{
    if (peg.size() > 1)
        output << peg.data[0] << "..." << peg.topmost();
    else if (peg.size() == 1)
        output << peg.data[0];
    else
        output << "empty peg";

    return output;
}
