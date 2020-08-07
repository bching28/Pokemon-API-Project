/*
 * PokeWrap.h
 *
 *  Created on: August 06, 2020
 *      Author: Bryan & Danny
 */

#ifndef POKEWRAP_H
#define POKEWRAP_H

#include <iostream>
#include "Requests.h"

class PokeWrap {
private:
	std::string baseUrl = "https://pokeapi.co/api/v2/";

	std::string formatUrl(std::string endpoint, std::string name);
	std::string retrieveHTTPResponse(std::string url);

public:
	//PokeWrap();
	//~PokeWrap();

	// Berries
	std::string berry         (std::string berryName);
	std::string berryFirmness (std::string berryFirmnessName);
	std::string berryFlavor   (std::string berryFlavorName);

	// Contests
	std::string contestType        (std::string contestTypeName);
	std::string contestEffect      (std::string contestEffectName);
	std::string superContestEffect (std::string superContestEffectName);

	// Encounters
	std::string encounterMethod         (std::string encounterMethodName);
	std::string encounterCondition      (std::string encounterConditionName);
	std::string encounterConditionValue (std::string encounterConditionValueName);

	// Evolution
	std::string evolutionChain   (std::string evolutionChainName);
	std::string evolutionTrigger (std::string evolutionTriggerName);

	// Games
	std::string generation   (std::string generationName);
	std::string pokedex      (std::string pokedexName);
	std::string version      (std::string versionName);
	std::string versionGroup (std::string versionGroupName);

	// Items
	std::string item            (std::string itemName);
	std::string itemAttribute   (std::string itemAttributeName);
	std::string itemCategory    (std::string itemCategoryName);
	std::string itemFlingEffect (std::string itemFlingEffectName);
	std::string itemPocket      (std::string itemPocketName);

	// Locations
	std::string location     (std::string locationName);
	std::string locationArea (std::string locationAreaName);
	std::string palParkArea  (std::string palParkAreaName);
	std::string region       (std::string regionName);

	// Machines
	std::string machine (std::string machineName);

	// Moves
	std::string move            (std::string moveName);
	std::string moveAilment     (std::string moveAilmentName);
	std::string moveBattleStyle (std::string moveBattleStyleName);
	std::string moveCategory    (std::string moveCategoryName);
	std::string moveDamageClass (std::string moveDamageClassName);
	std::string moveLearnMethod (std::string moveLearnMethodName);
	std::string moveTarget      (std::string moveTargetName);

	// Pokemon
	std::string ability        (std::string abilityName);
	std::string characteristic (std::string characteristicName);
	std::string eggGroup       (std::string eggGroupName);
	std::string gender         (std::string genderName);
	std::string growthRate     (std::string growthRateName);
	std::string nature         (std::string natureName);
	std::string pokeathlonStat (std::string pokeathlonStatName);
	std::string pokemon        (std::string pokemonName);
	std::string pokemonColor   (std::string pokemonColorName);
	std::string pokemonForm    (std::string pokemonFormName);
	std::string pokemonHabitat (std::string pokemonHabitatName);
	std::string pokemonShape   (std::string pokemonShapeName);
	std::string pokemonSpecies (std::string pokemonSpeciesName);
	std::string stat           (std::string statName);
	std::string type           (std::string typeName);

	// Utility
	std::string language (std::string languageName);

};

#endif; // POKEWRAP_H