#include "Encounters.h"
#include "Requests.h"

// Encounter Method
// -------------------------------------------------------------------------
// Constructor
EncounterMethod::EncounterMethod(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    parsedJson = req.retrieveJson("encounter-method", name);

    dict = dict->getInstance();

    this->id = parsedJson["id"];
    this->name = to_string(parsedJson["name"]);
    this->order = parsedJson["order"];

    for (auto& name : parsedJson["names"]) {
        this->names.push_back(new Name(name));
    }
}

// Destructor
EncounterMethod::~EncounterMethod() {

}

int EncounterMethod::getId() {
    return this->id;
}

std::string EncounterMethod::getName() {
    return this->name;
}

int EncounterMethod::getOrder() {
    return order;
}

Name EncounterMethod::getNames(int index) {
    return *(names.at(index));
}


// Encounter Conditions
// -------------------------------------------------------------------------
// Constructor
EncounterCondition::EncounterCondition() {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    parsedJson = req.retrieveJson("encounter-method", name);

    dict = dict->getInstance();

    this->id = parsedJson["id"];
    this->name = to_string(parsedJson["name"]);
}

EncounterCondition::~EncounterCondition() {

}

int EncounterCondition::getId() {
    return this->id;
}

std::string EncounterCondition::getName() {
    return this->name;
}

//Name EncounterCondition::getNames() {
//
//}
//
//EncounterConditionValue EncounterCondition::getValues() {
//
//}