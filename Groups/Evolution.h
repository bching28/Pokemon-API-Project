#ifndef EVOLUTION_H
#define EVOLUTION_H

#include <iostream>
#include "Items.h"
#include "Locations.h"
#include "Resource.h"
//#include "Pokemon.h"
#include "Utility.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// forward declarations
class ChainLink;
class EvolutionChain;
class EvolutionDetail;
class EvolutionTrigger;

class Item;           // Items.h
class Location;       // Locations.h
class Name;           // Utility.h
//class PokemonSpecies; // Pokemon.h

// TODO::Need to inherit APIResource
class EvolutionChain {
private:
    int id;
    Item* babyTriggerItem;
    ChainLink* chain;

public:
    EvolutionChain();
    ~EvolutionChain();
};

class ChainLink {
private:
    bool isBaby;
    //PokemonSpecies species; // Pokemon.h
    EvolutionDetail* evolutionDetails;
    ChainLink* evolvesTo;

public:
    ChainLink();
    ~ChainLink();
};

class EvolutionDetail {
private:
    Item* item;
    EvolutionTrigger* trigger;
    int gender;
    Item* heldItem;
    //Move knownMove; // Moves.h
    //Type knownMoveType; // Pokemon.h
    //Location location;
    int minLevel;
    int minHappiness;
    int minBeauty;
    int minAffection;
    bool needsOverworldRain;
    //PokemonSpecies partySpecies; // Pokemon.g
    //Type partyType; // Pokemon.h
    int relativePhysicalStats;
    std::string timeOfDay;
    //PokemonSpecies tradeSpecies; // Pokemon.h
    bool turnUpsideDown;

public:
    EvolutionDetail();
    ~EvolutionDetail();
};

class EvolutionTrigger : public NamedAPIResource {
    int id;
    std::string name;
    Name* names;
    //PokemonSpecies pokemonSpecies; // Pokemon.h

public:
    EvolutionTrigger();
    ~EvolutionTrigger();
};

#endif // EVOLUTION_H