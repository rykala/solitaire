/**
 * @file Deck.h
 * @class Deck
 * @brief %Deck implementation.
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "Globals.h"
#include <vector>

using std::vector;
/**
 * @brief The Deck class implements deck for solitaire game.
 */
class Deck
{
    public:
        vector<Card*> cards;    /**< Vector of cards. */
        Deck();                 /**< Constructor. */
};

#endif // DECK_H
