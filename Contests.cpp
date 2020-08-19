#include "Contests.h"
#include "Requests.h"

ContestType::ContestType(std::string contestTypeName, bool isFirstCall) {
    if (isFirstCall) {
        Requests req;

        //TODO::make a file that has variables for all the endpoints
        json parsedCT = req.retrieveJson("contest-type", contestTypeName);

        id = parsedCT["id"];
        name = to_string(parsedCT["name"]);

        //TODO::make funciton to convert id int to name string

        //TODO::Still need to fill in NamedAPIResource fields (i.e. name and url)
        berryFlavor = new BerryFlavor(parsedCT["berry_flavor"]["name"], isFirstCall);

        for (auto& contestName : parsedCT["names"]) {
            names.push_back(new ContestName(contestName, isFirstCall));
        }
    }
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
    return *berryFlavor;
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