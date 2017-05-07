#ifndef PACK_H
#define PACK_H

#include "Globals.h"
#include "Card.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <vector>

using std::vector;

class Pack {
public:
    vector<Card*> cards;
    Card *getCard(int index);
    int numOfCards();
    vector<Card*> getCards(int index = 0);

private:
    friend class boost::serialization::access;
      template <typename Archive>
      void serialize(Archive &ar, const unsigned int version) { ar & cards; }

};

#endif // PACK_H
