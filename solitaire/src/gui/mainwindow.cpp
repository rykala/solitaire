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

    this->menuBar()->setStyleSheet("QMenuBar {background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 lightgray, stop:1 darkgray);}"
                                   "QMenuBar::item {spacing: 15px; padding: 5px 10px;background: transparent;border-radius: 4px;}"
                                   "QMenuBar::item:selected { background: #a8a8a8;}"
                                   "QMenuBar::item:pressed {background: #888888;}");
    this->setStyleSheet("background-color: #4DBD33;");
    this->setFixedSize(650,450);

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



void MainWindow::on_actionGame1_triggered()
{
//    on_actionClose1_triggered();

    game1 = new GraphicGameBoard(ui->centralWidget);
    game1->setObjectName(QStringLiteral("game1"));

    if(game2 || game3 || game4) {
        game1->setGeometry(QRect(0, 0, this->width()*0.5, this->height()*0.5));
    } else {
        game1->setGeometry(QRect(0, 0, this->width(), this->height()));
    }

    game1->drawGameBoard();
}

void MainWindow::on_actionGame2_triggered()
{
    anotherGame();
//    on_actionClose2_triggered();

    game2 = new GraphicGameBoard(ui->centralWidget);
    game2->setObjectName(QStringLiteral("game2"));
    game2->setGeometry(QRect(this->width()*0.5, 0, this->width()*0.5, this->height()*0.5));
    game2->setStyleSheet("border: 0px solid green; border-top: 0; border-right: 0;");
    game2->drawGameBoard();
}

void MainWindow::on_actionGame3_triggered()
{
    anotherGame();
//    on_actionClose3_triggered();

    game3 = new GraphicGameBoard(ui->centralWidget);
    game3->setObjectName(QStringLiteral("game3"));
    game3->setGeometry(QRect(0, this->height()*0.5, this->width()*0.5, this->height()*0.5));
    game3->setStyleSheet("border: 0px solid green; border-top: 0; border-right: 0;");
    game3->drawGameBoard();
}

void MainWindow::on_actionGame4_triggered()
{
    anotherGame();
//    on_actionClose4_triggered();

    game4 = new GraphicGameBoard(ui->centralWidget);
    game4->setObjectName(QStringLiteral("game4"));
    game4->setGeometry(QRect(this->width()*0.5, this->height()*0.5, this->width()*0.5, this->height()*0.5));
    game4->setStyleSheet("border-left: 0px solid green; border-top: 0; border-right: 0;");
    game4->drawGameBoard();
}

void MainWindow::anotherGame()
{
    this->setFixedSize(1300,900);
    if(game1){
        game1->setGeometry(QRect(0, 0, this->width()*0.5, this->height()*0.5));
        game1->setStyleSheet("border: 0px solid green; border-top: 0; border-left: 0; border-right: 0");
    }
}

void MainWindow::on_actionClose1_triggered()
{
    if(game1){
        game1->close();
        game1 = NULL;
        closeCheck();
    }
}

void MainWindow::on_actionClose2_triggered()
{
    if(game2){
        game2->close();
        game2 = NULL;
        closeCheck();
    }
}

void MainWindow::on_actionClose3_triggered()
{
    if(game3){
        game3->close();
        game3 = NULL;
        closeCheck();
    }
}

void MainWindow::on_actionClose4_triggered()
{
    if(game4){
        game4->close();
        game4 = NULL;
        closeCheck();
    }
}

void MainWindow::closeCheck()
{
    if(game1 && !game2 && !game3 && !game4){
        this->setFixedSize(650,350);
        game1->setGeometry(QRect(0, 0, this->width(), this->height()));
    } else if (!game1 && game2 && !game3 && !game4) {
        game1 = game2;

        if(game2){
            game2 = NULL;
        }

        game1->setObjectName(QStringLiteral("game1"));
        game1->setStyleSheet("border: 0;");
        this->setFixedSize(650,350);
        game1->setGeometry(QRect(0, 0, this->width(), this->height()));
    } else if (!game1 && !game2 && game3 && !game4) {
        game1 = game3;

        if(game3){
            game3 = NULL;
        }

        game1->setObjectName(QStringLiteral("game1"));
        game1->setStyleSheet("border: 0;");
        this->setFixedSize(650,350);
        game1->setGeometry(QRect(0, 0, this->width(), this->height()));
    } else if(!game1 && !game2 && !game3 && game4) {
        game1 = game4;

        if(game4){
            game4 = NULL;
        }

        game1->setObjectName(QStringLiteral("game1"));
        game1->setStyleSheet("border: 0;");
        this->setFixedSize(650,350);
        game1->setGeometry(QRect(0, 0, this->width(), this->height()));
    }
}


void MainWindow::on_actionUndo1_triggered()
{
    if(game1) {
        game1->undoTurn();
    }
}

void MainWindow::on_actionUndo2_triggered()
{
    if(game2) {
        game2->undoTurn();
    }
}

void MainWindow::on_actionUndo3_triggered()
{
    if(game3) {
        game3->undoTurn();
    }
}

void MainWindow::on_actionUndo4_triggered()
{
    if(game4) {
        game4->undoTurn();
    }
}

void MainWindow::on_actionHint1_triggered()
{
    if(game1){
        game1->hint();
    }
}

void MainWindow::on_actionHint2_triggered()
{
    if(game2) {
        game2->hint();
    }
}

void MainWindow::on_actionHint3_triggered()
{
    if(game3) {
        game3->hint();
    }
}

void MainWindow::on_actionHint4_triggered()
{
    if(game4) {
        game4->hint();
    }
}

void MainWindow::on_actionSave_Game1_triggered()
{
    game1->saveGame();
}

void MainWindow::on_actionLoad_game1_triggered()
{
    game1->loadGame();
}
