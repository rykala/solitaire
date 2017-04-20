#include "Card.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::to_string;

Card::Card(){}

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

string Card::getName() {
    string tmp = "";

    if (value == 1) {
        tmp += "A";
    } else if (value == 11) {
        tmp += "J";
    } else if (value == 12) {
        tmp += "Q";
    } else if (value == 13) {
        tmp += "K";
    } else {
        tmp += to_string(value);
    }

    if (type == Spade) {
        tmp += "♠";
    } else if (type == Diamond) {
        tmp += "♦";
    } else if (type == Club) {
        tmp += "♣";
    } else if (type == Heart) {
        tmp += "♥";
    }

    return tmp;
}
