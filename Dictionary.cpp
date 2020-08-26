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
            return true;
        }
    }

    return false;
}

void Dictionary::setContestTypeDictEntry(ContestType* ct, std::string key) {
    contestTypeDict[key] = ct;
}

ContestType Dictionary::getContestTypeDictEntry(std::string key) {
    return *contestTypeDict.at(key);
}

void Dictionary::setBerryFlavorDictEntry(std::string key, std::string bfUrl) {
    //BerryFlavor* bf = new BerryFlavor(bfName, bfUrl);
    berryFlavorDict[key] = new BerryFlavor(key, bfUrl);;
}

BerryFlavor Dictionary::getBerryFlavorDictEntry(std::string key) {
    return *berryFlavorDict.at(key);
}