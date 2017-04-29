#ifndef GRAPHICCARD_H
#define GRAPHICCARD_H

#include <QLabel>
#include <QGraphicsItem>
#include "Card.h"

class Card;

class GraphicCard : public QLabel, Card
{
public:
    GraphicCard(Card *card, QWidget *parent = 0);
    ~GraphicCard();

private:
//    Card *card;
    void drawCard();
    void drawBackCard();
};

#endif // GRAPHICCARD_H
