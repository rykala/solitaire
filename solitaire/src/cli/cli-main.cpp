/**
 * @file cli-main.cpp
 * @brief %rSimple main for command line version.
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

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
