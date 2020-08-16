#ifndef NAMED_API_RESOURCE_H
#define NAMED_API_RESOURCE_H

#include <iostream>

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

#endif // NAMED_API_RESOURCE_H