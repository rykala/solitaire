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

    /* METHODS */
    void newGame();

    void flipCards();
    int flipStartCard();

    void popCards(Card *card);
    bool pushCards(DeckType decktype, int deckIndex = 0);
    void pushCardsBack();
    bool isValidMove();

    /* GETTERS */
    StartPack *getStartPack() {return startPack;}
    WorkPack *getWorkPack(int i) {return workPacks.at(i);}
    TargetPack *getTargetPack(int i) {return targetPacks.at(i);}
    vector<Card*> getHand() {return hand;}

protected:
    Deck deck;
    vector<TargetPack*> targetPacks;
    vector<WorkPack*> workPacks;
    StartPack *startPack;
    vector<Card*> hand;
};

#endif // GAME_H
