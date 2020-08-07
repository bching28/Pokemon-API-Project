/*
 * main.cpp
 *
 *  Created on: Jul 26, 2020
 *      Author: Bryan & Danny
 */

#include <nlohmann/json.hpp>
#include "PokeWrap.h"

using json = nlohmann::json;

//TODO::create APIResource class
//      - handles calling the URL

//TODO::create user interface class ("PokeWrap")
//      - user can just call a specific "endpoint" function
//      PokeWrap pw --> pw.pokemon("charmander"); --> https://pokeapi.co/api/v2/pokemon/charmander

//TODO::create classes

int main() {
    std::cout << "Pokemon API Project...begin!" << std::endl;
    PokeWrap pw;
    
    std::string pokemonName;
    /*std::cout << "Enter a Pokemon name: ";
    getline(std::cin, pokemonName);
    std::cout << std::endl;*/
    pokemonName = "charmander";

    std::string testResponse = pw.pokemon(pokemonName);

    auto j = json::parse(testResponse);

    std::cout << "Parsed abilities: " << std::endl;
    for (auto& abilities : j["abilities"]) {
        std::cout << abilities["ability"]["name"] << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Done" << std::endl;

    return 0;
}
