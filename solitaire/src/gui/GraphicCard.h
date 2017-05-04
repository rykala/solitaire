#ifndef GRAPHICCARD_H
#define GRAPHICCARD_H

#include "Card.h"

#include <QLabel>

class GraphicCard : public QLabel
{
public:
    Card *card;

    GraphicCard(QWidget *parent);
    GraphicCard(QWidget *parent, Card *card);
    ~GraphicCard();

    void drawCard(int x, int y);
    void drawBackCard(int x, int y);
    void updateCard();
};

#endif // GRAPHICCARD_H
