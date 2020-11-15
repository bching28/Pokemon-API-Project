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
class EvolutionChain : public APIResource {
private:
    json parsedJson;
    Dictionary* dict;

    int id;
    //Item* babyTriggerItem;
    ChainLink* chain;

public:
    EvolutionChain(int id, std::string url);
    EvolutionChain(const EvolutionChain& obj);
    ~EvolutionChain();

    int getId();
    Item* getBabyTriggerItem();
    ChainLink* getChain();
};

class ChainLink {
private:
    json parsedJson;
    Dictionary* dict;

    bool isBaby;
    //PokemonSpecies species; // Pokemon.h
    std::vector<EvolutionDetail*> evolutionDetails;
    std::vector<ChainLink*> evolvesTo;

public:
    ChainLink(json chainLinkJson);
    ChainLink(const ChainLink& obj);
    ~ChainLink();

    bool getIsBaby();
    EvolutionDetail* getEvolutionDetails(int index);
    ChainLink* getEvolvesTo(int index);
};

class EvolutionDetail {
private:
    json parsedJson;
    Dictionary* dict;

    Item* item;
    //EvolutionTrigger* trigger;
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
    EvolutionDetail(json evolutionDetailJson);
    ~EvolutionDetail();

    Item* getItem();
    EvolutionTrigger* getTrigger();
    int getGender();
    Item* getHeldItem();
    //Move* getKnownMove();
    //Type* getKnownMoveType();
    //Location* getLocation();
    int getMinLevel();
    int getMinHappiness();
    int getMinBeauty();
    int getMinAffection();
    bool getNeedsOverworldRain();
    //PokemonSpecies* getPartySpecies();
    //Type* getPartyType();
    int getRelativePhysicalStats();
    std::string getTimeOfDay();
    //PokemonSpecies* getTradeSpecies();
    bool getTurnUpsideDown();

};

class EvolutionTrigger : public NamedAPIResource {
private:
    json parsedJson;
    Dictionary* dict;

    int id;
    std::string name;
    std::vector<Name*> names;
    //PokemonSpecies pokemonSpecies; // Pokemon.h

public:
    EvolutionTrigger(std::string name, std::string url);
    ~EvolutionTrigger();

    int getId();
    std::string getName();
    Name getNames(int index);
    //PokemonSpecies* getPokemonSpecies();
};

#endif // EVOLUTION_H