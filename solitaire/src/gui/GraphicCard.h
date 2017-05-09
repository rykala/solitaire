/**
 * @file GraphicCard.h
 * @class GraphicCard
 * @brief %rGraphic card implementation for GUI.
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

#ifndef GRAPHICCARD_H
#define GRAPHICCARD_H

#include "Card.h"

#include <QLabel>

/**
 * @brief The GraphicCard class
 */
class GraphicCard : public QLabel
{
public:
    
    Card *card; /**< Pointer of logical card. */

    GraphicCard(QWidget *parent); /**< Constructor. */
    GraphicCard(QWidget *parent, Card *card);   /**< Constructor. */
    ~GraphicCard(); /**< Destructor. */
    
    /**
     * @brief drawCard Card graphic in GUI.
     * @param x Position.
     * @param y Position.
     */
    void drawCard(int x, int y);
    /**
     * @brief updateCard Redraw of card after movement.
     */
    void updateCard();
    /**
     * @brief getX Gets the position of card.
     * @return X position of card.
     */
    int getX() {return x;}
    /**
     * @brief getY Gets the position of card.
     * @return Y position of card.
     */
    int getY() {return y;}

private:
    int x;  /**< Position of card. */
    int y;  /**< Position of card. */
};

#endif // GRAPHICCARD_H
