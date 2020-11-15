#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include <nlohmann/json.hpp> // might be able to move to Resource.h and get rid of #include in all other files
using json = nlohmann::json;

class APIResource {
protected:
    std::string url;

public:
    APIResource();
    ~APIResource();
};

class NamedAPIResource {
protected:
    std::string name;
    std::string url;

public:
    NamedAPIResource();
    ~NamedAPIResource();
};

int checkForNull(json parsedJson, std::string field);

#endif // RESOURCE_H