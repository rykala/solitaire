/**
 * @file TargetPack.h
 * @class TargetPack
 * @brief %rTarget pack class.
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

#ifndef TARGETPACK_H
#define TARGETPACK_H

#include "Card.h"

#include <vector>

using std::vector;
/**
 * @brief The TargetPack class
 */
class TargetPack
{
public:

    TargetPack();       /**< Constructor. */
    TargetPack(vector<Card*> cards);        /**< Constructor. */
    ~TargetPack();      /**< Destructor. */

    vector<Card*> cards;            /**< Vector of cards in target pack. */
};

#endif // TARGETPACK_H
