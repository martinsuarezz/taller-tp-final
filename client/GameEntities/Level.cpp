#include "Level.h"
#include "MovableEntity.h"
#include "../Configuration.h"
#include <cmath>

Level::Level(MovableEntity& entity): level(1), experience(0), entity(entity){}

int Level::getLevel(){
    return level;
}

void Level::addExperience(int experience){
    changeExperience(experience);
}

void Level::changeExperience(int newExperience){
    experience += newExperience;
    if (experience < 0)
        experience = 0;
    while (experience > levelUpLimit()){
        experience -= levelUpLimit();
        changeLevel(1);
    }
    entity.notifyExperienceUpdate(experience);
}

int Level::levelUpLimit(){
    Configuration& config = Configuration::getInstance();
    return config.getLevelUpExp(level);
}

void Level::changeLevel(int addLevel){
    level += addLevel;
    entity.notifyLevelUpdate(level);
}