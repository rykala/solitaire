/**
 * @file Card.h
 * @class Card
 * @brief %rCard implementation.
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

#ifndef CARD_H
#define CARD_H

#include "Globals.h"

#include <string>

using std::string;
/**
 * @brief The Card class
 */
class Card
{
public:
    Card();
    Card(int value, CardType type, bool faceUp = true); //constructor

    /* METHODS */
    /**
     * @brief flipCard implements card flipping
     */
    void flipCard();

    /* GETTERS SETTERS */
    /**
     * @brief getName
     * @return Name of card.
     */
    string getName();
    /**
     * @brief getValue
     * @return Value of card.
     */
    int getValue();
    /**
     * @brief getType
     * @return Type of card.
     */
    CardType getType();

    /**
     * @brief getDeckType Gets type of deck of card.
     * @return Type of deck.
     */
    DeckType getDeckType() {return this->deck;}
    /**
     * @brief setDeckType Sets type of deck of card.
     * @param deck
     */
    void setDeckType(DeckType deck) {this->deck = deck;}
    /**
     * @brief getDeckIndex Gets position of deck.
     * @return Index, position of deck
     */
    int getDeckIndex() {return this->deckIndex;}
    /**
     * @brief getDeckIndex Sets position of deck.
     * @return Index, position of deck
     */
    void setDeckIndex(int index) {this->deckIndex = index;}

    bool getFaceUp() {return this->faceUp;}
    void setFaceUp(bool value) {this->faceUp = value;}

private:
    int value;      /**< Value of card. */
    CardType type;  /**< Enum of card types. */
    DeckType deck;  /**< Enum of deck types. */
    int deckIndex;  /**< Index of deck. */
    bool faceUp;    /**< If card is face down or face up. */

};

#endif // CARD_H
