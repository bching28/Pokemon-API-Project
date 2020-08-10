#include "Berries.h"

BerryFlavor::BerryFlavor(json berryFlavor) :
    id(berryFlavor["id"]),
    name(to_string(berryFlavor["name"])),
    contestType(NULL)
{
    //name = berryFlavor["names"];
    //url = berryFlavor["url"];
    //std::cout << "BF Name: " << typeid((std::string)berryFlavor["name"]).name() << std::endl;
}

BerryFlavor::~BerryFlavor() {

}