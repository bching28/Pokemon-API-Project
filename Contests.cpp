#include "Contests.h"
#include "Requests.h"

ContestType::ContestType(std::string contestTypeName)
{
    Requests req;

    json parsedCT = req.retrieveJson("contest-type", contestTypeName);
    std::cout << "ParsedCT: " << parsedCT << std::endl << std::endl;

    id = parsedCT["id"];
    name = to_string(parsedCT["name"]);

    //TODO::make funciton to convert id int to name string
    
    json parsedBF = req.retrieveJson("berry-flavor", parsedCT["berry_flavor"]["name"]);
    std::cout << "ParsedBF: " << parsedBF << std::endl << std::endl;

    //TODO::Still need to fill in NamedAPIResource fields (i.e. name and url)
    berryFlavor = new BerryFlavor(parsedBF);
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