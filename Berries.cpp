#include "Berries.h"

BerryFlavor::BerryFlavor(json berryFlavor) :
    id(berryFlavor["id"]),
    name(berryFlavor["name"]),
    contestType(NULL)
{
    //name = berryFlavor["names"];
    //url = berryFlavor["url"];
}

BerryFlavor::~BerryFlavor() {

}