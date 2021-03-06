#include "ZombieAI.h"
#include "Zombie.h"
#include "../Configuration.h"

ZombieAI::ZombieAI(Zombie& zombie, int visionRange): zombie(zombie), x(-1), y(-1), 
                                    visionRange(visionRange){

}

void ZombieAI::update(){
    if (x == -1 || y == -1){
        zombie.stop();
        return;
    }
        
    if (zombie.isInRange(x, y, 1)){
        zombie.attackPlayer();
        return;
    }
        
    if (zombie.isInRange(x, y, visionRange)){
        if (x > zombie.getX()){
            zombie.moveRight();
        } else if (x < zombie.getX()){
            zombie.moveLeft();
        } else if (y > zombie.getY()){
            zombie.moveDown();
        } else if (y < zombie.getY()){
            zombie.moveUp();
        }
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