#include "GraphicStartPack.h"
#include "Card.h"
#include "GraphicCard.h"

#include <sstream>
#include <QLabel>
#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <vector>

using std::vector;

GraphicStartPack::GraphicStartPack(QWidget *parent, vector<Card> m_cards) : QLabel(parent), StartPack(m_cards)
{
    for (auto &card : m_cards) // access by reference to avoid copying
     {
         GraphicCard *m_card = new GraphicCard(&card, parent);
         m_card->drawCard(20,5);

         m_card->stackUnder(this);

         cards.push_back(m_card);
     }

    setPixmap(QPixmap(":/back/2").scaled(70, 105, Qt::KeepAspectRatio));
    this->setStyleSheet("border: 0;");
    this->move(20, 5);
    this->show();
}

void GraphicStartPack::mousePressEvent(QMouseEvent *event)
{
    flipCard();
}

void GraphicStartPack::generateCards()
{

}

void GraphicStartPack::flipCard()
{
    cards.at(this->top)->move(110,5);

    if(this->top >= (cards.size() - 1)) {
        for (auto &card : cards) {
             card->move(20, 5);
         }
        this->top = 0;
    }

    this->top++;
}
