#ifndef POKEMON_H
#define POKEMON_H

#include "NamedAPIResource.h"

class Ability : public NamedAPIResource {
private:
    int id;
    std::string name;
    bool isMainSeries;
    //Generation generation;
    //Name names;
    //VerboseEffect effectEntries;
    //AbilityEffectChange effectChanges;
    //AbilityFlavorText flavorTextEntries;
    //AbilityPokemon pokemon;

public:
    Ability();
    ~Ability();
};

class AbilityEffectChange {
private:
    Effect effectEntries;
    /*VersionGroup versionGroup;*/

public:
    AbilityEffectChange();
    ~AbilityEffectChange();
};

class AbilityFlavorText {
private:
    std::string flavorText;
    //Language language;
    //VersionGroup versionGroup;

public:
    AbilityFlavorText();
    ~AbilityFlavorText();
};

class AbilityPokemon {
private:
    bool isHidden;
    int slot;
    //Pokemon pokemon;

public:
    AbilityPokemon();
    ~AbilityPokemon();
};

class Characteristic {
private:
    int id;
    int geneModulo;
    int possibleValues;

public:
    Characteristic();
    ~Characteristic();
};

class EggGroup : public NamedAPIResource {
private:
    int id;
    std::string name;
    //Name names;
    //PokemonSpecies pokemonSpecies;

public:
    EggGroup();
    ~EggGroup();
};

class Gender {
private:
    int id;
    std::string name;
    //PokemonSpeciesGender pokemonSpeciesDetails;
    //PokemonSpecies requiredForEvolution;
public:
    Gender();
    ~Gender();
};

class PokemonSpeciesGender {
private:
    int rate;
    //PokemonSpecies pokemonSpecies;

public:
    PokemonSpeciesGender();
    ~PokemonSpeciesGender();
};

class GrowthRate : public NamedAPIResource {
private:
    int id;
    std::string name;
    std::string formula;
    //Description descriptions;
    //GrowthRateExperienceLevel levels;
    //PokemonSpecies pokemonSpecies;

public:
    GrowthRate();
    ~GrowthRate();
};

class GrowthRateExperienceLevel {
private:
    int level;
    int experience;

public:
    GrowthRateExperienceLevel();
    ~GrowthRateExperienceLevel();
};

class Nature : public NamedAPIResource {
private:
    int id;
    std::string name;
    //Stat decreasedStat;
    //Stat increasedStat;
    //BerryFlavor hatesFlavor;
    //BerryFlavor likesFlavor;
    //NatureStatChange pokeathlonStatChanges;
    //MoveBattleStylePreference moveBattleStylePreferences;
    //Name names;

public:
    Nature();
    ~Nature();
};

class NatureStatChange {
private:
    int maxChange;
    //PokeathlonStat pokeathlonStat;

public:
    NatureStatChange();
    ~NatureStatChange();
};

class MoveBattleStylePreference {
private:
    int lowHpPreference;
    int highHpPreference;
    //MoveBattleStyle moveBattleStyle;

public:
    MoveBattleStylePreference();
    ~MoveBattleStylePreference();
};

class PokeathlonStat : public NamedAPIResource {
private:
    int id;
    std::string name;
    //Name names;
    //NaturePokeathlonStatAffectSets affectingNatures;

public:
    PokeathlonStat();
    ~PokeathlonStat();
};

class NaturePokeathlonStatAffectSets {
private:
    //NaturePokeathlonStatAffect increase;
    //NaturePokeathlonStatAffect decrease;

public:
    NaturePokeathlonStatAffectSets();
    ~NaturePokeathlonStatAffectSets();
};

class NaturePokeathlonStatAffect {
private:
    int maxChange;
    //Nature nature;

public:
    NaturePokeathlonStatAffect();
    ~NaturePokeathlonStatAffect();
};

class Pokemon : public NamedAPIResource {
private:
    int id;
    std::string name;
    int baseExperience;
    int height;
    bool isDefault;
    int order;
    int weight;
    //PokemonAbility abilities;
    //PokemonForm forms;
    //VersionGameIndex gameIndicies;
    //PokemonHeldItems heldItems;
    std::string locationAreaEncounters;
    //PokemonMove moves;
    //PokemonSprites sprites;
    //PokemonSpecies species;
    //PokemonStat stats;
    //PokemonType types;

public:
    Pokemon();
    ~Pokemon();
};

class PokemonAbility {
private:
    bool isHidden;
    int slot;
    //Ability ability;

public:
    PokemonAbility();
    ~PokemonAbility();
};

class PokemonType {
private:
    int slot;
    //Type type;

public:
    PokemonType();
    ~PokemonType();
};

class PokemonHeldItem {
private:
    //Item item;
    //PokemonHeldItemVersion versionDetails;

public:
    PokemonHeldItem();
    ~PokemonHeldItem();
};

class PokemonHeldItemVersion {
private:
    //Version version;
    int rarity;

public:
    PokemonHeldItemVersion();
    ~PokemonHeldItemVersion();
};

class PokemonMove {
private:
    //Move move;
    //PokemonMoveVersion versionGroupDetails;

public:
    PokemonMove();
    ~PokemonMove();
};

class PokemonMoveVersion {
private:
    //MoveLearnMethod moveLearnMethod;
    //VersionGroup versionGroup;
    int levelLearnedAt;

public:
    PokemonMoveVersion();
    ~PokemonMoveVersion();
};

