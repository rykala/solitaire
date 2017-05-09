/**
 * @file GraphicTargetPack.cpp
 * @class GraphicTargetPack
 * @brief %rTarget pack for GUI .
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

#include "GraphicTargetPack.h"
#include "TargetPack.h"

GraphicTargetPack::GraphicTargetPack(QWidget *parent, TargetPack *targetPack, int x, int y, int index) : QLabel(parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->targetPack = targetPack;
    this->x = x;
    this->y = y;
    this->index = index;

    this->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    this->setFixedSize(67, 100);
    this->move(this->x, this->y);

    for (int i = 0; i < (int)this->targetPack->cards.size(); i++) {
        GraphicCard *m_card = new GraphicCard(parent, this->targetPack->cards.at(i));
        m_card->drawCard(x, y);
        m_card->raise();
        m_card->show();
    }
}
