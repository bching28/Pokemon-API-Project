#include "Berries.h"
#include "Requests.h"

BerryFlavor::BerryFlavor(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    parsedBF = req.retrieveJson("berry-flavor", name);

    id = parsedBF["id"];
    this->name = to_string(parsedBF["name"]);
    contestType = NULL;

    for (auto& name : parsedBF["names"]) {
        names.push_back(new Name(name));
    }

    dict = dict->getInstance();
}

BerryFlavor::~BerryFlavor() {

}

int BerryFlavor::getId() {
    return id;
}

std::string BerryFlavor::getName() {
    return name;
}

ContestType BerryFlavor::getContestType() {
    //search dict by passing in name
    std::string ctName = parsedBF["contest_type"]["name"];
    std::string ctUrl = parsedBF["contest_type"]["url"];

    //if not found in dict
    if (dict->hasFoundKey("contest-type", ctName) == false) {
        // add to dictionary
        dict->setContestTypeDictEntry(ctName, ctUrl);
    }
    dict->printContestTypeMap();
    return dict->getContestTypeDictEntry(ctName);
}

Name BerryFlavor::getUtilityName(int index) {
    return *(names.at(index));
}