#ifndef WORKPACK_H
#define WORKPACK_H

#include "Pack.h"

class WorkPack: public Pack
{
public:
    WorkPack(vector<Card*> cards, int hiddenIndex);
    void flipHidden();
    int numOfHiddenCards();

protected:
    int hiddenIndex;

};

#endif // WORKPACK_H
