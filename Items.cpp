#include "Items.h"
#include "Requests.h"
#include <typeinfo>

// Item
// -------------------------------------------------------------------------
// Constructor
Item::Item(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    parsedI = req.retrieveJson("item", name);

    dict = dict->getInstance();

    this->id = parsedI["id"];
    this->name = to_string(parsedI["name"]);
    this->cost = parsedI["cost"];
    
    if (parsedI["fling_power"].is_null()) {
        this->flingPower = NULL;
    } else {
        this->flingPower = parsedI["fling_power"];
    }
}

Item::~Item() {

}

ItemFlingEffect* Item::getFlintEffect() {
    std::string feName;
    std::string feUrl;

    if (parsedI["fling_effect"].is_null()) {
        return NULL;
    } else {
        //search dict by passing in name
        feName = to_string(parsedI["fling_effect"]["name"]);
        feUrl = to_string(parsedI["fling_effect"]["url"]);
    }

    //if not found in dict
    if (dict->hasFoundKey("item-fling-effect", feName) == false) {
        // add to dictionary
        dict->setItemFlingEffectDictEntry(feName, feUrl);
    }

    return dict->getItemFlingEffectDictEntry(feName);
}

// Item Fling Effect
// -------------------------------------------------------------------------
// Constructor
ItemFlingEffect::ItemFlingEffect(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    parsedIFE = req.retrieveJson("item-fling-effect", name);

    dict = dict->getInstance();

    this->id = parsedIFE["id"];
    this->name = to_string(parsedIFE["name"]);
}

ItemFlingEffect::~ItemFlingEffect() {

}

std::string ItemFlingEffect::getName() {
    return this->name;
}
