#ifndef CONTESTS_H
#define CONTESTS_H

#include <iostream>
#include "Berries.h"
//#include "Moves.h"
#include "Resource.h"
#include "Dictionary.h"
#include "Utility.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// forward declarations
class Dictionary;
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
    std::vector<ContestName*> names; // vector of ContestName names (which are the key for the dict)

    json parsedCT;
    Dictionary* dict;

public:
    //ContestType(std::string contestTypeName, bool isFirstCall);
    ContestType(std::string name, std::string url);
    ~ContestType();

    int getId();
    std::string getName();
    BerryFlavor getBerryFlavor();
    ContestName getContestName(int index);
};

class ContestName {
private:
    std::string name;
    std::string color;
    Language* language;

    json parsedCN;
    Dictionary* dict;

public:
    ContestName(json contestNameJson);
    ~ContestName();

    std::string getName();
    std::string getColor();
    Language getLanguage();
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