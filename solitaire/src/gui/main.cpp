#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QSvgRenderer>
#include <QGraphicsSvgItem>
#include <QtSvg>
#include <QRectF>
#include "GraphicCard.h"
#include "GraphicDeck.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene();
    GraphicCard *black = new GraphicCard(":/cards/club_10");

    GraphicDeck *deck = new GraphicDeck();

    scene->addItem(deck);
    scene->addItem(black);

    QBrush darkBrown(QColor(152,251,152));
    QGraphicsView *view = new QGraphicsView(scene);
    view->setBackgroundBrush(darkBrown);
    view->setStyleSheet( "QGraphicsView { border-style: none; }" );
    view->showMaximized();

    return a.exec();
}
