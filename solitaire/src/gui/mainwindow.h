/**
 * @file mainwindow.h
 * @class mainwindow
 * @brief %rcreates main window for GUI .
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

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
class MainWindow; //TODO preco 2 krat
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    GraphicGameBoard *game1 = NULL; /**< Creates pointer for specific game1. */
    GraphicGameBoard *game2 = NULL; /**< Creates pointer for specific game2. */
    GraphicGameBoard *game3 = NULL; /**< Creates pointer for specific game3. */
    GraphicGameBoard *game4 = NULL; /**< Creates pointer for specific game4. */

protected:
    /**
     * @brief anotherGame creates place for new game in tabulae.
     */
    void anotherGame();
    /**
     * @brief closeCheck checks if it is only one game played and if it is changes tabulae only for one game.
     */
    void closeCheck();
private slots:
    /**
     * @brief on_actionGame1_triggered Action after game 1 button is clicked.
     */
    void on_actionGame1_triggered();
    /**
     * @brief on_actionGame2_triggered Action after game 2 button is clicked.
     */
    void on_actionGame2_triggered();
    /**
     * @brief on_actionGame3_triggered Action after game 3 button is clicked.
     */
    void on_actionGame3_triggered();
    /**
     * @brief on_actionGame4_triggered Action after game 4 button is clicked.
     */
    void on_actionGame4_triggered();
    /**
     * @brief on_actionClose1_triggered Action after close 1 button is clicked.
     */
    void on_actionClose1_triggered();
    /**
     * @brief on_actionClose2_triggered
     */
    void on_actionClose2_triggered();
    /**
     * @brief on_actionClose3_triggered
     */
    void on_actionClose3_triggered();
    /**
     * @brief on_actionClose4_triggered
     */
    void on_actionClose4_triggered();
    /**
     * @brief on_actionUndo1_triggered
     */
    void on_actionUndo1_triggered();
    /**
     * @brief on_actionHint1_triggered
     */
    void on_actionHint1_triggered();
    /**
     * @brief on_actionUndo2_triggered
     */
    void on_actionUndo2_triggered();
    /**
     * @brief on_actionUndo3_triggered
     */
    void on_actionUndo3_triggered();
    /**
     * @brief on_actionUndo4_triggered
     */
    void on_actionUndo4_triggered();
    /**
     * @brief on_actionHint2_triggered
     */
    void on_actionHint2_triggered();
    /**
     * @brief on_actionHint3_triggered
     */
    void on_actionHint3_triggered();
    /**
     * @brief on_actionHint4_triggered
     */
    void on_actionHint4_triggered();
    /**
     * @brief on_actionSave_Game1_triggered
     */
    void on_actionSave_Game1_triggered();
    /**
     * @brief on_actionLoad_game1_triggered
     */
    void on_actionLoad_game1_triggered();
    /**
     * @brief on_actionLoad_game2_triggered
     */
    void on_actionLoad_game2_triggered();
    /**
     * @brief on_actionLoad_game3_triggered
     */
    void on_actionLoad_game3_triggered();
    /**
     * @brief on_actionLoad_game4_triggered
     */
    void on_actionLoad_game4_triggered();
    /**
     * @brief on_actionSave_Game2_triggered
     */
    void on_actionSave_Game2_triggered();
    /**
     * @brief on_actionSave_Game3_triggered
     */
    void on_actionSave_Game3_triggered();
    /**
     * @brief on_actionSave_Game4_triggered
     */
    void on_actionSave_Game4_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
