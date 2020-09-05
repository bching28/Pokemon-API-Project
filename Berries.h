#ifndef BERRIES_H
#define BERRIES_H

#include <iostream>
#include "Contests.h"
#include "Items.h"
#include "Resource.h"
#include "Dictionary.h"
//#include "Pokemon.h"
#include "Utility.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// forward declarations
class Dictionary;
class Berry;
class BerryFirmness;
class BerryFlavor;
class BerryFlavorMap;
class FlavorBerryMap;

class ContestType;     // Contests.h
class Item;            // Items.h
class Name;            // Utility.h
//class Type;            // Pokemon.h

//dict = new Dictionary();

class Berry : public NamedAPIResource {
private:
    int id;
    std::string name;
    int growthTime;
    int maxHarvest;
    int naturalGiftPower;
    int size;
    int smoothness;
    int soilDryness;
    BerryFirmness* firmness;
    std::vector<BerryFlavorMap*> flavors;
    Item* item;
    //Type* naturalGiftType; // Pokemon.h

    json parsedB;
    Dictionary* dict;

public:
    Berry(std::string name, std::string url);
    ~Berry();
    int getId();
    std::string getName();
    int getGrowthTime();
    int getMaxHarvest();
    int getNaturalGiftPower();
    int getSize();
    int getSmoothness();
    int getSoilDryness();
    BerryFirmness getFirmness();
    BerryFlavorMap getFlavors(int index);
    Item getItem();
};

class BerryFlavorMap {
private:
    int potency;
    BerryFlavor* flavor;

    json parsedBFM;
    Dictionary* dict;

public:
    BerryFlavorMap(json berryFlavorMapJson);
    ~BerryFlavorMap();

    int getPotency();
    BerryFlavor getFlavor();
};

class BerryFirmness : public NamedAPIResource {
private:
    json parsedBF;
    Dictionary* dict;

    int id;
    std::string name;
    std::vector<Berry*> berries;
    std::vector<Name*> names;

public:
    BerryFirmness(std::string name, std::string url);
    ~BerryFirmness();

    int getId();
    std::string getName();
    Berry getBerries(int index);
    Name getNames(int index);
};

class BerryFlavor : public NamedAPIResource {
private:
    int id;
    std::string name;
    std::vector<FlavorBerryMap*> berries;
    ContestType* contestType;
    std::vector<Name*> names;

    json parsedBF;
    Dictionary* dict;

public:
    //BerryFlavor(std::string berryFlavor, bool isFirstCall);
    BerryFlavor(std::string name, std::string url);
    ~BerryFlavor();

    int getId();
    std::string getName();
    FlavorBerryMap getBerries(int index);
    ContestType getContestType();
    Name getNames(int index);
};

class FlavorBerryMap {
private:
    int potency;
    Berry* berry;

    json parsedFBM;
    Dictionary* dict;

public:
    FlavorBerryMap(json flavorBerryMapJson);
    ~FlavorBerryMap();

    int getPotency();
    Berry getBerry();
};

#endif // BERRIES_H