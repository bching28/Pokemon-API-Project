#ifndef CONTESTS_H
#define CONTESTS_H

#include <iostream>
#include "Berries.h"
#include "../Dictionary.h"
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
    json parsedJson;
    Dictionary* dict;

    int id;
    std::string name;
    std::vector<ContestName*> names;

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
    json parsedJson;
    Dictionary* dict;

    std::string name;
    std::string color;

public:
    ContestName(json contestNameJson);
    ~ContestName();

    std::string getName();
    std::string getColor();
    Language getLanguage();
};

class ContestEffect : public NamedAPIResource {
private:
    json parsedJson;
    Dictionary* dict;

    int id;
    int appeal;
    int jam;
    std::vector<Effect*> effectEntries;
    std::vector<FlavorText*> flavorTextEntries;

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
    json parsedJson;
    Dictionary* dict;

    int id;
    int appeal;
    std::vector<FlavorText*> flavorTextEntries;
    //std::vector<Move*> moves;

public:
    SuperContestEffect(std::string name, std::string url);
    ~SuperContestEffect();

    int getId();
    int getAppeal();
    FlavorText getFlavorText(int index);
    //Move getMove(int index);
};

#endif // CONTESTS_H