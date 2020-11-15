#include "Evolution.h"
#include "../Requests.h"

// Evolution Chain (endpoint)
// -------------------------------------------------------------------------
// Constructor
EvolutionChain::EvolutionChain(int id, std::string url) {
    APIResource::url = url;

    Requests req;
    this->parsedJson = req.retrieveJson("evolution-chain", id);

    this->dict = this->dict->getInstance();

    this->id = this->parsedJson["id"];

    this->chain = new ChainLink(this->parsedJson["chain"]);
}

/*
Looks like we will need copy constructors for all the main endpoint
functions located in PokeWrap.cpp/.h
This is because we are creating local copies in the PokeWrap class,
but we are attempting to return the local copies to the main function.
By the end of the local function call in the PokeWrap class, the object
created is destroyed, which will result in exceptions in main.
*/
EvolutionChain::EvolutionChain(const EvolutionChain& obj) {
    chain = new ChainLink(*obj.chain);
    //chain = obj.chain;
    id = obj.id;
    std::cout << "Copy Constructor: " << chain << std::endl;
}

EvolutionChain::~EvolutionChain() {
    std::cout << "Destructor: " << chain << std::endl;
    delete chain;
}

int EvolutionChain::getId() {
    return this->id;
}

Item* EvolutionChain::getBabyTriggerItem() {
    std::string name;
    std::string url;

    // determine if field is NULL
    if (parsedJson["baby_trigger_item"].is_null()) {
        return NULL;
    }
    else {
        name = to_string(parsedJson["baby_trigger_item"]["name"]);
        url = to_string(parsedJson["baby_trigger_item"]["url"]);
    }

    //if not found in dict
    if (dict->hasFoundKey("item", name) == false) {
        // add to dictionary
        dict->setItemDictEntry(name, url);
    }

    return dict->getItemDictEntry(name);
}

ChainLink* EvolutionChain::getChain() {
    return chain;
}


// Chain Link
// -------------------------------------------------------------------------
// Constructor
ChainLink::ChainLink(json chainLinkJson) {
    parsedJson = chainLinkJson;
    dict = dict->getInstance();
    isBaby = parsedJson["is_baby"];

    //TODO::determine more graceful solution
    // check if the json is empty
    if (!parsedJson["evolution_details"].empty()) {
        for (auto& detail : parsedJson["evolution_details"]) {
            evolutionDetails.push_back(new EvolutionDetail(detail));
        }
    }
    else {
        evolutionDetails.push_back(NULL);
    }

    //TODO::determine more graceful solution
    // check if the json is empty
    if (!parsedJson["evolves_to"].empty()) {
        for (auto& evolution : parsedJson["evolves_to"]) { // for debugging: eevee is evolution chain #67
            evolvesTo.push_back(new ChainLink(evolution));
        }
    }
    else {
        evolvesTo.push_back(NULL);
    }
}

// Copy Constructor
ChainLink::ChainLink(const ChainLink& obj) {
    evolutionDetails = obj.evolutionDetails;
    evolvesTo = obj.evolvesTo;
}

ChainLink::~ChainLink() {
    // delete each pointer in vector
    for (auto detail : evolutionDetails) {
        delete detail;
    }
    evolutionDetails.clear();

    // delete each pointer in vector
    //TODO::fix exception error (probably because this is calling itself
    //for (auto evolution : evolvesTo) {
    //    delete evolution;
    //}
    //evolvesTo.clear();
}

bool ChainLink::getIsBaby() {
    return this->isBaby;
}

EvolutionDetail* ChainLink::getEvolutionDetails(int index) {
    return this->evolutionDetails.at(index);
}

ChainLink* ChainLink::getEvolvesTo(int index) {
    return this->evolvesTo.at(index);
}


// Evolution Detail
// -------------------------------------------------------------------------
// Constructor
EvolutionDetail::EvolutionDetail(json evolutionDetailJson) {
    this->parsedJson = evolutionDetailJson;
    this->dict = this->dict->getInstance();

    this->gender = checkForNull(this->parsedJson, "gender");
    this->minLevel = checkForNull(this->parsedJson, "min_level");
    this->minHappiness = checkForNull(this->parsedJson, "min_happiness");
    this->minBeauty = checkForNull(this->parsedJson, "min_beauty");
    this->minAffection = checkForNull(this->parsedJson, "min_affection");
    this->needsOverworldRain = this->parsedJson["needs_overworld_rain"];
    this->relativePhysicalStats = checkForNull(this->parsedJson, "relative_physical_stats");
    this->timeOfDay = this->parsedJson["time_of_day"];
    this->turnUpsideDown = this->parsedJson["turn_upside_down"];
}

