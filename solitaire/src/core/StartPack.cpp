#include "StartPack.h"
#include <vector>

StartPack::StartPack() {

}

StartPack::StartPack(vector<Card*> cards, int top)
{
    this->cards = cards;
    this->top = top;
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
