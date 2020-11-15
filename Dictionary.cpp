#include "Dictionary.h"

Dictionary* Dictionary::instance = 0;

Dictionary::Dictionary() {

}

Dictionary::~Dictionary() {
    //TODO::delete every dictionary
    std::unordered_map <std::string, Berry* >::iterator itrB = berryDict.begin();
    while (itrB != berryDict.end()) {
        delete itrB->second;
        itrB++;
    }
    std::unordered_map <std::string, BerryFirmness* >::iterator itrBFirm = berryFirmnessDict.begin();
    while (itrBFirm != berryFirmnessDict.end()) {
        delete itrBFirm->second;
        itrBFirm++;
    }
    std::unordered_map <std::string, BerryFlavor* >::iterator itrBFlavor = berryFlavorDict.begin();
    while (itrBFlavor != berryFlavorDict.end()) {
        delete itrBFlavor->second;
        itrBFlavor++;
    }
    std::unordered_map <std::string, ContestType* >::iterator itrCT = contestTypeDict.begin();
    while (itrCT != contestTypeDict.end()) {
        delete itrCT->second;
        itrCT++;
    }
    std::unordered_map <int, ContestEffect* >::iterator itrCE = contestEffectDict.begin();
    while (itrCE != contestEffectDict.end()) {
        delete itrCE->second;
        itrCE++;
    }
    std::unordered_map <std::string, SuperContestEffect* >::iterator itrSCE = superContestEffectDict.begin();
    while (itrSCE != superContestEffectDict.end()) {
        delete itrSCE->second;
        itrSCE++;
    }

}

Dictionary* Dictionary::getInstance() {
    if (!instance) {
        instance = new Dictionary;
    }
    
    return instance;
}

void Dictionary::terminate() {
    // Call Constructor
    Dictionary::~Dictionary();
}

// Named API Resources
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
    else if (endPoint == "super-contest-effect") {
        if (superContestEffectDict.find(key) == superContestEffectDict.end()) {
            return false;
        }
    }
    else if (endPoint == "encounter-condition") {
        if (encounterConditionDict.find(key) == encounterConditionDict.end()) {
            return false;
        }
    }
    else if (endPoint == "encounter-condition-value") {
        if (encounterConditionValueDict.find(key) == encounterConditionValueDict.end()) {
            return false;
        }
    }
    else if (endPoint == "item") {
        if (itemDict.find(key) == itemDict.end()) {
            return false;
        }
    }
    else if (endPoint == "item-fling-effect") {
        if (itemFlingEffectDict.find(key) == itemFlingEffectDict.end()) {
            return false;
        }
    }
    else if (endPoint == "language") {
        if (languageDict.find(key) == languageDict.end()) {
            return false;
        }
    }
    else if (endPoint == "version") {
        if (languageDict.find(key) == languageDict.end()) {
            return false;
        }
    }

    return true;
}

// API Resources
bool Dictionary::hasFoundKey(std::string endPoint, int key) {
    if (endPoint == "contest-effect") {
        if (contestEffectDict.find(key) == contestEffectDict.end()) {
            return false;
        }
    }
    
    return true;
}

void Dictionary::setBerryDictEntry(std::string key, std::string url) {
    berryDict[key] = new Berry(key, url);;
}

Berry Dictionary::getBerryDictEntry(std::string key) {
    return *berryDict.at(key);
}

void Dictionary::setBerryFirmnessDictEntry(std::string key, std::string url) {
    berryFirmnessDict[key] = new BerryFirmness(key, url);;
}

BerryFirmness Dictionary::getBerryFirmnessDictEntry(std::string key) {
    return *berryFirmnessDict.at(key);
}

void Dictionary::setBerryFlavorDictEntry(std::string key, std::string url) {
    berryFlavorDict[key] = new BerryFlavor(key, url);;
}

BerryFlavor Dictionary::getBerryFlavorDictEntry(std::string key) {
    return *berryFlavorDict.at(key);
}

void Dictionary::setContestTypeDictEntry(std::string key, std::string url) {
    contestTypeDict[key] = new ContestType(key, url);
}

ContestType Dictionary::getContestTypeDictEntry(std::string key) {
    return *contestTypeDict.at(key);
}

void Dictionary::setContestEffectDictEntry(int key, std::string url) {
    contestEffectDict[key] = new ContestEffect(key, url);
}

ContestEffect Dictionary::getContestEffectDictEntry(int key) {
    return *contestEffectDict.at(key);
}

void Dictionary::setSuperContestEffectDictEntry(std::string key, std::string url) {
    superContestEffectDict[key] = new SuperContestEffect(key, url);
}

SuperContestEffect Dictionary::getSuperContestEffectDictEntry(std::string key) {
    return *superContestEffectDict.at(key);
}

void Dictionary::setEncounterConditionDictEntry(std::string key, std::string url) {
    encounterConditionDict[key] = new EncounterCondition(key, url);
}

EncounterCondition Dictionary::getEncounterConditionDictEntry(std::string key) {
    return *encounterConditionDict.at(key);
}

void Dictionary::setEvolutionChainDictEntry(int key, std::string url) {
    evolutionChainDict[key] = new EvolutionChain(key, url);
}

EvolutionChain* Dictionary::getEvolutionChainDictEntry(int key) {
    return evolutionChainDict.at(key);
}

void Dictionary::setEvolutionTriggerDictEntry(std::string key, std::string url) {
    evolutionTriggerDict[key] = new EvolutionTrigger(key, url);
}

EvolutionTrigger* Dictionary::getEvolutionTriggerDictEntry(std::string key) {
    return evolutionTriggerDict.at(key);
}

void Dictionary::setItemDictEntry(std::string key, std::string url) {
    itemDict[key] = new Item(key, url);
}

Item* Dictionary::getItemDictEntry(std::string key) {
    return itemDict.at(key);
}

void Dictionary::setItemFlingEffectDictEntry(std::string key, std::string url) {
    itemFlingEffectDict[key] = new ItemFlingEffect(key, url);;
}

ItemFlingEffect* Dictionary::getItemFlingEffectDictEntry(std::string key) {
    return itemFlingEffectDict.at(key);
}

void Dictionary::setLanguageDictEntry(std::string key, std::string url) {
    languageDict[key] = new Language(key, url);
}

Language Dictionary::getLanguageDictEntry(std::string key) {
    return *languageDict.at(key);
}

//void Dictionary::setVersionDictEntry(std::string key, std::string url) {
//    versionDict[key] = new Version(key, url);
//}
//
//Version Dictionary::getVersionDictEntry(std::string key) {
//    return *versionDict.at(key);
//}

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