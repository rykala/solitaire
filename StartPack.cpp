#include "StartPack.h"

StartPack::StartPack(vector<Card> cards)
{
    this->cards = cards;
//    top = nullptr; //cpp int null
}

Card StartPack::getTopCard() {
    top += 1;

    if(top > (cards.size() - 1)) {
        top = 0;
    }

    return cards.at(top);
}
