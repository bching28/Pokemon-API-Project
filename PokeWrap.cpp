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

std::string PokeWrap::pokemon(std::string pokemonName) {
	std::string formattedUrl = formatUrl("pokemon", pokemonName);
	
	int curlReturnStatus = 0;
	req.createConnection(formattedUrl);
	if (curlReturnStatus != 0) {
		return "Connection failed";
	}

	return req.getResponse();
}