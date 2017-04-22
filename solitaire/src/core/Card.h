#ifndef CARD_H
#define CARD_H

#include "Globals.h"
#include <string>

using std::string;

class Card
{
    private:
            int value;
            CardType type;
            CardColor color;

    public:
            Card();
            Card(int value, CardType type); //constructor
            int getValue();
            CardType getType();
            CardColor getColor();
            string getName();
};

#endif // CARD_H
