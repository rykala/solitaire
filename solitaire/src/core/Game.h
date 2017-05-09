/**
 * @file Game.h
 * @class Game
 * @brief %Game logic implementation for GUI and command line version.
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

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
/**
 * @brief The Game class implements logic of game for GUI and command line version.
 */
class Game
{
public:
    Game(); /**< Constructor. */
    Game(vector <WorkPack*> workPacks, vector<TargetPack*> targetPacks, StartPack *startPack);  /**< Constructor. */
    ~Game();    /**< Destructor. */

    /* METHODS */
    /**
     * @brief newGame Initialization of pack for new game.
     */
    void newGame();
    /**
     * @brief undoTurn Moves card to history position after undo
     * @return
     */
    bool undoTurn();
    /**
     * @brief saveGame Save implementation for save functionality.
     * @param filename Saved game.
     * @return File of saved game.
     */
    bool saveGame(string filename);
    /**
     * @brief loadGame Load implementation for load functionality.
     * @param filename Load game.
     * @return File of load game.
     */
    bool loadGame(const string &filename);
    /**
     * @brief flipCards Implementation of logical flip.
     */
    void flipCards();
    /**
     * @brief flipStartCard Flips card from start pack.
     * @return Top card from start pack.
     */
    int flipStartCard();
    /**
     * @brief popCards Pops card to hand vector from pack.
     * @param card Poped card.
     */
    void popCards(Card *card);
    /**
     * @brief pushCards Push of card to selected deck after pop to hand.
     * @param decktype Type of dack, work, target...
     * @param deckIndex Which one.
     * @return
     */
    bool pushCards(DeckType decktype, int deckIndex = 0);
    /**
     * @brief pushCardsBack if it is not possible to push poped cards to selected deck, its returned.
     */
    void pushCardsBack();
    /**
     * @brief isValidMove Checks if selected move of card is valid.
     * @param cards     Selected card.
     * @param deckType  Type of dack, work, target...
     * @param deckIndex Which one.
     * @return
     */
    bool isValidMove(vector <Card*> cards, DeckType deckType, int deckIndex = 0);
    /**
     * @brief getHint   Chceck actual possible moves.
     * @return  Possible moves.
     */
    string getHint();

    /**
     * @brief isWin
     * @return Win string.
     */
    bool isWin();

    /* GETTERS */
    /**
     * @brief getStartPack  Getter.
     * @return Start pack.
     */
    StartPack *getStartPack() {return startPack;}
    /**
     * @brief getWorkPack   Getter.
     * @param i
     * @return Work pack.
     */
    WorkPack *getWorkPack(int i) {return workPacks.at(i);}
    /**
     * @brief getTargetPack Getter.
     * @param i
     * @return Target pack.
     */
    TargetPack *getTargetPack(int i) {return targetPacks.at(i);}
    /**
     * @brief getHand   Getter.
     * @return Vector of cards in hand.
     */
    vector<Card*> getHand() {return hand;}
    /**
     * @brief getWorkPacks  Getter.
     * @return Vector of work packs.
     */
    vector<WorkPack*> getWorkPacks() {return workPacks;}

protected:
    Deck deck;                          /**< Shuffled deck for packs. */
    vector<TargetPack*> targetPacks;    /**< Vector of target packs. */
    vector<WorkPack*> workPacks;        /**< Vector of work packs. */
    StartPack *startPack;               /**< Initialization of start pack. */
    vector<Card*> hand;                 /**< Vector of cards in hand when is draged. */

    /**
     * @brief saveTurn Seves necessary information for undo function.
     * @param hand
     * @param deckType
     * @param deckIndex
     * @param topIndex
     */
    void saveTurn(vector<Card*> hand, DeckType deckType, int deckIndex, int topIndex);
    vector< vector<Card*> > historyHand;    /**< Vector of cards that have been used for history inmplementation. */
    vector<DeckType> historyDeckType;       /**< Vector of decks that have been used for history inmplementation. */
    vector<int> historyDeckIndex;           /**< Vector of deck position that have been used for history inmplementation. */
    vector<int> historyTop;                 /**< Vector of card that was on top that have been used for history inmplementation. */
    vector<bool> historyFlip;               /**< Vector of flip moves that have been made for history inmplementation. */
};

#endif // GAME_H
