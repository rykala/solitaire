#include <QtWidgets>
#include <QMouseEvent>
#include <QMimeData>
#include <QDebug>
#include <QPixmap>

#include "GraphicGameBoard.h"
#include "GraphicCard.h"
#include "GraphicStartPack.h"

GraphicGameBoard::GraphicGameBoard(QWidget *parent) : QFrame(parent)
{
    this->game = new Game();
    setAcceptDrops(true);
}

void GraphicGameBoard::drawGameBoard()
{
    // Vykreslit: stack -> getTopCard(), getTopCard() - 1;
    // TargetPacks: null => [], !null => getTopCard()....private int value; value+1, CardType
    // WorkPacks vector hidden, work...hidenn 3x drawBackCard(), [[[], for(work) [ [ [], WorkPack isWin() 4x Packy full == WIN;
    drawStartPack();
    drawWorkPacks();
    drawTargetPacks();
    this->show();


    Card *card = new Card(10,CardType::Heart);
    GraphicCard *gc = new GraphicCard(card, this);
    gc->drawCard(100, 150);

}

void GraphicGameBoard::drawStartPack()
{
    GraphicStartPack *sp = new GraphicStartPack(this);

    QLabel *test = new QLabel(this);
    test->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    test->setFixedSize(67, 100);
    test->move(110, 5);
}

void GraphicGameBoard::drawWorkPacks()
{
    QLabel *test = new QLabel(this);
    test->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    test->setFixedSize(67, 100);
    test->move(290, 5);

    QLabel *test2 = new QLabel(this);
    test2->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    test2->setFixedSize(67, 100);
    test2->move(380, 5);

    QLabel *test3 = new QLabel(this);
    test3->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    test3->setFixedSize(67, 100);
    test3->move(470, 5);

    QLabel *test4 = new QLabel(this);
    test4->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    test4->setFixedSize(67, 100);
    test4->move(560, 5);
}

void GraphicGameBoard::drawTargetPacks()
{
    QLabel *test = new QLabel(this);
    test->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    test->setFixedSize(67, 100);
    test->move(20, 130);

    QLabel *test2 = new QLabel(this);
    test2->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    test2->setFixedSize(67, 100);
    test2->move(110, 130);

    QLabel *test3 = new QLabel(this);
    test3->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    test3->setFixedSize(67, 100);
    test3->move(200, 130);

    QLabel *test4 = new QLabel(this);
    test4->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    test4->setFixedSize(67, 100);
    test4->move(290, 130);

    QLabel *test5 = new QLabel(this);
    test5->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    test5->setFixedSize(67, 100);
    test5->move(380, 130);

    QLabel *test6 = new QLabel(this);
    test6->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    test6->setFixedSize(67, 100);
    test6->move(470, 130);

    QLabel *test7 = new QLabel(this);
    test7->setStyleSheet("border-radius: 3px; border: 1.5px solid green");
    test7->setFixedSize(67, 100);
    test7->move(560, 130);
}
