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
