/*
 * main.cpp
 *
 *  Created on: Jul 26, 2020
 *      Author: Bryan
 */


#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

size_t write_function(char *data, size_t size, size_t data_size, std::string *write_data);
int init_curl(CURL *curl, std::string url, std::string *response, std::string *header);
int create_connection(std::string url, std::string *response, std::string *header, long *response_code, double *elapsed_time);
int get_curl_info(CURL *curl, long *response_code, double *elapsed_time);

int main() {
    std::cout << "Pokemon API Project...begin!" << std::endl;

    std::string pokemon_url = "https://pokeapi.co/api/v2/pokemon/";
    std::string response;
    std::string header;
    long response_code;
    double elapsed_time;
    int curl_ret_status = 0;

    std::string pokemon_name;
    std::cout << "Enter a Pokemon name: ";
    getline(std::cin, pokemon_name);
    std::cout << std::endl;

    pokemon_url.append(pokemon_name);

    curl_ret_status = create_connection(pokemon_url, &response, &header, &response_code, &elapsed_time);
    if (curl_ret_status != 0) {
        return -1;
    }

    std::cout << "Response: " << std::endl << response << std::endl;

    std::cout << "Done" << std::endl;

    return 0;
}

size_t write_function(char *rcvd_data, size_t size, size_t nmemb, std::string *user_data) {
    user_data->append(rcvd_data, size * nmemb);
    return size * nmemb;
}

int init_curl(CURL *curl, std::string url, std::string *response, std::string *header) {
    CURLcode ret_code;

    //TODO: place curl_easy_init() here

    ret_code = curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    if (ret_code != CURLE_OK) {
        std::cerr << "Failed to set up URL" << std::endl;
        return -1;
    }

    ret_code = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_function);
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

int get_curl_info(CURL *curl, long *response_code, double *elapsed_time) {
    CURLcode ret_code;

    ret_code = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, response_code);
    if (ret_code != CURLE_OK) {
        std::cerr << "Failed to set up response code retriever" << std::endl;
        return -1;
    }

    ret_code = curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, elapsed_time);
    if (ret_code != CURLE_OK) {
        std::cerr << "Failed to set up total elapsed time retriever" << std::endl;
        return -1;
    }

    return 0;
}

int create_connection(std::string url, std::string *response, std::string *header, long *response_code, double *elapsed_time) {
    CURL *curl = NULL;
    CURLcode ret_code;
    int ret_status = 0;

    std::cout << "1 " << std::endl;

    curl = curl_easy_init();
    if (curl == NULL) {
        std::cerr << "Failed to initialize curl" << std::endl;
        return -1;
    }

    std::cout << "2 " << std::endl;

    ret_status = init_curl(curl, url, response, header);
    if (ret_status != 0) {
        return -1;
    }

    std::cout << "3 " << std::endl;

    ret_code = curl_easy_perform(curl);
    if (ret_code != CURLE_OK) {
        std::cerr << "Failed to execute curl_easy_perform(): " << curl_easy_strerror(ret_code) << std::endl;
        return -1;
    }

    std::cout << "4 " << std::endl;

    get_curl_info(curl, response_code, elapsed_time);

    curl_easy_cleanup(curl);

    return 0;
}
