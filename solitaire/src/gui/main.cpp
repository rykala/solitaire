/**
 * @file main.cpp
 * @brief %rSimple main for GUI .
 *
 * @author Krystof Rykala <xrykal00@stud.fit.vutbr.cz>
 * @author Martin Polakovic <xpolak33@stud.fit.vutbr.cz>
 * @date 08.05.2017
 */

#include <QApplication>
#include <iostream>
#include <ctime>

#include "mainwindow.h"


int main(int argc, char *argv[])
{
    srand(unsigned(std::time(0)));
    QApplication a(argc, argv);

    MainWindow w;

    w.show();

    return a.exec();
}
