/**
 * @file GraphicWorkPack.cpp
 * @class GraphicWorkPack
 * @brief %rWork pack for GUI .
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

#include "GraphicWorkPack.h"
#include "WorkPack.h"
#include "GraphicCard.h"

GraphicWorkPack::GraphicWorkPack(QWidget *parent, WorkPack *workPack, int x, int y, int index) : QLabel(parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->workPack = workPack;
    this->x = x;
    this->y = y;
    this->index = index;

    this->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    this->setFixedSize(70, 105);
    this->move(this->x, this->y);

    int tmp_y = this->y;

    for (int i = 0; i < (int)this->workPack->cards.size(); i++) {
        GraphicCard *m_card = new GraphicCard(parent, this->workPack->cards.at(i));
        m_card->drawCard(x, tmp_y);

        tmp_y += (m_card->card->getFaceUp() ? 15 : 5);
        m_card->raise();
        m_card->show();
    }
}
