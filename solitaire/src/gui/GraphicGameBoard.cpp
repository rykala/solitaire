#include <QWidget>
#include <QMouseEvent>
#include <QMimeData>

#include "GraphicGameBoard.h"

GraphicGameBoard::GraphicGameBoard(QWidget *parent) : QFrame(parent)
{
    setAcceptDrops(true);
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
