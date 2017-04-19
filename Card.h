#ifndef CARD_H
#define CARD_H

#include "Globals.h"

class Card
{
    private:
            int value;
            CardType type;
            CardColor color;

    public:
            Card(int value, CardType type); //constructor

            int getValue();
            CardType getType();
            CardColor getColor();

            string print();
};

#endif // CARD_H
