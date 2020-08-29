#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <unordered_map>
#include "Berries.h"
#include "Contests.h"
#include "Utility.h"

class BerryFlavor;
class ContestType;
class Language;

//std::unordered_map< std::string, std::unordered_map<std::string, BerryFlavor> > berryFlavorDict;
class Dictionary {
private:
    Dictionary(); // private constructor for singleton
    static Dictionary* instance;

    std::unordered_map < std::string, BerryFlavor* > berryFlavorDict;
    std::unordered_map < std::string, ContestType* > contestTypeDict;
    std::unordered_map < std::string, Language* > LanguageDict;

public:
    ~Dictionary();
    static Dictionary* getInstance();

    bool hasFoundKey(std::string endPoint, std::string key);
    void setContestTypeDictEntry(std::string key, std::string ctUrl);
    ContestType getContestTypeDictEntry(std::string key);
    void setBerryFlavorDictEntry(std::string key, std::string bfUrl);
    BerryFlavor getBerryFlavorDictEntry(std::string key);
    void setLanguageDictEntry(std::string key, std::string lUrl);
    Language getLanguageDictEntry(std::string key);

    void printBerryFlavorMap();
    void printContestTypeMap();
};

#endif // DICTIONARY_H