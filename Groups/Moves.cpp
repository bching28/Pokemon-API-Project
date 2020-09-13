#include "Moves.h"
#include "../Requests.h"

// Moves
// -------------------------------------------------------------------------
// Constructor
Move::Move(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    parsedM = req.retrieveJson("move", name);

    id = parsedM["id"];
    name = to_string(parsedM["name"]);
    accuracy = parsedM["accuracy"];
    effectChance = parsedM["effect_chance"];
    pp = parsedM["pp"];
    priority = parsedM["priority"];
    power = parsedM["power"];

    /*for (auto& flavorTextEntry : parsedM["flavor_text_entries"]) {
        flavorTextEntries.push_back(new FlavorText(flavorTextEntry));
    }

    for (auto& move : parsedM["moves"]) {
        moves.push_back(new Move(move["name"], move["url"]));
    }*/

    dict = dict->getInstance();
}

Move::~Move() {

}