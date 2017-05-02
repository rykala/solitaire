#include "GameFacade.h"
#include "Deck.h"
#include "WorkPack.h"
#include "Card.h"
#include "TargetPack.h"
#include "StartPack.h"
#include <vector>
#include "Globals.h"
#include <iostream>

using std::vector;
using std::move;
using std::back_inserter;
using std::next;
using std::cout;

GameFacade::GameFacade()
{

}

void GameFacade::NewGame(Deck &deck, vector<TargetPack> &targetPacks, vector<WorkPack> &workPacks, StartPack &startPack) {
    for (int i = 1; i < 8; ++i) {
        vector<Card> cards;

        auto it = next(deck.cards.begin(), i);

        move(deck.cards.begin(), it, back_inserter(cards));

        deck.cards.erase(deck.cards.begin(), it);

        WorkPack workPack(cards, i);
        workPacks.push_back(workPack);
    }

    for (int i = 0; i < 4; ++i) {
        TargetPack targetPack;
        targetPacks.push_back(targetPack);
    }

    vector<Card> startCards;
    auto it = std::next(deck.cards.begin(), deck.cards.size());
    move(deck.cards.begin(), it, back_inserter(startCards));
    deck.cards.erase(deck.cards.begin(), it);
    StartPack helpPack(startCards);
    startPack = helpPack;
}

bool GameFacade::isWin(vector<TargetPack> &targetPacks) {
    int winFlag = 0;

    for (unsigned int i = 0; i < targetPacks.size(); ++i) {
        if(targetPacks.size() == 13) {
            winFlag++;
        }
    }

    if (winFlag == 4) {
        return true;
    }

    return false;
}

void GameFacade::moveCard(StartPack &startPack, TargetPack &targetPack) {
    auto it = next(startPack.cards.begin(), startPack.cards.size());
//    move(startPack.cards.begin(), it, back_inserter(targetPack.cards));

    targetPack.cards.push_back(startPack.cards.at(startPack.top));

//    startPack.cards.erase(startPack.cards.begin(), it);

//    startPack.flipCard();
}
