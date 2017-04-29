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
    bool isWin();
    void moveCard(StartPack &startPack, TargetPack &targetPack);
    void History();
    void Undo();
    bool isStartPackEmpty();
    vector<Card> stackBufferCards();

private:
    Deck deck;
    vector<TargetPack> targetPacks;
    vector<WorkPack> workPacks;
    StartPack startPack;
};

#endif // GAME_H
