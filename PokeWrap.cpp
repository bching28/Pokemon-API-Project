/*
 * PokeWrap.cpp
 *
 *  Created on: August 06, 2020
 *      Author: Bryan & Danny
 */

#include <nlohmann/json.hpp>
#include "PokeWrap.h"

 // Constructor
PokeWrap::PokeWrap() : baseUrl("https://pokeapi.co/api/v2/") {}

// Destructor
PokeWrap::~PokeWrap() {}

std::string PokeWrap::retrieveHTTPResponse(std::string url) {
	Requests req;
	int curlReturnStatus = 0;
	curlReturnStatus = req.createConnection(url);
	if (curlReturnStatus != 0) {
		return "Connection Failed.";
	}
	return req.getResponse();
}

// Berries

Berry PokeWrap::berry(std::string berryName) {
	std::string formattedUrl = req.formatUrl("berry", berryName);

	Berry berry(berryName, formattedUrl);

	return berry;
}

BerryFirmness PokeWrap::berryFirmness(std::string berryFirmnessName) {
	std::string formattedUrl = req.formatUrl("berry-firmness", berryFirmnessName);

	BerryFirmness berryFirmness(berryFirmnessName, formattedUrl);

	return berryFirmness;
}

BerryFlavor PokeWrap::berryFlavor(std::string berryFlavorName) {
	std::string formattedUrl = req.formatUrl("berry-flavor", berryFlavorName);

	BerryFlavor berryFlavor(berryFlavorName, formattedUrl); // 1 == spicy

	return berryFlavor;
}

// Contests

ContestType PokeWrap::contestType(std::string contestTypeName) {
	//bool isFirstCall = true;
	//TODO::Still need to fill in NamedAPIResource fields (i.e. name and url)
	//ContestType contestType(contestTypeName, true);
	ContestType contestType(contestTypeName, "https://pokeapi.co/api/v2/contest-type/1"); // 1 == cool

	return contestType;
}

ContestEffect PokeWrap::contestEffect(int contestEffectId) {

	std::string formattedUrl = req.formatUrl("contest-effect", contestEffectId);

	ContestEffect contestEffect(contestEffectId, formattedUrl);

	return contestEffect;
}

std::string PokeWrap::superContestEffect(std::string superContestEffectName) {
	std::string formattedUrl = req.formatUrl("super-contest-effect", superContestEffectName);

	return retrieveHTTPResponse(formattedUrl);
}

// Encounters

EncounterMethod PokeWrap::encounterMethod(std::string encounterMethodName) {
	std::string formattedUrl = req.formatUrl("encounter-method", encounterMethodName);

	EncounterMethod encounterMethod(encounterMethodName, formattedUrl);

	return encounterMethod;
}

EncounterCondition PokeWrap::encounterCondition(std::string encounterConditionName) {
	std::string formattedUrl = req.formatUrl("encounter-condition", encounterConditionName);

	EncounterCondition encounterCondition(encounterConditionName, formattedUrl);

	return encounterCondition;
}

EncounterConditionValue PokeWrap::encounterConditionValue(std::string encounterConditionValueName) {
	std::string formattedUrl = req.formatUrl("encounter-condition-value", encounterConditionValueName);

	EncounterConditionValue encounterConditionValue(encounterConditionValueName, formattedUrl);

	return encounterConditionValue;
}

// Evolution

EvolutionChain PokeWrap::evolutionChain(int evolutionChainId) {
	std::string formattedUrl = req.formatUrl("evolution-chain", evolutionChainId);

	EvolutionChain evolutionChain(evolutionChainId, formattedUrl);

	return evolutionChain;
}

std::string PokeWrap::evolutionTrigger(std::string evolutionTriggerName) {
	std::string formattedUrl = req.formatUrl("evolution-trigger", evolutionTriggerName);

	return retrieveHTTPResponse(formattedUrl);
}

// Games

