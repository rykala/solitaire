#ifndef GRAPHICTARGETPACK_H
#define GRAPHICTARGETPACK_H

#include "TargetPack.h"
#include "GraphicCard.h"

#include <QLabel>

class GraphicTargetPack : public QLabel
{
public:
    TargetPack *targetPack;

    GraphicTargetPack(QWidget *parent, TargetPack *targetPack, int x, int y, int index);

    int getX() {return x;}
    int getY() {return y;}
    int getIndex() {return index;}

protected:
    int x;
    int y;
    int index;

};

#endif // GRAPHICTARGETPACK_H
