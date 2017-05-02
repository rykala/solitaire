#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QWidget>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GraphicGameBoard.h"
#include "GraphicCard.h"
#include "Card.h"
#include "Globals.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusBar()->hide();

    this->setStyleSheet("background-color: #4DBD33;");
    ui->mainToolBar->setStyleSheet("QToolButton:!hover {background-color:30, 30,30; color:white}"
                                   "QToolButton:hover {text-decoration: underline; border: 0px; background: none;}"
                                   "QToolBar {background: rgb(30, 30, 30)}"
                                   );
    this->setFixedSize(650,350);

    game1 = new GraphicGameBoard(ui->centralWidget);
    game1->setObjectName(QStringLiteral("game1"));
    game1->setGeometry(QRect(0, 0, this->width(), this->height()));
    game1->setStyleSheet("border: 0;");
    game1->drawGameBoard();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_Instance_triggered()
{
    this->setFixedSize(1300,700);
    game1->setGeometry(QRect(0, 0, this->width()*0.5, this->height()*0.5));
    game1->setStyleSheet("border: 1px solid green; border-top: 0; border-left: 0; border-right: 0");

    game2 = new GraphicGameBoard(ui->centralWidget);
    game2->setObjectName(QStringLiteral("game2"));
    game2->setGeometry(QRect(this->width()*0.5, 0, this->width()*0.5, this->height()*0.5));
    game2->setStyleSheet("border: 1px solid green; border-top: 0; border-right: 0;");
    game2->drawGameBoard();

    game3 = new GraphicGameBoard(ui->centralWidget);
    game3->setObjectName(QStringLiteral("game3"));
    game3->setGeometry(QRect(0, this->height()*0.5, this->width()*0.5, this->height()*0.5));
    game3->setStyleSheet("border: 0px solid green; border-top: 0; border-right: 0;");
    game3->drawGameBoard();

    game4 = new GraphicGameBoard(ui->centralWidget);
    game4->setObjectName(QStringLiteral("game4"));
    game4->setGeometry(QRect(this->width()*0.5, this->height()*0.5, this->width()*0.5, this->height()*0.5));
    game4->setStyleSheet("border-left: 1px solid green; border-top: 0; border-right: 0;");
    game4->drawGameBoard();
}

void MainWindow::on_actionNew_Game_triggered()
{
    game1 = new GraphicGameBoard(ui->centralWidget);

    if(game2 || game3 || game4) {
            game1->setGeometry(QRect(0, 0, this->width()*0.5, this->height()*0.5));
    } else {
            game1->setGeometry(QRect(0, 0, this->width(), this->height()));
    }

    game1->drawGameBoard();
}
