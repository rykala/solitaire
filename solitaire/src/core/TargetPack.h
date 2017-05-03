#ifndef TARGETPACK_H
#define TARGETPACK_H

#include "Pack.h"
#include "Card.h"


class TargetPack : public Pack
{
public:
    TargetPack();
    Card TakeCard();
    bool putCards(vector<Card> cards);
    vector<Card> popCard();

private:
    int value = 1;

};

#endif // TARGETPACK_H
