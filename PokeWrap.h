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
	Requests req;
	std::string baseUrl = "https://pokeapi.co/api/v2/";

	std::string formatUrl(std::string endpoint, std::string name);

public:
	//PokeWrap();
	//~PokeWrap();
	std::string pokemon(std::string pokemonName);

};

#endif; // POKEWRAP_H