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
