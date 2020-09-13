#ifndef MOVES_H
#define MOVES_H

#include "Pokemon.h"
#include "Resource.h"
#include "Utility.h"

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
    //ContestType contestType; // n-api
    //ContestEffect contestEffect; //API Resource?
    //MoveDamageClass damageClass; // n-api
    //VerboseEffect effectEntries; // list
    std::vector<VerboseEffect*> effectEntries;
    //AbilityEffectChange effectChanges; // list
    //MoveFlavorText flavorTextEntries; // list
    //Generation generation; // n-api
    //MachineVersionDetail machines; // list
    //MoveMetaData meta;
    //Name names; // list
    //PastMoveStatValues pastValues; // list
    //MoveStatChange statChanges; // list
    //SuperContestEffect superContestEffect; //API Resource
    //MoveTarget target; // n-api
    //Type type; // n-api

    json parsedM;
    Dictionary* dict;

public:
    Move(std::string name, std::string url);
    ~Move();

    //int getId();
    //std::string getName();
    //int getAccuracy();
    //int getEffectChance();
    //int getPp();
    //int getPriority();
    //int getPower();

    //ContestComboSets getContestComboSets();
    //ContestType getContestType();
    //MoveDamageClass getMoveDamageClass();
    //VerboseEffect getVerboseEffect();
    //AbilityEffectChange getAbilityEffectChange();
    //MoveFlavorText getMoveFlavorText();
    //Generation getGeneration();
    //MachineVersionDetail getMachineVersionDetail();
    //MoveMetaData getMoveMetaData();
    //Name getName();
    //PastMoveStatValues getPastMoveStatValues();
    //MoveStatChange getMoveStatChange();

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
};

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