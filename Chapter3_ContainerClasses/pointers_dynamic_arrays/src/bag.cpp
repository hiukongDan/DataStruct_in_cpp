#include "bag.h"
#include <algorithm>

using namespace hiukong_dan;
using namespace std;

const bag::size_type bag::DEFAULT_CAPACITY;

bag::bag(const size_type initial_capacity)
{
    capacity = initial_capacity;
    data = new value_type[capacity];
    used = 0;
}

bag::bag(const bag& source)
{
    capacity = source.capacity;
    used = source.used;
    data = new value_type[capacity];
    copy(source.data, source.data+used, data);
}

bag::~bag()
{
    delete[] data;
}

void bag::reserve(size_type new_capacity)
{
    value_type *large_array;

    if (new_capacity == capacity)
        return;

    if (new_capacity < used)
        new_capacity = used;

    large_array = new value_type[new_capacity];
    copy(data, data + used, large_array);
    delete[] data;
    data = large_array;
    capacity = new_capacity;
}

bool bag::erase_one(const value_type& target)
{
    for (size_type i = 0; i < used; i++)
    {
        if (data[i] == target)
        {
            for (size_type j = i; j < used-1; j++)
            {
                data[j] = data[j+1];
            }
            used--;
            return true;
        }
    }
    return false;
}

bag::size_type bag::erase(const value_type& target)
{
    size_type sum = 0;
    while(erase_one(target))
        sum++;
    return sum;
}

void bag::insert(const value_type& entry)
{
    if (used == capacity)
        reserve(used+(used/10 > 0 ? used/10 : 1));
    data[used++] = entry;
}

void bag::operator +=(const bag& addend)
{
    if (used + addend.used < capacity)
        reserve(used + addend.used);
    copy(addend.data, addend.data+addend.used, data+used);
    used += addend.used;
}

void bag::operator =(const bag& source)
{
    value_type *new_data;

    if (this == &source)
        return;

    if (capacity != source.capacity)
    {
        new_data = new value_type[source.capacity];
        delete[] data;
        data = new_data;
        capacity = source.capacity;
    }
    used = source.used;
    copy(source.data, source.data+used, data);
}

bag::size_type bag::count(const value_type& target) const
{
    size_type sum = 0;
    for (size_type i = 0; i < used; i++)
        if (data[i] == target)
            sum++;
    return sum;
}

bag operator+(const bag& b1, const bag& b2)
{
    bag b(b1);
    b += b2;
    return b;
}
