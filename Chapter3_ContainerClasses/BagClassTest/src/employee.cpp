#include "employee.h"

const double employee::REGULAR_BIWEEK_WORK_HOUR;
int employee::ID = 0;

employee::employee()
{
    id = employee::genID();
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
