#include "Contests.h"
#include "../Requests.h"

// Contest Type
// -------------------------------------------------------------------------
// Constructor
ContestType::ContestType(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    parsedJson = req.retrieveJson("contest-type", name);

    this->id = parsedJson["id"];
    this->name = to_string(parsedJson["name"]);

    for (auto& contestName : parsedJson["names"]) {
        names.push_back(new ContestName(contestName));
    }

    dict = dict->getInstance();
}

ContestType::~ContestType() {
    //TODO::deallocated memory of dynamic variables
}

int ContestType::getId() {
    return id;
}

std::string ContestType::getName() {
    return name;
}

BerryFlavor ContestType::getBerryFlavor() {
    //search dict by passing in name
    std::string bfName = parsedJson["berry_flavor"]["name"];
    std::string bfUrl = parsedJson["berry_flavor"]["url"];

    //if not found in dict
    if (dict->hasFoundKey("berry-flavor", bfName) == false) {
        // add to dictionary
        dict->setBerryFlavorDictEntry(bfName, bfUrl);
    }
    dict->printBerryFlavorMap();
    return dict->getBerryFlavorDictEntry(bfName);
}

ContestName ContestType::getContestName(int index) {
    return *(names.at(index));
}


// ContestName
ContestName::ContestName(json contestNameJson) {
    parsedJson = contestNameJson;
    this->name = to_string(parsedJson["name"]);
    this->color = to_string(parsedJson["color"]);

    dict = dict->getInstance();
}

ContestName::~ContestName() {}

std::string ContestName::getName() {
    return name;
}

std::string ContestName::getColor() {
    return color;
}

Language ContestName::getLanguage() {
    //search dict by passing in name
    std::string lName = parsedJson["language"]["name"];
    std::string lUrl = parsedJson["language"]["url"];

    //if not found in dict
    if (dict->hasFoundKey("language", lName) == false) {
        // add to dictionary
        dict->setLanguageDictEntry(lName, lUrl);
    }

    return dict->getLanguageDictEntry(lName);
}

// Contest Effect
// -------------------------------------------------------------------------
// Constructor
ContestEffect::ContestEffect(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url  = url;

    Requests req;
    parsedJson = req.retrieveJson("contest-effect", name);

    this->id     = parsedJson["id"];
    this->appeal = parsedJson["appeal"];
    this->jam    = parsedJson["jam"];

    for (auto& effectEntry : parsedJson["effect_entries"]) {
        effectEntries.push_back(new Effect(effectEntry));
    }

    for (auto& flavorTextEntry : parsedJson["flavor_text_entries"]) {
        flavorTextEntries.push_back(new FlavorText(flavorTextEntry));
    }

    dict = dict->getInstance();
}

ContestEffect::~ContestEffect() {

}

int ContestEffect::getId() {
    return this->id;
}

int ContestEffect::getAppeal() {
    return this->appeal;
}

int ContestEffect::getJam() {
    return this->jam;
}

Effect ContestEffect::getEffect(int index) {
    return *(this->effectEntries.at(index));
}

FlavorText ContestEffect::getFlavorText(int index) {
    return *(this->flavorTextEntries.at(index));
}

// Super Contest Effect
// -------------------------------------------------------------------------
// Constructor
SuperContestEffect::SuperContestEffect(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    parsedJson = req.retrieveJson("super-contest-effect", name);

    this->id = parsedJson["id"];
    this->appeal = parsedJson["appeal"];

    for (auto& flavorTextEntry : parsedJson["flavor_text_entries"]) {
        flavorTextEntries.push_back(new FlavorText(flavorTextEntry));
    }

    /*for (auto& move : parsedSCE["moves"]) {
        moves.push_back(new Move(move["name"], move["url"]));
    }*/

    dict = dict->getInstance();
}

SuperContestEffect::~SuperContestEffect() {

}

int SuperContestEffect::getId() {
    return this->id;
}

int SuperContestEffect::getAppeal() {
    return this->appeal;
}

FlavorText SuperContestEffect::getFlavorText(int index) {
    return *(this->flavorTextEntries.at(index));
}

//Move SuperContestEffect::getMove(int index) {
//    return *(this->moves.at(index));
//}