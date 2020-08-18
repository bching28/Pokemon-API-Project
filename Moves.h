#ifndef MOVES_H
#define MOVES_H

#include "NamedAPIResource.h"
#include "Utilies.h"

class Move : public NamedAPIResource {
private:
    int id;
    std::string name;
    int accuracy;
    int effectChance;
    int pp;
    int priority;
    int power;
    //ContestComboSets contestCombos;
    //ContestType contestType;
    //ContentEffect contestEffect; / APIResource?
    //MoveDamageClass damageClass;
    //VerboseEffect effectEntries;
    //AbilityEffectChange effectChanges;
    //MoveFlavorText flavorTextEntries;
    //Generation generation;
    //MachineVersionDetail machines;
    //MoveMetaData meta;
    //Name names;
    //PastMoveStatValues pastValues;
    //MoveStatChange statChanges;
    //SuperContestEffect superContestEffect;
    //MoveTarget target;
    //Type type;

public:
    Move();
    ~Move();
};

class ContestComboSets {
private:
    /*ContestComboDetail normal;
    ContestComboDetail super;*/

public:
    ContestComboSets();
    ~ContestComboSets();
};

class ContestComboDetail {
private:
    Move useBefore;
    Move useAfter;
public:
    ContestComboDetail();
    ~ContestComboDetail();
};

class MoveFlavorText {
private:
    std::string flavorText;
    //Language language;
    //VersionGroup versionGroup;
public: 
    MoveFlavorText();
    ~MoveFlavorText();
};

class MoveMetaData {
private:
    //MoveAilment ailment;
    //MoveCategory category;
    int minHits;
    int maxHits;
    int minTurns;
    int maxTurns;
    int drain;
    int healing;
    int critRate;
    int ailmentChance;
    int flinchChance;
    int statChance;

public:
    MoveMetaData();
    ~MoveMetaData();
}

class MoveStatChange {
private:
    int change;
    //Stat stat;

public:
    MoveStatChange();
    ~MoveStatChange();
};

class PastMoveStatValues {
private:
    int accuracy;
    int effectChance;
    int power;
    int pp;
    //VerboseEffect effectEntries;
    //Type type;
    //VersionGroup versionGroup;

public:
    PastMoveStatValues();
    ~PastMoveStatValues();
};

class MoveAilment {
private:
    int id;
    std::string name;
    //Move moves;
    //Name names;

public:
    MoveAilment();
    ~MoveAilment();
};

class MoveBattleStyle : public NamedAPIResource {
private:
    int id;
    std::string name;
    //Name names;

public:
    MoveBattleStyle();
    ~MoveBattleStyle();
};

class ModelName {
private:
    int id;
    std::string name;
    //Move moves;
    //Description descriptions;

public:
    ModelName();
    ~ModelName();
};

class MoveDamageClass : public NamedAPIResource {
private:
    int id;
    std::string name;
    //Description descriptions;
    //Move moves;
    //Name names;

public:
    MoveDamageClass();
    ~MoveDamageClass();
};

class MoveLearnMethod : public NamedAPIResource {
private:
    int id;
    std::string name;
    //Description description;
    //Name names;
    //VersionGroup versionGroups;

public:
    MoveLearnMethod();
    ~MoveLearnMethod();
};

class MoveTarget : public NamedAPIResource {
private:
    int id;
    std::string name;
    //Description descriptions;
    //Move moves;
    //Name names;

public:
    MoveTarget();
    ~MoveTarget();
};

#endif // MOVES_H