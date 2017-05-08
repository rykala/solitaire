#include "CliGameBoard.h"

#include <ctime>

int main()
{
    srand(unsigned(std::time(0)));

    CliGameBoard *game = new CliGameBoard();

    game->startGame();

    delete game;

    return 1;
}
