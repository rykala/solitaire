/**
 * @file Card.cpp
 * @class Card
 * @brief %rCard implementation.
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

#include "Card.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::to_string;

Card::Card(){}

Card::Card(int value, CardType type, bool faceUp)
{
    this->value = value;
    this->type = type;
    this->faceUp = faceUp;
}

void Card::flipCard()
{
    faceUp = true;
}

CardType Card::getType() {
    return type;
}

int Card::getValue() {
    return value;
}

string Card::getName() {
    string tmp = "";
    if (!faceUp) {
        tmp += "🂠";
    } else if (type == Club) {
        if (value == 1) {
            tmp += "🃑"; }
        else if (value == 2) {
            tmp += "🃒";
        } else if (value == 3) {
            tmp += "🃓";
        } else if (value == 4) {
            tmp += "🃔";
        } else if (value == 5) {
            tmp += "🃕";
        } else if (value == 6) {
            tmp += "🃖";
        } else if (value == 7) {
            tmp += "🃗";
        } else if (value == 8) {
            tmp += "🃘";
        } else if (value == 9) {
            tmp += "🃙";
        } else if (value == 10) {
            tmp += "🃚";
        } else if (value == 11) {
            tmp += "🃛";
        } else if (value == 12) {
            tmp += "🃝";
        } else if (value == 13) {
            tmp += "🃞";
        }
    } else if (type == Diamond) {
        if (value == 1) {
            tmp += "🃁"; }
        else if (value == 2) {
            tmp += "🃂";
        } else if (value == 3) {
            tmp += "🃃";
        } else if (value == 4) {
            tmp += "🃄";
        } else if (value == 5) {
            tmp += "🃅";
        } else if (value == 6) {
            tmp += "🃆";
        } else if (value == 7) {
            tmp += "🃇";
        } else if (value == 8) {
            tmp += "🃈";
        } else if (value == 9) {
            tmp += "🃉";
        } else if (value == 10) {
            tmp += "🃊";
        } else if (value == 11) {
            tmp += "🃋";
        } else if (value == 12) {
            tmp += "🃍";
        } else if (value == 13) {
            tmp += "🃎";
        }
    } else if (type == Spade) {
        if (value == 1) {
            tmp += "🂡"; }
        else if (value == 2) {
            tmp += "🂢";
        } else if (value == 3) {
            tmp += "🂣";
        } else if (value == 4) {
            tmp += "🂤";
        } else if (value == 5) {
            tmp += "🂥";
        } else if (value == 6) {
            tmp += "🂦";
        } else if (value == 7) {
            tmp += "🂧";
        } else if (value == 8) {
            tmp += "🂨";
        } else if (value == 9) {
            tmp += "🂩";
        } else if (value == 10) {
            tmp += "🂪";
        } else if (value == 11) {
            tmp += "🂫";
        } else if (value == 12) {
            tmp += "🂭";
        } else if (value == 13) {
            tmp += "🂮";
        }
    } else if (type == Heart) {
        if (value == 1) {
            tmp += "🂱"; }
        else if (value == 2) {
            tmp += "🂲";
        } else if (value == 3) {
            tmp += "🂳";
        } else if (value == 4) {
            tmp += "🂴";
        } else if (value == 5) {
            tmp += "🂥";
        } else if (value == 6) {
            tmp += "🂶";
        } else if (value == 7) {
            tmp += "🂷";
        } else if (value == 8) {
            tmp += "🂸";
        } else if (value == 9) {
            tmp += "🂹";
        } else if (value == 10) {
            tmp += "🂺";
        } else if (value == 11) {
            tmp += "🂻";
        } else if (value == 12) {
            tmp += "🂽";
        } else if (value == 13) {
            tmp += "🂾";
        }
    }

    return tmp;
}
