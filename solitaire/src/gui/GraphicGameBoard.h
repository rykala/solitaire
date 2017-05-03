#ifndef GRAPHICGAMEBOARD_H
#define GRAPHICGAMEBOARD_H

#include <QApplication>
#include <QWidget>
#include <QDrag>
#include <QFrame>
#include <vector>

#include "Game.h"
#include "GraphicStartPack.h"
#include "GraphicWorkPack.h"
#include "GraphicTargetPack.h"

using std::vector;

class QDragEnterEvent;
class QDropEvent;

class GraphicGameBoard : public QFrame
{
public:
    GraphicGameBoard(QWidget *parent = 0);
    void drawGameBoard();

protected:
    /* GAME PACKS */
    vector<GraphicCard*> hand;
    vector<GraphicTargetPack*> targetPacks;
    vector<GraphicWorkPack*> workPacks;
    GraphicStartPack *startPack;

    /* MOUSE EVENTS */
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;

    /* GRAPHIC GAME LOGIC */
    void popCards(GraphicCard *card);
    void pushCards(Card *bottomCard);

private:
    Game *game;
    void drawWorkPacks();
    void drawStartPack();
    void drawTargetPacks();
    void reloadCards();

};

#endif // GRAPHICGAMEBOARD_H
