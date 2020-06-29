#ifndef ARGENTUM_SERVER_CONFIG_H_
#define ARGENTUM_SERVER_CONFIG_H_

#include <map>
#include <string>

class Config {
 public:
  static Config& getInstance();
  int getValue(const std::string& key);
 private:
  std::map<std::string, int> map;
  Config();
};

#endif