#ifndef GRAPHICWORKPACK_H
#define GRAPHICWORKPACK_H

#include "WorkPack.h"
#include "GraphicCard.h"

#include <QLabel>

class GraphicWorkPack : public QLabel, public WorkPack
{
public:
    GraphicWorkPack(QWidget *parent, vector<Card> m_cards, int hiddenIndex, int x, int y);
    int getX() {return x;}
    int getY() {return y;}
    vector <GraphicCard*> gCards;
    void flipHidden();
protected:
    int x;
    int y;
};

#endif // GRAPHICWORKPACK_H
