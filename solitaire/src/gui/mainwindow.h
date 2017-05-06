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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
