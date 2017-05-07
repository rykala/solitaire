#ifndef TARGETPACK_H
#define TARGETPACK_H

#include "Pack.h"
#include "Card.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

class TargetPack : public Pack
{
public:
    TargetPack();
    TargetPack(vector <Card*> cards);
    Card TakeCard();

    vector<Card> popCard();

private:
    int value = 1;

    friend class boost::serialization::access;
    template <typename Archive>
      void serialize(Archive &ar, const unsigned int version)
      {
        ar & boost::serialization::base_object<Pack>(*this);
      }

};

#endif // TARGETPACK_H
