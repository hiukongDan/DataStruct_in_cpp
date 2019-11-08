#ifndef POKERHAND_H
#define POKERHAND_H

#include <cstdlib>

class pokerhand
{
    public:
        typedef size_t size_type;
        typedef int value_type;
        static const size_type CAPACITY = 5;

        pokerhand();
        virtual ~pokerhand();

        void insert(const value_type& entry);
        void remove(const value_type& target);

        value_type value() const;    /* Returns the value of current cards */
        size_type size() const;

    private:
        value_type cards[CAPACITY];
        size_type used;
};

bool operator >(const pokerhand& p1, const pokerhand& p2);
bool operator <(const pokerhand& p1, const pokerhand& p2);
bool operator >=(const pokerhand& p1, const pokerhand& p2);
bool operator <=(const pokerhand& p1, const pokerhand& p2);
bool operator ==(const pokerhand& p1, const pokerhand& p2);
bool operator !=(const pokerhand& p1, const pokerhand& p2);

#endif // POKERHAND_H
