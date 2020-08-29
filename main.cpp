/*
 * main.cpp
 *
 *  Created on: Jul 26, 2020
 *      Author: Bryan & Danny
 */

#include <nlohmann/json.hpp>
#include "PokeWrap.h"
#include <typeinfo>

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
    std::string testBerryResponse = pw.berry(berryName);
    ContestType testContestResponse = pw.contestType("cool");
    BerryFlavor testBerryFlavorResponse = pw.berryFlavor("spicy");

    json j = json::parse(testPokemonResponse);

    std::cout << "Parsed abilities: " << std::endl;
    for (auto& abilities : j["abilities"]) {
        std::cout << abilities["ability"]["name"] << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Berry Response: " << std::endl << testBerryResponse << std::endl;

    std::cout << std::endl << "------------------------------------------------------------" << std::endl;

    std::cout << "Contest Type Name Response: " << std::endl << testContestResponse.getName() << std::endl;

    std::cout << "Contest Type Names List Response: " << std::endl << testContestResponse.getContestName(0).getLanguage().getUtilityName(1).getLanguage().getName() << std::endl;
    std::cout << "Contest Type Names List Response: " << std::endl << testContestResponse.getContestName(1).getLanguage().getUtilityName(2).getLanguage().getName() << std::endl;

    std::cout << std::endl;

    std::cout << "Contest Type Response for BerryFlavor ID: " << std::endl << testContestResponse.getBerryFlavor().getId() << std::endl;
    std::cout << "Contest Type Response for BerryFlavor Name: " << std::endl << testContestResponse.getBerryFlavor().getName() << std::endl;

    std::cout << std::endl;

    std::cout << "BF->CT: " << std::endl << testContestResponse.getBerryFlavor().getContestType().getName() << std::endl;
    std::cout << "BF->CT->BF: " << std::endl << testContestResponse.getBerryFlavor().getContestType().getBerryFlavor().getName() << std::endl;

    std::cout << std::endl << "------------------------------------------------------------" << std::endl;

    std::cout << "Berry Flavor Response: " << std::endl << testBerryFlavorResponse.getName() << std::endl;

    std::cout << "Berry Flavor Response for ContestType ID: " << std::endl << testBerryFlavorResponse.getContestType().getId() << std::endl;
    std::cout << "Berry Flavor Response for ContetType Name: " << std::endl << testBerryFlavorResponse.getContestType().getName() << std::endl;

    std::cout << std::endl;

    std::cout << "CT->BF: " << std::endl << testBerryFlavorResponse.getContestType().getBerryFlavor().getName() << std::endl;
    std::cout << "CT->BF->CT: " << std::endl << testBerryFlavorResponse.getContestType().getBerryFlavor().getContestType().getName() << std::endl;


    /*for (int i = 0; i < 2; i++) {
        std::cout << "Contest Type - Contest Name Name: " << testContestResponse.getContestName(i).getName() << std::endl;
        std::cout << "Contest Type - Contest Name Color: " << testContestResponse.getContestName(i).getColor() << std::endl;
        std::cout << "Contest Type - Contest Name Language - ID: " << testContestResponse.getContestName(i).getLanguage().getId() << std::endl;
        std::cout << "Contest Type - Contest Name Language - Name: " << testContestResponse.getContestName(i).getLanguage().getName() << std::endl;
    }*/

    std::cout << "Done" << std::endl;

    return 0;
}
