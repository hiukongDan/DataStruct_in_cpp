// FILE: towers.h
// CLASS PROVIDED: towers
//
// TYPEDEFs and CONSTANT MEMBERS for the class towers:
//      typedef ____ peg_type
//          towers::peg_type is the data type of pegs.
//
//      typedef ____ size_type
//          towers::size_type is the type of number counting.
//
//      static const NUMBER_OF_PEGS = 3
//          towers::NUMBER_OF_PEGS is the number of pegs, which should be 3 by default.
//
// CONSTRUCTOR for the class towers:
//      towers(size_type n=64)
//          Precondition: 1 <= n <= 64.
//          Postcondition: The towers have been initialized with n rings on the first peg
//          and no rings on the other two pegs. The diameters of the first peg's rings are
//          from one inch (on the top) to n inches (on the bottom).
//
// MODIFICATION FUNCTIONS for the class towers:
//      void move(int start_peg, int end_peg)
//          Precondition: start_peg is a peg number (1, 2 or 3), and many_rings(start_peg) > 0;
//          end_peg is a different peg number (not equal to start_peg), and top_diameter(end_peg)
//          is either 0 or more than top_diameter(start_peg).
//          Postcondition: The top ring has been moved from start_peg to end_peg.
//
// CONSTANT FUNCTIONS for the class towers:
//      size_type many_rings(int peg_number) const
//          Precondition: peg_number is 1, 2 or 3.
//          Postcondition: The return value is the number of rings on the specified peg.
//
//      size_type towers::top_diameter(int peg_number) const
//          Precondition: peg_number is 1, 2 or 3.
//          Postcondition: if mane_rings(peg_number) > 0, than the return value is the
//          diameter of the top ring on the specified peg; otherwise the return value
//          is zero.
//
// FRIEND FUNCTIONS for the class towers:
//      std::ostream& operator <<(std::ostream& output, const towers& t)
//          Postcondition: Print out representation of the towers to user's screen.
//

#ifndef TOWERS_H
#define TOWERS_H

#include "peg1.h"
#include <cstdlib>
#include <iostream>


class towers
{
    public:
        typedef peg_stacked_ring peg_type;
        typedef size_t size_type;
        static const size_type NUMBER_OF_PEGS = 3;

        towers(size_type n=64);
        virtual ~towers();

        void move(int start_peg, int end_peg);

        size_type many_rings(int peg_number) const;
        size_type top_diameter(int peg_number) const;


    protected:

    private:
        peg_type pegs[NUMBER_OF_PEGS];

    friend std::ostream& operator <<(std::ostream& output, const towers& t);
};

#endif // TOWERS_H
