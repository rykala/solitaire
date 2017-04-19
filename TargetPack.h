#ifndef TARGETPACK_H
#define TARGETPACK_H

#include "Pack.h"
#include "Card.h"

class TargetPack : public Pack
{
public:
    TargetPack();
    Card TakeCard();
    Card PutCard();
};

#endif // TARGETPACK_H
