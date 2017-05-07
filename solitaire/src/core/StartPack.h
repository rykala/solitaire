#ifndef STARTPACK_H
#define STARTPACK_H

#include "Card.h"
#include "Pack.h"

class StartPack : public Pack
{
public:
    StartPack();
    StartPack(vector<Card *> cards, int top = -1);

    int flipCard();

    void decrementTop() {top--;}
    void incrementTop() {top++;}

    int getTopIndex() {return top;}
    void setTopIndex(int top) {this->top = top;}

protected:
    int top; // Inicializace na null, kdyz zadna karta neni prevracena
};

#endif // STARTPACK_H
