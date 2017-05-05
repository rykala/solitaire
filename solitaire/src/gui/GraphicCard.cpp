#include "GraphicCard.h"
#include "Card.h"

#include <sstream>
#include <QPixmap>

using std::stringstream;

GraphicCard::GraphicCard(QWidget *parent) : QLabel(parent) {}

GraphicCard::GraphicCard(QWidget *parent, Card *card) : QLabel(parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->card = card;
}

GraphicCard::~GraphicCard(){}

void GraphicCard::drawCard(int x, int y)
{
    this->x = x;
    this->y = y;

    if(card->getFaceUp()) {
        stringstream ss;
        ss << ":/" << card->getType() << "/" << card->getValue();
        setPixmap(QPixmap(ss.str().data()).scaled(70, 105, Qt::KeepAspectRatio));
    } else {
        setPixmap(QPixmap(":/back/2").scaled(70, 105, Qt::KeepAspectRatio));
    }

    this->setStyleSheet("border: 0;");
    this->move(x, y);
}

void GraphicCard::updateCard()
{
    if(card->getFaceUp()) {
        stringstream ss;
        ss << ":/" << card->getType() << "/" << card->getValue();
        setPixmap(QPixmap(ss.str().data()).scaled(70, 105, Qt::KeepAspectRatio));
    } else {
        setPixmap(QPixmap(":/back/2").scaled(70, 105, Qt::KeepAspectRatio));
    }
}
