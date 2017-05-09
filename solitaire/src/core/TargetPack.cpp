/**
 * @file TargetPack.cpp
 * @class TargetPack
 * @brief %rTarget pack class.
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

#include "TargetPack.h"
#include "Card.h"

#include <vector>

using std::vector;

TargetPack::TargetPack()
{

}

TargetPack::TargetPack(vector<Card*> cards)
{
    this->cards = cards;
}

TargetPack::~TargetPack()
{
    for (auto card : this->cards) {
        delete card;
    }
}
