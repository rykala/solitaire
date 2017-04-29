#include <QGraphicsSceneMouseEvent>
#include <QList>
#include <QPainter>

#include "GraphicDeck.h"

GraphicDeck::GraphicDeck()
{
}

GraphicDeck::~GraphicDeck(){}

QPainterPath GraphicDeck::shape() const
{
    // This is called when finding collinding items
    // with QGraphicScene::collidingItems()
    QPainterPath path;
    QRectF rect = boundingRect();
    path.addRect(rect);
    return path;
}

QRectF GraphicDeck::boundingRect() const
{
    return QRectF(0, 0, 75, 110);
}

void GraphicDeck::paint(QPainter *painter,
                 const QStyleOptionGraphicsItem *option,
                 QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Draw deck background rect
    painter->setPen(Qt::SolidLine);
    painter->setPen(QColor(Qt::black));
    QRectF rect = boundingRect();
    rect.adjust(4,4,-4,-4);

    painter->drawRoundedRect(rect,2,2);
}
