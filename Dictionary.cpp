#include "Dictionary.h"

Dictionary* Dictionary::instance = 0;

Dictionary::Dictionary() {

}

Dictionary* Dictionary::getInstance() {
    if (!instance) {
        instance = new Dictionary;
    }
    
    return instance;
}

bool Dictionary::hasFoundKey(std::string endPoint, std::string key) {
    if (endPoint == "contest-type") {
        if (contestTypeDict.find(key) == contestTypeDict.end()) {
            return false;
        }
    }
    else if (endPoint == "berry-flavor") {
        if (berryFlavorDict.find(key) == berryFlavorDict.end()) {
            return false;
        }
    }

    return true;
}

void Dictionary::setContestTypeDictEntry(std::string key, std::string ctUrl) {
    contestTypeDict[key] = new ContestType(key, ctUrl);
}

ContestType Dictionary::getContestTypeDictEntry(std::string key) {
    return *contestTypeDict.at(key);
}

void Dictionary::setBerryFlavorDictEntry(std::string key, std::string bfUrl) {
    berryFlavorDict[key] = new BerryFlavor(key, bfUrl);;
}

BerryFlavor Dictionary::getBerryFlavorDictEntry(std::string key) {
    return *berryFlavorDict.at(key);
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