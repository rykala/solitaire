#include <QApplication>
#include <iostream>
#include <ctime>

#include "mainwindow.h"


int main(int argc, char *argv[])
{
    srand(unsigned(std::time(0)));
    QApplication a(argc, argv);

//    QGraphicsScene *scene = new QGraphicsScene();
//    GraphicCard *black = new GraphicCard(":/cards/club_10");

//    GraphicDeck *deck = new GraphicDeck();

//    scene->addItem(deck);
//    scene->addItem(black);

//    QBrush darkBrown(QColor(152,251,152));
//    QGraphicsView *view = new QGraphicsView(scene);
//    view->setBackgroundBrush(darkBrown);
//    view->setStyleSheet( "QGraphicsView { border-style: none; }" );
//    view->showMaximized();

    MainWindow w;

    w.show();

    return a.exec();
}
