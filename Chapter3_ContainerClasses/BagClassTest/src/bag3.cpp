#include "bag3.h"
#include <cassert>
#include <iostream>

using namespace std;

const int keyed_bag::CAPACITY;

keyed_bag::keyed_bag()
{
    used = 0;
    for(size_type i = 0; i < CAPACITY; i++)
    {
        in_use[i] = false;
        keys[i] = -1;
    }
}

keyed_bag::~keyed_bag()
{
    //dtor
}

void keyed_bag::insert(const value_type& entry, int key)
{
    assert(size() < CAPACITY && !contains_key(key));

    size_type index;
    for (index = 0; index < CAPACITY && in_use[index]; ++index)
        ;
    if (index < CAPACITY)
    {
        keys[index] = key;
        in_use[index] = true;
        data[index] = entry;
    }
}

void keyed_bag::remove(int key)
{
    size_type index;
    for (index = 0; index < CAPACITY && keys[index] != key; index++)
        ;

    if (index < CAPACITY)
    {
        in_use[index] = false;
        ++used;
    }
}

keyed_bag::size_type keyed_bag::size() const
{
    return used;
}


bool keyed_bag::contains_key(int key) const
{
    bool contains = false;
    for (size_type i = 0; i < CAPACITY; i++)
    {
        if (in_use[i] && keys[i] == key)
        {
            contains = true;
            break;
        }
    }
    return contains;
}

keyed_bag::value_type keyed_bag::retrieve(int key) const
{
    assert(contains_key(key));

    size_type index;
    for (index = 0; index < CAPACITY && keys[index] != key; ++index)
        ;
    return data[index];
}
