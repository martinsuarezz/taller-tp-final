#include "Configuration.h"
#include "nlohmann/json.hpp"
#include <fstream>

using json = nlohmann::json;

Configuration::Configuration(){
    std::ifstream configFile("config.json");
    json configJSON;
    configFile >> configJSON;

    for (json::iterator it = configJSON.begin(); it != configJSON.end(); ++it){
        std::string parameter(it.key());
        int value = it.value();
        map.emplace(std::make_pair(std::move(parameter), value));
    }
}

Configuration& Configuration::getInstance(){
    static Configuration instance;
    return instance;
}

int Configuration::getValue(std::string parameter) const{
    return map.find(parameter)->second;
}
