#ifndef DECK_OF_CARDS_H
#define DECK_OF_CARDS_H

#include "card.h"
#include <cstdlib>


class deck_of_cards
{
    public:
        typedef size_t size_type;
        static const size_type CAPACITY = 52;

        deck_of_cards();
        virtual ~deck_of_cards();

    protected:

    private:
        card deck[CAPACITY];

    friend void displayDeck(const deck_of_cards& deck);
};

#endif // DECK_OF_CARDS_H
