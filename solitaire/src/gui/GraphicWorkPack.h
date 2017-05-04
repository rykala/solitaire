#ifndef GRAPHICWORKPACK_H
#define GRAPHICWORKPACK_H

#include "WorkPack.h"
#include "GraphicCard.h"

#include <QLabel>

class GraphicWorkPack : public QLabel
{
public:
    WorkPack *workPack;

    GraphicWorkPack(QWidget *parent, WorkPack *workPack, int x, int y);

    int getX() {return x;}
    int getY() {return y;}
protected:
    int x;
    int y;
};

#endif // GRAPHICWORKPACK_H
