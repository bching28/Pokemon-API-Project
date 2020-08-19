#include "Berries.h"
#include "Requests.h"

BerryFlavor::BerryFlavor(std::string berryFlavorName, bool isFirstCall)
{
    if (isFirstCall) {
        Requests req;
        json parsedBF = req.retrieveJson("berry-flavor", berryFlavorName);

        id = parsedBF["id"];
        name = to_string(parsedBF["name"]);
    
        //contestType = new ContestType(parsedBF["contest_type"], isFirstCall, true);

        isFirstCall = false;
    }
}

BerryFlavor::~BerryFlavor() {

}

int BerryFlavor::getId() {
    return id;
}

std::string BerryFlavor::getName() {
    return name;
}