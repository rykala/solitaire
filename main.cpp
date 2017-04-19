#include "mainwindow.h"
#include <QApplication>
#include "Card.h"
#include "Deck.h"
#include "Globals.h"

int main(int argc, char *argv[])
{
    Deck deck;

    cout << "[]           _   _   _   _" << endl;
    cout << "[1] [2] [3] [4] [5] [6] [7]" << endl;


    Card card = deck.getCard();
    cout << print(card) << endl;

    return 0;
}
