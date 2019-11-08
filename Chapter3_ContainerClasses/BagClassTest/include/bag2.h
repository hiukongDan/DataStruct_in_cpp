// FILE: bag2.h
// CLASS PROVIDED: bag_with_receipts
//
// TYPEDEFs and COMSTANT MEMBERS for the class bag_with_receipts:
//
//      typedef ____ value_type
//          bag_with_receipts::value_type is the data type of the items in the bag. It may be any of the C++
//          built-in types (int, chat, etc.), or a class with a default constructor, an assignment
//          operator, and operators to test for equality (x == y) and non-equality (x != y).
//
//      typedef ____ size_type
//          bag_with_receipts::size_type is any variables that keep track how many items in the
//          bag_with_receipts class.
//
//      typedef ____ receipt_type
//          bag_with_receipts::receipt_type is an int which returned to user as a receipt number.
//
// CONSTRUCTORS for the class bag_with_receipts:
//      bag_with_receipts()
//          Postcondition: The bag has been initialized as an empty bag.
//
// MODIFICATION MEMBER FUNCTIONS for the class bag_with_receipts:
//      receipt_type insert(const value_type& entry)
//          Precondition: size() < CAPACITY.
//          Postcondition: A copy of entry has been inserted in to the bag, and a receipt number has
//          been given back to the user. The receipt number is where the index number of the copy of the entry
//          has been stored. And in_use[index] has been set to true.
//
//      void remove(const receipt_type& receipt)
//          Postcondition: in_use[receipt] has been set to false, if there is no such index equals to receipt,
//          do nothing.
//
// CONSTANT MEMBER FUNCTIONS for the class bag_with_receipts:
//      size_type size() const
//          Postcondition: Returns the number of items currently stored in the bag, which is simply the value of
//          variable used.
//
//      value_type retrieve(const receipt_type& receipt) const
//          Precondition: in_use[receipt] == true.
//          Postcondition: Returns the target value stored in data[receipt].

#ifndef BAG2_H
#define BAG2_H

#include <cstdlib>

class bag_with_receipts
{
    public:
        // TYPEDEFs and CONSTANT MEMBERs
        typedef double value_type;
        typedef size_t size_type;
        typedef int receipt_type;
        static const int CAPACITY = 30;

        // CONSTRUCTOR and DESTRUCTOR
        bag_with_receipts();
        virtual ~bag_with_receipts();

        // MODIFICATION MEMBER FUNCTIONs
        receipt_type insert(const value_type& entry);
        void remove(const receipt_type& receipt);

        // CONSTANT MEMBER FUNCTIONS
        size_type size() const;
        value_type retrieve(const receipt_type& receipt) const;


    protected:

    private:
        value_type data[CAPACITY];
        bool in_use[CAPACITY];
        size_type used;
};

#endif // BAG2_H
