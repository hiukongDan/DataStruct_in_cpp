#include "card.h"

card::card()
{

}

card::card(Suit s, Rank r)
{
    suit = s;
    rank = r;
}

card::~card()
{
    //dtor
}


void card::setSuit(Suit newSuit)
{
    suit = newSuit;
}

void card::setRank(Rank newRank)
{
    rank = newRank;
}

void card::setCard(Suit newSuit, Rank newRank)
{
    suit = newSuit;
    rank = newRank;
}

card::Suit card::getSuit() const
{
    return suit;
}

card::Rank card::getRank() const
{
    return rank;
}
