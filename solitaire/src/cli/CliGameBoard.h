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

    string generateTurnInfo();
    string generateGameBoard();
    int getBiggestWorkPack(vector<WorkPack*> packs);
    void parseTurn();
    void flipCards();
    void moveCards();
};

#endif // CLIGAMEBOARD_H
