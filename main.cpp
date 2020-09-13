/*
 * main.cpp
 *
 *  Created on: Jul 26, 2020
 *      Author: Bryan & Danny
 */

#include <nlohmann/json.hpp>
#include "PokeWrap.h"
#include <typeinfo>
#include "Dictionary.h"

using json = nlohmann::json;

//TODO::create Endpoint classes
//      -- resource: https://pokeapi.co/docs/v2
//      -- Each Category will have its own file
//      -- Each file will have that Cateogry's Endpoint classes 
//         (e.g. Contest.cpp/.h contains ContestType, ContestEffects, SuperContestEffects)

//TODO::move "*" for pointers to be attached to object type and not the variables

int main() {
    std::cout << "Pokemon API Project...begin!" << std::endl;
    PokeWrap pw;
    
    std::string pokemonName;
    std::string berryName;
    /*std::cout << "Enter a Pokemon name: ";
    getline(std::cin, pokemonName);
    std::cout << std::endl;*/
    pokemonName = "charmander";
    berryName = "chesto";

    std::string testPokemonResponse = pw.pokemon(pokemonName);
    Berry testBerryResponse = pw.berry(berryName);
    ContestType testContestResponse = pw.contestType("cool");
    Item testItemResponse = pw.item("master-ball");
    BerryFlavor testBerryFlavorResponse = pw.berryFlavor("spicy");
    BerryFirmness testBerryFirmnessResponse = pw.berryFirmness("very-soft");
    EncounterCondition testEncounterConditionResponse = pw.encounterCondition("swarm");

    json j = json::parse(testPokemonResponse);

    std::cout << "Parsed abilities: " << std::endl;
    for (auto& abilities : j["abilities"]) {
        std::cout << abilities["ability"]["name"] << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Berry Response Name: " << std::endl << testBerryResponse.getName() << std::endl;
    std::cout << "Berry Response for BerryFlavorMap BerryFlavor ContestType Name: " << std::endl << testBerryResponse.getFlavors(0).getFlavor().getContestType().getName() << std::endl;


    std::cout << std::endl << "------------------------------------------------------------" << std::endl;

    std::cout << "Contest Type Name: " << std::endl << testContestResponse.getName() << std::endl;

    std::cout << "Contest Type Names List Response: " << std::endl << testContestResponse.getContestName(0).getLanguage().getNames(1).getLanguage().getName() << std::endl;
    std::cout << "Contest Type Names List Response: " << std::endl << testContestResponse.getContestName(1).getLanguage().getNames(2).getLanguage().getName() << std::endl;

    std::cout << std::endl;

    std::cout << "Contest Type Response for BerryFlavor ID: " << std::endl << testContestResponse.getBerryFlavor().getId() << std::endl;
    std::cout << "Contest Type Response for BerryFlavor Name: " << std::endl << testContestResponse.getBerryFlavor().getName() << std::endl;

    std::cout << std::endl;

    std::cout << "BF->CT: " << std::endl << testContestResponse.getBerryFlavor().getContestType().getName() << std::endl;
    std::cout << "BF->CT->BF: " << std::endl << testContestResponse.getBerryFlavor().getContestType().getBerryFlavor().getName() << std::endl;

    std::cout << std::endl << "------------------------------------------------------------" << std::endl << "Berry Flavor" << std::endl;

    std::cout << "Berry Flavor Name: " << std::endl << testBerryFlavorResponse.getName() << std::endl;

    std::cout << "Berry Flavor Response for ContestType ID: " << std::endl << testBerryFlavorResponse.getContestType().getId() << std::endl;
    std::cout << "Berry Flavor Response for ContetType Name: " << std::endl << testBerryFlavorResponse.getContestType().getName() << std::endl;
    std::cout << "Berry Flavor Response Name->Language: " << std::endl << testBerryFlavorResponse.getNames(0).getLanguage().getName() << std::endl;

    std::cout << std::endl;

    std::cout << "CT->BF: " << std::endl << testBerryFlavorResponse.getContestType().getBerryFlavor().getName() << std::endl;
    std::cout << "CT->BF->CT: " << std::endl << testBerryFlavorResponse.getContestType().getBerryFlavor().getContestType().getName() << std::endl;
    std::cout << "CT->BF->CT->BF: " << std::endl << testBerryFlavorResponse.getContestType().getBerryFlavor().getContestType().getBerryFlavor().getName() << std::endl;

    std::cout << std::endl << "------------------------------------------------------------" << std::endl << "Encounter Condition" << std::endl;

    std::cout << "EncounterCondition Values[0] Name:" << std::endl << testEncounterConditionResponse.getValues(0).getName() << std::endl;
    std::cout << "EncounterCondition Values[1] Name:" << std::endl << testEncounterConditionResponse.getValues(1).getName() << std::endl;
    std::cout << "EncounterCondition Values[0] Condition Name:" << std::endl << testEncounterConditionResponse.getValues(0).getCondition().getName() << std::endl;
    std::cout << "EncounterCondition Values[1] Condition Name:" << std::endl << testEncounterConditionResponse.getValues(1).getCondition().getName() << std::endl;

    //std::cout << "Get Fling Effect Name: " << std::endl << testItemResponse.getFlintEffect().getName() << std::endl;

    std::cout << "Done" << std::endl;

    Dictionary* dict;
    dict = dict->getInstance();
    dict->terminate();
     
    return 0;
}
