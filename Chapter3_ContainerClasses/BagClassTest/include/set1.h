// FILE: set1.h
// CLASS provided: set
//
// TYPEDEFS and MEMBER CONSTANTS for the class set:
//      typedef ____ value_type
//          set::value_type is the data type in the items in the set. It may be any C++
//          built-in types (int, char, etc.), or any class with a default constructor,
//          an assignment operator, and operators to test for equality (x == y) and
//          non-equality (x != y).
//
//      typedef ____ size_type
//          set::size_type is the data type of any variable that keep a track of how many
//          items inside a set.
//
//      static const size_type CAPACITY = _____
//          set::CAPACITY is the maximum number of items a set can hold.
//
// CONSTUCTOR for the class set:
//      set()
//          Postcondition: The set has been initialized as an empty set.
//
// MODIFICASION MEMBER FUNCTIONS for the class set:
//      void insert(const value_type& entry)
//          Precondition: !contains(entry) && size() < CAPACITY.
//          Postcondition: A new copy of entry has been added to the set.
//
//      void remove(const value_type& target)
//          Postcondition: An item of set has been removed from the set, if there is no such item which
//          has the value of target, do nothing.
//
//      void operator +=(const set& addend)
//          Precondition: union_size(addend) < CAPACITY.
//          Postcondition: Each item of set addend which has not appeared in this set has been added to
//          this set.
//
//      void operator -=(const set& minusend)
//          Postcondition: Exam each item in set set minusend, if there is one existence in this set, remove it.
//
// CONSTANT MEMBER FUNCTIONS for the class set:
//      bool contains(const value_type& target) const
//          Postcondition:  Returns true if this set contains item which has value of target, otherwise
//          returns false to indicate there is no such item.
//
//      size_type size() const
//          Postcondition: Returns the total number of items in the set.
//
//      size_type union_size(const set& other) const
//          Postcondition: Returns the number of union items of this set and set other.
//
// NON MEMBER FUNCTIONS for the class set:
//      set operator +(const set& s1, const set& s2)
//          Precondition: s1.union_size(s2) < CAPACITY.
//          Postcondition: Returns a new set which combines s1 and s2.
//
//      set operator -(const set& s1, const set& s2)
//          Postcondition:  Returns a new set which is made of extracting each item in s2 which
//          also appears in s1 from s1.
//

#ifndef SET1_H
#define SET1_H

#include <cstdlib>

class set
{
    public:
        typedef double value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30;

        set();
        virtual ~set();

        // MODIFIACTION MEMBER FUNCTIONS
        void insert(const value_type& entry);
        void remove(const value_type& target);
        void operator +=(const set& addend);
        void operator -=(const set& minusend);



        // CONSTANT MEMBER FUNCTIONS
        bool contains(const value_type& target) const;
        size_type size() const;
        size_type union_size(const set& other) const;
        value_type operator [](size_type& index) const;

    private:
        value_type data[CAPACITY];
        size_type used;
};

set operator +(const set& s1, const set& s2);
set operator -(const set& s1, const set& s2);

#endif // SET1_H
