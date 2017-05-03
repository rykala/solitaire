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

GraphicCard::GraphicCard(Card *card, QWidget *parent, bool face) : QLabel(parent), Card(card->getValue(), card->getType()) {
        this->setAttribute(Qt::WA_DeleteOnClose);
        this->faceUp = face;
        this->setDeckType(card->getDeckType());
        this->setDeckIndex(card->getDeckIndex());
}

GraphicCard::~GraphicCard(){}

void GraphicCard::drawCard(int x, int y)
{
    if(this->faceUp) {
        stringstream ss;
        ss << ":/" << this->getType() << "/" << this->getValue();
        setPixmap(QPixmap(ss.str().data()).scaled(70, 105, Qt::KeepAspectRatio));
    } else {
        setPixmap(QPixmap(":/back/2").scaled(70, 105, Qt::KeepAspectRatio));
    }

    this->setStyleSheet("border: 0;");
    this->move(x, y);
}

void GraphicCard::updateCard()
{
    stringstream ss;

    ss << ":/" << this->getType() << "/" << this->getValue();
    setPixmap(QPixmap(ss.str().data()).scaled(70, 105, Qt::KeepAspectRatio));
}
