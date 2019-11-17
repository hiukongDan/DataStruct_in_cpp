#include "employee.h"

const double employee::REGULAR_BIWEEK_WORK_HOUR;
int employee::ID = 0;

employee::employee()
{
    id = employee::genID();
    wage = 0;
    age = 0;
    sex = MALE;
}

employee::employee(std::string newName, double newWage, float newAge, Sex newSex)
{
    id = employee::genID();
    name = newName;
    wage = newWage;
    age = newAge;
    sex = newSex;
}

employee::~employee()
{
    //dtor
}

double employee::getYearlySalary() const
{
    return 52 * 0.5 * REGULAR_BIWEEK_WORK_HOUR * wage;
}

void employee::increaseSalary(double percentage)
{
    wage *= (1+percentage);
}

void employee::setBiweekPaycheck(double paycheck)
{
    biweek_paycheck = paycheck;
    calculateOvertime();
}

void employee::setAge(float a)
{
    age = a;
}

void employee::setSex(Sex s)
{
    sex = s;
}
void employee::setName(std::string n)
{
    name = n;
}

void employee::setWage(float newWage)
{
    wage = newWage;
}

void employee::calculateOvertime()
{
    overtime = (biweek_paycheck - (wage * REGULAR_BIWEEK_WORK_HOUR)) / wage;
}

double employee::getOvertime() const
{
    return overtime;
}

int employee::genID()
{
    return ++employee::ID;
}

float employee::getAge() const
{
    return age;
}

employee::Sex employee::getSex() const
{
    return sex;
}

int employee::getID() const
{
    return id;
}

std::string employee::getName() const
{
    return name;
}

float employee::getWage() const
{
    return wage;
}

double employee::getWorkedHours() const
{
    return REGULAR_BIWEEK_WORK_HOUR + overtime;
}

bool operator ==(const employee& e1, const employee& e2)
{
    return e1.getID() == e2.getID();
}

bool operator !=(const employee& e1, const employee& e2)
{
    return e1.getID() != e2.getID();
}

bool operator >(const employee& e1, const employee& e2)
{
    return e1.getID() > e2.getID();
}

bool operator <(const employee& e1, const employee& e2)
{
    return e1.getID() < e2.getID();
}

bool operator >=(const employee& e1, const employee& e2)
{
    return e1.getID() >= e2.getID();
}

bool operator <=(const employee& e1, const employee& e2)
{
    return e1.getID() <= e2.getID();
}
