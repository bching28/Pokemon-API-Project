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

int main() {
    std::cout << "Pokemon API Project...begin!" << std::endl;

    CURL *curl;
    CURLcode ret_code;
    std::string url = "pokeapi.co";
    std::string response;
    std::string header;
    long response_code;
    double elapsed_time;

    curl = curl_easy_init();
    if (curl == NULL) {
        std::cerr << "Failed to initialize curl" << std::endl;
        return -1;
    }

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

    ret_code = curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    if (ret_code != CURLE_OK) {
        std::cerr << "Failed to set up set up response buffer" << std::endl;
        return -1;
    }

    ret_code = curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header);
    if (ret_code != CURLE_OK) {
        std::cerr << "Failed to set up response header" << std::endl;
        return -1;
    }

    ret_code = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    if (ret_code != CURLE_OK) {
        std::cerr << "Failed to set up response code retriever" << std::endl;
        return -1;
    }

    ret_code = curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed_time);
    if (ret_code != CURLE_OK) {
        std::cerr << "Failed to set up total elapsed time retriever" << std::endl;
        return -1;
    }

    ret_code = curl_easy_perform(curl);
    if (ret_code != CURLE_OK) {
        std::cerr << "Failed to execute curl_easy_perform(): " << curl_easy_strerror(ret_code) << std::endl;
        return -1;
    }

    curl_easy_cleanup(curl);

    std::cout << "Done" << std::endl;

    return 0;
}

size_t write_function(char *rcvd_data, size_t size, size_t nmemb, std::string *user_data) {
    user_data->append(rcvd_data, size * nmemb);
    return size * nmemb;
}

