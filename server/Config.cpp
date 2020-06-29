#include "Config.h"

#include "../utils/nlohmann/json.hpp"
#include <fstream>

Config::Config(){
  std::ifstream configFile("../server/config.json");
  nlohmann::json configJSON;
  configFile >> configJSON;

  for (nlohmann::json::iterator it = configJSON.begin(); it != configJSON.end(); ++it) {
    std::string parameter(it.key());
    int value = it.value();
    map.emplace(std::make_pair(std::move(parameter), value));
  }
}

Config& Config::getInstance(){
  static Config instance;
  return instance;
}

int Config::getValue(const std::string& param){
  return map.find(param)->second;
}
