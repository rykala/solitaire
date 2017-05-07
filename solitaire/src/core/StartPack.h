#ifndef STARTPACK_H
#define STARTPACK_H

#include "Card.h"
#include "Pack.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

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

private:
    friend class boost::serialization::access;
    template <typename Archive>
      void serialize(Archive &ar, const unsigned int version)
      {
        ar & boost::serialization::base_object<Pack>(*this);
        ar & cards;
        ar & top;
      }
};

#endif // STARTPACK_H
