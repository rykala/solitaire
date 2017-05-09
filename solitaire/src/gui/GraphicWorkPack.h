/**
 * @file GraphicWorkPack.h
 * @class GraphicWorkPack
 * @brief %rWork pack for GUI .
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

#ifndef GRAPHICWORKPACK_H
#define GRAPHICWORKPACK_H

#include "WorkPack.h"
#include "GraphicCard.h"

#include <QLabel>

/**
 * @brief The GraphicWorkPack class for work pack draw.
 */
class GraphicWorkPack : public QLabel
{
public:
    WorkPack *workPack; /**< Initialized target packs. */

    GraphicWorkPack(QWidget *parent, WorkPack *workPack, int x, int y, int index);  /**< Constructor. */

    /**
     * @brief getX Gets x coordinate of work pack position.
     * @return x coordinate
     */
    int getX() {return x;}
    /**
     * @brief getY Gets y coordinate of work pack position.
     * @return y coordinate
     */
    int getY() {return y;}
    /**
     * @brief getIndex Gets index of work pack, specifies which work pack it is.
     * @return x coordinate
     */
    int getIndex() {return index;}

protected:
    int x;      /**< x coordinate of pack. */
    int y;      /**< y coordinate of pack. */
    int index;  /**< Index of pack. */
};

#endif // GRAPHICWORKPACK_H
