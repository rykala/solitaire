#include <QWidget>
#include <QMouseEvent>
#include <QMimeData>

#include "GraphicGameBoard.h"

GraphicGameBoard::GraphicGameBoard(QWidget *parent) : QFrame(parent)
{
    this->game = new Game();
}

void GraphicGameBoard::updateGameBoard()
{
    // Vykreslit: stack -> getTopCard(), getTopCard() - 1;
    // TargetPacks: null => [], !null => getTopCard()....private int value; value+1, CardType
    // WorkPacks vector hidden, work...hidenn 3x drawBackCard(), [[[], for(work) [ [ [], WorkPack isWin() 4x Packy full == WIN;

}

void GraphicGameBoard::drawStartPack()()
{
    if(Game.isStartPackEmpty()) {

    }
}


void GraphicGameBoard::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if(event->source() == this) {
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
        if(event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
    } else {
        event->ignore();
    }
}

void GraphicGameBoard::dropEvent(QDropEvent *event)
{

}

void GraphicGameBoard::mousePressEvent(QMouseEvent *event)
{

}
