#include "StartPack.h"
#include <vector>

StartPack::StartPack() {

}

StartPack::StartPack(vector<Card> cards)
{
    this->cards = cards;
//    top = nullptr; //cpp int null
}

bool StartPack::getTopCard(Card &topCard) {
    if (top == -1) {
        return false;
    }

    topCard = cards.at(top);

    return true;
}

void StartPack::flipCard() {
    top++;

    if(top > (cards.size() - 1)) {
        top = -1;
    }

}
