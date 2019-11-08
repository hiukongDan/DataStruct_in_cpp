// FILE: bag3.h
// CLASS PROVIDED: keyed_bag
//
// TYPEDEFS and CONSTANT MEMBERS for the class keyed_bag:
//      typedef ____ value_type
//
//      typedef ____ size_type
//
//      static const size_type CAPACITY = ____
//
// MODIFICATION FUNCTIONS for the class keyed_bag:
//
//
// CONSTANT MEMBER FUNCTIONS for the class keyed_bag:
//
//


#ifndef BAG3_H
#define BAG3_H

#include <cstdlib>


class keyed_bag
{
    public:
        typedef double value_type;
        typedef size_t size_type;
        static const int CAPACITY = 30;

        keyed_bag();
        virtual ~keyed_bag();

        void insert(const value_type& entry, int key);
        void remove(int key);

        size_type size() const;
        bool contains_key(int key) const;
        value_type retrieve(int key) const;

    private:
        size_type data[CAPACITY];
        bool in_use[CAPACITY];
        int keys[CAPACITY];
        size_type used;
};

#endif // BAG3_H
