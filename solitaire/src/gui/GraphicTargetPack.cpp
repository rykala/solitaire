#include "GraphicTargetPack.h"
#include "Card.h"
#include "TargetPack.h"
#include "GraphicCard.h"

#include <QLabel>
#include <vector>
#include <QDropEvent>
#include <QMimeData>
#include <QDragEnterEvent>

using std::vector;

GraphicTargetPack::GraphicTargetPack(QWidget *parent, int x, int y) : QLabel(parent), TargetPack()
{
    this->x = x;
    this->y = y;

    this->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    this->setFixedSize(67, 100);
    this->move(this->x, this->y);
}