class PokemonStat {
private:
    //Stat stat;
    int effort;
    int baseStat;

public:
    PokemonStat();
    ~PokemonStat();
};

class PokemonSprites {
private:
    std::string frontDefault;
    std::string frontShiny;
    std::string frontFemale;
    std::string frontShinyFemale;
    std::string backDefault;
    std::string backShiny;
    std::string backFemale;
    std::string backShinyFemale;

public:
    PokemonSprites();
    ~PokemonSprites();
};

class LocationAreaEncounter {
private:
    //LocationArea locationArea;
    //VersionEncounterDetail versionDetails;

public:
    LocationAreaEncounter();
    ~LocationAreaEncounter();
};

class PokemonColor : public NamedAPIResource {
private:
    int id;
    std::string name;
    //Name names;
    //PokemonSpecies pokemonSpecies;

public:
    PokemonColor();
    ~PokemonColor();
};

class PokemonForm : public NamedAPIResource {
private:
    int id;
    std::string name;
    int order;
    int formOrder;
    bool isDefault;
    bool isBattleOnly;
    bool isMega;
    std::string formName;
    //Pokemon pokemon;
    //PokemonFormSprites sprites;
    //VersionGroup versionGroup;
    //Name names;
    //Name formNames;

public:
    PokemonForm();
    ~PokemonForm();
};

class PokemonFormSprites {
private:
    std::string frontDefault;
    std::string frontShiny;
    std::string backDefault;
    std::string backShiny;

public:
    PokemonFormSprites();
    ~PokemonFormSprites();
};

class PokemonHabitat : public NamedAPIResource {
private:
    int id;
    std::string name;
    //Name names;
    //PokemonSpecies pokemonSpecies;

public:
    PokemonHabitat();
    ~PokemonHabitatI();
};

class PokemonShape : public NamedAPIResource {
private:
    int id;
    std::string name;
    //AwesomeName awesomeNames;
    //Name names;
    //PokemonSpecies pokemonSpecies;

public:
    PokemonShape();
    ~PokemonShape();
};

class AwesomeName {
private:
    std::string awesomeName;
    //Language language;

public:
    AwesomeName();
    ~AwesomeName();
};

class PokemonSpecies : public NamedAPIResource {
private:
    int id;
    std::string name;
    int order;
    int genderRate;
    int captureRate;
    int baseHappiness;
    bool isBaby;
    int hatchCounter;
    bool hasGenderDifferences;
    bool formsSwitchable;
    //GrowthRate growthRate;
    //DexEntry pokedexNumbers;
    //EggGroup eggGroups;
    //PokemonColor color;
    //PokemonShape shape;
    //PokemonSpecies evolvesFromSpecies;
    //EvolutionChain evolutionChain;
    //PokemonHabitat habitat;
    //Generation generation;
    //Name names;
    //PalParkEncounterArea palParkEncounters;
    //FlavorText flavorTextEntries;
    //Description formDescriptions;
    //Genus genera;
    //PokemonSpeciesVariety varieties;

public:
    PokemonSpecies();
    ~PokemonSpecies();
};

class Genus {
private:
    std::string genus;
    //Language language;
public:
    Genus;
    ~Genus;
};

class PokemonSpeciesDexEntry {
private:
    int entryNumber;
    //Pokedex pokedex;

public:
    PokemonSpeciesDexEntry();
    ~PokemonSpeciesDexEntry();
};

class PalParkEncounterArea {
private:
    int baseScore;
    int rate;
    //PalParkArea area;

public:
    PalParkEncounterArea();
    ~PalParkEncounterArea();
};

class PokemonSpeciesVariety {
private:
    bool isDefault;
    //Pokemon pokemon;

public:
    PokemonSpeciesVariety();
    ~PokemonSpeciesVariety();
};

class Stat : public NamedAPIResource {
private:
    int id;
    std::string name;
    int gameIndex;
    bool isBattleOnly;
    //MoveStatAffectSets affectingMoves;
    //NatureStatAffectSets affectingNatures;
    //Characteristic characteristics;
    //MoveDamageClass moveDamageClass;
    //Name names;

public:
    Stat();
    ~Stat();
};

class MoveStatAffectSets {
private:
    //MoveStatAffect increase;
    //MoveStatAffect decrease;

public:
    MoveStatAffectSets();
    ~MoveStatAffectSets();
};

class MoveStatAffect {
private:
    int change;
    //Move move;

public:
    MoveStatAffect();
    ~MoveStatAffect();
};

class NatureStatAffectSets {
private:
    //Nature increase;
    //Nature decrease;

public:
    NatureStatAffectSets();
    ~NatureStatAffectSets();
};

class Type : public NamedAPIResource {
private:
    int id;
    std::string name;
    //TypeRelations damageRelations;
    //GenerationGameIndex gameIndices;
    //Generation generation;
    //MoveDamageClass moveDamageClass;
    //Name names;
    //TypePokemon pokemon;
    //Move moves;

public:
    Type();
    ~Type();
};

class TypePokemon {
private:
    int slot;
    Pokemon pokemon;

public:
    TypePokemon();
    ~TypePokemon();
};

class TypeRelations {
private:
    Type noDamageTo;
    Type halfDamageTo;
    Type doubleDamageTo;
    Type noDamageFrom;
    Type halfDamageFrom;
    Type doubleDamageFrom;

public:
    TypeRelations();
    ~TypeRelations();
};

#endif // POKEMON_H