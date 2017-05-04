#include "Pack.h"
#include <vector>

using std::vector;

Card *Pack::getCard(int index) {
    return cards.at(index);
}

int Pack::numOfCards() {
    int i;

    i = cards.size();

    return i;
}

vector<Card*> Pack::getCards(int index)
{
    vector<Card*> tmp(this->cards.begin() + index, this->cards.end());
    return tmp;
}
