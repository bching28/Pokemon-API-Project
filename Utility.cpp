#include "Utility.h"
#include "Requests.h"

Language::Language(std::string languageName, bool isFirstTime) {
    Requests req;
    json parsedL = req.retrieveJson("language", languageName);
    std::cout << "Parsed Language: " << parsedL << std::endl << std::endl;

    id = parsedL["id"];
    name = parsedL["name"];
    official = parsedL["official"];
    iso639 = parsedL["iso639"];
    iso3166 = parsedL["iso3166"];

    for (auto& languageName : parsedL["names"]) {
        if (isFirstTime) {
            std::cout << languageName << std::endl;
            isFirstTime = false;
            names.push_back(new Name(languageName, isFirstTime));
        }
    }
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


// Name
Name::Name(json nameName, bool isFirstTime) {
    name = nameName["name"];
    language = new Language(nameName["language"]["name"], isFirstTime);
}

Name::~Name() {}