#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "Globals.h"
#include <vector>

using std::vector;

class Deck
{
    public:
        vector<Card*> cards;
        Deck();
//        Card getCard();
};

#endif // DECK_H
