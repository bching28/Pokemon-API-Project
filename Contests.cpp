#include "Contests.h"
#include "Requests.h"

ContestType::ContestType(json contestType) :
    id(contestType["id"]),
    name(contestType["name"]),
    berryFlavor(NULL)
    //berryFlavor(&contestType["berry_flavor"])
{
    //TODO::make funciton to convert id int to name string
    std::string berryFlavorResponse = retrieveHTTPResponse("https://pokeapi.co/api/v2/berry-flavor/1/"); // currently hard coded...rowap == 1
    json parsedBF = json::parse(berryFlavorResponse);
    std::cout << "ParsedBF: " << parsedBF << std::endl;

    BerryFlavor bf(parsedBF);
    berryFlavor = &bf;
}

ContestType::~ContestType() {

}

//TODO::the HTTP requests will probably need to be moved out of PokeWrap
// into the Requests class?
std::string ContestType::retrieveHTTPResponse(std::string url) {
    Requests req;
    int curlReturnStatus = 0;
    curlReturnStatus = req.createConnection(url);
    if (curlReturnStatus != 0) {
        return "Connection Failed.";
    }
    return req.getResponse();
}