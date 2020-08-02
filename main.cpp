/*
 * main.cpp
 *
 *  Created on: Jul 26, 2020
 *      Author: Bryan
 */

#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

//TODO::create classes

//TODO::create "Requests" class and move curl functionality to that class
size_t writeFunction(char *data, size_t size, size_t data_size, std::string *writeData);
int initCurl(CURL *curl, std::string url, std::string *response, std::string *header);
int createConnection(std::string url, std::string *response, std::string *header, long *responseCode, double *elapsedTime);
int getCurlInfo(CURL *curl, long *responseCode, double *elapsedTime);

int main() {
    std::cout << "Pokemon API Project...begin!" << std::endl;

    std::string pokemonUrl = "https://pokeapi.co/api/v2/pokemon/";
    std::string response;
    std::string header;
    long responseCode;
    double elapsedTime;
    int curlReturnStatus = 0;

    std::string pokemonName;
    std::cout << "Enter a Pokemon name: ";
    getline(std::cin, pokemonName);
    std::cout << std::endl;

    pokemonUrl.append(pokemonName);

    curlReturnStatus = createConnection(pokemonUrl, &response, &header, &responseCode, &elapsedTime);
    if (curlReturnStatus != 0) {
        return -1;
    }

    std::cout << "Response: " << std::endl << response << std::endl;

    std::cout << "Done" << std::endl;

    return 0;
}

size_t writeFunction(char *rcvd_data, size_t size, size_t nmemb, std::string *userData) {
    userData->append(rcvd_data, size * nmemb);
    return size * nmemb;
}

int initCurl(CURL *curl, std::string url, std::string *response, std::string *header) {
    CURLcode ret_code;

    //TODO: place curl_easy_init() here

    ret_code = curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    if (ret_code != CURLE_OK) {
        std::cerr << "Failed to set up URL" << std::endl;
        return -1;
    }

    ret_code = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
    if (ret_code != CURLE_OK) {
        std::cerr << "Failed to set up data write function" << std::endl;
        return -1;
    }

    ret_code = curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
    if (ret_code != CURLE_OK) {
        std::cerr << "Failed to set up set up response buffer" << std::endl;
        return -1;
    }

    ret_code = curl_easy_setopt(curl, CURLOPT_HEADERDATA, header);
    if (ret_code != CURLE_OK) {
        std::cerr << "Failed to set up response header" << std::endl;
        return -1;
    }

    return 0;
}

int getCurlInfo(CURL *curl, long *responseCode, double *elapsedTime) {
    CURLcode ret_code;

    ret_code = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, responseCode);
    if (ret_code != CURLE_OK) {
        std::cerr << "Failed to set up response code retriever" << std::endl;
        return -1;
    }

    ret_code = curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, elapsedTime);
    if (ret_code != CURLE_OK) {
        std::cerr << "Failed to set up total elapsed time retriever" << std::endl;
        return -1;
    }

    return 0;
}

int createConnection(std::string url, std::string *response, std::string *header, long *responseCode, double *elapsedTime) {
    CURL *curl = NULL;
    CURLcode ret_code;
    int ret_status = 0;

    curl = curl_easy_init();
    if (curl == NULL) {
        std::cerr << "Failed to initialize curl" << std::endl;
        return -1;
    }

    ret_status = initCurl(curl, url, response, header);
    if (ret_status != 0) {
        return -1;
    }

    ret_code = curl_easy_perform(curl);
    if (ret_code != CURLE_OK) {
        std::cerr << "Failed to execute curl_easy_perform(): " << curl_easy_strerror(ret_code) << std::endl;
        return -1;
    }

    getCurlInfo(curl, responseCode, elapsedTime);

    curl_easy_cleanup(curl);

    return 0;
}
