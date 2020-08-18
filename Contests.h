#ifndef CONTESTS_H
#define CONTESTS_H

#include <iostream>
#include "Berries.h"
//#include "Moves.h"
#include "NamedAPIResource.h"
#include "Utility.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// forward declarations
class ContestEffect;
class ContestName;
class ContestType;
class SuperContestEffect;

class BerryFlavor; // Berries.h
class Effect;      // Utility.h
class FlavorText;  // Utility.h
class Language;    // Utility.h
//class Move;        // Moves.h

class ContestType : public NamedAPIResource {
private:
    int id;
    std::string name;
    BerryFlavor* berryFlavor;
    ContestName* names;

public:
    ContestType(std::string contestTypeName);
    ~ContestType();

    int getId();
    std::string getName();
    BerryFlavor getBerryFlavor();
};

class ContestName {
private:
    std::string name;
    std::string color;
    Language* language;

public:
    ContestName();
    ~ContestName();
};

class ContestEffect {
private:
    int id;
    int appeal;
    int jam;
    Effect* effectEntries;
    FlavorText* flavorTextEntries;

public:
    ContestEffect();
    ~ContestEffect();
};

class SuperContestEffect {
private:
    int id;
    int appeal;
    FlavorText* flavorTextEntries;
    //Move moves; // Moves.h

public:
    SuperContestEffect();
    ~SuperContestEffect();
};

#endif // CONTESTS_H