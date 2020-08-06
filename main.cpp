/*
 * main.cpp
 *
 *  Created on: Jul 26, 2020
 *      Author: Bryan
 */

#include <nlohmann/json.hpp>
#include "Requests.h"

using json = nlohmann::json;

//TODO::create APIResource class
//      - handles calling the URL

//TODO::create user interface class ("PokeWrap")
//      - user can just call a specific "endpoint" function

//TODO::create classes

int main() {
    std::cout << "Pokemon API Project...begin!" << std::endl;
    std::string pokemonUrl = "https://pokeapi.co/api/v2/pokemon/";
    int curlReturnStatus = 0;
    Requests req;
    
    std::string pokemonName;
    std::cout << "Enter a Pokemon name: ";
    getline(std::cin, pokemonName);
    std::cout << std::endl;

    pokemonUrl.append(pokemonName);

    curlReturnStatus = req.createConnection(pokemonUrl);
    if (curlReturnStatus != 0) {
        return -1;
    }

    std::cout << "Response: " << std::endl << req.getResponse() << std::endl << std::endl;

    auto j = json::parse(req.getResponse());

    std::cout << "Parsed abilities: " << std::endl;
    for (auto& abilities : j["abilities"]) {
        std::cout << abilities["ability"]["name"] << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Done" << std::endl;

    return 0;
}
