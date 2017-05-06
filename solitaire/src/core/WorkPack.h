#ifndef WORKPACK_H
#define WORKPACK_H

#include "Pack.h"

class WorkPack: public Pack
{
public:
    WorkPack(vector<Card*> cards, int hiddenIndex);
    bool flipHidden();
    int numOfHiddenCards();
    void incrementHiddenIndex();

protected:
    int hiddenIndex;

};

#endif // WORKPACK_H
