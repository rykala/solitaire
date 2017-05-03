#include "StartPack.h"
#include <vector>

StartPack::StartPack() {

}

StartPack::StartPack(vector<Card> cards)
{
    this->cards = cards;
}

bool StartPack::getTopCard(Card &topCard) {
    if (top == -1) {
        return false;
    }

    topCard = cards.at(top);

    return true;
}

int StartPack::getTopIndex()
{
    return top-1;
}

//int StartPack::flipCard() {
//     if(top > (cards.size() - 1)) {
//        top = 0;
//    }

//    return top++;

//}
