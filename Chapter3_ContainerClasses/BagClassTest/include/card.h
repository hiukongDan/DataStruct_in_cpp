#ifndef CARD_H
#define CARD_H


class card
{
    public:
        enum Suit
        {
            SPADE,
            HEART,
            CLUB,
            DIAMOND,
            SUIT_SIZE
        };

        enum Rank
        {
            ACE,
            TWO,
            THREE,
            FOUR,
            FIVE,
            SIX,
            SEVEN,
            EIGHT,
            NINE,
            TEN,
            JACK,
            QUEEN,
            KING,
            RANK_SIZE
        };

        card();
        card(Suit s, Rank r);
        virtual ~card();

        void setSuit(Suit newSuit);
        void setRank(Rank newRank);
        void setCard(Suit newSuit, Rank newRank);
        Suit getSuit() const;
        Rank getRank() const;

    protected:

    private:
        Suit suit;
        Rank rank;
};

#endif // CARD_H
