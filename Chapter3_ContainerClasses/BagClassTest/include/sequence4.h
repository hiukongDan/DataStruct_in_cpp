#ifndef SEQUENCE4_H
#define SEQUENCE4_H

#include <cstdlib>

#include "employee.h"

class employee_sequence
{
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef employee value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30;

        // CONSTRUCTOR AND DESTRUCTOR
        employee_sequence();
        virtual ~employee_sequence();

        // MODIFICATION FUNCTIONS
        void start();
        void advance();
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current();
        void remove_one(const value_type& target);

        // new functions to implement
        void insert_front(const value_type& entry);
        void remove_front();
        void attach_end(const value_type& entry);
        void remove_end();
        void operator +=(const employee_sequence& addend);
        value_type operator [](size_type index) const;
        int find(int id); /* returns index of found item or -1 */

        // CONSTANT FUNCTIONS
        size_type size() const;
        bool is_item() const;
        value_type current() const;

    protected:

    private:
        value_type data[CAPACITY];
        size_type used;
        size_type current_index;
};

float averageAge(const employee_sequence& employees);
float averageSalaries(const employee_sequence& employees);
float averageWorkedHours(const employee_sequence& employees);
float radioMaleFemale(const employee_sequence& employees);


#endif // SEQUENCE4_H
