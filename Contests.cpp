#include "Contests.h"
#include "Requests.h"
//#include "Dictionary.h"

//ContestType::ContestType(std::string contestTypeName, bool isFirstCall) {
//    if (isFirstCall) {
//        Requests req;
//
//        //TODO::make a file that has variables for all the endpoints
//        json parsedCT = req.retrieveJson("contest-type", contestTypeName);
//
//        id = parsedCT["id"];
//        name = to_string(parsedCT["name"]);
//
//        //TODO::make funciton to convert id int to name string
//
//        //TODO::Still need to fill in NamedAPIResource fields (i.e. name and url)
//        //berryFlavor = new BerryFlavor(parsedCT["berry_flavor"]["name"], isFirstCall);
//        berryFlavor = NULL;
//
//        for (auto& contestName : parsedCT["names"]) {
//            names.push_back(new ContestName(contestName, isFirstCall));
//        }
//    }
//}

ContestType::ContestType(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    parsedCT = req.retrieveJson("contest-type", name); //cool

    id = parsedCT["id"];
    this->name = to_string(parsedCT["name"]);
    std::string bfName = parsedCT["berry_flavor"]["name"];
    //berryFlavor = new BerryFlavor(parsedCT["berry_flavor"]["name"], parsedCT["berry_flavor"]["url"]);
    berryFlavor = NULL;
    //names = NULL;
    dict = dict->getInstance();
}

ContestType::~ContestType() {
    //TODO::deallocated memory of dynamic variables
}

int ContestType::getId() {
    return id;
}

std::string ContestType::getName() {
    return name;
}

BerryFlavor ContestType::getBerryFlavor() {
    //search dict by passing in name
    std::string bfName = parsedCT["berry_flavor"]["name"];
    std::string bfUrl = parsedCT["berry_flavor"]["url"];

    //if not found in dict
    if (dict->hasFoundKey("berry-flavor", bfName) == false) {
        // add to dictionary
        //BerryFlavor* bf = new BerryFlavor(bfName, bfUrl);
        dict->setBerryFlavorDictEntry(bfName, bfUrl);
    }

    return dict->getBerryFlavorDictEntry(bfName);
}

ContestName ContestType::getContestName(int index) {
    return *(names.at(index));
}


// ContestName
ContestName::ContestName(json contestNameName, bool isFirstCall) {
    name = contestNameName["name"];
    color = contestNameName["color"];
    language = new Language(contestNameName["language"]["name"], isFirstCall);
}

ContestName::~ContestName() {}

std::string ContestName::getName() {
    return name;
}

std::string ContestName::getColor() {
    return color;
}

Language ContestName::getLanguage() {
    return *language;
}