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
    void makeGrabbable(bool flag = true);
//    vector<GraphicCard*> popCard();

protected:
    vector<GraphicCard*> graphicCards;
    int x;
    int y;
//    void mousePressEvent(QMouseEvent *event);

};

#endif // GRAPHICTARGETPACK_H
