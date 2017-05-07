#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "WorkPack.h"
#include "Card.h"
#include "TargetPack.h"
#include "StartPack.h"

#include <vector>
#include <string>

using std::string;

class Game
{
public:
    Game();
    Game(vector <WorkPack*> workPacks, vector<TargetPack*> targetPacks, StartPack *startPack,
         vector< vector<Card*> > historyHand,
         vector<DeckType> historyDeckType,
         vector<int> historyDeckIndex,
         vector<int> historyTop,
         vector<bool> historyFlip);

    /* METHODS */
    void newGame();
    bool undoTurn();

    void flipCards();
    int flipStartCard();

    void popCards(Card *card);
    bool pushCards(DeckType decktype, int deckIndex = 0);
    void pushCardsBack();
    bool isValidMove(vector <Card*> cards, DeckType deckType, int deckIndex = 0);
    string getHint();

    bool isWin();

    /* GETTERS */
    StartPack *getStartPack() {return startPack;}
    WorkPack *getWorkPack(int i) {return workPacks.at(i);}
    TargetPack *getTargetPack(int i) {return targetPacks.at(i);}
    vector<Card*> getHand() {return hand;}
    vector<WorkPack*> getWorkPacks() {return workPacks;}

protected:
    Deck deck;
    vector<TargetPack*> targetPacks;
    vector<WorkPack*> workPacks;
    StartPack *startPack;
    vector<Card*> hand;

    void saveTurn(vector<Card*> hand, DeckType deckType, int deckIndex, int topIndex);
    vector< vector<Card*> > historyHand;
    vector<DeckType> historyDeckType;
    vector<int> historyDeckIndex;
    vector<int> historyTop;
    vector<bool> historyFlip;
    void saveGame();
};

#endif // GAME_H
