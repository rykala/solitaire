/**
 * @file WorkPack.h
 * @class WorkPack
 * @brief %rWork pack class.
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

#ifndef WORKPACK_H
#define WORKPACK_H

#include "Card.h"

#include <vector>

using std::vector;
/**
 * @brief The WorkPack class
 */
class WorkPack
{
public:
    WorkPack() {}   /**< Constructor. */
    WorkPack(vector<Card*> cards, int index);   /**< Constructor. */
    ~WorkPack();    /**< Destructor. */

    vector<Card*> cards;
    /**
     * @brief flipHidden Flips hidden card tha is on top of work pack.
     * @return
     */
    bool flipHidden();
    /**
     * @brief getHiddenIndex Gets index of card in work pack that is the last hidden card on top.
     * @return
     */
    int getHiddenIndex() {return hiddenIndex;}
    /**
     * @brief incrementHiddenIndex Increments idex of hidden card in work pack to next card.
     */
    void incrementHiddenIndex();

protected:
    int hiddenIndex = 0;    /**< Initialization of hidden index. */
};

#endif // WORKPACK_H
