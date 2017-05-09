/**
 * @file GraphicGameBoard.h
 * @class GraphicGameBoard
 * @brief %rMovements, tabluae implementation and addons for GUI .
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

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

/**
 * @brief The GraphicGameBoard class Movements, tabluae implementation and addons for GUI .
 */
class GraphicGameBoard : public QFrame
{
public:
    GraphicGameBoard(QWidget *parent = 0); /**< Constructor. */
    /**
     * @brief drawGameBoard Draws every necesarry object for game in GUI.
     */
    void drawGameBoard();
    /**
     * @brief undoTurn Calls undo in logic implementation of game.
     * @see undoTurn() in game.h
     */
    void undoTurn();
    /**
     * @brief hint Calls hint in logic implementation.
     * @see hint() in game.h
     */
    void hint();
    /**
     * @brief saveGame Implements the save dialog and calls the save function in game logic.
     * @see saveFame() in game.h
     */
    void saveGame();
    /**
     * @brief loadGame Implements the load dialog and calls the load function in game logic.
     * @see loadGame() in game.h
     */
    void loadGame();

protected:
    /* MOUSE EVENTS */
    /**
     * @brief dropEvent Implements the functionality in GUI of card after it is dropped on some stack.
     * @param event specification of event for inizialization
     */
    void dropEvent(QDropEvent *event) override;
    /**
     * @brief dragEvent Implements the functionality in GUI of card after it is dragged from some stack.
     * @param event specification of event for inizialization
     */
    void dragEnterEvent(QDragEnterEvent *event) override;
    /**
     * @brief mousePressEvent Implements the functionality in GUI of card after it is clicked on card on deck.
     * @param event specification of event for inizialization
     */
    void mousePressEvent(QMouseEvent *event) override;
    /**
     * @brief dragMoveEvent Implements the functionality in GUI of movement of card.
     * @param event specification of event for inizialization
     */
    void dragMoveEvent(QDragMoveEvent *event) override;

    /* GRAPHIC GAME LOGIC */
    /**
     * @brief flipStartPack Infinite loop for start pack and the possibility to turn card from start pack.
     * @param clickedCard card that was clicked.
     */
    void flipStartPack(GraphicCard *clickedCard = NULL);
    /**
     * @brief reloadCards method that is called when is clicked on card and it is redraw in other place.
     */
    void reloadCards();

private:
    Game *game;                             /**< Current game. */
    QLabel *hintLabel = NULL;               /**< GUI label for hint. */

    /**
     * @brief drawWorkPacks Draws work packs on right position.
     */
    void drawWorkPacks();
    /**
     * @brief drawStartPack Draws start pack on right position.
     */
    void drawStartPack();
    /**
     * @brief drawTargetPacks Draws target packs on right position.
     */
    void drawTargetPacks();
    /**
     * @brief reDrawPacks TODO
     * @param card
     */
    void reDrawPacks(GraphicCard *card);
    /**
     * @brief gameWon Method to show winning screen after method isWin() returns true.
     * @see isWin() in game.h
     */
    void gameWon();
};

#endif // GRAPHICGAMEBOARD_H
