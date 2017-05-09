/**
 * @file GraphicTargetPack.h
 * @class GraphicTargetPack
 * @brief %rTarget pack for GUI .
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

#ifndef GRAPHICTARGETPACK_H
#define GRAPHICTARGETPACK_H

#include "TargetPack.h"
#include "GraphicCard.h"

#include <QLabel>
/**
 * @brief The GraphicTargetPack class for target pack draw.
 */
class GraphicTargetPack : public QLabel
{
public:
    TargetPack *targetPack; /**< Initialized target packs. */

    GraphicTargetPack(QWidget *parent, TargetPack *targetPack, int x, int y, int index); /**< Constructor. */
    /**
     * @brief getX Gets x coordinate of target pack position.
     * @return x coordinate
     */
    int getX() {return x;}
    /**
     * @brief getY Gets y coordinate of target pack position.
     * @return y coordinate
     */
    int getY() {return y;}
    /**
     * @brief getIndex Gets index of target pack, specifies which target pack it is.
     * @return x coordinate
     */
    int getIndex() {return index;}

protected:
    int x;      /**< x coordinate of pack. */
    int y;      /**< y coordinate of pack. */
    int index;  /**< Index of pack. */

};

#endif // GRAPHICTARGETPACK_H
