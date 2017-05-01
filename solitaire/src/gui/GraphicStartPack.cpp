#include "GraphicStartPack.h"

#include <sstream>
#include <QLabel>
#include <QWidget>
#include <QDebug>
#include <QMouseEvent>


GraphicStartPack::GraphicStartPack(QWidget *parent) : QLabel(parent)
{
    setPixmap(QPixmap(":/back/2").scaled(100, 100, Qt::KeepAspectRatio));
    this->setStyleSheet("border: 0;");
    this->move(20, 5);
    this->show();
}

void GraphicStartPack::mousePressEvent(QMouseEvent *event)
{
//    GraphicCard *child = dynamic_cast<GraphicCard*>(childAt(event->pos()));
//    if (!child) {
//        qDebug() << "error";
//        return;
//    }
    event->accept();
    qDebug() << "Klik na deck";
}
