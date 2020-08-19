#ifndef RESOURCE_H
#define RESOURCE_H

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

#endif // RESOURCE_H