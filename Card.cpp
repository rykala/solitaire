#include "Card.h"

Card::Card(int value, CardType type)
{
    this->value = value;
    this->type = type;
}

CardColor Card::getColor() {
    return color;
}

CardType Card::getType() {
    return type;
}

int Card::getValue() {
    return value;
}

string print(Card card) {
    string tmp = "";

    tmp += to_string(card.value);

    return tmp;
}
