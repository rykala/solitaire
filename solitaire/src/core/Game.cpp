#include "Game.h"

Game::Game()
{
    this->NewGame();
}

void Game::NewGame()
{
    for (int i = 1; i < 8; ++i) {
        vector<Card> cards;

        auto it = next(deck.cards.begin(), i);

        move(deck.cards.begin(), it, back_inserter(cards));

        deck.cards.erase(deck.cards.begin(), it);

        WorkPack workPack(cards);
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
