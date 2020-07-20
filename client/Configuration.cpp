#include "Configuration.h"
#include "nlohmann/json.hpp"
#include "Constants.h"
#include <fstream>
#include <cmath>
#include <algorithm>
#include "RandomGenerator.h"

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

    map.emplace("inv_x_slot_size_px", getValue("inv_x_slot_size_perc") * getValue("window_width") / 100);
    map.emplace("inv_y_slot_size_px", getValue("inv_y_slot_size_perc") * getValue("window_height") / 100);
}

Configuration& Configuration::getInstance(){
    static Configuration instance;
    return instance;
}

int Configuration::getValue(std::string parameter) const{
    return map.find(parameter)->second;
}

int Configuration::getCriticalDamage(int damage) const{
    return damage * getValue("critical_multiplier");
}

bool Configuration::evadeAttack(int agility) const{
    RandomGenerator& random = RandomGenerator::getInstance();
    double randomNum = (double) random(1000) / 1000;
    return pow(randomNum, (double) agility) < 0.001;
}

int Configuration::getTotalDefense(int armorDef, int helmetDef, int shieldDef) const{
    return armorDef + helmetDef + shieldDef;
}

int Configuration::getMaxHealth(std::string race, std::string type, int level) const{
    int constitution = getValue(race + "_constitution");
    int typeHealth = getValue(type + "_health");
    int raceHealth = getValue(race + "_health");
    
    return constitution * typeHealth * raceHealth * level;
}

int Configuration::getAttackExp(int damage, int defenderLevel, int attackerLevel) const{
    return damage * std::max(defenderLevel - attackerLevel + 10, 0);
}

int Configuration::getKillExp(int maxHealth, int defenderLevel, int attackerLevel) const{
    RandomGenerator& random = RandomGenerator::getInstance();
    double modifier = (double) random(100) / 1000;
    return (int) (modifier * (double) maxHealth * (double) std::max(defenderLevel - attackerLevel + 10, 0));
}

int Configuration::getHealthRegen(std::string race) const{
    int typeRegen = getValue(race + "_health_regen");
    
    return typeRegen;
}

int Configuration::getMaxMana(std::string race, std::string type, int level) const{
    int inteligence = getValue(race + "_inteligence");
    int typeMana = getValue(type + "_mana");
    int raceMana = getValue(race + "_mana");
    
    return inteligence * typeMana * raceMana * level;
}

int Configuration::getZombieWalkDuration() const{
    RandomGenerator& random = RandomGenerator::getInstance();
    int minSpeed = getValue("zombie_min_speed");
    int maxSpeed = getValue("zombie_max_speed");
    return random(minSpeed, maxSpeed + 1);
}

int Configuration::getZombieVision(int level) const{
    RandomGenerator& random = RandomGenerator::getInstance();
    int minVision = getValue("zombie_min_vision");
    int maxVision = getValue("zombie_max_vision");
    return random(minVision, maxVision + 1);
}

int Configuration::getZombieStrength(int level) const{
    int stregth = (int) ((double) level * (double) getValue("zombie_strength_perc") / 100);
    int maxStrength = getValue("zombie_strength_cap");
    return std::max(1, std::min(maxStrength, stregth));
}

int Configuration::getZombieDefense(int level) const{
    int defense = (int) ((double) level * (double) getValue("zombie_defense_perc") / 100);
    int maxDefense = getValue("zombie_defense_cap");
    return std::min(maxDefense, defense);
}

int Configuration::getZombieConstitution(int level) const{
    RandomGenerator& random = RandomGenerator::getInstance();
    int constitution = random(getValue("zombie_min_constitution"), getValue("zombie_max_constitution"));
    return level * constitution;
}

int Configuration::getWalkDuration(std::string race) const{
    int agility = getValue(race + "_agility");
    double speed = (double) agility * (-0.72) + 10.72;
    return (int) (speed * (MICROS_IN_SECOND / 10));
}

int Configuration::getManaRegen(std::string race) const{
    int typeRegen = getValue(race + "_mana_regen");
    
    return typeRegen;
}

int Configuration::getLevelUpExp(int level) const{
    return (int) (1000 * pow((double) level, 1.8));
}

int Configuration::getRandomGold(int maxHealth) const{
    RandomGenerator& random = RandomGenerator::getInstance();
    double randomNum = (double) random(2000) / 10000;
    randomNum += 200;
    return (int) (randomNum * maxHealth);
}
