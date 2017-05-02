#ifndef GRAPHICGAMEBOARD_H
#define GRAPHICGAMEBOARD_H

#include <QApplication>
#include <QWidget>
#include <QDrag>
#include <QFrame>

#include "Game.h"

class QDragEnterEvent;
class QDropEvent;

class GraphicGameBoard : public QFrame
{
public:
    GraphicGameBoard(QWidget *parent = 0);
    void drawGameBoard();

protected:
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
private:
    Game *game;
    void drawWorkPacks();
    void drawStartPack();
    void drawTargetPacks();
    void reloadCards();
    Card *hand;
};

#endif // GRAPHICGAMEBOARD_H
