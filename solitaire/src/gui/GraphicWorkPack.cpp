#include "GraphicWorkPack.h"
#include "WorkPack.h"
#include "GraphicCard.h"

#include <QDebug>

GraphicWorkPack::GraphicWorkPack(QWidget *parent, vector<Card> m_cards, int hiddenIndex, int x, int y)
    : QLabel(parent), WorkPack(m_cards, hiddenIndex)
{
    this->x = x;
    this->y = y;

    this->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    this->setFixedSize(70, 105);
    this->move(this->x, this->y);

    int tmp_y = this->y;

    for (int i = 0; i < (int)m_cards.size(); i++) {
        bool face = (i >= this->hiddenIndex);


        GraphicCard *m_card = new GraphicCard(&(m_cards.at(i)), parent, face);
        m_card->drawCard(x, tmp_y);

        gCards.push_back(m_card);

        tmp_y += (m_card->faceUp ? 15 : 5);
    }
}

void GraphicWorkPack::flipHidden() {
    if (hiddenIndex == gCards.size()) {
        hiddenIndex--;
        gCards.at(hiddenIndex)->flipCard();
    }
}

