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
    //    setAttribute(Qt::WA_TransparentForMouseEvents);

    this->x = x;
    this->y = y;

    this->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    this->setFixedSize(67, 100);
    this->move(this->x, this->y);
}

void GraphicTargetPack::putCard(GraphicCard *card)
{
    card->setAttribute(Qt::WA_TransparentForMouseEvents);
    graphicCards.push_back(card);
}

void GraphicTargetPack::makeGrabbable(bool flag)
{
    if(cards.size() != 0){
        graphicCards.back()->setAttribute(Qt::WA_TransparentForMouseEvents, !flag);
    }
}

//void GraphicTargetPack::mousePressEvent(QMouseEvent *event)
//{
//        this->makeGrabbable();
//        this->popCard();
//        GraphicGameBoard::mousePressEvent(event);
//        targetPack->makeGrabbable(false);
//}

