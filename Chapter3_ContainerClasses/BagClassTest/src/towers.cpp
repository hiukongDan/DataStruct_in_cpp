

#include "towers.h"
#include "peg1.h"
#include <iostream>
#include <cassert>

const towers::size_type towers::NUMBER_OF_PEGS;

towers::towers(size_type n)
{
    pegs[0] = peg_stacked_ring(n);
    pegs[1] = peg_stacked_ring(0);
    pegs[2] = peg_stacked_ring(0);
}

towers::~towers()
{
    //dtor
}


void towers::move(int start_peg, int end_peg)
{
    if ((start_peg > 0 && start_peg <= 3) &&
        (end_peg > 0 && end_peg <= 3) &&
        (start_peg != end_peg) &&
        (pegs[end_peg-1].size() < peg_stacked_ring::CAPACITY) &&
        (pegs[start_peg-1].size() > 0) &&
        (pegs[end_peg-1].topmost() > pegs[start_peg-1].topmost() ||
           pegs[end_peg-1].size() == 0))
    {
        pegs[end_peg-1].push(pegs[start_peg-1].pop());
    }
    else
    {
        std::cout << "Invalid move!" << std::endl;
    }
}

towers::size_type towers::many_rings(int peg_number) const
{
    assert(peg_number > 0 && peg_number <= 3);

    return pegs[peg_number].size();
}

towers::size_type towers::top_diameter(int peg_number) const
{
    assert(peg_number > 0 && peg_number <= 3);

    if (pegs[peg_number].size() > 0)
        return pegs[peg_number].topmost();
    return 0;
}

std::ostream& operator<<(std::ostream& output, const towers& t)
{
    output << "1: " << t.pegs[0] << std::endl;
    output << "2: " << t.pegs[1] << std::endl;
    output << "3: " << t.pegs[2] << std::endl;
    return output;
}

