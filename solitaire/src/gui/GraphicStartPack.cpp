/**
 * @file GraphicStartPack.cpp
 * @class GraphicStartPack
 * @brief %rStart pack for GUI .
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

#include "GraphicStartPack.h"
#include "GraphicCard.h"

#include <sstream>

using std::vector;

GraphicStartPack::GraphicStartPack(QWidget *parent, StartPack *startPack) : QLabel(parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->startPack = startPack;

    for (int i = (int)this->startPack->cards.size(); i --> 0 && !this->startPack->cards.at(i)->getFaceUp();) {
        GraphicCard *m_card = new GraphicCard(parent, this->startPack->cards.at(i));
            m_card->drawCard(20, 5);
            m_card->show();
    }

    for (int i = 0; i < (int)this->startPack->cards.size() && this->startPack->cards.at(i)->getFaceUp(); i++) {
        GraphicCard *m_card = new GraphicCard(parent, this->startPack->cards.at(i));
            m_card->drawCard(110, 5);
            m_card->show();
    }

    this->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    this->setFixedSize(67, 100);
    this->move(20, 5);
}
