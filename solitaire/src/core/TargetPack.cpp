#include "TargetPack.h"
#include "Card.h"

#include <vector>

using std::vector;

TargetPack::TargetPack()
{

}

TargetPack::TargetPack(vector<Card *> cards)
{
    this->cards = cards;
}

//bool TargetPack::putCards(vector<Card*> cards)
//{
//    if(cards.size() != 1) {
//        return false;
//    }

//    Card card = cards.at(0);

//    if(this->value > 1) {
//        if (card.getType() != this->cards.at(0).getType()) {
//            return false;
//        }
//    }

//    if(card.getValue() == this->value) {
//        this->cards.push_back(card);
//           value++;
//           return true;
//    }

//    return false;
//}

//vector<Card> TargetPack::popCard()
//{
//    Card card = cards.back();
//    vector<Card> tmp;
//    tmp.push_back(card);

//    value--;

//    return tmp;
//}
