#include "Game.h"
#include "Card.h"
#include "Globals.h"

#include <QDebug>

Game::Game()
{
    this->NewGame();
}

void Game::NewGame()
{
    for (int i = 0; i < 7; ++i) {
        vector<Card> cards;

        auto it = next(deck.cards.begin(), i+1);

        move(deck.cards.begin(), it, back_inserter(cards));

        deck.cards.erase(deck.cards.begin(), it);

        WorkPack workPack(cards, i);

        for(auto &card: workPack.cards)
        {
            card.setDeckType(DeckType::Work);
            card.setDeckIndex(i);
        }

        workPacks.push_back(workPack);
    }

    for (int i = 0; i < 4; ++i) {
        TargetPack targetPack;

        for(auto &card: targetPack.cards)
        {
            card.setDeckType(DeckType::Target);
            card.setDeckIndex(i);
        }

        targetPacks.push_back(targetPack);
    }

    vector<Card> startCards;
    auto it = std::next(deck.cards.begin(), deck.cards.size());
    move(deck.cards.begin(), it, back_inserter(startCards));
    deck.cards.erase(deck.cards.begin(), it);

    for(auto &card: startCards)
    {
        card.setDeckType(DeckType::Start);
        card.setDeckIndex(0);
    }

    StartPack helpPack(startCards);
    startPack = helpPack;
}

bool Game::isWin()
{
//    if(targetPacks.at(0). == 13 && targetPacks.at(1).size() == 13 &&
//            targetPacks.at(2).length() == 13 && targetPacks.at(3).length() == 13) {
//        return true;
//    }

    return false;
}

bool Game::isStartPackEmpty()
{
//    Card *card = new Card();
//    if(startPack.getTopCard(card)) {
//        return true;
//    }

    return false;
}

vector<Card> Game::getStartPack()
{
    return startPack.cards;
}

vector<Card> Game::getWorkPack(int index)
{
    return workPacks.at(index).getCards();
}

void Game::popCards(Card card)
{
    hand.clear();
    hand.push_back(card);

    DeckType deckType = card.getDeckType();

    if(deckType == DeckType::Start){
        startPack.cards.erase(startPack.cards.begin() + startPack.getTopIndex());
    }
}

void Game::pushCards(Card bottomCard)
{
    DeckType deckType = bottomCard.getDeckType();

    if(deckType == DeckType::Start){
        startPack.cards.insert(startPack.cards.begin() + startPack.getTopIndex(), hand.at(0));
        qDebug() << "Vracim kartu zpet!";
    }
}
