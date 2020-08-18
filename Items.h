#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include "Evolution.h"
#include "Games.h"
//#include "Pokemon.h"
#include "Utility.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// forward declarations
class Item;
class ItemAttribute;
class ItemCategory;
class ItemFlingEffect;
class ItemHolderPokemon;
class ItemHolderPokemonVersionDetail;
class ItemPocket;
class ItemSprites;

//class Description;            // Utility.h
class Effect;                 // Utility.h
class EvolutionChain;         // Evolution.h
//class GenerationGameIndex;    // Utility.h
//class MachineVersionDetail;   // Utility.h
class Name;                   // Utility.h
//class Pokemon;                // Pokemon.h
class Version;                // Games.h
//class VerboseEffect;          // Utility.h
//class VersionGroupFlavorText; // Utility.h

class Item : public NamedAPIResource {
private:
    int id;
    std::string name;
    int cost;
    int flingPower;
    ItemFlingEffect* flintEffect;
    ItemAttribute* attributes;
    ItemCategory* category;
    //VerboseEffect effectEntries; // Utility.h
    //VersionGroupFlavorText flavorTextEntries; // Utility.h
    //GenerationGameIndex gameIndices;  // Utility.h
    Name* names;
    ItemSprites* sprites;
    ItemHolderPokemon* heldByPokemon;
    EvolutionChain* babyTriggerFor;
    //MachineVersionDetail machines; // Utility.h

public:
    Item();
    ~Item();
};

class ItemSprites {
private:
    std::string default_;

public:
    ItemSprites();
    ~ItemSprites();
};

class ItemHolderPokemon {
private:
    //Pokemon* pokemon; // Pokemon.h
    ItemHolderPokemonVersionDetail* versionDetail;

public:
    ItemHolderPokemon();
    ~ItemHolderPokemon();
};

class ItemHolderPokemonVersionDetail {
private:
    int rarity;
    Version* version;

public:
    ItemHolderPokemonVersionDetail();
    ~ItemHolderPokemonVersionDetail();
};

class ItemAttribute {
private:
    int id;
    std::string name;
    Item* items;
    Name* names;
    //Description* descriptions; // Utility.h

public:
    ItemAttribute();
    ~ItemAttribute();
};

class ItemCategory {
private:
    int id;
    std::string name;
    Item* items;
    Name* names;
    ItemPocket* pocket;

public:
    ItemCategory();
    ~ItemCategory();
};

class ItemFlingEffect {
private:
    int id;
    std::string name;
    Effect* effectEntries;
    Item* items;

public:
    ItemFlingEffect();
    ~ItemFlingEffect();
};

class ItemPocket {
private:
    int id;
    std::string name;
    ItemCategory* categories;
    Name* names;

public:
    ItemPocket();
    ~ItemPocket();
};

#endif // ITEMS_H
