#include "Moves.h"
#include "../Requests.h"

// Moves
// -------------------------------------------------------------------------
// Constructor
Move::Move(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    parsedJson = req.retrieveJson("move", name);

    dict = dict->getInstance();

    id = parsedJson["id"];
    name = to_string(parsedJson["name"]);
    accuracy = parsedJson["accuracy"];
    effectChance = parsedJson["effect_chance"];
    pp = parsedJson["pp"];
    priority = parsedJson["priority"];
    power = parsedJson["power"];

    /*for (auto& flavorTextEntry : parsedM["flavor_text_entries"]) {
        flavorTextEntries.push_back(new FlavorText(flavorTextEntry));
    }

    for (auto& move : parsedM["moves"]) {
        moves.push_back(new Move(move["name"], move["url"]));
    }*/
}

Move::~Move() {

}