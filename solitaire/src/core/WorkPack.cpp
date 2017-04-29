#include "WorkPack.h"
#include "Card.h"
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::to_string;
using std::next;

WorkPack::WorkPack(vector<Card> cards)
{
    this->hidden.insert(this->hidden.end(), cards.begin(), cards.end());
}

int WorkPack::numOfHiddenCards() {
    return hidden.size();
}

void WorkPack::flipCard() {
    if (hidden.size() == 0 || cards.size() > 0) {
        throw 1;
    }

    Card card;

    auto it = next(hidden.begin(), 1);

    move(hidden.begin(), it, back_inserter(cards));

    hidden.erase(hidden.begin(), it);
}
