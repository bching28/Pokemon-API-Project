#ifndef CONTESTS_H
#define CONTESTS_H

#include <iostream>
#include "NamedAPIResource.h"
#include "Berries.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// forward declarations
class BerryFlavor;
class PokeWrap;

class ContestName {
private:
    std::string name;
    std::string color;
    Language language;
public:
};

class ContestType : public NamedAPIResource{
private:
    int id;
    std::string name;
    BerryFlavor *berryFlavor;
    //ContestName names

    std::string retrieveHTTPResponse(std::string url);

public:
    ContestType(json parsedResp);
    ~ContestType();

    int getId();
    std::string getName();
    BerryFlavor getBerryFlavor();
};

class ContestEffect {
private:
    int id;
    int appeal;
    int jam;
    Effect effectEntries;
    FlavorText flavorTextEntries;

public:
};

class SuperContestEffect {
private:
    int id;
    int appeal;
    FlavorText flavorTextEntries;
    //Move moves;

public:
};

#endif; // CONTESTS_H