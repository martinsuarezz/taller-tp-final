#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <map>
#include <string>

class Configuration{
    private:
        std::map<std::string, int> map;
        Configuration();

    public:
        static Configuration& getInstance();
        int getValue(std::string parameter);

        Configuration(Configuration const&) = delete;
        void operator=(Configuration const&)  = delete;

};

#endif
