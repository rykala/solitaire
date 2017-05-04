#include "GraphicStartPack.h"
#include "GraphicCard.h"

#include <sstream>

using std::vector;

GraphicStartPack::GraphicStartPack(QWidget *parent, StartPack *startPack) : QLabel(parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->startPack = startPack;

    for (auto &card : startPack->cards) // access by reference to avoid copying
     {
         GraphicCard *m_card = new GraphicCard(parent, card);
         m_card->drawCard(20,5);
     }

    this->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    this->setFixedSize(67, 100);
    this->move(20, 5);
    this->show();
}
