#ifndef STARTPACK_H
#define STARTPACK_H

#include "Card.h"
#include "Pack.h"

class StartPack : public Pack
{
public:
    StartPack(vector<Card> cards);
    Card getTopCard(); // otoci kartu a vrati ji, zvyssi top

private:
    float top = -1; // Inicializace na null, kdyz zadna karta neni prevracena
};

#endif // STARTPACK_H
