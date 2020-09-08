#ifndef ENCOUNTERS_H
#define ENCOUNTERS_H

#include <iostream>
#include "Dictionary.h"
#include "Resource.h"
#include "Utility.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// forward declarations
class Dictionary;
class EncounterCondition;
class EncounterConditionValue;
class EncounterMethod;
class Name; // Utility.h

// Encounter Method
class EncounterMethod : public NamedAPIResource {
private:
    json parsedJson;
    Dictionary* dict;

    int id;
    std::string name;
    int order;
    std::vector<Name*> names;

public:
    EncounterMethod(std::string name, std::string url);
    ~EncounterMethod();

    int getId();
    std::string getName();
    int getOrder();
    Name getNames(int index);
};

// Encounter Condition
class EncounterCondition : public NamedAPIResource {
private:
    json parsedJson;
    Dictionary* dict;

    int id;
    std::string name;
    std::vector<Name*> names;
    std::vector<EncounterConditionValue*> values;

public:
    EncounterCondition();
    ~EncounterCondition();

    int getId();
    std::string getName();
    Name getNames();
    EncounterConditionValue getValues();
};

// Encounter Condition Value
class EncounterConditionValue : public NamedAPIResource {
private:
    json parsedJson;
    Dictionary* dict;

    int id;
    std::string name;
    EncounterCondition* condition;
    Name* names;

public:
    EncounterConditionValue();
    ~EncounterConditionValue();
};

#endif // ENCOUNTERS_H