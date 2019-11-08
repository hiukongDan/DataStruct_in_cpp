#ifndef SEQUENCE2_H
#define SEQUENCE2_H

#include <cstdlib>



class sorted_sequence
{
    public:

        // TYPEDEFS and MEMBER CONSTANTS
        typedef double value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30;

        // CONSTRUCTOR AND DESTRUCTOR
        sorted_sequence();
        virtual ~sorted_sequence();

        // MODIFICATION FUNCTIONS
        void start();
        void advance();
        void insert(const value_type& entry);
        void remove_current();

        // CONSTANT FUNCTIONS
        size_type size() const;
        bool is_item() const;
        value_type current() const;

    protected:

    private:
        value_type data[CAPACITY];
        size_type used;
        size_type current_index;
        void _insert(const value_type& entry);
};

// functions need to be implemented
sorted_sequence operator +(const sorted_sequence& s1, const sorted_sequence& s2);

#endif // SEQUENCE2_H
