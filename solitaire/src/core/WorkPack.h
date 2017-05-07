#ifndef WORKPACK_H
#define WORKPACK_H

#include "Pack.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

class WorkPack: public Pack
{
public:
    WorkPack() {}
    WorkPack(vector<Card*> cards, int index);
    bool flipHidden();
    int getHiddenIndex() {return hiddenIndex;}
    void incrementHiddenIndex();

protected:
    int hiddenIndex;

private:
    friend class boost::serialization::access;
    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & boost::serialization::base_object<Pack>(*this);
        ar & hiddenIndex;
    }


};

#endif // WORKPACK_H
