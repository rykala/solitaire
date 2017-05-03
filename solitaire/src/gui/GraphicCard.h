#ifndef GRAPHICCARD_H
#define GRAPHICCARD_H

#include <QLabel>
#include <QGraphicsItem>

#include "Card.h"

class GraphicCard : public QLabel, public Card
{
public:
    GraphicCard(QWidget *parent);
    GraphicCard(Card *card, QWidget *parent, bool faceUp = true);
    ~GraphicCard();
    void drawCard(int x, int y);
    void drawBackCard(int x, int y);
    void updateCard();
    bool faceUp;
    void flipCard();
};

#endif // GRAPHICCARD_H
