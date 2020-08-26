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
    BerryFlavorMap* flavors;
    Item* item;
    //Type* naturalGiftType; // Pokemon.h

public:
    Berry();
    ~Berry();
};

class BerryFlavorMap {
private:
    int potency;
    BerryFlavor* flavor;

public:
    BerryFlavorMap();
    ~BerryFlavorMap();
};

class BerryFirmness : public NamedAPIResource {
private:
    int id;
    std::string name;
    Berry* berries;
    Name* names;

public:
    BerryFirmness();
    ~BerryFirmness();
};

class BerryFlavor : public NamedAPIResource {
private:
    int id;
    std::string name;
    FlavorBerryMap* berries;
    ContestType* contestType;
    Name* names;

    json parsedBF;
    Dictionary* dict;

public:
    BerryFlavor(std::string berryFlavor, bool isFirstCall);
    BerryFlavor(std::string name, std::string url);
    BerryFlavor();
    ~BerryFlavor();

    int getId();
    std::string getName();
    ContestType getContestType();
};

class FlavorBerryMap {
private:
    int potency;
    Berry* berry;

public:
    FlavorBerryMap();
    ~FlavorBerryMap();
};

#endif // BERRIES_H