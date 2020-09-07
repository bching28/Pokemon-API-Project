#include "Dictionary.h"

Dictionary* Dictionary::instance = 0;

Dictionary::Dictionary() {

}

Dictionary::~Dictionary() {

}

Dictionary* Dictionary::getInstance() {
    if (!instance) {
        instance = new Dictionary;
    }
    
    return instance;
}

bool Dictionary::hasFoundKey(std::string endPoint, std::string key) {
    if (endPoint == "berry") {
        if (berryDict.find(key) == berryDict.end()) {
            return false;
        }
    }  
    else if (endPoint == "berry-firmness") {
        if (berryFirmnessDict.find(key) == berryFirmnessDict.end()) {
            return false;
        }
    }
    else if (endPoint == "berry-flavor") {
        if (berryFlavorDict.find(key) == berryFlavorDict.end()) {
            return false;
        }
    }
    else if (endPoint == "contest-type") {
        if (contestTypeDict.find(key) == contestTypeDict.end()) {
            return false;
        }
    }
    else if (endPoint == "language") {
        if (languageDict.find(key) == languageDict.end()) {
            return false;
        }
    }

    return true;
}

void Dictionary::setBerryDictEntry(std::string key, std::string bUrl) {
    berryDict[key] = new Berry(key, bUrl);;
}

Berry Dictionary::getBerryDictEntry(std::string key) {
    return *berryDict.at(key);
}

void Dictionary::setBerryFirmnessDictEntry(std::string key, std::string bUrl) {
    berryFirmnessDict[key] = new BerryFirmness(key, bUrl);;
}

BerryFirmness Dictionary::getBerryFirmnessDictEntry(std::string key) {
    return *berryFirmnessDict.at(key);
}

void Dictionary::setBerryFlavorDictEntry(std::string key, std::string bfUrl) {
    berryFlavorDict[key] = new BerryFlavor(key, bfUrl);;
}

BerryFlavor Dictionary::getBerryFlavorDictEntry(std::string key) {
    return *berryFlavorDict.at(key);
}

void Dictionary::setContestTypeDictEntry(std::string key, std::string ctUrl) {
    contestTypeDict[key] = new ContestType(key, ctUrl);
}

ContestType Dictionary::getContestTypeDictEntry(std::string key) {
    return *contestTypeDict.at(key);
}

void Dictionary::setItemDictEntry(std::string key, std::string iUrl) {
    itemDict[key] = new Item(key, iUrl);
}

Item Dictionary::getItemDictEntry(std::string key) {
    return *itemDict.at(key);
}

void Dictionary::setItemFlingEffectDictEntry(std::string key, std::string ifeUrl) {
    itemFlingEffectDict[key] = new ItemFlingEffect(key, ifeUrl);;
}

ItemFlingEffect Dictionary::getItemFlingEffectDictEntry(std::string key) {
    return *itemFlingEffectDict.at(key);
}

void Dictionary::setLanguageDictEntry(std::string key, std::string lUrl) {
    languageDict[key] = new Language(key, lUrl);
}

Language Dictionary::getLanguageDictEntry(std::string key) {
    return *languageDict.at(key);
}

// for debugging
void Dictionary::printBerryFlavorMap() {
    for (auto& pair : berryFlavorDict) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

void Dictionary::printContestTypeMap() {
    for (auto& pair : contestTypeDict) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}