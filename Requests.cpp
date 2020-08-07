/*
 * Requests.cpp
 *
 *  Created on: August 05, 2020
 *      Author: Bryan & Danny
 */

#include "Requests.h"

 // Constructor
Requests::Requests() : curl(nullptr),
                       response(""),
                       header(""),
                       responseCode(0),
                       elapsedTime(0) {}

// Destructor
Requests::~Requests() {}

int Requests::createConnection(std::string url) {
    CURLcode ret_code;
    int ret_status = 0;

    ret_status = initCurl(url);
    if (ret_status != 0) {
        return -1;
    }

    ret_code = curl_easy_perform(curl);
    if (ret_code != CURLE_OK) {
        std::cerr << "Failed to execute curl_easy_perform(): " << curl_easy_strerror(ret_code) << std::endl;
        return -1;
    }

    ret_status = getCurlInfo();
    if (ret_status != 0) {
        return -1;
    }

    curl_easy_cleanup(curl);

    return 0;
}

size_t Requests::writeFunction(char *rcvd_data, size_t size, size_t nmemb, std::string *userData) {
    userData->append(rcvd_data, size * nmemb);
    return size * nmemb;
}

int Requests::initCurl(std::string url) {
    CURLcode ret_code;

    curl = curl_easy_init();

    if (curl == nullptr) {
        std::cerr << "Failed to initialize curl" << std::endl;
        return -1;
    }

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

    return 0;
}

int Requests::getCurlInfo() {
    CURLcode ret_code;

    ret_code = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);
    if (ret_code != CURLE_OK) {
        std::cerr << "Failed to set up response code retriever" << std::endl;
        return -1;
    }

    ret_code = curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsedTime);
    if (ret_code != CURLE_OK) {
        std::cerr << "Failed to set up total elapsed time retriever" << std::endl;
        return -1;
    }

    return 0;
}

std::string Requests::getResponse() const {
    return response;
}