#ifndef GAMES_H
#define GAMES_H

#include <iostream>
#include "Games.h"
//#include "Moves.h"
#include "Resource.h"
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

class Generation : public NamedAPIResource {
private:
    json parsedJson;
    Dictionary* dict;

    int id;
    std::string name;
    //Ability* abilities; // Pokemon.h
    std::vector<Name*> names;
    //Region* mainRegion; // Locations.h
    //Move* moves; // Moves.h
    //PokemonSpecies* pokemonSpecies; // Pokemon.h
    //Type* types; // Pokemon.h
    VersionGroup* verionGroups;

public:
    Generation(std::string name, std::string url);
    //Generation(const Generation& obj) // copy constructor
    ~Generation();

    int getId();
    std::string getName();
    Name getNames(int index);
};

class Pokedex : public NamedAPIResource {
private:
    json parsedJson;
    Dictionary* dict;

    int id;
    std::string name;
    bool mainSeries;
    //Description descriptions; // Utility.h
    std::vector<Name*> names;
    PokemonEntry* pokemonEntries;
    //Region* region;  // Locations.h
    VersionGroup* versionGroups;

public:
    Pokedex(std::string name, std::string url);
    //Pokedex(const Generation& obj) // copy constructor
    ~Pokedex();

    int getId();
    std::string getName();
    bool isMainSeries();

    Name getNames(int index);
};

class PokemonEntry {
private:
    int entryNumber;
   // PokemonSpecies* pokemoneSpecies; // Pokemon

public:
    PokemonEntry();
    ~PokemonEntry();
};

class Version : public NamedAPIResource {
private:
    json parsedJson;
    Dictionary* dict;

    int id;
    std::string name;
    std::vector<Name*> names;
    VersionGroup* versionGroup;

public:
    Version(std::string name, std::string url);
    //Version(const Generation& obj) // copy constructor
    ~Version();

    int getId();
    std::string getName();
    Name getNames(int index);
};

class VersionGroup : public NamedAPIResource {
private:
    json parsedJson;
    Dictionary* dict;

    int id;
    std::string name;
    int order;
    Generation* generation;
    //MoveLearnMethod* moveLearnMethods; // Moves.h
    Pokedex* pokedexes;
    Region* regions;
    Version* verions;

public:
    VersionGroup(std::string name, std::string url);
    //VersionGroup(const Generation& obj) // copy constructor
    ~VersionGroup();

    int getId();
    std::string getName();
    int getOrder();
};

#endif // GAMES_H
