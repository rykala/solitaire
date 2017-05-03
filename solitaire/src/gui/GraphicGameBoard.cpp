#include <QtWidgets>
#include <QMouseEvent>
#include <QMimeData>
#include <QDebug>
#include <QPixmap>

#include "GraphicGameBoard.h"
#include "GraphicCard.h"
#include "GraphicStartPack.h"
#include "GraphicTargetPack.h"
#include "Card.h"
#include "GraphicWorkPack.h"

GraphicGameBoard::GraphicGameBoard(QWidget *parent) : QFrame(parent)
{
    this->game = new Game();
    setAcceptDrops(true);
}

void GraphicGameBoard::drawGameBoard()
{
    // Vykreslit: stack -> getTopCard(), getTopCard() - 1;
    // TargetPacks: null => [], !null => getTopCard()....private int value; value+1, CardType
    // WorkPacks vector hidden, work...hidenn 3x drawBackCard(), [[[], for(work) [ [ [], WorkPack isWin() 4x Packy full == WIN;
    drawStartPack();
    drawWorkPacks();
    drawTargetPacks();
    this->show();
}

void GraphicGameBoard::drawStartPack()
{
    GraphicStartPack *startPack = new GraphicStartPack(this, game->getStartPack());
}

void GraphicGameBoard::drawTargetPacks()
{
    GraphicTargetPack *targetPack1 = new GraphicTargetPack(this, 290, 5);
    GraphicTargetPack *targetPack2 = new GraphicTargetPack(this, 380, 5);
    GraphicTargetPack *targetPack3 = new GraphicTargetPack(this, 470, 5);
    GraphicTargetPack *targetPack4 = new GraphicTargetPack(this, 560, 5);
}

void GraphicGameBoard::drawWorkPacks()
{
    GraphicWorkPack *workPack1 = new GraphicWorkPack(this, game->getWorkPack(0), 0, 20, 130);
    GraphicWorkPack *workPack2 = new GraphicWorkPack(this, game->getWorkPack(1), 1, 110, 130);
    GraphicWorkPack *workPack3 = new GraphicWorkPack(this, game->getWorkPack(2), 2, 200, 130);
    GraphicWorkPack *workPack4 = new GraphicWorkPack(this, game->getWorkPack(3), 3, 290, 130);
    GraphicWorkPack *workPack5 = new GraphicWorkPack(this, game->getWorkPack(4), 4, 380, 130);
    GraphicWorkPack *workPack6 = new GraphicWorkPack(this, game->getWorkPack(5), 5, 470, 130);
    GraphicWorkPack *workPack7 = new GraphicWorkPack(this, game->getWorkPack(6), 6, 560, 130);
}

void GraphicGameBoard::reloadCards()
{
    QList<QLabel*> items = findChildren<QLabel*>();

    for(auto &item : items) {
        GraphicCard *card = dynamic_cast<GraphicCard*>(item);
        if(card) {
            card->updateCard();
        }
    }
}

void GraphicGameBoard::dropEvent(QDropEvent *event)
{
    int x = 0;
    int y = 0;
    GraphicTargetPack *targetPack = dynamic_cast<GraphicTargetPack*>(childAt(event->pos()));

    if(targetPack) {
        x = targetPack->getX();
        y = targetPack->getY();
    } else {
        return;
    }

    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;
        //        reloadCards();

        GraphicCard *newIcon = new GraphicCard(hand, this);
        newIcon->setPixmap(pixmap);
        newIcon->move(x, y);
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void GraphicGameBoard::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void GraphicGameBoard::mousePressEvent(QMouseEvent *event)
{
    GraphicCard *child = static_cast<GraphicCard*>(childAt(event->pos()));

    if(!child || !child->faceUp)
        return;

    QPixmap pixmap = *child->pixmap();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->pos() - child->pos());

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - child->pos());

    child->hide();
//    child->setPixmap(pixmap);
    this->hand = child;

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        child->close();
    } else {
        child->show();
        child->setPixmap(pixmap);
    }
}

void GraphicGameBoard::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}


