#include "Games.h"
#include "../Requests.h"

// Generation (endpoint)
// -------------------------------------------------------------------------
// Constructor
Generation::Generation(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    this->parsedJson = req.retrieveJson("generation", name);

    this->dict = this->dict->getInstance();

    this->id = this->parsedJson["id"];
    this->name = this->parsedJson["name"];

    for (auto& name : parsedJson["names"]) {
        this->names.push_back(new Name(name));
    }
}

Generation::~Generation() {
    // delete each pointer in vector
    /*for (auto name : names) {
        delete name;
    }
    names.clear();*/
}

int Generation::getId() {
    return this->id;
}

std::string Generation::getName() {
    return this->name;
}

Name Generation::getNames(int index) {
    return *(this->names.at(index));
}



// Generation (endpoint)
// -------------------------------------------------------------------------
// Constructor
Pokedex::Pokedex(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    this->parsedJson = req.retrieveJson("pokedex", name);

    this->dict = this->dict->getInstance();

    this->id = this->parsedJson["id"];
    this->name = this->parsedJson["name"];
    this->mainSeries = this->parsedJson["is_main_series"];

    for (auto& name : parsedJson["names"]) {
        this->names.push_back(new Name(name));
    }
}

Pokedex::~Pokedex() {
    // delete each pointer in vector
    /*for (auto name : names) {
        delete name;
    }
    names.clear();*/
}

int Pokedex::getId() {
    return this->id;
}

std::string Pokedex::getName() {
    return this->name;
}

bool Pokedex::isMainSeries() {
    return this->mainSeries;
}

Name Pokedex::getNames(int index) {
    return *(this->names.at(index));
}


// Version (endpoint)
// -------------------------------------------------------------------------
// Constructor
Version::Version(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    this->parsedJson = req.retrieveJson("version", name);

    this->dict = this->dict->getInstance();

    this->id = this->parsedJson["id"];
    this->name = this->parsedJson["name"];

    for (auto& name : parsedJson["names"]) {
        this->names.push_back(new Name(name));
    }
}

Version::~Version() {
    // delete each pointer in vector
    /*for (auto name : names) {
        delete name;
    }
    names.clear();*/
}

int Version::getId() {
    return this->id;
}

std::string Version::getName() {
    return this->name;
}

Name Version::getNames(int index) {
    return *(this->names.at(index));
}


// Version Group (endpoint)
// -------------------------------------------------------------------------
// Constructor
VersionGroup::VersionGroup(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    this->parsedJson = req.retrieveJson("version-group", name);

    this->dict = this->dict->getInstance();

    this->id = this->parsedJson["id"];
    this->name = this->parsedJson["name"];
    this->order = this->parsedJson["order"];
}

VersionGroup::~VersionGroup() {
    // delete each pointer in vector
    /*for (auto name : names) {
        delete name;
    }
    names.clear();*/
}

int VersionGroup::getId() {
    return this->id;
}

std::string VersionGroup::getName() {
    return this->name;
}

int VersionGroup::getOrder() {
    return this->order;
}