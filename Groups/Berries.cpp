#include "Berries.h"
#include "../Requests.h"

// Berry
// -------------------------------------------------------------------------
// Constructor
Berry::Berry(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    parsedB = req.retrieveJson("berry", name);

    dict = dict->getInstance();

    this->id = parsedB["id"];
    this->name = to_string(parsedB["name"]);
    this->growthTime = parsedB["growth_time"];
    this->maxHarvest = parsedB["max_harvest"];
    this->naturalGiftPower = parsedB["natural_gift_power"];
    this->size = parsedB["size"];
    this->smoothness = parsedB["smoothness"];
    this->soilDryness = parsedB["soil_dryness"];

    firmness = NULL;

    for (auto& flavor : parsedB["flavors"]) {
        flavors.push_back(new BerryFlavorMap(flavor));
    }

    item = NULL;
}

Berry::~Berry() {

}

int Berry::getId() {
    return this->id;
}

std::string Berry::getName() {
    return this->name;
}

int Berry::getGrowthTime() {
    return this->growthTime;
}

int Berry::getMaxHarvest() {
    return this->maxHarvest;
}

int Berry::getNaturalGiftPower() {
    return this->naturalGiftPower;
}

int Berry::getSize() {
    return this->size;
}

int Berry::getSmoothness() {
    return this->smoothness;
}

int Berry::getSoilDryness() {
    return this->soilDryness;
}

BerryFirmness Berry::getFirmness() {
    //search dict by passing in name
    std::string fName = parsedB["firmness"]["name"];
    std::string fUrl = parsedB["firmness"]["url"];

    //if not found in dict
    if (dict->hasFoundKey("berry-firmness", fName) == false) {
        // add to dictionary
        dict->setBerryFirmnessDictEntry(fName, fUrl);
    }

    return dict->getBerryFirmnessDictEntry(fName);
}

BerryFlavorMap Berry::getFlavors(int index) {
    return *(this->flavors.at(index));
}

Item Berry::getItem() {
    //search dict by passing in name
    std::string iName = parsedB["item"]["name"];
    std::string iUrl = parsedB["item"]["url"];

    //if not found in dict
    if (dict->hasFoundKey("item", iName) == false) {
        // add to dictionary
        dict->setItemDictEntry(iName, iUrl);
    }

    return dict->getItemDictEntry(iName);
}

// Berry Flavor Map
// -------------------------------------------------------------------------
// Constructor
BerryFlavorMap::BerryFlavorMap(json berryFlavorMapJson) {
    parsedBFM = berryFlavorMapJson;
    potency = parsedBFM["potency"];
    flavor = NULL;
    dict = dict->getInstance();
}

BerryFlavorMap::~BerryFlavorMap() {

}

int BerryFlavorMap::getPotency() {
    return this->potency;
}

BerryFlavor BerryFlavorMap::getFlavor() {
    //search dict by passing in name
    std::string fName = parsedBFM["flavor"]["name"];
    std::string fUrl = parsedBFM["flavor"]["url"];

    //if not found in dict
    if (dict->hasFoundKey("language", fName) == false) {
        // add to dictionary
        dict->setBerryFlavorDictEntry(fName, fUrl);
    }

    return dict->getBerryFlavorDictEntry(fName);
}

// Berry Firmness
// -------------------------------------------------------------------------
// Constructor
BerryFirmness::BerryFirmness(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    parsedBF = req.retrieveJson("berry-firmness", name);

    dict = dict->getInstance();

    this->id = parsedBF["id"];
    this->name = to_string(parsedBF["name"]);

    for (auto& berry : parsedBF["berries"]) {
        berries.push_back(new Berry(berry["name"], berry["url"]));
    }

    for (auto& name : parsedBF["names"]) {
        names.push_back(new Name(name));
    }
}

BerryFirmness::~BerryFirmness() {

}

int BerryFirmness::getId() {
    return this->id;
}

std::string BerryFirmness::getName() {
    return this->name;
}

Berry BerryFirmness::getBerries(int index) {
    return *(berries.at(index));
}

Name BerryFirmness::getNames(int index) {
    return *(names.at(index));
}


// Berry Flavor
// -------------------------------------------------------------------------
// Constructor
BerryFlavor::BerryFlavor(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    parsedBF = req.retrieveJson("berry-flavor", name);

    this->id = parsedBF["id"];
    this->name = to_string(parsedBF["name"]);

    for (auto& berry : parsedBF["berries"]) {
        berries.push_back(new FlavorBerryMap(berry));
    }

    contestType = NULL;

    for (auto& name : parsedBF["names"]) {
        names.push_back(new Name(name));
    }

    dict = dict->getInstance();
}

// Destructor
BerryFlavor::~BerryFlavor() {

}

int BerryFlavor::getId() {
    return id;
}

std::string BerryFlavor::getName() {
    return name;
}

FlavorBerryMap BerryFlavor::getBerries(int index) {
    return *(berries.at(index));
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

Name BerryFlavor::getNames(int index) {
    return *(names.at(index));
}

// Flavor Berry Map
// -------------------------------------------------------------------------
// Constructor
FlavorBerryMap::FlavorBerryMap(json flavorBerryMapJson) {
    parsedFBM = flavorBerryMapJson;
    potency = parsedFBM["potency"];
    berry = NULL;
    dict = dict->getInstance();
}

FlavorBerryMap::~FlavorBerryMap() {

}

int FlavorBerryMap::getPotency() {
    return potency;
}

Berry FlavorBerryMap::getBerry() {
    //search dict by passing in name
    std::string bName = parsedFBM["berry"]["name"];
    std::string bUrl = parsedFBM["berry"]["url"];

    //if not found in dict
    if (dict->hasFoundKey("berry", bName) == false) {
        // add to dictionary
        dict->setBerryDictEntry(bName, bUrl);
    }

    return dict->getBerryDictEntry(bName);
}
