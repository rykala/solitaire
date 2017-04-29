#ifndef GRAPHICCARD_H
#define GRAPHICCARD_H

#include <QLabel>
#include <QGraphicsItem>

#include "Card.h"

class GraphicCard : public QLabel, Card
{
public:
    GraphicCard(Card *card, QWidget *parent = 0);
    ~GraphicCard();
    void drawCard();
    void drawBackCard();
};

#endif // GRAPHICCARD_H
