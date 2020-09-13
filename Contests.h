#ifndef CONTESTS_H
#define CONTESTS_H

#include <iostream>
#include "Berries.h"
#include "Dictionary.h"
//#include "Moves.h"
#include "Resource.h"
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
    //BerryFlavor* berryFlavor;
    std::vector<ContestName*> names; // vector of ContestName names (which are the key for the dict)

    json parsedCT;
    Dictionary* dict;

public:
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

class ContestEffect : public NamedAPIResource {
private:
    int id;
    int appeal;
    int jam;
    std::vector<Effect*> effectEntries;
    std::vector<FlavorText*> flavorTextEntries;

    json parsedCE;
    Dictionary* dict;

public:
    ContestEffect(std::string name, std::string url);
    ~ContestEffect();

    int getId();
    int getAppeal();
    int getJam();
    Effect getEffect(int index);
    FlavorText getFlavorText(int index);
};

class SuperContestEffect : public NamedAPIResource {
private:
    int id;
    int appeal;
    std::vector<FlavorText*> flavorTextEntries;
    //std::vector<Move*> moves;

    json parsedSCE;
    Dictionary* dict;

public:
    SuperContestEffect(std::string name, std::string url);
    ~SuperContestEffect();

    int getId();
    int getAppeal();
    FlavorText getFlavorText(int index);
    //Move getMove(int index);
};

#endif // CONTESTS_H