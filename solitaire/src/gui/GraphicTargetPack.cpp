#include "GraphicTargetPack.h"
#include "Card.h"
#include "TargetPack.h"
#include "GraphicCard.h"
#include "GraphicGameBoard.h"

#include <QLabel>
#include <vector>
#include <QDropEvent>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QMouseEvent>

using std::vector;

GraphicTargetPack::GraphicTargetPack(QWidget *parent, int x, int y) : QLabel(parent), TargetPack()
{
    this->x = x;
    this->y = y;

    this->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    this->setFixedSize(67, 100);
    this->move(this->x, this->y);
}

//void GraphicTargetPack::putCard(GraphicCard *card)
//{
//    graphicCards.push_back(card);
//}
