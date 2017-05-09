/**
 * @file GraphicStartPack.h
 * @class GraphicStartPack
 * @brief %rStart pack for GUI .
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

#ifndef GRAPHICSTARTPACK_H
#define GRAPHICSTARTPACK_H

#include "StartPack.h"

#include <QLabel>

/**
 * @brief The GraphicStartPack class for start pack draw.
 */
class GraphicStartPack : public QLabel
{    
public:
    StartPack *startPack; /**< Shuffeld start pack. */

    GraphicStartPack(QWidget *parent, StartPack *startPack);

    void flipCard(); //TODO potrebujeme?

protected:
    void generateCards(); //TODO potrebujeme?
};

#endif // GRAPHICSTARTPACK_H
