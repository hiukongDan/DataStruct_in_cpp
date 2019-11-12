#include "deck_of_cards.h"

#include <iostream>

using namespace std;

deck_of_cards::deck_of_cards()
{

    for (int s = 0; s < card::Suit::SUIT_SIZE; s++)
    {
        for (int r = 0; r < card::Rank::RANK_SIZE; r++)
        {
            deck[s*13+r].setCard(static_cast<card::Suit>(s), static_cast<card::Rank>(r));
        }
    }
}

deck_of_cards::~deck_of_cards()
{
    //dtor
}

void displayDeck(const deck_of_cards& deck)
{
    for (int i = 0; i < (int)deck_of_cards::CAPACITY; i++)
    {
        cout << "The ";
        switch(deck.deck[i].getRank())
        {
        case card::Rank::ACE:
            cout << "ace";
            break;
        case card::Rank::TWO:
            cout << "two";
            break;
        case card::Rank::THREE:
            cout << "three";
            break;
        case card::Rank::FOUR:
            cout << "four";
            break;
        case card::Rank::FIVE:
            cout << "five";
            break;
        case card::Rank::SIX:
            cout << "six";
            break;
        case card::Rank::SEVEN:
            cout << "seven";
            break;
        case card::Rank::EIGHT:
            cout << "eight";
            break;
        case card::Rank::NINE:
            cout << "nine";
            break;
        case card::Rank::TEN:
            cout << "ten";
            break;
        case card::Rank::JACK:
            cout << "Jack";
            break;
        case card::Rank::QUEEN:
            cout << "queen";
            break;
        case card::Rank::KING:
            cout << "king";
            break;
        default:
            break;
        }
        cout << " of ";
        switch(deck.deck[i].getSuit())
        {
        case card::Suit::SPADE:
            cout << "spade";
            break;
        case card::Suit::HEART:
            cout << "heart";
            break;
        case card::Suit::CLUB:
            cout << "club";
            break;
        case card::Suit::DIAMOND:
            cout << "diamond";
            break;
        default:
            break;
        }
        cout << endl;
    }
}
