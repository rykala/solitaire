#include "StartPack.h"
#include <vector>

StartPack::StartPack() {

}

StartPack::StartPack(vector<Card*> cards)
{
    this->cards = cards;
}

//bool StartPack::getTopCard(Card &topCard) {
//    if (top == -1) {
//        return false;
//    }

//    topCard = cards->at(top);

//    return true;
//}

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
