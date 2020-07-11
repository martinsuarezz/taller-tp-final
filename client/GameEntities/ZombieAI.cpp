#include "ZombieAI.h"
#include "Zombie.h"
#include "../Configuration.h"

ZombieAI::ZombieAI(Zombie& zombie): zombie(zombie), x(-1), y(-1), 
                                    visionRange(1){
    
    Configuration& config = Configuration::getInstance();
    visionRange = config.getValue("zombie_vision");
}

void ZombieAI::update(){
    if (x == -1 || y == -1){
        zombie.stop();
        return;
    }
        
    if (zombie.isInRange(x, y, 1)){
        // attack;
        return;
    }

    if (zombie.isInRange(x, y, visionRange)){
        // move;
        return;
    }
}

void ZombieAI::notifyPlayerMovement(int xObj, int yObj){
    if (!zombie.isInRange(xObj, yObj, visionRange)){
        x = -1;
        y = -1;
    } else {
        x = xObj;
        y = yObj;
    }
}