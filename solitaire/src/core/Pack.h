#ifndef PACK_H
#define PACK_H

#include "Globals.h"
#include "Card.h"
#include <vector>

using std::vector;

class Pack {
public:
    vector<Card> cards;
    Card getCard(int index);
    int numOfCards();
    vector<Card> getCards(int index = 0);
};

#endif // PACK_H
