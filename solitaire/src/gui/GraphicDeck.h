#ifndef DECK_H
#define DECK_H

#include <QGraphicsSvgItem>

class GraphicDeck : public QGraphicsSvgItem
{

public: // Constructor and destructor
    GraphicDeck();
    ~GraphicDeck();
    QPainterPath shape() const;
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);

private: // Data

};

#endif // DECK_H
