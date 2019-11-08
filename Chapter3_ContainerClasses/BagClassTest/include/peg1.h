#ifndef PEG1_H
#define PEG1_H

#include <cstdlib>
#include <iostream>

class peg_stacked_ring
{
    public:
        typedef size_t size_type;
        typedef int value_type;
        static const size_type CAPACITY = 64;

        peg_stacked_ring(size_type n=64);
        virtual ~peg_stacked_ring();


        void push(const value_type& diameter);
        value_type pop();

        size_type size() const;
        value_type topmost() const;

    protected:

    private:
        value_type data[CAPACITY];
        size_type used;

    friend std::ostream& operator <<(std::ostream& output, const peg_stacked_ring& peg);
};

#endif // PEG1_H
