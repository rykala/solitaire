#include "Pack.h"

Card Pack::getCard(int index) {
    return cards.at(index);
}

int Pack::numOfCards() {
    int i;

    i = cards.size();

    return i;
}
