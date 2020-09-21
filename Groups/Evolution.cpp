#include "Evolution.h"
#include "../Requests.h"

EvolutionChain::EvolutionChain(int id, std::string url) {
    APIResource::url = url;

    Requests req;
    parsedJson = req.retrieveJson("evolution-chain", id);

    dict = dict->getInstance();

    this->id = parsedJson["id"];

}

EvolutionChain::~EvolutionChain() {

}

int EvolutionChain::getId() {
    return this->id;
}

Item* EvolutionChain::getBabyTriggerItem() {
    std::string name;
    std::string url;

    // determine if field is NULL
    if (parsedJson["baby_trigger_item"].is_null()) {
        return NULL;
    }
    else {
        name = to_string(parsedJson["baby_trigger_item"]["name"]);
        url = to_string(parsedJson["baby_trigger_item"]["url"]);
    }

    //if not found in dict
    if (dict->hasFoundKey("item", name) == false) {
        // add to dictionary
        dict->setItemDictEntry(name, url);
    }

    return dict->getItemDictEntry(name);
}

