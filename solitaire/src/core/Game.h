#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "WorkPack.h"
#include "Card.h"
#include "TargetPack.h"
#include "StartPack.h"
#include <vector>

class Game
{
public:
    Game();
    void NewGame();
    void SaveGame();
    bool isWin(vector<TargetPack> &targetPacks);
    void moveCard(StartPack &startPack, TargetPack &targetPack);

private:
    Deck deck;
    vector<TargetPack> targetPacks;
    vector<WorkPack> workPacks;
    StartPack startPack;
};

#endif // GAME_H
