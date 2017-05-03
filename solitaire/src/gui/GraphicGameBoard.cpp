#include <QtWidgets>
#include <QMouseEvent>
#include <QMimeData>
#include <QDebug>
#include <QPixmap>
#include <vector>

#include "GraphicGameBoard.h"
#include "GraphicCard.h"
#include "GraphicStartPack.h"
#include "GraphicTargetPack.h"
#include "Card.h"
#include "GraphicWorkPack.h"
#include "Globals.h"

using std::vector;

GraphicGameBoard::GraphicGameBoard(QWidget *parent) : QFrame(parent)
{
    this->game = new Game();
    setAcceptDrops(true);
    this->setAttribute(Qt::WA_DeleteOnClose);
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
    startPack = new GraphicStartPack(this, game->getStartPack());
}

void GraphicGameBoard::drawTargetPacks()
{
    int x = 290;
    int y = 5;

    for (int i = 0; i < 4; ++i) {
        GraphicTargetPack *targetPack = new GraphicTargetPack(this, x, y);

        targetPacks.push_back(targetPack);

        x += 90;
    }
}

void GraphicGameBoard::drawWorkPacks()
{
    int x = 20;
    int y = 130;

    for (int i = 0; i < 7; ++i) {
        GraphicWorkPack *workPack = new GraphicWorkPack(this, game->getWorkPack(i), i, x, y);

        workPacks.push_back(workPack);

        x += 90;
    }
}

void GraphicGameBoard::popCards(GraphicCard *card)
{
    hand.clear();
    hand.push_back(card);

    DeckType deckType = card->getDeckType();

    if(deckType == DeckType::Start){
        startPack->cards.erase(startPack->cards.begin() + startPack->getTopIndex());
    }
}

void GraphicGameBoard::pushCards(Card *bottomCard)
{
    DeckType deckType = bottomCard->getDeckType();

    if(deckType == DeckType::Start){
        startPack->cards.insert(startPack->cards.begin() + startPack->getTopIndex(), hand.at(0));
        qDebug() << "Vracim kartu zpet!";
    }
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
        if (!(targetPack->putCards(game->hand))){
            return;
        }
    } else {
        return;
    }

    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        GraphicCard *newIcon = new GraphicCard(&(game->hand.at(0)), this);
        newIcon->setPixmap(pixmap);
        newIcon->move(x, y);
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);
        if(targetPack) {
            targetPack->putCard(newIcon);
        }

        hand.clear();

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
    GraphicCard *child = dynamic_cast<GraphicCard*>(childAt(event->pos()));

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

    popCards(child);

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        child->close();
    } else {
        pushCards(child);
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


