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
    void updateCard();

    int getX() {return x;}
    int getY() {return y;}

private:
    int x;
    int y;
};

#endif // GRAPHICCARD_H
