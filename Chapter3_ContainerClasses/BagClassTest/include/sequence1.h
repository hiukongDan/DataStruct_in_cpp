// FILE: sequence1.h
// CLASS PROVIDED: sequence
//
// TYPEDEF and MEMBER CONSTANTS for the sequence class:
//      typedef ____ value_type
//          sequence::value_type is the data type of the items in the sequence. It maybe any of the
//          C++ built-in types (int, char, etc.), or a class with a default constructor, an assignment
//          operator, and a copy constructor.
//
//      typedef ____ size_type
//          sequence::size_type is the data type of any variable that keeps track of how many
//          items are in a sequence.
//
//      static const size_type CAPACITY = ____
//          sequence: CAPACITY is the maximum number of items that a sequence can hold.
//
// CONSTRUCTOR for the sequence class:
//      sequence()
//          Postcondition: The sequence has been initialized as an empty sequence.
//
// MODIFICATION MEMBER FUNCTIONS for the sequence class:
//      void start()
//          Postcondition: The first item in the sequence becomes the current item (but if the
//          sequence is empty, then there is no current item.
//
//      void advance()
//          Precondition: is_item returns true.
//          Postcondition: If the current item is already the last item in the sequence, then
//          there is no long any current item. Otherwise, the new item is the item immediately
//          after the original current item.
//
//      void insert(const value_type& entry)
//          Precondition: size() < CAPACITY.
//          Postcondition A new copy of entry has been inserted in the sequence before the
//          current item. If there was no current item, then the new entry has been inserted
//          at the front. In either case, the new item is now the current item of the sequence.
//
//      void attach(const value_type& entry)
//          Precondition: size() < CAPACITY.
//          Postcondition: A new copy of entry has been inserted in the sequence after the current
//          item. If there was no current item, then the new entry has been attached to the end of
//          the sequence. In either case, the new item is now the current item of the sequence.
//
//      void remove_current()
//          Precondition: is_item returns true.
//          Postcondition: The current item has been removed from the sequence, and the item
//          after this (if there is one) is now the new current item.
//
//      void remove_one(const value_type& target)
//          Postcondition: If target is in the sequence, then the first copy of target is removed,
//          and the item after the removed item (if there is one) becomes the new current item;
//          otherwise the sequence remains unchanged.
//
//      void insert_front(const value_type& entry)
//          Precondition: size() < CAPACITY.
//          Postcondition: A new copy of entry has been inserted at the front of the sequence. And
//          the current item has become the new inserted item, which means current index equals to 0.
//
//      void remove_front()
//          Postcondition: The first item of the sequence has been removed from the sequence, if there is
//          no items in the sequence, do nothing.
//
//      void attach_end(const value_type& entry)
//          Precondition: size() < CAPACITY.
//          Postcondition: A new copy of entry has been inserted at the end of the sequence, and the
//          current item becomes the new item if the original current item doesn't exist, otherwise
//          the current item remains unchanged.
//
//      void remove_end()
//          Postcondition: If the sequence contains any items, remove the last item in the sequence,
//          otherwise do nothing.
//
//      void operator +=(const sequence& addend)
//          Precondition: size() + addend.size() <= CAPACITY.
//          Postcondition: Each item in addend has been added to this sequence.
//
//      value_type operator [](size_type index)
//          Precondition: index < size()
//          Postcondition: Returns the item which has been located at the index position.
//
// CONSTANT MEMBER FUNCTIONS for the sequence class:
//      size_type size() const
//          Postcondition: The return value is the number of items in the sequence.
//
//      bool is_item() const
//          Postcondition: A true return value indicates that there is a valid "current" item that
//          may be retrieved by the current member function (listed below). A false return value
//          indicates that there is no valid return value.
//
//      value_type current() const
//          Precondition: is_item returns true.
//          Postcondition: The item returned is the current item in the sequence.
//
// NONMEMBER FUNCTIONS for the sequence class:
//      sequence operator +(const sequence& s1, const sequence& s2)
//          Precondition: s1.size() + s2.size() <= CAPACITY.
//          Postcondition: The sequence returned is the union of s1 and s2.
//
// VALUE SEMANTICS for the sequence class:
//      Assignments and copy constructor may be used with sequence objects.


#ifndef SEQUENCE1_H
#define SEQUENCE1_H

#include <cstdlib>

class sequence
{
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef double value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30;

        // CONSTRUCTOR AND DESTRUCTOR
        sequence();
        virtual ~sequence();

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
        void operator +=(const sequence& addend);
        value_type operator [](size_type index) const;

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

// functions need to be implemented
sequence operator +(const sequence& s1, const sequence& s2);

#endif // SEQUENCE1_H
