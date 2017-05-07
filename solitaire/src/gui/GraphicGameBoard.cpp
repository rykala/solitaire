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
#include <QString>
#include <string>
#include <QFileDialog>

#include <boost/archive/tmpdir.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using std::vector;

GraphicGameBoard::GraphicGameBoard(QWidget *parent) : QFrame(parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    setAcceptDrops(true);

    this->game = new Game();
}

void GraphicGameBoard::drawGameBoard()
{
    QList<QLabel*> items = findChildren<QLabel*>();

    /* Backward loop */
    for (auto &item:items)
    {
        GraphicCard *card = dynamic_cast<GraphicCard*>(item);
        GraphicTargetPack *tPack = dynamic_cast<GraphicTargetPack*>(item);
        GraphicWorkPack *wPack = dynamic_cast<GraphicWorkPack*>(item);
        GraphicStartPack *sPack = dynamic_cast<GraphicStartPack*>(item);

        if (card) {
            card->close();
        } else if (tPack) {
            tPack->close();
        } else if (wPack) {
            wPack->close();
        } else if (sPack) {
            sPack->close();
        }
    }

    drawStartPack();
    drawWorkPacks();
    drawTargetPacks();
    this->show();
}

void GraphicGameBoard::undoTurn()
{
    if(!game->undoTurn()) {
        return;
    }

    drawGameBoard();
}

void GraphicGameBoard::hint()
{
    std::string hint = game->getHint();
    if(hint != "") {
        hintLabel = new QLabel(this);
        hintLabel->setText(QString::fromStdString(hint));
        hintLabel->setStyleSheet("font-size: 14px; background-color: rgba(255,255,255, 90%);"
                                 "color: green; border: 1px solid white; border-left:0;border-top:0;"
                                 "padding: 10px; padding-bottom:0px;");
        hintLabel->show();
    }
}

void GraphicGameBoard::saveGame()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save game"), "",
                                                    tr("Solitaire file (*.sol)"));
    std::ifstream fileHandler;
    try {
        if (!fileName.endsWith(".sol"))
            fileName += ".sol";

        string file(fileName.toLatin1());

        fileHandler.open(file);
        std::ofstream fileHandler(file);
        boost::archive::text_oarchive boostOutputArchieve(fileHandler);
        boostOutputArchieve << game;
        fileHandler.close();
    } catch (std::ifstream::failure err){
        std::cerr << "Exception a r c file";
    }
}


void GraphicGameBoard::loadGame()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Load game"), "",
                                                    tr("Solitaire file (*.sol)"));
    if (fileName.isEmpty())
        return;
    else {
        std::ifstream fileHandler;
        try
        {
            fileHandler.open(fileName.toLatin1());
            boost::archive::text_iarchive boostInputArchieve (fileHandler);
            //read class

            //        if(!game) {
            //            game = new Game();
            //        }

            boostInputArchieve >> game;
            fileHandler.close();
            drawGameBoard();
        }
        catch (std::ifstream::failure err){
            std::cerr << "Exception a r c file";
        }
    }
}

void GraphicGameBoard::drawStartPack()
{
    GraphicStartPack *startPack = new GraphicStartPack(this, game->getStartPack());
    startPack->show();
}

void GraphicGameBoard::drawTargetPacks()
{
    int x = 290;
    int y = 5;

    for (int i = 0; i < 4; ++i) {
        GraphicTargetPack *targetPack = new GraphicTargetPack(this, game->getTargetPack(i), x, y, i);
        targetPack->show();
        x += 90;
    }
}

void GraphicGameBoard::reDrawPacks(GraphicCard *card)
{
    if(card->card->getDeckType() == DeckType::Work){
        QList<QLabel*> items = findChildren<QLabel*>();

        for(auto &item : items) {
            GraphicWorkPack *pack = dynamic_cast<GraphicWorkPack*>(item);
            GraphicCard *card = dynamic_cast<GraphicCard*>(item);
            if (card && card->card->getDeckType() == DeckType::Work){
                card->close();
            }
            if(pack) {
                pack->close();
            }
        }

        drawWorkPacks();
    }
}

void GraphicGameBoard::gameWon()
{
    if(game->isWin()) {
        QLabel *win = new QLabel(this);
        win->setText(QString("YOU WIN!!! :)"));
        win->setFixedSize(650, 450);
        win->setStyleSheet("font-size: 50px; background-color: rgba(255,255,255, 90%);font-weight: bold;"
                           "color: green; width:650px; height:350px;");
        win->setAlignment(Qt::AlignCenter);
        win->show();
    }
}

