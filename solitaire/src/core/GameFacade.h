#ifndef GAMEFACADE_H
#define GAMEFACADE_H

#include "Deck.h"
#include "WorkPack.h"
#include "Card.h"
#include "TargetPack.h"
#include "StartPack.h"
#include <vector>

class GameFacade
{
private:
    Deck deck;
    vector<TargetPack> targetPacks;
    vector<WorkPack> workPacks;


public:
    GameFacade();
    static void NewGame(Deck &deck, vector<TargetPack> &targetPacks, vector<WorkPack> &workPacks, StartPack &startPack);
    static void SaveGame();
    static bool isWin(vector<TargetPack> &targetPacks);
    static void moveCard(StartPack &startPack, TargetPack &targetPack);
};

#endif // GAMEFACADE_H
