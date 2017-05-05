#include "WorkPack.h"
#include "Card.h"

#include <vector>
#include <string>

using std::vector;

WorkPack::WorkPack(vector<Card*> cards, int hiddenIndex)
{
    this->cards.insert(this->cards.end(), cards.begin(), cards.end());
    this->hiddenIndex = hiddenIndex;
}

int WorkPack::numOfHiddenCards() {
    return hiddenIndex;
}

void WorkPack::flipHidden() {
    if (hiddenIndex != 0 && hiddenIndex == (int)cards.size()) {
        hiddenIndex--;
        cards.at(hiddenIndex)->setFaceUp(true);
    }
}
