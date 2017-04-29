#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "GraphicGameBoard.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    GraphicGameBoard *game1;
    GraphicGameBoard *game2;
    GraphicGameBoard *game3;
    GraphicGameBoard *game4;

private slots:
    void on_actionNew_Instance_triggered();
    void on_actionNew_game_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
