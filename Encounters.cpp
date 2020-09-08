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
    return this->order;
}

Name EncounterMethod::getNames(int index) {
    return *(this->names.at(index));
}


// Encounter Conditions
// -------------------------------------------------------------------------
// Constructor
EncounterCondition::EncounterCondition(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    this->parsedJson = req.retrieveJson("encounter-condition", name);

    this->dict = this->dict->getInstance();

    this->id = this->parsedJson["id"];
    this->name = to_string(this->parsedJson["name"]);

    for (auto& name : this->parsedJson["names"]) {
        this->names.push_back(new Name(name));
    }
}

EncounterCondition::~EncounterCondition() {

}

int EncounterCondition::getId() {
    return this->id;
}

std::string EncounterCondition::getName() {
    return this->name;
}

Name EncounterCondition::getNames(int index) {
    return *(this->names.at(index));
}

//EncounterConditionValue EncounterCondition::getValues() {
//
//}

// Encounter Condition Value
// -------------------------------------------------------------------------
// Constructor
EncounterConditionValue::EncounterConditionValue(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    this->parsedJson = req.retrieveJson("encounter-condition-value", name);

    this->dict = this->dict->getInstance();

    this->id = this->parsedJson["id"];
    this->name = to_string(this->parsedJson["name"]);

    // condition = NULL;

    for (auto& name : this->parsedJson["names"]) {
        this->names.push_back(new Name(name));
    }
}

EncounterConditionValue::~EncounterConditionValue() {

}

int EncounterConditionValue::getId() {
    return this->id;
}

std::string EncounterConditionValue::getName() {
    return this->name;
}

EncounterCondition EncounterConditionValue::getCondition() {
    //search dict by passing in name
    std::string parsedJsonName = this->parsedJson["condition"]["name"];
    std::string parsedJsonUrl = this->parsedJson["condition"]["url"];

    //if not found in dict
    if (this->dict->hasFoundKey("encounter-condition", parsedJsonName) == false) {
        // add to dictionary
        this->dict->setEncounterConditionDictEntry(parsedJsonName, parsedJsonUrl);
    }

    return this->dict->getEncounterConditionDictEntry(parsedJsonName);
}

Name EncounterConditionValue::getNames(int index) {
    return *(this->names.at(index));
}