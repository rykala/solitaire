#ifndef CLIGAMEBOARD_H
#define CLIGAMEBOARD_H

#include "Game.h"

class CliGameBoard
{
public:
    CliGameBoard();

    void startGame();

private:
    Game *game;

    vector<Game*> games;

    string generateTurnInfo();
    string generateGameBoard();
    int getBiggestWorkPack(vector<WorkPack*> packs);
    void parseTurn();
    void flipCards();
    void moveCards();
    int gameNumber();
    void switchGames();
    void loadGame();
    void saveGame();
};

#endif // CLIGAMEBOARD_H
