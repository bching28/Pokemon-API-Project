#ifndef API_RESOURCE_H
#define API_RESOURCE_H

#include <iostream>

class APIResource {
protected:
    std::string url;

public:
    APIResource();
    ~APIResource();
};

#endif // API_RESOURCE_H