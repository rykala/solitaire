#ifndef GRAPHICSTARTPACK_H
#define GRAPHICSTARTPACK_H

#include "Card.h"
#include "StartPack.h"
#include "GraphicCard.h"

#include <QLabel>
#include <vector>

using std::vector;

class GraphicStartPack : public QLabel, public StartPack
{    
public:
    GraphicStartPack(QWidget *parent, vector<Card*> m_cards);
    void flipCard();
    vector <GraphicCard*> cards;

protected:
    void mousePressEvent(QMouseEvent *event);
    void generateCards();
};

#endif // GRAPHICSTARTPACK_H
