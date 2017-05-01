#include "GraphicCard.h"
#include "Card.h"

#include <sstream>
#include <QLabel>
#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <QDragEnterEvent>
#include <QFlags>
#include <QMimeData>
#include <QPixmap>

using std::stringstream;

GraphicCard::GraphicCard(QWidget *parent) : QLabel(parent) {}

GraphicCard::GraphicCard(Card *card, QWidget *parent) : QLabel(parent), Card(card->getValue(), card->getType()) {}

GraphicCard::~GraphicCard(){}

void GraphicCard::drawCard(int x, int y)
{
    stringstream ss;

    ss << ":/" << this->getType() << "/" << this->getValue();
    setPixmap(QPixmap(ss.str().data()).scaled(100, 100, Qt::KeepAspectRatio));
    this->setStyleSheet("border: 0;");
    this->move(x, y);
}

void GraphicCard::drawBackCard(int x, int y)
{
    setPixmap(QPixmap(":/back/2").scaled(100, 100, Qt::KeepAspectRatio));
    this->setStyleSheet("border: 0;");
    this->move(x, y);
}


void GraphicCard::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}

void GraphicCard::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void GraphicCard::mousePressEvent(QMouseEvent *event)
{
    GraphicCard *child = dynamic_cast<GraphicCard*>(this);
    QPixmap pixmap = *child->pixmap();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->pos() - child->pos());

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);

    QDrag *drag = new QDrag(child);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(QPoint(30,10));

    child->hide();

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        child->close();
    } else {
        child->show();
        child->setPixmap(pixmap);
    }
}
