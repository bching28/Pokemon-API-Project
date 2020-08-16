#ifndef UTILITIES_H
#define UTILITIES_H

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
    Name* names;

public:
    Language();
    ~Language();
};

class Description {
private:
    std::string description;
    Language* language;
public:
    Description();
    ~Description();
};

class Effect {
private:
    std::string effect;
    Language* language;
public:
    Effect();
    ~Effect();
};

class Encounter {
private:
    int minLevel;
    int maxLevel;
    //EncounterConditionValue conditionValues;
    int chance;
    //EncounterMethod method;
};

class FlavorText {
private:
    std::string flavorText;
    Language* language;
    //Version version;

public:
    FlavorText();
    ~FlavorText();
};

class GenerationGameIndex {
private:
    int gameIndex;
    //Generation generation;
public:
    GenerationGameIndex();
    ~GenerationGameIndex();
};

class MachineVersionDetail {
private:
    //Machine machine;
    //VersionGroup versionGroup;
public:
    MachineVersionDetail();
    ~MachineVersionDetail();
};

class Name {
private:
    std::string name;
    Language* language;
};

class VerboseEffect {
private:
    std::string effect;
    std::string shortEffect;
    Language* language;

public:
    VerboseEffect();
    ~VerboseEffect();
};

class VersionEncounterDetail {
private:
    //Version version;
    int maxChance;
    Encounter* encounterDetails;

public:
    VersionEncounterDetail();
    ~VersionEncounterDetail();
};

class VersionGameIndex {
private:
    int gameIndex;
    //Version version;

public:
    VersionGameIndex();
    ~VersionGameIndex();
};

class VersionGroupFlavorText {
private:
    std::string text;
    Language language;
    //VersionGroup versionGroup;

public:
    VersionGroupFlavorText();
    ~VersionGroupFlavorText();
};

#endif // UTILITIES_H