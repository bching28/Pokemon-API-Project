#ifndef LOCATIONS_H
#define LOCATIONS_H

#include <iostream>
#include "Encounters.h"
#include "Games.h"
#include "Utility.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// forward declarations
class EncounterMethodRate;
class EncounterVersionDetails;
class Location;
class LocationArea;
class PalParkArea;
class PalParkEncounterSpecies;
class PokemonEncounter;
class Region;

class EncounterMethod;        // Encounters.h
class Generation;             // Games.h
class GenerationGameIndex;    // Utility.h
class Name;                   // Utility.h
class Pokedex;                // Games.h
class Version;                // Games.h
//class VersionEncounterDetail; // Utility.h
class VersionGroup;           // Games.h


class Location : public NamedAPIResource {
private:
    int id;
    std::string name;
    Region* region;
    Name* names;
    //GenerationGameIndex* gameIndices; // Utility.h
    LocationArea* areas;

public:
    Location();
    ~Location();
};

class LocationArea {
private:
    int id;
    std::string name;
    int gameIndex;
    EncounterMethodRate* encounterMethodRates;
    Location* location;
    Name* names;
    PokemonEncounter* pokemonEncounters;

public:
    LocationArea();
    ~LocationArea();
};

class EncounterMethodRate {
private:
    EncounterMethod* encounterMethod;
    EncounterVersionDetails* versionDetails;

public:
    EncounterMethodRate();
    ~EncounterMethodRate();
};

class EncounterVersionDetails {
private:
    int rate;
    Version* version;

public:
    EncounterVersionDetails();
    ~EncounterVersionDetails();
};

class PokemonEncounter {
private:
    //Pokemon* pokemon; // Pokemon.h
    //VersionEncounterDetail versionDetails; // Utility.h

public:
    PokemonEncounter();
    ~PokemonEncounter();
};

class PalParkArea {
private:
    int id;
    std::string name;
    Name* names;
    PalParkEncounterSpecies* pokemonEncounters;

public:
    PalParkArea();
    ~PalParkArea();
};

class PalParkEncounterSpecies {
private:
    int baseScore;
    int rate;
    //PokemonSpecies* pokemonSpecies; // Pokemon.h

public:
    PalParkEncounterSpecies();
    ~PalParkEncounterSpecies();
};

class Region : public NamedAPIResource {
private:
    int id;
    Location* locations;
    std::string name;
    Name* names;
    Generation* mainGeneration;
    Pokedex* pokedexes;
    VersionGroup* versionGroups;

public:
    Region();
    ~Region();
};

#endif // LOCATIONS_H

