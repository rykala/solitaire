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
    //    ss << ":/" << ranknames.at(this->card->rank) << "_" << suitnames.at(this->card->suit);
}

void GraphicCard::drawBackCard()
{
    setPixmap(QPixmap(":back").scaled(100, 100, Qt::KeepAspectRatio));
}
