//#include <stdlib.h>
//#include <string>
//#include <iostream>
//#include "Card.h"
//#include "Deck.h"
//#include "Globals.h"
//#include "StartPack.h"
//#include "WorkPack.h"
//#include "TargetPack.h"
//#include "Game.h"

#include "CliGameBoard.h"

#include <ctime>

//using std::cout;
//
//using std::vector;
//using std::endl;
//using std::string;
//using std::getline;
//using std::to_string;


int main()
{
    srand(unsigned(std::time(0)));

    CliGameBoard *game = new CliGameBoard();

    game->startGame();

    return 1;
}
