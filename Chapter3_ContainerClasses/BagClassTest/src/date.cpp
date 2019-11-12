#include "date.h"
#include <iostream>
using namespace std;

date::date()
{
    //ctor
}

date::date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

date::~date()
{
    //dtor
}


void date::increaseDate()
{
    day++;
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
        if(day == 32)
        {
            day = 1;
            month++;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if(day == 31)
        {
            day = 1;
            month++;
        }
        break;
    case 12:
        if(day == 31)
        {
            day = 1;
            month = 1;
            year++;
        }
        break;
    case 2:
        if(year % 4 == 0 && year % 100 != 0)
        {
            if(day == 29)
            {
                day = 1;
                month++;
            }
        }
        else
        {
            if(day == 30)
            {
                day = 1;
                month++;
            }
        }
    default:
        break;
    }
}

void date::setDate(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

void printDate(const date& d)
{
    cout << d.day << "/" << d.month << "/" << d.year << endl;
}

int date::getDay() const
{
    return day;
}

int date::getMonth() const
{
    return month;
}

int date::getYear() const
{
    return year;
}
