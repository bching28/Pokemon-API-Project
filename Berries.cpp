#include "Berries.h"

BerryFlavor::BerryFlavor(json berryFlavor) :
    id(berryFlavor["id"]),
    name(to_string(berryFlavor["name"])),
    contestType(NULL)
{
    //name = berryFlavor["names"];
    //url = berryFlavor["url"];
    std::cout << "BF ID: " << id << std::endl;
    std::cout << "BF Name: " << name << std::endl;
}

BerryFlavor::~BerryFlavor() {

}

int BerryFlavor::getId() {
    return id;
}