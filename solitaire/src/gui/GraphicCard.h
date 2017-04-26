#ifndef GRAPHICCARD_H
#define GRAPHICCARD_H

#include <QGraphicsSvgItem>
#include <QPainter>
#include <QDebug>


class GraphicCard : public QGraphicsSvgItem
{
public:
    GraphicCard(const QString &fileName, QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool Pressed;

protected:
//    void mousePressEvent(QGraphicsSceneMouseEvent *event);
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
//        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // GRAPHICCARD_H
