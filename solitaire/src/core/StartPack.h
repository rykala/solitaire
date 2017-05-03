#ifndef STARTPACK_H
#define STARTPACK_H

#include "Card.h"
#include "Pack.h"

class StartPack : public Pack
{
public:
    StartPack();
    StartPack(vector<Card> cards);
    bool getTopCard(Card &topCard); // otoci kartu a vrati ji, zvyssi top
    int flipCard();
    int getTopIndex();
    void decrementTop();

protected:
    int top = -1; // Inicializace na null, kdyz zadna karta neni prevracena
};

#endif // STARTPACK_H
