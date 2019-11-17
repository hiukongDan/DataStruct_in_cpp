#include "sequence4.h"

#include <cassert>
#include <algorithm>

const employee_sequence::size_type employee_sequence::CAPACITY;

employee_sequence::employee_sequence()
{
    used = 0;
    current_index = 0;
}

employee_sequence::~employee_sequence()
{
    //dtor
}

void employee_sequence::start()
{
    current_index = 0;
}

void employee_sequence::advance()
{
    assert(is_item());

    current_index++;
}

void employee_sequence::insert(const value_type& entry)
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

void employee_sequence::attach(const value_type& entry)
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

void employee_sequence::remove_current()
{
    assert(is_item());

    for (size_type i = current_index; i < used-1; i++)
    {
        data[i] = data[i+1];
    }
    used--;
}

void employee_sequence::remove_one(const value_type& target)
{
    for (start(); is_item(); advance())
    {
        if (data[current_index] == target)
            break;
    }

    remove_current();
}

employee_sequence::size_type employee_sequence::size() const
{
    return used;
}

bool employee_sequence::is_item() const
{
    return current_index >= 0 && current_index < used;
}

employee_sequence::value_type employee_sequence::current() const
{
    return data[current_index];
}

void employee_sequence::insert_front(const value_type& entry)
{
    start();
    insert(entry);
}

void employee_sequence::remove_front()
{
    start();
    remove_current();
}

void employee_sequence::attach_end(const value_type& entry)
{
    current_index = used;
    attach(entry);
}

void employee_sequence::remove_end()
{
    if (size() == 0)
        return;
    current_index = used -1;
    remove_current();
}

void employee_sequence::operator +=(const employee_sequence& addend)
{
    assert(size() + addend.size() <= CAPACITY);

    std::copy(addend.data, addend.data + addend.size(), data + size());
    used += addend.size();
}

employee_sequence::value_type employee_sequence::operator [](size_type index) const
{
    assert (index < size());

    return data[index];
}


employee_sequence operator +(const employee_sequence& s1, const employee_sequence& s2)
{
    assert(s1.size() + s2.size() <= employee_sequence::CAPACITY);

    employee_sequence res;
    res += s1;
    res += s2;
    return res;
}

int employee_sequence::find(int id)
{
    for (start(); is_item(); advance())
    {
        employee p = current();
        if (p.getID() == id)
            return current_index;
    }
    return -1;
}

float averageAge(const employee_sequence& employees)
{
    float sum = 0;
    for (int i = 0; i < (int)employees.size(); i++)
        sum += employees[i].getAge();
    return sum / (employees.size() == 0 ? 1 : employees.size());
}

float averageSalaries(const employee_sequence& employees)
{
    float sum = 0;
    for (int i = 0; i < (int)employees.size(); i++)
        sum += employees[i].getYearlySalary();
    return sum / (employees.size() == 0 ? 1 : employees.size());
}

float averageWorkedHours(const employee_sequence& employees)
{
    float sum = 0;
    for (int i = 0; i < (int)employees.size(); i++)
        sum += employees[i].getWorkedHours();
    return sum / (employees.size() == 0 ? 1 : employees.size());
}

float radioMaleFemale(const employee_sequence& employees)
{
    float maleNum = 0;
    float femaleNum = 0;
    employee::Sex sex;
    for (int i = 0; i < (int)employees.size(); i++)
    {
        sex = employees[i].getSex();
        if (sex == employee::MALE)
            maleNum++;
        else if (sex == employee::FEMALE)
            femaleNum++;
    }
    return maleNum / (femaleNum == 0 ? maleNum : femaleNum);
}




