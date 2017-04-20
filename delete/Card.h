#ifndef CARD_H
#define CARD_H

#include "Globals.h"
#include <string>

class Card
{
    public:
            int value;
            CardType type;
            CardColor color;

    public:
            Card(int value, CardType type); //constructor

            int getValue();
            CardType getType();
            CardColor getColor();

            string to_string2(Card card);
};

#endif // CARD_H
