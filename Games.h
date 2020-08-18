#ifndef GAMES_H
#define GAMES_H

#include <iostream>
#include "Games.h"
//#include "Moves.h"
#include "NamedAPIResource.h"
//#include "Pokemon.h"
#include "Utility.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// forward declarations
class Generation;
class Pokedex;
class PokemonEntry;
class Version;
class VersionGroup;

//class Ability;        // Pokemon.h
class Description;    // Utility.h
//class Move;           // Moves.h
class Name;           // Utility.h
//class PokemonSpecies; // Pokemon.h
class Region;         // Locations.h
//class Type;           // Pokemon.h

class Generation {
    int id;
    std::string name;
    //Ability* abilities; // Pokemon.h
    Name* names;
    Region* mainRegion; // Locations.h
    //Move* moves; // Moves.h
    //PokemonSpecies* pokemonSpecies; // Pokemon.h
    //Type* types; // Pokemon.h
    VersionGroup* verionGroups;

public:
    Generation();
    ~Generation();
};

class Pokedex {
private:
    int id;
    std::string name;
    bool isMainSeries;
    //Description descriptions; // Utility.h
    Name* names;
    PokemonEntry* pokemonEntries;
    //Region* region;  // Locations.h
    VersionGroup* versionGroups;

public:
    Pokedex();
    ~Pokedex();
};

class PokemonEntry {
private:
    int entryNumber;
   // PokemonSpecies* pokemoneSpecies; // Pokemon

public:
    PokemonEntry();
    ~PokemonEntry();
};

class Version {
private:
    int id;
    std::string name;
    Name* names;
    VersionGroup* versionGroup;

public:
    Version();
    ~Version();
};

class VersionGroup {
private:
    int id;
    std::string name;
    int order;
    Generation* generation;
    //MoveLearnMethod* moveLearnMethods; // Moves.h
    Pokedex* pokedexes;
    Region* regions;
    Version* verions;

public:
    VersionGroup();
    ~VersionGroup();
};

#endif // GAMES_H
