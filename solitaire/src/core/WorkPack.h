#ifndef WORKPACK_H
#define WORKPACK_H

#include "Pack.h"

class WorkPack
{
public:
    WorkPack() {}
    WorkPack(vector<Card*> cards, int index);
    ~WorkPack();

    vector<Card*> cards;

    bool flipHidden();
    int getHiddenIndex() {return hiddenIndex;}
    void incrementHiddenIndex();

protected:
    int hiddenIndex = 0;
};

#endif // WORKPACK_H
