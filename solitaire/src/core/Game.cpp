#include "Game.h"
#include "Card.h"
#include "Globals.h"

#include <QDebug>

Game::Game()
{
    this->newGame();
}

void Game::newGame()
{
    for (int i = 0; i < 7; ++i) {
        vector<Card*> cards;

        auto it = next(deck.cards.begin(), i+1);
        move(deck.cards.begin(), it, back_inserter(cards));
        deck.cards.erase(deck.cards.begin(), it);

        WorkPack *workPack = new WorkPack(cards, i);

        for(int j = 0; j < (int)workPack->cards.size(); j++)
        {
            if (j < i) {
                workPack->cards.at(j)->setFaceUp(false);
            }

            workPack->cards.at(j)->setDeckType(DeckType::Work);
            workPack->cards.at(j)->setDeckIndex(j);
        }

        workPacks.push_back(workPack);
    }

    for (int i = 0; i < 4; ++i) {
        TargetPack *targetPack = new TargetPack();

        for(auto &card: targetPack->cards)
        {
            card->setDeckType(DeckType::Target);
            card->setDeckIndex(i);
        }

        targetPacks.push_back(targetPack);
    }

    vector<Card*> startCards;
    auto it = std::next(deck.cards.begin(), deck.cards.size());
    move(deck.cards.begin(), it, back_inserter(startCards));
    deck.cards.erase(deck.cards.begin(), it);

    for(auto &card: startCards)
    {
        card->setDeckType(DeckType::Start);
        card->setDeckIndex(0);
        card->setFaceUp(false);
    }

    startPack = new StartPack(startCards);
    //    startPack = helpPack;
}

void Game::flipCard(Card *card)
{
    card->setFaceUp(true);
}

void Game::flipCards() {
    for(auto &pack: workPacks) {
        pack->flipHidden();
    }
}

void Game::popCards(Card *card)
{
    hand.clear();
    hand.push_back(card);

    DeckType deckType = card->getDeckType();

    if(deckType == DeckType::Start){
        startPack->cards.erase(startPack->cards.begin() + startPack->getTopIndex());
        startPack->decrementTop();

        qDebug("StartPack -> Ruka");
    } else if (deckType == DeckType::Work) {
        WorkPack *workPack = workPacks.at(card->getDeckIndex());
        workPack->cards.pop_back();

        qDebug("WorkPack -> Ruka");
    }
}

void Game::pushCards(DeckType deckType, int deckIndex)
{

    if(deckType == DeckType::Start){
        startPack->cards.insert(startPack->cards.begin() + startPack->getTopIndex(), hand.at(0));
        qDebug() << "StartPack <- Ruka";
    }else if(deckType == DeckType::Target) {
//        if (bottomCard->getValue() == (hand.at(0)->getValue() - 1) && bottomCard->getType() == hand.at(0)->getType()) {
//            qDebug() << "TargetPack <- Ruka";
//        }
    }
}


