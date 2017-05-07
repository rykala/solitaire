#include "CliGameBoard.h"
#include "WorkPack.h"
#include "StartPack.h"
#include "TargetPack.h"

#include <string>
#include <iostream>
#include <algorithm>
#include <QDebug>


using std::to_string;
using std::cout;
using std::endl;
using std::cin;
using std::transform;

CliGameBoard::CliGameBoard()
{
    for (int i = 0; i < 4; ++i) {
        Game *newGame = new Game();
        games.push_back(newGame);
    }

    game = games.at(0);
}


void CliGameBoard::startGame() {
    while(!game->isWin()) {
        cout << generateGameBoard() << endl;
        cout << generateTurnInfo() << endl;
        parseTurn();
        game->flipCards();
    }

    cout << "YOU WON!!! :)" << endl;
    exit(1);
}

int CliGameBoard::gameNumber() {
    ptrdiff_t pos = find(games.begin(), games.end(), game) - games.begin();

    if(pos >= (int)games.size()) {
        //old_name_ not found
    }

    return pos;
}

void CliGameBoard::switchGames()
{
    bool isInputInvalid = false;

    do {
        isInputInvalid = false;
        string gameNum;

        cout << "Number of game to switch to (1-4 or press x to cancel): ";

        getline(cin, gameNum);
        transform(gameNum.begin(), gameNum.end(), gameNum.begin(), ::tolower);

        if(gameNum == "x") {
            return;
        } else if (gameNum == "1" || gameNum == "2" || gameNum == "3" || gameNum == "4") {
            int pos = (int)gameNum[0] - 49;
            qDebug() << pos;
            game = games.at(pos);
        } else {
            isInputInvalid = true;
        }
    } while (isInputInvalid);

}


void CliGameBoard::parseTurn() {
    bool isInputInvalid = false;

    do {
        isInputInvalid = false;
        string position, index, positionTo, playerTurn;

        cout << "Enter your turn: ";

        getline(cin, playerTurn);
        transform(playerTurn.begin(), playerTurn.end(), playerTurn.begin(), ::tolower);

        if(playerTurn == "e") {
            exit(1);
        } else if(playerTurn =="s") {
            game->flipStartCard();
        } else if(playerTurn == "h") {
            cout << endl << game->getHint() << endl;
            isInputInvalid = true;
        } else if(playerTurn == "u") {
            if (!game->undoTurn()) {
                cout << endl << "Nothing to undo!" << endl << endl;
                isInputInvalid = true;
            }
        } else if (playerTurn == "m") {
            moveCards();
        } else if (playerTurn == "n") {
            int i = gameNumber();
            delete game;
            games.at(i) = new Game();
            game = games.at(i);
        } else if(playerTurn == "w"){
            switchGames();
        } else {
            isInputInvalid = true;
        }
    } while (isInputInvalid);
}

