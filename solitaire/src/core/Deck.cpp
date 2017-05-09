/**
 * @file Deck.h
 * @class Deck
 * @brief %Deck implementation.
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

#include "Deck.h"
#include "Globals.h"
#include <algorithm>

using std::vector;

Deck::Deck() {
    for(int value = 1; value < 14; value++){
        for(int type = 1; type < 5; type++){
            CardType tmp = static_cast<CardType>(type);
            Card *card = new Card(value,tmp);
            this->cards.push_back(card);
        }
    }

    random_shuffle(cards.begin(), cards.end());
}
