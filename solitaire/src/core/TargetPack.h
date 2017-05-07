#ifndef TARGETPACK_H
#define TARGETPACK_H

#include "Pack.h"
#include "Card.h"

class TargetPack : public Pack
{
public:
    TargetPack();
    TargetPack(vector <Card*> cards);
};

#endif // TARGETPACK_H