std::string PokeWrap::generation(std::string generationName) {
	std::string formattedUrl = req.formatUrl("generation", generationName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::pokedex(std::string pokedexName) {
	std::string formattedUrl = req.formatUrl("pokedex", pokedexName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::version(std::string versionName) {
	std::string formattedUrl = req.formatUrl("version", versionName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::versionGroup(std::string versionGroupName) {
	std::string formattedUrl = req.formatUrl("version-group", versionGroupName);

	return retrieveHTTPResponse(formattedUrl);
}

// Items

Item PokeWrap::item(std::string itemName) {
	std::string formattedUrl = req.formatUrl("item", itemName);

	Item item(itemName, formattedUrl);

	return item;
}

std::string PokeWrap::itemAttribute(std::string itemAttributeName) {
	std::string formattedUrl = req.formatUrl("item-attribute", itemAttributeName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::itemCategory(std::string itemCategoryName) {
	std::string formattedUrl = req.formatUrl("item-category", itemCategoryName);

	return retrieveHTTPResponse(formattedUrl);
}

ItemFlingEffect PokeWrap::itemFlingEffect(std::string itemFlingEffectName) {
	std::string formattedUrl = req.formatUrl("item-fling-effect", itemFlingEffectName);

	ItemFlingEffect itemFlingEffect(itemFlingEffectName, formattedUrl);

	return itemFlingEffect;
}

std::string PokeWrap::itemPocket(std::string itemPocketName) {
	std::string formattedUrl = req.formatUrl("item-pocket", itemPocketName);

	return retrieveHTTPResponse(formattedUrl);
}

// Locations

std::string PokeWrap::location(std::string locationName) {
	std::string formattedUrl = req.formatUrl("location", locationName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::locationArea(std::string locationAreaName) {
	std::string formattedUrl = req.formatUrl("location-area", locationAreaName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::palParkArea(std::string palParkAreaName) {
	std::string formattedUrl = req.formatUrl("pal-park-area", palParkAreaName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::region(std::string regionName) {
	std::string formattedUrl = req.formatUrl("region", regionName);

	return retrieveHTTPResponse(formattedUrl);
}

// Machines

std::string PokeWrap::machine(std::string machineName) {
	std::string formattedUrl = req.formatUrl("machine", machineName);

	return retrieveHTTPResponse(formattedUrl);
}

// Moves

std::string PokeWrap::move(std::string moveName) {
	std::string formattedUrl = req.formatUrl("move", moveName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::moveAilment(std::string moveAilmentName) {
	std::string formattedUrl = req.formatUrl("move-ailment", moveAilmentName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::moveBattleStyle(std::string moveBattleStyleName) {
	std::string formattedUrl = req.formatUrl("move-battle-style", moveBattleStyleName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::moveCategory(std::string moveCategoryName) {
	std::string formattedUrl = req.formatUrl("move-category", moveCategoryName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::moveDamageClass(std::string moveDamageClassName) {
	std::string formattedUrl = req.formatUrl("move-damage-class", moveDamageClassName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::moveLearnMethod(std::string moveLearnMethodName) {
	std::string formattedUrl = req.formatUrl("move-learn-method", moveLearnMethodName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::moveTarget(std::string moveTargetName) {
	std::string formattedUrl = req.formatUrl("move-target", moveTargetName);

	return retrieveHTTPResponse(formattedUrl);
}

// Pokemon

std::string PokeWrap::ability(std::string abilityName) {
	std::string formattedUrl = req.formatUrl("ability", abilityName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::characteristic(std::string characteristicName) {
	std::string formattedUrl = req.formatUrl("characteristic", characteristicName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::eggGroup(std::string eggGroupName) {
	std::string formattedUrl = req.formatUrl("egg-group", eggGroupName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::gender(std::string genderName) {
	std::string formattedUrl = req.formatUrl("gender", genderName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::growthRate(std::string growthRateName) {
	std::string formattedUrl = req.formatUrl("growth-rate", growthRateName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::nature(std::string natureName) {
	std::string formattedUrl = req.formatUrl("nature", natureName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::pokeathlonStat(std::string pokeathlonStatName) {
	std::string formattedUrl = req.formatUrl("pokeathlon-stat", pokeathlonStatName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::pokemon(std::string pokemonName) {
	std::string formattedUrl = req.formatUrl("pokemon", pokemonName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::pokemonColor(std::string pokemonColorName) {
	std::string formattedUrl = req.formatUrl("pokemon-color", pokemonColorName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::pokemonForm(std::string pokemonFormName) {
	std::string formattedUrl = req.formatUrl("pokemon-form", pokemonFormName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::pokemonHabitat(std::string pokemonHabitatName) {
	std::string formattedUrl = req.formatUrl("pokemon-habitat", pokemonHabitatName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::pokemonShape(std::string pokemonShapeName) {
	std::string formattedUrl = req.formatUrl("pokemon-shape", pokemonShapeName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::pokemonSpecies(std::string pokemonSpeciesName) {
	std::string formattedUrl = req.formatUrl("pokemon-species", pokemonSpeciesName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::stat(std::string statName) {
	std::string formattedUrl = req.formatUrl("stat", statName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::type(std::string typeName) {
	std::string formattedUrl = req.formatUrl("type", typeName);

	return retrieveHTTPResponse(formattedUrl);
}

// Languages

std::string PokeWrap::language(std::string languageName) {
	std::string formattedUrl = req.formatUrl("language", languageName);

	return retrieveHTTPResponse(formattedUrl);
}
