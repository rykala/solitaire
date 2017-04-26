#include "GraphicCard.h"

GraphicCard::GraphicCard(const QString &fileName, QGraphicsItem *parent) : QGraphicsSvgItem(fileName,parent)
{
    Pressed = false;
    qDebug() << "Created card";
    setFlag(ItemIsMovable);
}


QRectF GraphicCard::boundingRect() const
{
    return QRectF(0,0,75,110);
}

//void GraphicCard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    QRectF rec = boundingRect();
//    QBrush brush(Qt::blue);

//    if(Pressed){
//        brush.setColor(Qt::red);
//    } else {
//        brush.setColor(Qt::blue);
//    }

//    painter->fillRect(rec, brush);
//    painter->drawRect(rec);
//}

//void GraphicCard::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    Pressed = true;
//    update();
//    QGraphicsItem::mousePressEvent(event);
//}

//void GraphicCard::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//{
//    Pressed = true;
//    update();
//    QGraphicsItem::mouseReleaseEvent(event);
//}
