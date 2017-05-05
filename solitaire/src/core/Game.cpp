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
            workPack->cards.at(j)->setDeckIndex(i);
        }

        workPacks.push_back(workPack);
    }

    for (int i = 0; i < 4; ++i) {
        TargetPack *targetPack = new TargetPack();
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

int Game::flipStartCard()
{
    qDebug() << "Flipping card";
    return startPack->flipCard();
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
    } else if (deckType == DeckType::Target) {
        TargetPack *targetPack = targetPacks.at(card->getDeckIndex());
        targetPack->cards.pop_back();

        qDebug("TargetPack -> Ruka");
    }
}

bool Game::pushCards(DeckType deckType, int deckIndex)
{
        if(!isValidMove()){
            pushCardsBack();
            return false;
        }

    if(deckType == DeckType::Target) {
        if(targetPacks.at(deckIndex)->cards.size() == 0) {
            if(hand.at(0)->getValue() == 1) {
                targetPacks.at(deckIndex)->cards.push_back(hand.at(0));
                hand.at(0)->setDeckType(deckType);
                hand.at(0)->setDeckIndex(deckIndex);
                qDebug() << "TargetPack <- Ruka";
                return true;
            }
        } else if(targetPacks.at(deckIndex)->cards.back()->getValue() == (hand.at(0)->getValue() - 1) &&
                  targetPacks.at(deckIndex)->cards.back()->getType() == hand.at(0)->getType()) {
            targetPacks.at(deckIndex)->cards.push_back(hand.at(0));
            hand.at(0)->setDeckType(deckType);
            hand.at(0)->setDeckIndex(deckIndex);
            qDebug() << "TargetPack <- Ruka";
            return true;
        }
    } else if(deckType == DeckType::Work) {
        if(workPacks.at(deckIndex)->cards.back()->getValue() == (hand.at(0)->getValue() + 1)) {
            if(((workPacks.at(deckIndex)->cards.back()->getType() == CardType::Club ||
                 workPacks.at(deckIndex)->cards.back()->getType() == CardType::Spade) &&
                (hand.at(0)->getType() == CardType::Club || hand.at(0)->getType() == CardType::Spade)) ||
                    ((workPacks.at(deckIndex)->cards.back()->getType() == CardType::Heart ||
                      workPacks.at(deckIndex)->cards.back()->getType() == CardType::Diamond) &&
                     (hand.at(0)->getType() == CardType::Heart || hand.at(0)->getType() == CardType::Diamond))) {
                return false;
            }
            workPacks.at(deckIndex)->cards.push_back(hand.at(0));
            hand.at(0)->setDeckType(deckType);
            hand.at(0)->setDeckIndex(deckIndex);
            qDebug() << "WorkPack <- Ruka";
            return true;
        }

    }

    return false;
}

void Game::pushCardsBack()
{
    for(int i = 0; i < hand.size(); i++) {
        DeckType deckType = hand.at(i)->getDeckType();
        int index = hand.at(i)->getDeckIndex();

        if(deckType == DeckType::Start){
            startPack->incrementTop();
            startPack->cards.insert(startPack->cards.begin() + startPack->getTopIndex(), hand.at(i));
            qDebug() << "StartPack <- Ruka";
        } else if(deckType == DeckType::Target) {
            targetPacks.at(index)->cards.push_back(hand.at(i));
            qDebug() << "TargetPack <- Ruka";
        }
        else if(deckType == DeckType::Work) {
            workPacks.at(index)->cards.push_back(hand.at(i));
            qDebug() << "WorkPack <- Ruka";
        }
    }
}

bool Game::isValidMove()
{
    return false;
}


