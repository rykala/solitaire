#include "GraphicTargetPack.h"
#include "TargetPack.h"

GraphicTargetPack::GraphicTargetPack(QWidget *parent, TargetPack *targetPack, int x, int y, int index) : QLabel(parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->targetPack = targetPack;
    this->x = x;
    this->y = y;
    this->index = index;

    this->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    this->setFixedSize(67, 100);
    this->move(this->x, this->y);
}
