// FILE: bag2.cpp
// CLASS IMPLEMENTATION: bag_with_receipts
// INVARIANT for the bag_with_receipts class:
//      1. The number of items in the bag is in the member variable used.
//      2. For an empty bag, we do not care what is stored in the data, for a not empty bag,
//      item is stored in the corresponding data[index] which in_use[index] returns true.
//      3. When user stored an item in the bag, give back a receipt number which is the data index,
//      and set corresponding in_use cell to true. If user erase an item, set the in_use cell to false.

#include "bag2.h"
#include <cassert>

const int bag_with_receipts::CAPACITY;

bag_with_receipts::bag_with_receipts()
{
    //ctor
    used = 0;
    for (size_type i = 0; i < CAPACITY; i++)
        in_use[i] = false;
}

bag_with_receipts::~bag_with_receipts()
{
    //dtor
}


// MODIFICATION MEMBER FUNCTIONs
bag_with_receipts::receipt_type bag_with_receipts::insert(const value_type& entry)
{
    assert(size() < CAPACITY);

    size_type index;
    for (index = 0; index < CAPACITY && in_use[index]; index++)
        ;

    in_use[index] = true;
    data[index] = entry;
    ++used;

    return index;
}

void bag_with_receipts::remove(const receipt_type& receipt)
{
    assert(receipt >= 0 && receipt < CAPACITY);

    if (in_use[receipt])
    {
        in_use[receipt] = false;
        --used;
    }
}

bag_with_receipts::value_type bag_with_receipts::retrieve(const receipt_type& receipt) const
{
    assert(in_use[receipt]);
    return data[receipt];
}

// CONSTANT MEMBER FUNCTIONS
bag_with_receipts::size_type bag_with_receipts::size() const
{
    return used;
}
