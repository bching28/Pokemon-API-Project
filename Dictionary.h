#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <unordered_map>
#include "Berries.h"
#include "Contests.h"
#include "Items.h"
#include "Utility.h"

class Berry;
class BerryFirmness;
class BerryFlavor;
class ContestType;
class ContestEffect;
class EncounterCondition;
class EncounterConditionValue;
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
    std::unordered_map < std::string, ContestEffect* > contestEffectDict;
    std::unordered_map < std::string, EncounterCondition* > encounterConditionDict;
    std::unordered_map < std::string, EncounterConditionValue* > encounterConditionValueDict;
    std::unordered_map < std::string, Item* > itemDict;
    std::unordered_map < std::string, ItemFlingEffect* > itemFlingEffectDict;
    std::unordered_map < std::string, Language* > languageDict;

public:
    ~Dictionary();
    static Dictionary* getInstance();
    void terminate();

    bool hasFoundKey(std::string endPoint, std::string key);

    void setBerryDictEntry(std::string key, std::string bUrl);
    Berry getBerryDictEntry(std::string key);

    void setBerryFirmnessDictEntry(std::string key, std::string bUrl);
    BerryFirmness getBerryFirmnessDictEntry(std::string key);

    void setBerryFlavorDictEntry(std::string key, std::string bfUrl);
    BerryFlavor getBerryFlavorDictEntry(std::string key);

    void setContestTypeDictEntry(std::string key, std::string ctUrl);
    ContestType getContestTypeDictEntry(std::string key);

    void setContestEffectDictEntry(std::string key, std::string ceUrl);
    ContestEffect getContestEffectDictEntry(std::string key);

    void setEncounterConditionDictEntry(std::string key, std::string url);
    EncounterCondition getEncounterConditionDictEntry(std::string key);

    void setItemDictEntry(std::string key, std::string iUrl);
    Item getItemDictEntry(std::string key);

    void setItemFlingEffectDictEntry(std::string key, std::string iUrl);
    ItemFlingEffect getItemFlingEffectDictEntry(std::string key);

    void setLanguageDictEntry(std::string key, std::string lUrl);
    Language getLanguageDictEntry(std::string key);

    void printBerryFlavorMap();
    void printContestTypeMap();
};

#endif // DICTIONARY_H