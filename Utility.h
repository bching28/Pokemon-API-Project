#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include "NamedAPIResource.h"

// forward declaration
class Language;
class Name;

class Language : public NamedAPIResource {
private:
    int id;
    std::string name;
    bool official;
    std::string iso639;
    std::string iso3166;
    Name *names;

public:
};

class Effect {
private:
    std::string effect;
    Language language;
public:
};

class FlavorText {
private:
    std::string flavorText;
    Language language;
    //Version version;

public:

};

class Name {
private:
    std::string name;
    Language *language;
};

#endif // UTILITIES_H