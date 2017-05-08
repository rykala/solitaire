#include "StartPack.h"
#include <vector>

StartPack::StartPack() {

}

StartPack::StartPack(vector<Card*> cards)
{
    int tmpTop = -1;
    this->cards = cards;

    for(auto &card : cards) {
        if(card->getFaceUp()) {
            tmpTop++;
        }
    }

    this->top = tmpTop;
}

StartPack::~StartPack()
{
    for (auto card : cards) {
        delete card;
    }
}

int StartPack::flipCard() {
    top++;

    if(top > (int)(cards.size() - 1)) {
        top = -1;
        for(auto card : cards) {
            card->setFaceUp(false);
        }
    } else {
        cards.at(top)->setFaceUp(true);
    }
    return top;
}
