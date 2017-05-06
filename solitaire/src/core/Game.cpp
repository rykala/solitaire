#include "Game.h"
#include "Card.h"
#include "Globals.h"

#include <QDebug>
#include <algorithm>    // std::reverse

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

    historyHand.clear();
    historyDeckType.clear();
    historyDeckIndex.clear();
    historyTop.clear();
}

int Game::flipStartCard()
{
    qDebug() << "Flipping card";
    return startPack->flipCard();
}

void Game::flipCards() {
    bool flip = false;

    for(auto &pack: workPacks) {

        if(!flip) {
            flip = pack->flipHidden();
        }
    }
    if (historyFlip.size() > 5) {
        historyFlip.erase(historyFlip.begin());
    }

    historyFlip.push_back(flip);
}

void Game::popCards(Card *card)
{
    hand.clear();

    DeckType deckType = card->getDeckType();

    if(deckType == DeckType::Start){
        hand.push_back(card);
        startPack->cards.erase(startPack->cards.begin() + startPack->getTopIndex());
        startPack->decrementTop();
        qDebug("StartPack -> Ruka");
    } else if (deckType == DeckType::Work) {
        WorkPack *workPack = workPacks.at(card->getDeckIndex());

        do {
            hand.push_back(workPack->cards.back());
            workPack->cards.pop_back();
        } while (workPack->cards.size() > 0 && hand.back()->getName() != card->getName());

        std::reverse(hand.begin(), hand.end());

        qDebug("WorkPack -> Ruka");
    } else if (deckType == DeckType::Target) {
        hand.push_back(card);
        TargetPack *targetPack = targetPacks.at(card->getDeckIndex());
        targetPack->cards.pop_back();

        qDebug("TargetPack -> Ruka");
    }
}

bool Game::pushCards(DeckType deckType, int deckIndex)
{

    if(!isValidMove(hand, deckType, deckIndex)){
        return false;
    }

    DeckType tmpType = hand.at(0)->getDeckType();
    int tmpIndex = hand.at(0)->getDeckIndex();

    if(deckType == DeckType::Target) {
        targetPacks.at(deckIndex)->cards.push_back(hand.at(0));
        hand.at(0)->setDeckType(deckType);
        hand.at(0)->setDeckIndex(deckIndex);
        qDebug() << "TargetPack <- Ruka";
    } else if(deckType == DeckType::Work) {
        for (auto &card : hand) {
            card->setDeckType(deckType);
            card->setDeckIndex(deckIndex);
            workPacks.at(deckIndex)->cards.push_back(card);
        }
        qDebug() << "WorkPack <- Ruka";
    }

    saveTurn(hand, tmpType, tmpIndex, startPack->getTopIndex());

    return true;
}

void Game::pushCardsBack()
{
    for(int i = 0; i < (int)hand.size(); i++) {
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

bool Game::isValidMove(vector <Card*> cards, DeckType deckType, int deckIndex)
{
    Card *card = cards.at(0);

    if(deckType == DeckType::Target) {
        if(targetPacks.at(deckIndex)->cards.size() == 0) {
            // If target pack is empty
            if(card->getValue() != 1) {
                // If the card put on empty target is not ACE
                return false;
            }
        } else if(cards.size() > 1) {
            return false;
        } else if(targetPacks.at(deckIndex)->cards.back()->getValue() == (card->getValue() - 1)) {
            if(targetPacks.at(deckIndex)->cards.back()->getType() != card->getType()) {
                // If target is not empty, card has to be same color and value+1
                return false;
            }
        } else {
            return false;
        }
    } else if(deckType == DeckType::Work) {
        if(workPacks.at(deckIndex)->cards.size() == 0) {
            // If work pack is empty
            if(card->getValue() != 13){
                return false;
            }
        } else if(workPacks.at(deckIndex)->cards.back()->getValue() == (card->getValue() + 1)) {
            // If workpack not empty card needs to be lower value-1
            if((workPacks.at(deckIndex)->cards.back()->getType() == CardType::Club ||
                workPacks.at(deckIndex)->cards.back()->getType() == CardType::Spade) &&
                    (card->getType() == CardType::Club || card->getType() == CardType::Spade)) {
                return false;
            } else if ((workPacks.at(deckIndex)->cards.back()->getType() == CardType::Heart ||
                        workPacks.at(deckIndex)->cards.back()->getType() == CardType::Diamond) &&
                       (card->getType() == CardType::Heart || card->getType() == CardType::Diamond)) {
                // Color has to be different
                return false;
            }
        } else {
            return false;
        }
    }

    return true;
}

std::string Game::getHint()
{
//    string hint;

//    for(auto worPack : workPacks) {
//        workPacks->cards.back();
//        for(auto targetPack : targetPacks) {

//        }
//    }
}

void Game::saveTurn(vector<Card*> hand, DeckType deckType, int deckIndex, int topIndex)
{
    if (historyHand.size() > 5) {
        historyHand.erase(historyHand.begin());
        historyDeckType.erase(historyDeckType.begin());
        historyDeckIndex.erase(historyDeckIndex.begin());
        historyTop.erase(historyTop.begin());
    }

    historyHand.push_back(hand);
    historyDeckType.push_back(deckType);
    historyDeckIndex.push_back(deckIndex);
    historyTop.push_back(topIndex);
}

bool Game::undoTurn()
{
    if(historyHand.size() == 0) {
        return false;
    }

    DeckType deckType = historyDeckType.back();
    if(historyFlip.back() && deckType == DeckType::Work) {
        workPacks.at(historyDeckIndex.back())->cards.back()->setFaceUp(!historyFlip.back());
        workPacks.at(historyDeckIndex.back())->incrementHiddenIndex();
    }

    for(int i = 0; i < (int)historyHand.back().size(); i++) {
        DeckType deckType = historyDeckType.back();
        int index = historyDeckIndex.back();

        // Remove card from old pack
        if(historyHand.back().at(i)->getDeckType() == DeckType::Target) {
            targetPacks.at(historyHand.back().at(i)->getDeckIndex())->cards.pop_back();
        } else if(historyHand.back().at(i)->getDeckType() == DeckType::Work) {
            workPacks.at(historyHand.back().at(i)->getDeckIndex())->cards.pop_back();
        }

        // Move card to new location (undo)
        if(deckType == DeckType::Start){
            // if we are moving card back to the start pack we need to increase top, cuz the top in history
            // is one less, because it was saved after the pop of the card, therefore top one less
            startPack->cards.insert(startPack->cards.begin() + (++historyTop.back()), historyHand.back().at(i));
            qDebug() << "Historie: StartPack <- Ruka";
        } else if(deckType == DeckType::Target) {
            targetPacks.at(index)->cards.push_back(historyHand.back().at(i));
            qDebug() << "Historie: TargetPack <- Ruka";
        } else if(deckType == DeckType::Work) {
            workPacks.at(index)->cards.push_back(historyHand.back().at(i));
            qDebug() << "Historie: WorkPack <- Ruka";
        }

        historyHand.back().at(i)->setDeckType(deckType);
        historyHand.back().at(i)->setDeckIndex(index);
    }

    for(int i = 0; i < startPack->cards.size(); i++) {
        bool face = (i <= historyTop.back());
        startPack->cards.at(i)->setFaceUp(face);
    }

    startPack->setTopIndex(historyTop.back());

    historyHand.pop_back();
    historyDeckType.pop_back();
    historyDeckIndex.pop_back();
    historyTop.pop_back();
    historyFlip.pop_back();

    return true;
}
