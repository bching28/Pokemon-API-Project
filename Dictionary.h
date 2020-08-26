#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <unordered_map>
#include "Berries.h"
#include "Contests.h"

class BerryFlavor;
class ContestType;

//std::unordered_map< std::string, std::unordered_map<std::string, BerryFlavor> > berryFlavorDict;
class Dictionary {
private:
    Dictionary(); // private constructor for singleton
    static Dictionary* instance;

    std::unordered_map < std::string, BerryFlavor* > berryFlavorDict;
    std::unordered_map < std::string, ContestType* > contestTypeDict;

public:
    ~Dictionary();
    static Dictionary* getInstance();

    bool hasFoundKey(std::string endPoint, std::string key);
    void setContestTypeDictEntry(ContestType* ct, std::string key);
    ContestType getContestTypeDictEntry(std::string key);
    void setBerryFlavorDictEntry(std::string key, std::string bfUrl);
    BerryFlavor getBerryFlavorDictEntry(std::string key);
};

#endif // DICTIONARY_H