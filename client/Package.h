#ifndef PACKAGE_H
#define PACKAGE_H
#include <vector>

class Package{
    private:
        std::vector<int> attributes;

    public:
        Package(const char* buffer);
        Package(Package&&);
        Package& operator=(Package&&);
        int operator[](size_t index) const;

};

#endif