void GraphicGameBoard::drawWorkPacks()
{
    int x = 20;
    int y = 130;

    for (int i = 0; i < 7; ++i) {
        GraphicWorkPack *workPack = new GraphicWorkPack(this, game->getWorkPack(i), x, y, i);
        x += 90;
        workPack->show();
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
    int flippedCard = game->flipStartCard();

    if (flippedCard > -1 && clickedCard) {
        clickedCard->raise();
        clickedCard->move(110,5);
        clickedCard->updateCard();
    } else {
        QList<QLabel*> items = findChildren<QLabel*>();

        /* Backward loop */
        for (int i = items.size(); i --> 0 ;)
        {
            GraphicCard *card = dynamic_cast<GraphicCard*>(items.at(i));
            if(card && card->card->getDeckType() == DeckType::Start) {
                card->raise();
                card->move(20, 5);
                card->updateCard();
            }
        }
    }

    qDebug() << flippedCard;
}


/* -------------------------------------------------------------------------------------*/
/*                                  MOUSE EVENTS                                        */
/* -------------------------------------------------------------------------------------*/


void GraphicGameBoard::dropEvent(QDropEvent *event)
{
    /* ---------------------------- CUSTOM ACTIONS ------------------------------------ */
    GraphicTargetPack *targetPack = dynamic_cast<GraphicTargetPack*>(childAt(event->pos()));
    GraphicCard *bottomCard = dynamic_cast<GraphicCard*>(childAt(event->pos()));
    GraphicWorkPack *workPack = dynamic_cast<GraphicWorkPack*>(childAt(event->pos()));

    int x = 0;
    int y = 0;
    DeckType deckType;
    int deckIndex = 0;

    if(targetPack) {
        x = targetPack->getX();
        y = targetPack->getY();
        deckType = DeckType::Target;
        deckIndex = targetPack->getIndex();
    } else if (workPack) {
        x = workPack->getX();
        y = workPack->getY();
        deckType = DeckType::Work;
        deckIndex = workPack->getIndex();
    } else if (bottomCard) {
        deckType = bottomCard->card->getDeckType();
        deckIndex = bottomCard->card->getDeckIndex();

        if (deckType == DeckType::Target) {
            // Drop on card in target pack, get its coordinations
            x = bottomCard->getX();
            y = bottomCard->getY();
        } else if (deckType == DeckType::Start) {
            return;
        } else if (deckType == DeckType::Work){
            x = bottomCard->getX();
            y = bottomCard->getY() + 10;
        }
    } else {
        return;
    }

    if(!game->pushCards(deckType, deckIndex)) {
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
        //            newCard->setPixmap(pixmap);
        newCard->drawCard(x,y);
        newCard->raise();
        newCard->show();


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
    if(hintLabel) {
        hintLabel->close();
    }

    GraphicCard *clickedCard = dynamic_cast<GraphicCard*>(childAt(event->pos()));
    GraphicStartPack *startPack = dynamic_cast<GraphicStartPack*>(childAt(event->pos()));

    if(!clickedCard && !startPack)
        return;

    if (clickedCard) {
        if(clickedCard->card->getDeckType() == DeckType::Start && !clickedCard->card->getFaceUp())
        {
            clickedCard->card->setFaceUp(true);
            // Flip card if clicked on startpack
            this->flipStartPack(clickedCard);
            return;
        } else if (clickedCard->card->getDeckType() == DeckType::Work && !clickedCard->card->getFaceUp()) {
            //If clicked on card in workPack with face down
            return;
        }
    } else if(startPack) {
        // Click on startpack, all the cards are on the right side
        flipStartPack();
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

    if(clickedCard->card->getDeckType() == DeckType::Work) {
        QList<QLabel*> items = findChildren<QLabel*>();

        for(auto &item : items) {
            GraphicCard *card = dynamic_cast<GraphicCard*>(item);
            if(card && card->card->getFaceUp() && card->card->getDeckType() == clickedCard->card->getDeckType() &&
                    card->card->getDeckIndex() == clickedCard->card->getDeckIndex() &&
                    card->card->getValue() < clickedCard->card->getValue()) {
                card->close();
            }
        }
    }

    /*--------------------------------------------------------------------------------*/

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        clickedCard->close();
        reDrawPacks(clickedCard);
        reloadCards(); //If card is moved from workPack, flips top hidden card.
        gameWon();
    } else {
        // PUSH THE CARD BACK TO THE ORIGINAL PACK, IF IT'S NOT DROPPED ANYWHERE VALID
        game->pushCardsBack();
        clickedCard->show();
        clickedCard->setPixmap(pixmap);
        reDrawPacks(clickedCard);
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




