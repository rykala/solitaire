#ifndef GRAPHICWORKPACK_H
#define GRAPHICWORKPACK_H

#include "WorkPack.h"
#include "GraphicCard.h"

#include <QLabel>

class GraphicWorkPack : public QLabel, WorkPack
{
public:
    GraphicWorkPack(QWidget *parent, vector<Card> m_cards, int hiddenIndex, int x, int y);
    int getX() {return x;}
    int getY() {return y;}
private:
    vector <GraphicCard*> cards;
    int x;
    int y;
};

#endif // GRAPHICWORKPACK_H
