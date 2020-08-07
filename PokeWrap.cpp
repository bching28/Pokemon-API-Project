/*
 * PokeWrap.cpp
 *
 *  Created on: August 06, 2020
 *      Author: Bryan & Danny
 */

#include "PokeWrap.h"

std::string PokeWrap::formatUrl(std::string endpoint, std::string name) {
	return (baseUrl + endpoint + "/" + name);
}

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

std::string PokeWrap::berry(std::string berryName) {
	std::string formattedUrl = formatUrl("berry", berryName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::berryFirmness(std::string berryFirmnessName) {
	std::string formattedUrl = formatUrl("berry-firmness", berryFirmnessName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::berryFlavor(std::string berryFlavorName) {
	std::string formattedUrl = formatUrl("berry-flavor", berryFlavorName);

	return retrieveHTTPResponse(formattedUrl);
}

// Contests

std::string PokeWrap::contestType(std::string contestTypeName) {
	std::string formattedUrl = formatUrl("contest-type", contestTypeName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::contestEffect(std::string contestEffectName) {
	std::string formattedUrl = formatUrl("contest-effect", contestEffectName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::superContestEffect(std::string superContestEffectName) {
	std::string formattedUrl = formatUrl("super-contest-effect", superContestEffectName);

	return retrieveHTTPResponse(formattedUrl);
}

// Encounters

std::string PokeWrap::encounterMethod(std::string encounterMethodName) {
	std::string formattedUrl = formatUrl("encounter-method", encounterMethodName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::encounterCondition(std::string encounterConditionName) {
	std::string formattedUrl = formatUrl("encounter-condition", encounterConditionName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::encounterConditionValue(std::string encounterConditionValueName) {
	std::string formattedUrl = formatUrl("encounter-condition-value", encounterConditionValueName);

	return retrieveHTTPResponse(formattedUrl);
}

// Evolution

std::string PokeWrap::evolutionChain(std::string evolutionChainName) {
	std::string formattedUrl = formatUrl("evolution-chain", evolutionChainName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::evolutionTrigger(std::string evolutionTriggerName) {
	std::string formattedUrl = formatUrl("evolution-trigger", evolutionTriggerName);

	return retrieveHTTPResponse(formattedUrl);
}

// Games

std::string PokeWrap::generation(std::string generationName) {
	std::string formattedUrl = formatUrl("generation", generationName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::pokedex(std::string pokedexName) {
	std::string formattedUrl = formatUrl("pokedex", pokedexName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::version(std::string versionName) {
	std::string formattedUrl = formatUrl("version", versionName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::versionGroup(std::string versionGroupName) {
	std::string formattedUrl = formatUrl("version-group", versionGroupName);

	return retrieveHTTPResponse(formattedUrl);
}

// Items

std::string PokeWrap::item(std::string itemName) {
	std::string formattedUrl = formatUrl("item", itemName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::itemAttribute(std::string itemAttributeName) {
	std::string formattedUrl = formatUrl("item-attribute", itemAttributeName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::itemCategory(std::string itemCategoryName) {
	std::string formattedUrl = formatUrl("item-category", itemCategoryName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::itemFlingEffect(std::string itemFlingEffectName) {
	std::string formattedUrl = formatUrl("item-fling-effect", itemFlingEffectName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::itemPocket(std::string itemPocketName) {
	std::string formattedUrl = formatUrl("item-pocket", itemPocketName);

	return retrieveHTTPResponse(formattedUrl);
}

// Locations

std::string PokeWrap::location(std::string locationName) {
	std::string formattedUrl = formatUrl("location", locationName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::locationArea(std::string locationAreaName) {
	std::string formattedUrl = formatUrl("location-area", locationAreaName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::palParkArea(std::string palParkAreaName) {
	std::string formattedUrl = formatUrl("pal-park-area", palParkAreaName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::region(std::string regionName) {
	std::string formattedUrl = formatUrl("region", regionName);

	return retrieveHTTPResponse(formattedUrl);
}

// Machines

std::string PokeWrap::machine(std::string machineName) {
	std::string formattedUrl = formatUrl("machine", machineName);

	return retrieveHTTPResponse(formattedUrl);
}

// Moves

std::string PokeWrap::move(std::string moveName) {
	std::string formattedUrl = formatUrl("move", moveName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::moveAilment(std::string moveAilmentName) {
	std::string formattedUrl = formatUrl("move-ailment", moveAilmentName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::moveBattleStyle(std::string moveBattleStyleName) {
	std::string formattedUrl = formatUrl("move-battle-style", moveBattleStyleName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::moveCategory(std::string moveCategoryName) {
	std::string formattedUrl = formatUrl("move-category", moveCategoryName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::moveDamageClass(std::string moveDamageClassName) {
	std::string formattedUrl = formatUrl("move-damage-class", moveDamageClassName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::moveLearnMethod(std::string moveLearnMethodName) {
	std::string formattedUrl = formatUrl("move-learn-method", moveLearnMethodName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::moveTarget(std::string moveTargetName) {
	std::string formattedUrl = formatUrl("move-target", moveTargetName);

	return retrieveHTTPResponse(formattedUrl);
}

// Pokemon

std::string PokeWrap::ability(std::string abilityName) {
	std::string formattedUrl = formatUrl("ability", abilityName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::characteristic(std::string characteristicName) {
	std::string formattedUrl = formatUrl("characteristic", characteristicName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::eggGroup(std::string eggGroupName) {
	std::string formattedUrl = formatUrl("egg-group", eggGroupName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::gender(std::string genderName) {
	std::string formattedUrl = formatUrl("gender", genderName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::growthRate(std::string growthRateName) {
	std::string formattedUrl = formatUrl("growth-rate", growthRateName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::nature(std::string natureName) {
	std::string formattedUrl = formatUrl("nature", natureName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::pokeathlonStat(std::string pokeathlonStatName) {
	std::string formattedUrl = formatUrl("pokeathlon-stat", pokeathlonStatName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::pokemon(std::string pokemonName) {
	std::string formattedUrl = formatUrl("pokemon", pokemonName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::pokemonColor(std::string pokemonColorName) {
	std::string formattedUrl = formatUrl("pokemon-color", pokemonColorName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::pokemonForm(std::string pokemonFormName) {
	std::string formattedUrl = formatUrl("pokemon-form", pokemonFormName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::pokemonHabitat(std::string pokemonHabitatName) {
	std::string formattedUrl = formatUrl("pokemon-habitat", pokemonHabitatName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::pokemonShape(std::string pokemonShapeName) {
	std::string formattedUrl = formatUrl("pokemon-shape", pokemonShapeName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::pokemonSpecies(std::string pokemonSpeciesName) {
	std::string formattedUrl = formatUrl("pokemon-species", pokemonSpeciesName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::stat(std::string statName) {
	std::string formattedUrl = formatUrl("stat", statName);

	return retrieveHTTPResponse(formattedUrl);
}

std::string PokeWrap::type(std::string typeName) {
	std::string formattedUrl = formatUrl("type", typeName);

	return retrieveHTTPResponse(formattedUrl);
}

// Languages

std::string PokeWrap::language(std::string languageName) {
	std::string formattedUrl = formatUrl("language", languageName);

	return retrieveHTTPResponse(formattedUrl);
}
