#ifndef GRAPHICSTARTPACK_H
#define GRAPHICSTARTPACK_H

#include "StartPack.h"

#include <QLabel>

class GraphicStartPack : public QLabel
{    
public:
    StartPack *startPack;

    GraphicStartPack(QWidget *parent, StartPack *startPack);

    void flipCard();

protected:
    void generateCards();
};

#endif // GRAPHICSTARTPACK_H
