#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "Globals.h"
#include <vector>

class Deck
{
    private:
        vector<Card> cards;

    public:
        Deck();
        Card getCard();
};

#endif // DECK_H
