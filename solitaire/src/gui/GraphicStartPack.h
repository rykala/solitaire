#ifndef GRAPHICSTARTPACK_H
#define GRAPHICSTARTPACK_H

#include <QLabel>
//#include <QGraphicsItem>

class GraphicStartPack : QLabel
{    
public:
    GraphicStartPack(QWidget *parent);

protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // GRAPHICSTARTPACK_H
