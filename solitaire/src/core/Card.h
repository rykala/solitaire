#ifndef CARD_H
#define CARD_H

#include "Globals.h"

#include <string>

using std::string;

class Card
{
public:
    Card();
    Card(int value, CardType type, bool faceUp = true); //constructor

    /* METHODS */
    void flipCard();
    string getName();

    /* GETTERS SETTERS */
    int getValue();

    CardType getType();

    DeckType getDeckType() {return this->deck;}
    void setDeckType(DeckType deck) {this->deck = deck;}

    int getDeckIndex() {return this->deckIndex;}
    void setDeckIndex(int index) {this->deckIndex = index;}

    bool getFaceUp() {return this->faceUp;}
    void setFaceUp(bool value) {this->faceUp = value;}

private:
    int value;
    CardType type;
    DeckType deck;
    int deckIndex;
    bool faceUp;

};

#endif // CARD_H