EvolutionDetail::~EvolutionDetail() {

}

Item* EvolutionDetail::getItem() {
    std::string name;
    std::string url;

    // determine if field is NULL
    if (this->parsedJson["item"].is_null()) {
        return NULL;
    }
    else {
        name = to_string(parsedJson["item"]["name"]);
        url = to_string(parsedJson["item"]["url"]);
    }

    //if not found in dict
    if (this->dict->hasFoundKey("item", name) == false) {
        // add to dictionary
        this->dict->setItemDictEntry(name, url);
    }

    return this->dict->getItemDictEntry(name);
}

EvolutionTrigger* EvolutionDetail::getTrigger() {
    std::string name;
    std::string url;

    // determine if field is NULL
    if (this->parsedJson["trigger"].is_null()) {
        return NULL;
    }
    else {
        name = to_string(parsedJson["trigger"]["name"]);
        url = to_string(parsedJson["trigger"]["url"]);
    }

    //if not found in dict
    if (this->dict->hasFoundKey("evolution-trigger", name) == false) {
        // add to dictionary
        this->dict->setEvolutionTriggerDictEntry(name, url);
    }

    return this->dict->getEvolutionTriggerDictEntry(name);
}

int EvolutionDetail::getGender() {
    return this->gender; // TODO::determine what null integer returns
}

Item* EvolutionDetail::getHeldItem() {
    std::string name;
    std::string url;

    // determine if field is NULL
    if (this->parsedJson["held_item"].is_null()) {
        return NULL;
    }
    else {
        name = to_string(parsedJson["held_item"]["name"]);
        url = to_string(parsedJson["held_item"]["url"]);
    }

    //if not found in dict
    if (this->dict->hasFoundKey("item", name) == false) {
        // add to dictionary
        this->dict->setItemDictEntry(name, url);
    }

    return this->dict->getItemDictEntry(name);
}

//Move* EvolutionDetail::getKnownMove() {}

//Type* EvolutionDetail::getKnownMoveType() {}

//Location* EvolutionDetail::getLocation() {}

int EvolutionDetail::getMinLevel() {
    return this->minLevel;
}

int EvolutionDetail::getMinHappiness() {
    return this->minHappiness;
}

int EvolutionDetail::getMinBeauty() {
    return this->minBeauty;
}

int EvolutionDetail::getMinAffection() {
    return this->minAffection;
}

bool EvolutionDetail::getNeedsOverworldRain() {
    return this->needsOverworldRain;
}

//PokemonSpecies* EvolutionDetail::getPartySpecies() {}

//Type* EvolutionDetail::getPartyType() {}

int EvolutionDetail::getRelativePhysicalStats() {
    return this->relativePhysicalStats;
}

std::string EvolutionDetail::getTimeOfDay() {
    return this->timeOfDay;
}

//PokemonSpecies* EvolutionDetail::getTradeSpecies();

bool EvolutionDetail::getTurnUpsideDown() {
    return this->turnUpsideDown;
}


// Evolution Triggers (endpoint)
// -------------------------------------------------------------------------
// Constructor
EvolutionTrigger::EvolutionTrigger(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    this->parsedJson = req.retrieveJson("evolution-trigger", name);

    this->dict = this->dict->getInstance();

    this->id = this->parsedJson["id"];
    this->name = this->parsedJson["name"];

    for (auto& name : parsedJson["names"]) {
        this->names.push_back(new Name(name));
    }
}

EvolutionTrigger::~EvolutionTrigger() {
    // delete each pointer in vector
    for (auto name : names) {
        delete name;
    }
    names.clear();
}

int EvolutionTrigger::getId() {
    return this->id;
}

std::string EvolutionTrigger::getName() {
    return this->name;
}

Name EvolutionTrigger::getNames(int index) {
    return *(this->names.at(index));
}

//PokemonSpecies* EvolutionTrigger::getPokemonSpecies() {}