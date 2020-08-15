#ifndef BERRIES_H
#define BERRIES_H

#include <iostream>
#include "NamedAPIResource.h"
#include "Utilies.h"
#include "Contests.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// forward declarations
class BerryFirmness;
class ContestType;

class Berry {
private:
    int id;
    std::string name;
    int growthTime;
    int maxHarvest;
    int naturalGiftPower;
    int size;
    int smoothness;
    int soilDryness;
    BerryFirmness *firmness;
    //BerryFlavorsList flavors;
    //Item item;
    //Type naturalGiftTyoe;

public:

};

class BerryFirmness {
private:
    int id;
    std::string name;
    Berry *berries;
    Name names;

public:
};

class BerryFlavor : public NamedAPIResource {
private:
    int id;
    std::string name;
    //FlavorBerryMap berries;
    ContestType* contestType;
    //Name names;

public:
    BerryFlavor(json berryFlavor);
    ~BerryFlavor();

    int getId();
    std::string getName();
};

#endif // BERRIES_H