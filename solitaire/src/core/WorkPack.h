#ifndef WORKPACK_H
#define WORKPACK_H

#include "Pack.h"

class WorkPack: public Pack
{
public:
    WorkPack(vector<Card> cards);
    void flipCard();
    vector<Card> putCard();
    vector<Card> takeCards(int index);
    string numOfHiddenCards();

private:
    vector<Card> hidden;

};

#endif // WORKPACK_H
