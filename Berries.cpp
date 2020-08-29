#include "Berries.h"
#include "Requests.h"

//BerryFlavor::BerryFlavor(std::string berryFlavorName, bool isFirstCall) {
//    if (isFirstCall) {
//        Requests req;
//        json parsedBF = req.retrieveJson("berry-flavor", berryFlavorName);
//
//        id = parsedBF["id"];
//        name = to_string(parsedBF["name"]);
//    
//        //contestType = new ContestType(parsedBF["contest_type"], isFirstCall, true);
//
//        isFirstCall = false;
//    }
//}

BerryFlavor::BerryFlavor(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    parsedBF = req.retrieveJson("berry-flavor", name); //spicy

    id = parsedBF["id"]; //1
    this->name = to_string(parsedBF["name"]); //spicy
    //contestType = new ContestType(parsedBF["contest_type"]);
    //id = 0;
    //this->name = "";
    contestType = NULL;

    dict = dict->getInstance();
}

BerryFlavor::BerryFlavor() {
    NamedAPIResource::name = "";
    NamedAPIResource::url = "";

    id = 0;
    name = "";
    contestType = NULL;
}

BerryFlavor::~BerryFlavor() {

}

int BerryFlavor::getId() {
    return id;
}

std::string BerryFlavor::getName() {
    return name;
}

ContestType BerryFlavor::getContestType() {
    //search dict by passing in name
    std::string ctName = parsedBF["contest_type"]["name"];
    std::string ctUrl = parsedBF["contest_type"]["url"];

    //if not found in dict
    if (dict->hasFoundKey("contest-type", ctName) == false) {
        // add to dictionary
        dict->setContestTypeDictEntry(ctName, ctUrl);
    }
    dict->printContestTypeMap();
    return dict->getContestTypeDictEntry(ctName);
}