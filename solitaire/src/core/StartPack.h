/**
 * @file StartPack.h
 * @class StartPack
 * @brief %rImplementation of start pack logic.
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

#ifndef STARTPACK_H
#define STARTPACK_H

#include "Card.h"

#include <vector>

using std::vector;
/**
 * @brief The StartPack class
 */
class StartPack
{
public:
    StartPack();        /**< Canstructor. */
    StartPack(vector<Card*> cards);     /**< Constructor. */
    ~StartPack();   /**< Destructor. */

    vector<Card*> cards;            /**< Pointer to vector of cards. */
    /**
     * @brief flipCard  Implementation of flipping card logic from start pack.
     * @return Top card from start pack.
     */
    int flipCard();
    /**
     * @brief decrementTop Decrements top.
     */
    void decrementTop() {top--;}
    /**
     * @brief incrementTop Increments top.
     */
    void incrementTop() {top++;}
    /**
     * @brief getTopIndex Returns index of card that is on top in stat pack.
     * @return Index of topped card.
     */
    int getTopIndex() {return top;}
    void setTopIndex(int top) {this->top = top;}

protected:
    int top = -1; /**< Top is NULL if no card is flipped. */  // Inicializace na null, kdyz zadna karta neni prevracena
};

#endif // STARTPACK_H
