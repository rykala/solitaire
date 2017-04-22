#include <QApplication>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Globals.h"
#include "GameFacade.h"
#include "StartPack.h"
#include "WorkPack.h"
#include "TargetPack.h"

using std::cout;
using std::cin;
using std::vector;
using std::endl;
using std::string;
using std::getline;
using std::to_string;

string generateGameBoard(StartPack startPack, vector<TargetPack> targetPacks, vector<WorkPack> workPacks) {
    string board;
    Card topCard;
    int numOfRows = 0;

    for (auto i : workPacks) {
        if (i.cards.size() > (unsigned) numOfRows) {
            numOfRows = i.cards.size();
        }
    }

    board += "____________________________________________________\n\n";
    board += " S:    T:             a:       b:       c:       d:\n";

    board += "[";
    board += startPack.cards.size() ? "  ": "__";
    board += "]";
    board += "  [";
    board += startPack.getTopCard(topCard) ? topCard.getName() : "__";
    board += "]           [";

    for (int i = 0; i < 4; ++i) {
        board += targetPacks.at(i).cards.size() ? targetPacks.at(i).getCard(targetPacks.at(i).cards.size() - 1).getName() : "__";

        if(i == 3) {
            board += "]\n\n";
        } else {
            board += "]     [";
        }
    }

    board += " 1:      2:      3:      4:      5:      6:      7:\n";

    for (float row = -1; row < numOfRows; ++row) {
        for (int column = 0; column < 7; ++column) {
            if (row == -1) {
                board += "[ ";
                board += workPacks.at(column).numOfHiddenCards();

                if (column == 6) {
                    board += "]\n";
                } else {
                    board += "]    ";
                }
            } else {
                if(workPacks.at(column).numOfCards() > 0) {
                    board += "[";
                    board += workPacks.at(column).getCard(row).getName();
                    if (column == 6) {
                        board += ("] :" + to_string((int)row) + "\n");
                    } else {
                        board += "]    ";
                    }
                } else {
                    if (column == 6) {
                        board += "        :" + to_string((int)row) + "\n";
                    } else {
                        board += "        ";
                    }
                }
            }
        }
    }

    board += "\n_____________________________________________________\n";


    return board;
}

int main()
{
    Deck deck;
    vector<TargetPack> targetPacks;
    vector<WorkPack> workPacks;
    StartPack startPack;
    bool isInputInvalid = false;

    GameFacade::NewGame(deck,targetPacks, workPacks, startPack);

    string turnInfo, gameBoard, playerTurn;
    while(!GameFacade::isWin(targetPacks)) {
        turnInfo = "\nS) Get next card from stack\n"
                      "M) Move card from position\n"
                      "F) Flip card at position\n"
                      "E) Exit game\n";

        gameBoard = generateGameBoard(startPack, targetPacks, workPacks);

        cout << gameBoard << endl;


        do {
            isInputInvalid = false;
            string position, index, positionTo;
            int pos;
            int card, posTo, Index;

            cout << turnInfo << endl << "Enter your turn: ";

            getline(cin, playerTurn);
            std::transform(playerTurn.begin(), playerTurn.end(), playerTurn.begin(), ::tolower);

            if(playerTurn == "e") {
                exit(1);
            } else if(playerTurn =="f") {
                cout << "Enter position: ";
                getline(cin, position);
                std::transform(position.begin(), position.end(), position.begin(), ::tolower);

                if (position == "s") {
                    startPack.flipCard();
                } else if((pos = (atoi(position.data())) - 1) >= 0 && pos < 7) {
                    try {
                        workPacks.at(pos).flipCard();
                    } catch (int Exception) {
                        cout << "\nCannot flip this card!\n";
                        isInputInvalid = true;
                    }
                }
            } else if (playerTurn == "m") {
                cout << "Enter position: ";
                getline(cin, position);

                if (position == "t") {
                } else if (position == "a" || position == "b" || position == "c" || position == "d") {

                } else if((pos = (atoi(position.data())) - 1) >= 0 && pos < 7) {
                    cout << "Enter index of card: ";
                    getline(cin, index);
                }

                cout << "Move to position: ";
                getline(cin, positionTo);

                if (positionTo == "a" || positionTo == "b" || positionTo == "c" || positionTo == "d") {
                    GameFacade::moveCard(startPack, targetPacks.at(0));
                }

            } else {
                isInputInvalid = true;
            }
        } while (isInputInvalid);

    }

    return 1;
}
