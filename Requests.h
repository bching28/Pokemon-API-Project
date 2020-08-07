/*
 * Requests.h
 *
 *  Created on: August 05, 2020
 *      Author: Bryan & Danny
 */

#ifndef REQUESTS_H
#define REQUESTS_H
#include <iostream>
#include <curl/curl.h>

class Requests {
private:
    CURL *curl;
    std::string response;
    std::string header;
    long responseCode;
    double elapsedTime;

    int initCurl(std::string url);
    static size_t writeFunction(char *rcvd_data, size_t size, size_t nmemb, std::string *userData);
    int getCurlInfo();

public:
    // Constructor
    Requests();

    // Destructor
    ~Requests();

    int createConnection(std::string url);
    std::string getResponse() const;
};

#endif // REQUEST_H