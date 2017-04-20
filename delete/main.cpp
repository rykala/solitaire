#include "mainwindow.h"
#include <QApplication>
#include "Card.h"
#include "Deck.h"
#include "Globals.h"
#include <string>
#include <sstream>

int main(int argc, char *argv[])
{
    Deck deck;

    cout << "[]           _   _   _   _" << endl;
    cout << "[1] [2] [3] [4] [5] [6] [7]" << endl;
    int i = 3;

    Card card = deck.getCard();
    cout << to_string(32) << endl;

    return 0;
}
