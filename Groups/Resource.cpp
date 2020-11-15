#include "Resource.h"

APIResource::APIResource() :
    url("") 
{

}

APIResource::~APIResource() {

}

NamedAPIResource::NamedAPIResource() :
    name(""), url("")
{

}

NamedAPIResource::~NamedAPIResource() {

}

// for testing
//TODO::move to another file that included in every endpoint file (e.g. Resource.h? or make a new file?)
int checkForNull(json parsedJson, std::string field) {
    if (parsedJson[field].is_null()) {
        return -1;
    }
    return parsedJson[field];
}