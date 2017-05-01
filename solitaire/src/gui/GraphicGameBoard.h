#ifndef GRAPHICGAMEBOARD_H
#define GRAPHICGAMEBOARD_H

#include <QApplication>
#include <QWidget>
#include <QDrag>
#include <QFrame>

#include "Game.h"

class GraphicGameBoard : public QFrame
{
public:
    GraphicGameBoard(QWidget *parent = 0);
    void drawGameBoard();

private:
    Game *game;
    void drawWorkPacks();
    void drawStartPack();
    void drawTargetPacks();
};

#endif // GRAPHICGAMEBOARD_H
