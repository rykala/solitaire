#ifndef CARD_H
#define CARD_H

#include "Globals.h"
#include <string>

using std::string;

class Card
{
public:
    Card();
    Card(int value, CardType type); //constructor
    int getValue();
    CardType getType();
    CardColor getColor();
    string getName();
    void setDeckType(DeckType deck) {this->deck = deck;}
    DeckType getDeckType() {return this->deck;}
    void setDeckIndex(int index) {this->deckIndex = index;}
    int getDeckIndex() {return this->deckIndex;}

private:
    int value;
    CardType type;
    CardColor color;
    DeckType deck;
    int deckIndex;

};

#endif // CARD_H
