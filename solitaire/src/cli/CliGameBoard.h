/**
 * @file CliGameBoard.h
 * @class CliGameBoard
 * @brief %rCommand line verison implementation.
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

#ifndef CLIGAMEBOARD_H
#define CLIGAMEBOARD_H

#include "Game.h"

/**
 * @brief The CliGameBoard class for command line gameboard.
 */
class CliGameBoard
{
public:
    CliGameBoard();
    ~CliGameBoard();

    void startGame();

private:
    Game *game; /**< Pointer to actual game. */

    vector<Game*> games;    /**< Vector for multiple games. */

    /**
     * @brief generateTurnInfo  Generates command line info about turns.
     * @return Command line info about turns.
     */
    string generateTurnInfo();
    /**
     * @brief generateGameBoard Generates game graphic of cards and packs in command line version.
     * @return Game graphic of cards and packs in command line version.
     */
    string generateGameBoard();
    /**
     * @brief getBiggestWorkPack Gets index of biggest pack.
     * @param packs Work packs.
     * @return index.
     */
    int getBiggestWorkPack(vector<WorkPack*> packs);
    /**
     * @brief parseTurn Parses input with logical turn.
     * @return True if it is valid.
     */
    bool parseTurn();
    /**
     * @brief flipCards Flips selected cards.
     */
    void flipCards();
    /**
     * @brief moveCards Redraws card in selected position.
     */
    void moveCards();
    /**
     * @brief gameNumber Computes position of game.
     * @return Number of selected game.
     */
    int gameNumber();
    /**
     * @brief switchGames Switches the game table to another game.
     */
    void switchGames();
    /**
     * @brief loadGame Calls load game logic in command line.
     */
    void loadGame();
    /**
     * @brief saveGame  Calls save game logic in command line.
     */
    void saveGame();
};

#endif // CLIGAMEBOARD_H
