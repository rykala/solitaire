#include "Deck.h"
#include "Globals.h"
#include <algorithm>

Deck::Deck() {
    for(int value = 0; value < 13; value++){
        for(int type = 1; type < 5; type++){
            CardType tmp = static_cast<CardType>(type);
            Card card(value,tmp);
            this->cards.push_back(card);
        }
    }

    random_shuffle(cards.begin(), cards.end());
}


Card Deck::getCard() {
    return cards.at(4);
}
