#ifndef PERSON_H
#define PERSON_H

#include "date.h"
#include <string>
#include <iostream>


class person
{
    public:
        person();
        person(std::string n, date bd);
        virtual ~person();

        std::string getName() const;

    protected:

    private:
        std::string name;
        date birthday;

    friend void displayPerson(const person& p);
    friend bool operator ==(const person& p1, const person& p2);
    friend std::ostream& operator <<(std::ostream& output, const person& p);
};


#endif // PERSON_H
