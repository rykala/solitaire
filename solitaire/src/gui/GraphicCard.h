#ifndef GRAPHICCARD_H
#define GRAPHICCARD_H

#include <QLabel>
#include <QGraphicsItem>

#include "Card.h"

class GraphicCard : public QLabel, public Card
{
public:
    GraphicCard(QWidget *parent);
    GraphicCard(Card *card, QWidget *parent);
    ~GraphicCard();
    void drawCard(int x, int y);
    void drawBackCard(int x, int y);
protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // GRAPHICCARD_H
