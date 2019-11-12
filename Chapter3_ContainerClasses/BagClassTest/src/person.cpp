#include "person.h"
#include <iostream>

using namespace std;

person::person()
{
    //ctor
}


person::person(std::string n, date bd)
{
    name = n;
    birthday = bd;
}

person::~person()
{
    //dtor
}


void displayPerson(const person& p)
{
    cout << p.name << " : ";
    printDate(p.birthday);
}


bool operator ==(const person& p1, const person& p2)
{
    if (p1.name == p2.name &&
        p1.birthday.getDay() == p2.birthday.getDay() &&
        p1.birthday.getMonth() == p2.birthday.getMonth() &&
        p1.birthday.getYear() == p2.birthday.getYear())
        return true;
    return false;
}

ostream& operator <<(ostream& output, const person& p)
{
    output << p.name << "'s birthday is: ";
    printDate(p.birthday);
    return output;
}

std::string person::getName() const
{
    return name;
}
