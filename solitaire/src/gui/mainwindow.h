#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "GraphicGameBoard.h"

#include <QMainWindow>

#include <boost/archive/tmpdir.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    GraphicGameBoard *game1 = NULL;
    GraphicGameBoard *game2 = NULL;
    GraphicGameBoard *game3 = NULL;
    GraphicGameBoard *game4 = NULL;

protected:
    void anotherGame();
    void closeCheck();
private slots:
    void on_actionGame1_triggered();
    void on_actionGame2_triggered();
    void on_actionGame3_triggered();
    void on_actionGame4_triggered();
    void on_actionClose1_triggered();
    void on_actionClose2_triggered();
    void on_actionClose3_triggered();
    void on_actionClose4_triggered();

    void on_actionUndo1_triggered();

    void on_actionHint1_triggered();

    void on_actionUndo2_triggered();

    void on_actionUndo3_triggered();

    void on_actionUndo4_triggered();

    void on_actionHint2_triggered();

    void on_actionHint3_triggered();

    void on_actionHint4_triggered();

    void on_actionSave_Game1_triggered();

    void on_actionLoad_game1_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
