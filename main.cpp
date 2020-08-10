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

    json j = json::parse(testPokemonResponse);

    std::cout << "Parsed abilities: " << std::endl;
    for (auto& abilities : j["abilities"]) {
        std::cout << abilities["ability"]["name"] << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Berry Response: " << std::endl << testBerryResponse << std::endl;

    std::cout << std::endl;

    std::cout << "Contest Type Response: " << std::endl << testContestResponse.getName() << std::endl;

    std::cout << std::endl;

    std::cout << "Contest Type Response for BerryFlavor ID: " << std::endl << testContestResponse.getBerryFlavor().getId() << std::endl;
    std::cout << "Contest Type Response for BerryFlavor Name: " << std::endl << testContestResponse.getBerryFlavor().getName() << std::endl;

    std::cout << std::endl;

    std::cout << "Done" << std::endl;

    return 0;
}
