#include "GraphicGameBoard.h"
#include "GraphicCard.h"
#include "GraphicStartPack.h"
#include "GraphicTargetPack.h"
#include "Card.h"
#include "GraphicWorkPack.h"
#include "Globals.h"

#include <QtWidgets>
#include <QMouseEvent>
#include <QMimeData>
#include <QDebug>
#include <QPixmap>
#include <vector>

using std::vector;

GraphicGameBoard::GraphicGameBoard(QWidget *parent) : QFrame(parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    setAcceptDrops(true);

    this->game = new Game();
}

void GraphicGameBoard::drawGameBoard()
{
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
    int x = 290;
    int y = 5;

    for (int i = 0; i < 4; ++i) {
        GraphicTargetPack *targetPack = new GraphicTargetPack(this, game->getTargetPack(i), x, y);
        x += 90;
    }
}

void GraphicGameBoard::drawWorkPacks()
{
    int x = 20;
    int y = 130;

    for (int i = 0; i < 7; ++i) {
        GraphicWorkPack *workPack = new GraphicWorkPack(this, game->getWorkPack(i), x, y);
        x += 90;
    }
}

void GraphicGameBoard::reloadCards()
{
    game->flipCards();

    QList<QLabel*> items = findChildren<QLabel*>();

    for(auto &item : items) {
        GraphicCard *card = dynamic_cast<GraphicCard*>(item);
        if(card) {
            card->updateCard();
        }
    }
}

void GraphicGameBoard::flipStartPack(GraphicCard *clickedCard)
{
    game->flipCard(clickedCard->card);
    clickedCard->raise();
    clickedCard->move(110,5);
    clickedCard->updateCard();
}

void GraphicGameBoard::reloadStartPack()
{
    QList<QLabel*> items = findChildren<QLabel*>();

    /* Backward loop */
    for (int i = items.size(); i --> 0 ;)
    {
        GraphicCard *card = dynamic_cast<GraphicCard*>(items.at(i));
        if(card && card->card->getDeckType() == DeckType::Start) {
            card->card->setFaceUp(false);
            card->raise();
            card->move(20, 5);
            card->updateCard();
        }
    }
}


/* -------------------------------------------------------------------------------------*/
/*                                  MOUSE EVENTS                                        */
/* -------------------------------------------------------------------------------------*/


void GraphicGameBoard::dropEvent(QDropEvent *event)
{
    /* ---------------------------- CUSTOM ACTIONS ------------------------------------ */
    GraphicTargetPack *targetPack = dynamic_cast<GraphicTargetPack*>(childAt(event->pos()));
    GraphicCard *bottomCard = dynamic_cast<GraphicCard*>(childAt(event->pos()));

    int x = 0;
    int y = 0;

    if(targetPack) {
        x = targetPack->getX();
        y = targetPack->getY();

//        if(game->hand.at(0).)
//        targetPack->cards.push_back(game->hand.at(0));

//    } else if (bottomCard->card->getDeckType() == DeckType::Target) {
//        qDebug() << "Dropping on target Pkac";
//        x = targetPack->at(bottomCard->card->getDeckIndex())->getX();
//        y = targetPack->at(bottomCard->card->getDeckIndex())->getY();
//    } else if (bottomCard) {
//        qDebug() << "Drop na kartu";
    } else {
        return;
    }

    /*--------------------------------------------------------------------------------*/

    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        GraphicCard *newCard = new GraphicCard(this, game->getHand().at(0));
        newCard->setPixmap(pixmap);
        newCard->move(x, y);
        newCard->show();
        newCard->setAttribute(Qt::WA_DeleteOnClose);

        /* ---------------------------- CUSTOM ACTIONS ------------------------------------ */


        /*--------------------------------------------------------------------------------*/
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
    /* ---------------------------- CUSTOM ACTIONS ------------------------------------ */
    GraphicCard *clickedCard = dynamic_cast<GraphicCard*>(childAt(event->pos()));
    GraphicStartPack *startPack = dynamic_cast<GraphicStartPack*>(childAt(event->pos()));

    if(!clickedCard && !startPack)
        return;

    if (clickedCard) {
        if(clickedCard->card->getDeckType() == DeckType::Start && !clickedCard->card->getFaceUp())
        {
            this->flipStartPack(clickedCard);
            return;
        } else if (clickedCard->card->getDeckType() == DeckType::Work && !clickedCard->card->getFaceUp()) {
            game->flipCard(clickedCard->card);
            clickedCard->updateCard();
            return;
        }
    } else if(startPack) {
        reloadStartPack();
        return;
    } else {
        return;
    }

    /*--------------------------------------------------------------------------------*/

    QPixmap pixmap = *clickedCard->pixmap();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->pos() - clickedCard->pos());

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - clickedCard->pos());

    clickedCard->hide();

    /* ---------------------------- CUSTOM ACTIONS ------------------------------------ */

    game->popCards(clickedCard->card);

    /*--------------------------------------------------------------------------------*/

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        clickedCard->close();
        reloadCards(); //If card is moved from workPack, flips top hidden card.
    } else {
        game->pushCards(clickedCard->card->getDeckType()); // PUSH THE CARD BACK TO THE ORIGINAL PACK, IF IT'S NOT DROPPED ANYWHERE VALID
        clickedCard->show();
        clickedCard->setPixmap(pixmap);
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


