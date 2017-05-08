#ifndef TARGETPACK_H
#define TARGETPACK_H

#include "Card.h"

#include <vector>

using std::vector;

class TargetPack
{
public:

    TargetPack();
    TargetPack(vector<Card*> cards);
    ~TargetPack();

    vector<Card*> cards;
};

#endif // TARGETPACK_H
