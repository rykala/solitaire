#ifndef GRAPHICGAMEBOARD_H
#define GRAPHICGAMEBOARD_H

#include <QApplication>
#include <QWidget>
#include <QDrag>
#include <QFrame>

#include "Game.h"
#include "GraphicStartPack.h"
#include "GraphicWorkPack.h"
#include "GraphicTargetPack.h"

class GraphicGameBoard : public QFrame
{
public:
    GraphicGameBoard(QWidget *parent = 0);
    void drawGameBoard();

protected:
    /* MOUSE EVENTS */
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;

    /* GRAPHIC GAME LOGIC */
    void flipStartPack(GraphicCard *clickedCard = NULL);
    void reloadCards();

private:
    Game *game;

    void drawWorkPacks();
    void drawStartPack();
    void drawTargetPacks();
};

#endif // GRAPHICGAMEBOARD_H
