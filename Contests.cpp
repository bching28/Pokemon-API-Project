#include "Contests.h"
#include "Requests.h"

ContestType::ContestType(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    parsedCT = req.retrieveJson("contest-type", name); //cool

    id = parsedCT["id"];
    this->name = to_string(parsedCT["name"]);
    berryFlavor = NULL;

    for (auto& contestName : parsedCT["names"]) {
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
    std::string bfName = parsedCT["berry_flavor"]["name"];
    std::string bfUrl = parsedCT["berry_flavor"]["url"];

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
    parsedCN = contestNameJson;
    name = to_string(parsedCN["name"]);
    color = to_string(parsedCN["color"]);
    language = NULL;
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
    std::string lName = parsedCN["language"]["name"];
    std::string lUrl = parsedCN["language"]["url"];

    //if not found in dict
    if (dict->hasFoundKey("language", lName) == false) {
        // add to dictionary
        dict->setLanguageDictEntry(lName, lUrl);
    }

    return dict->getLanguageDictEntry(lName);
}