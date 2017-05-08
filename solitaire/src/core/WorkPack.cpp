#include "WorkPack.h"
#include "Card.h"

#include <vector>
#include <string>

using std::vector;

WorkPack::WorkPack(vector<Card*> cards, int index)
{
    this->cards.insert(this->cards.end(), cards.begin(), cards.end());
    this->hiddenIndex = index;
}

WorkPack::~WorkPack()
{
    for (auto card : cards) {
        delete card;
    }
}

void WorkPack::incrementHiddenIndex()
{
    hiddenIndex++;
}

bool WorkPack::flipHidden() {
    if (hiddenIndex != 0 && hiddenIndex == (int)cards.size()) {
        hiddenIndex--;
        cards.at(hiddenIndex)->setFaceUp(true);
        return true;
    }
    return false;
}
