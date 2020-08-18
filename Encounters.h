#ifndef ENCOUNTERS_H
#define ENCOUNTERS_H

#include <iostream>
#include "NamedAPIResource.h"
#include "Utility.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// forward declarations
class EncounterCondition;
class EncounterConditionValue;
class EncounterMethod;

class Name; // Utility.h

class EncounterMethod {
private:
    int id;
    std::string name;
    int order;
    Name* names;

public:
    EncounterMethod();
    ~EncounterMethod();
};

class EncounterCondition : public NamedAPIResource {
private:
    int id;
    std::string name;
    Name* names;
    EncounterConditionValue* values;

public:
    EncounterCondition();
    ~EncounterCondition();
};

class EncounterConditionValue : public NamedAPIResource {
private:
    int id;
    std::string name;
    EncounterCondition* condition;
    Name* names;

public:
    EncounterConditionValue();
    ~EncounterConditionValue();
};

#endif // ENCOUNTERS_H