#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <unordered_map>
#include "Groups/Berries.h"
#include "Groups/Contests.h"
#include "Groups/Items.h"
#include "Groups/Utility.h"

class Berry;
class BerryFirmness;
class BerryFlavor;
class ContestType;
class ContestEffect;
class SuperContestEffect;
class EncounterCondition;
class EncounterConditionValue;
class EvolutionChain;
class EvolutionTrigger;
class Generation;
class Pokedex;
class Version;
class VersionGroup;
class Item;
class ItemFlingEffect;
class Language;

class Dictionary {
private:
    Dictionary(); // private constructor for singleton
    static Dictionary* instance;

    std::unordered_map < std::string, Berry* > berryDict;
    std::unordered_map < std::string, BerryFirmness* > berryFirmnessDict;
    std::unordered_map < std::string, BerryFlavor* > berryFlavorDict;
    std::unordered_map < std::string, ContestType* > contestTypeDict;
    std::unordered_map < int, ContestEffect* > contestEffectDict;
    std::unordered_map < std::string, SuperContestEffect* > superContestEffectDict;
    std::unordered_map < std::string, EncounterCondition* > encounterConditionDict;
    std::unordered_map < std::string, EncounterConditionValue* > encounterConditionValueDict;
    std::unordered_map < int, EvolutionChain* > evolutionChainDict;
    std::unordered_map < std::string, EvolutionTrigger* > evolutionTriggerDict;
    std::unordered_map < std::string, Generation* > generationDict;
    std::unordered_map < std::string, Pokedex* > pokedexDict;
    std::unordered_map < std::string, Version* > versionDict;
    std::unordered_map < std::string, VersionGroup* > versionGroupDict;
    std::unordered_map < std::string, Item* > itemDict;
    std::unordered_map < std::string, ItemFlingEffect* > itemFlingEffectDict;
    std::unordered_map < std::string, Language* > languageDict;
    

public:
    ~Dictionary();
    static Dictionary* getInstance();
    void terminate();

    bool hasFoundKey(std::string endPoint, std::string key);
    bool hasFoundKey(std::string endPoint, int key);

    void setBerryDictEntry(std::string key, std::string url);
    Berry getBerryDictEntry(std::string key);

    void setBerryFirmnessDictEntry(std::string key, std::string url);
    BerryFirmness getBerryFirmnessDictEntry(std::string key);

    void setBerryFlavorDictEntry(std::string key, std::string url);
    BerryFlavor getBerryFlavorDictEntry(std::string key);

    void setContestTypeDictEntry(std::string key, std::string url);
    ContestType getContestTypeDictEntry(std::string key);

    void setContestEffectDictEntry(int key, std::string url);
    ContestEffect getContestEffectDictEntry(int key);

    void setSuperContestEffectDictEntry(std::string key, std::string url);
    SuperContestEffect getSuperContestEffectDictEntry(std::string key);

    void setEncounterConditionDictEntry(std::string key, std::string url);
    EncounterCondition getEncounterConditionDictEntry(std::string key);

    void setEvolutionChainDictEntry(int key, std::string url);
    EvolutionChain* getEvolutionChainDictEntry(int key);

    void setEvolutionTriggerDictEntry(std::string key, std::string url);
    EvolutionTrigger* getEvolutionTriggerDictEntry(std::string key);

    // Games (group)
    // ---------------------------------------------------------------------

    void setGenerationDictEntry(std::string key, std::string url);
    Generation* getGenerationDictEntry(std::string key);

    void setPokedexDictEntry(std::string key, std::string url);
    Pokedex* getPokedexDictEntry(std::string key);

    void setVersionDictEntry(std::string key, std::string url);
    Version* getVersionDictEntry(std::string key);

    void setVersionGroupDictEntry(std::string key, std::string url);
    VersionGroup* getVersionGroupDictEntry(std::string key);

    // Items (group)
    // ---------------------------------------------------------------------

    void setItemDictEntry(std::string key, std::string url);
    Item* getItemDictEntry(std::string key);

    void setItemFlingEffectDictEntry(std::string key, std::string url);
    ItemFlingEffect* getItemFlingEffectDictEntry(std::string key);

    void setLanguageDictEntry(std::string key, std::string url);
    Language getLanguageDictEntry(std::string key);

    void printBerryFlavorMap();
    void printContestTypeMap();
};

#endif // DICTIONARY_H