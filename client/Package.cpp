#include "Package.h"
#include <stdexcept>
#include <cstring>
#include <arpa/inet.h>
#include <iostream>

#define PACKAGE_ATTRIBUTES 3

Package::Package(const char* buffer){
    if (buffer[0] != 0){
        char firstAttribute = buffer[0];
        attributes.push_back((int)firstAttribute);

        std::cout << 0 << std::endl;
        std::cout << (int)firstAttribute << std::endl;
    
        for (int i = 0; i < PACKAGE_ATTRIBUTES; i++){
            uint32_t attribute;
            memcpy(&attribute, buffer + 1 + (i * 4), 4);
            attributes.push_back((int) ntohl(attribute));
            std::cout << i+1 << std::endl;
            std::cout << (int) ntohl(attribute) << std::endl;
        }
    }
}

Package::Package(Package&& other){
    this->attributes.swap(other.attributes);
}

Package& Package::operator=(Package&& other){
    this->attributes.swap(other.attributes);
    return *this;
}

int Package::operator[](size_t index) const{
    if (index >= attributes.size())
        throw std::out_of_range("Not a valid index");
    return attributes[index];
}