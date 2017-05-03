#ifndef GRAPHICTARGETPACK_H
#define GRAPHICTARGETPACK_H

#include "TargetPack.h"
#include "GraphicCard.h"

#include <QLabel>

class GraphicTargetPack : public QLabel, public TargetPack
{
public:
    GraphicTargetPack(QWidget *parent, int x, int y);
    int getX() {return x;}
    int getY() {return y;}
    GraphicCard *getTopCard();
    void putCard(GraphicCard* card);
protected:
    vector<GraphicCard*> graphicCards;
    int x;
    int y;

};

#endif // GRAPHICTARGETPACK_H
