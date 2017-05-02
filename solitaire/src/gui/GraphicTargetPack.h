#ifndef GRAPHICTARGETPACK_H
#define GRAPHICTARGETPACK_H

#include "TargetPack.h"

#include <QLabel>

class GraphicTargetPack : public QLabel, TargetPack
{
public:
    GraphicTargetPack(QWidget *parent, int x, int y);
    int getX() {return x;}
    int getY() {return y;}
private:
    int x;
    int y;

};

#endif // GRAPHICTARGETPACK_H
