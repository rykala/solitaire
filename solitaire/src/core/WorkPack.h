#ifndef WORKPACK_H
#define WORKPACK_H

#include "Pack.h"

class WorkPack: public Pack
{
public:
    WorkPack() {}
    WorkPack(vector<Card*> cards, int index);
    bool flipHidden();
    int getHiddenIndex() {return hiddenIndex;}
    void incrementHiddenIndex();

protected:
    int hiddenIndex;
};

#endif // WORKPACK_H