void CliGameBoard::moveCards()
{
    string column;
    string index;
    string columnTo;
    bool isInputInvalid = false;

    do {
        isInputInvalid = false;

        cout << "Pick up card(s) from column (x to cancel): ";
        getline(cin, column);
        transform(column.begin(), column.end(), column.begin(), ::tolower);

        if (column == "x") {
            return;
        } else if (column == "s") {
            int top = game->getStartPack()->getTopIndex();
            if (top != -1) {
                game->popCards(game->getStartPack()->cards.at(top));
            } else {
                cout << "There is no card in that position!" << endl;
                isInputInvalid = true;
            }
        } else if (column == "a" || column == "b" || column == "c" || column == "d") {
            int from = (int)column[0] - 97;
            if (game->getTargetPack(from)->cards.size() > 0) {
                game->popCards(game->getTargetPack(from)->cards.back());
            } else {
                cout << "There is no card in that position!" << endl;
                isInputInvalid = true;
            }
        } else if(column == "1" || column == "2" || column == "3" || column == "4" || column == "5" ||
                  column == "6" || column == "7") {
            // Converts 1-7 string to indexes 0-6
            int workColumn = (int)column[0] - 49;
            cout << "Enter index of card (x to cancel): ";
            getline(cin, index);
            transform(index.begin(), index.end(), index.begin(), ::tolower);

            if (column == "x") {
                return;
            }

            int workRow = (int)index[0] - 49;
            int workPackSize = game->getWorkPack(workColumn)->cards.size();

            if (workRow >= 0 && workRow < workPackSize) {
                if ((int)game->getWorkPack(workColumn)->cards.size() > workRow) {
                    if((int)game->getWorkPack(workColumn)->cards.at(workRow)->getFaceUp()) {
                        game->popCards(game->getWorkPack(workColumn)->cards.at(workRow));
                    } else {
                        cout << "I cannot pick up that card!" << endl;
                        isInputInvalid = true;
                    }
                }
            } else {
                cout << "There is no card in that position!" << endl;
                isInputInvalid = true;
            }
        } else {
            cout << "I don't know how to pick that up!" << endl;
            isInputInvalid = true;
        }
    } while (isInputInvalid);

    do {
        isInputInvalid = false;
        cout << "Move to position (x to cancel): ";
        getline(cin, columnTo);
        transform(columnTo.begin(), columnTo.end(), columnTo.begin(), ::tolower);

        if (columnTo == "x") {
            game->pushCardsBack();
        } else if (columnTo == "a" || columnTo == "b" || columnTo == "c" || columnTo == "d") {
            // Converst a-d to 0-4
            int pos = (int)columnTo[0] - 97;
            if (!game->pushCards(DeckType::Target, pos)) {
                cout << "I cannot move the card(s) there!" << endl;
                isInputInvalid = true;
            }
        } else if(columnTo == "1" || columnTo == "2" || columnTo == "3" || columnTo == "4" || columnTo == "5" ||
                  columnTo == "6" || columnTo == "7") {
            // Converts 1-7 string to indexes 0-6
            int workColumn = (int)columnTo[0] - 49;
            qDebug() << workColumn;
            cout << "Enter index of card (x to cancel): ";
            getline(cin, index);
            transform(index.begin(), index.end(), index.begin(), ::tolower);

            if (index == "x") {
                game->pushCardsBack();
                return;
            }

            int workRow = (int)index[0] - 49;
            int workPackSize = game->getWorkPack(workColumn)->cards.size();

            if ((workRow >= 0 && workRow < workPackSize) || (workPackSize == 0 && workRow == 0)) {
                if(game->getWorkPack(workColumn)->cards.at(workRow)->getFaceUp() &&
                        game->getWorkPack(workColumn)->cards.at(workRow) == game->getWorkPack(workColumn)->cards.back()) {
                    if (!game->pushCards(DeckType::Work, workColumn)) {
                        qDebug() << "Push fail!";
                        cout << "I cannot move the card(s) there!" << endl;
                        isInputInvalid = true;
                    }
                } else {
                    qDebug() << "Face is not up!";
                    cout << "I cannot put the card(s) there!" << endl;
                    isInputInvalid = true;
                }
            } else {
                qDebug() << "out of index!";
                cout << "There is no place to put the card on!" << endl;
                isInputInvalid = true;
            }
        } else {
            cout << "I cannot move the card(s) there!" << endl;
            isInputInvalid = true;
        }
    } while (isInputInvalid);
}

string CliGameBoard::generateTurnInfo() {
    string turnInfo = "GAME #";
    turnInfo +=       to_string(gameNumber() + 1);
    turnInfo +=       "\n";
    turnInfo +=       "S) Give me more cards!\n"
                      "M) Move cards!\n"
                      "U) Woops! Take me one turn back!\n"
                      "H) I need help!\n"
                      "W) Switch to another game!\n"
                      "N) Give me new cards!\n"
                      "E) Get me out of here!\n";

    return turnInfo;
}

string CliGameBoard::generateGameBoard() {
    string board;
    StartPack *startPack = game->getStartPack();

    board += "_______________________________________\n\n";
    board += "       S:          a:    b:    c:    d:\n";
    board += !startPack->cards.back()->getFaceUp() ? " 🂠     ": " ◻     ";
    board += startPack->cards.at(0)->getFaceUp() ? startPack->cards.at(startPack->getTopIndex())->getName() : "◻";
    board += "           ";

    for (int i = 0; i < 4; ++i) {
        board += (game->getTargetPack(i)->cards.size() > 0) ? game->getTargetPack(i)->cards.back()->getName() : "◻";

        if(i == 3) {
            board += "\n\n";
        } else {
            board += "     ";
        }
    }

    board += " 1:    2:    3:    4:    5:    6:    7:\n";

    for (int row = 0; row < getBiggestWorkPack(game->getWorkPacks()); ++row) {
        for (int column = 0; column < 7; ++column) {
            if (row == 0) {
                board += " ";
                board += (game->getWorkPack(column)->cards.size() > 0) ? game->getWorkPack(column)->cards.at(row)->getName() : "◻";
                board += "    ";
            } else {
                board += " ";
                board += ((int)game->getWorkPack(column)->cards.size() > row) ? game->getWorkPack(column)->cards.at(row)->getName() : " ";
                board += "    ";
            }
        }
        board += ":";
        board += to_string(row+1);
        board += "\n";
    }

    board += "\n_______________________________________\n";


    return board;
}

int CliGameBoard::getBiggestWorkPack(vector<WorkPack *> packs)
{
    int max = 0;

    for(auto pack : packs) {
        if(max < (int)pack->cards.size()) {
            max = pack->cards.size();
        }
    }

    return max;
}
