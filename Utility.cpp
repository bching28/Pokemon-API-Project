#include "Utility.h"
#include "Requests.h"

Language::Language(std::string name, std::string url) {
    NamedAPIResource::name = name;
    NamedAPIResource::url = url;

    Requests req;
    parsedL = req.retrieveJson("language", name);

    id = parsedL["id"];
    this->name = to_string(parsedL["name"]);
    official = parsedL["official"];
    iso639 = to_string(parsedL["iso639"]);
    iso3166 = to_string(parsedL["iso3166"]);

    for (auto& name : parsedL["names"]) {
        names.push_back(new Name(name));
    }

    dict = dict->getInstance();
}

Language::~Language() {}

int Language::getId() {
    return id;
}

std::string Language::getName() {
    return name;
}

bool Language::getOfficial() {
    return official;
}

std::string Language::getIso639() {
    return iso639;
}

std::string Language::getIso3166() {
    return iso3166;
}

Name Language::getNames(int index) {
    return *(names.at(index));
}


// Name
Name::Name(json nameJson) {
    parsedN = nameJson;
    name = to_string(nameJson["name"]);
    language = NULL;
    dict = dict->getInstance();
}

Name::~Name() {}

std::string Name::getName() {
    return name;
}

Language Name::getLanguage() {
    //search dict by passing in name
    std::string lName = parsedN["language"]["name"];
    std::string lUrl = parsedN["language"]["url"];

    //if not found in dict
    if (dict->hasFoundKey("language", lName) == false) {
        // add to dictionary
        dict->setLanguageDictEntry(lName, lUrl);
    }

    return dict->getLanguageDictEntry(lName);
}