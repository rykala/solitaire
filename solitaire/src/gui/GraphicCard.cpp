#include "GraphicCard.h"
#include "Card.h"

#include <sstream>
#include <QLabel>
#include <QWidget>
#include <QDebug>

using std::stringstream;

GraphicCard::GraphicCard(Card *card, QWidget *parent) : QLabel(parent), Card(card->getValue(), card->getType())
{

}

GraphicCard::~GraphicCard(){}

void GraphicCard::drawCard()
{
    stringstream ss;

    ss << ":/" << this->getType() << "/" << this->getValue();
    setPixmap(QPixmap(ss.str().data()).scaled(100, 100, Qt::KeepAspectRatio));
    this->show();
}

void GraphicCard::drawBackCard()
{
    setPixmap(QPixmap(":/back/2").scaled(100, 100, Qt::KeepAspectRatio));
    this->show();
}
