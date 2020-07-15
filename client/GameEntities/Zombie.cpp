#include "Zombie.h"
#include "MovableEntity.h"
#include "GameEntity.h"
#include "../GameMap.h"
#include "../Sender.h"
#include "../State/WalkingState.h"
#include "../State/ZombieAttackingState.h"
#include "../State/IdleState.h"
#include "../Command/IdleCommand.h"
#include "../Constants.h"
#include "../Command/MoveCommand.h"
#include "../Configuration.h"
#include "../RandomGenerator.h"
#include "../GameItem/GameItemFactory.h"
#include "ZombieAI.h"
#include <iostream>

static int zombieSpeed(){
    Configuration& config = Configuration::getInstance();
    return config.getValue("zombie_speed");
}

Zombie::Zombie(Sender& game, GameMap& map, int entityId, int x, int y): 
                    MovableEntity(game, map, entityId, x, y, zombieSpeed()), 
                    visionRange(1), zombieAI(ZombieAI(*this)){
    
    Configuration& config = Configuration::getInstance();
    visionRange = config.getValue("zombie_vision");
    health.setMaxHealth(100);
}

void Zombie::notifyMovement(int direction, int xNew, int yNew){
    game.addCommand(new MoveCommand(entityId, direction, xNew, yNew));
}

void Zombie::notifyIdle(){
    game.addCommand(new IdleCommand(entityId, x * 100, y * 100));
}

void Zombie::kill(){
    RandomGenerator& random = RandomGenerator::getInstance();
    Configuration& config = Configuration::getInstance();
    if (random(100) < config.getValue("spawn_item_prob")){
        int itemId = random(4, 21);
        map.addItem(itemId, x, y);
    }
    game.removeMob(entityId);
}

void Zombie::update(int timeElapsed){
    zombieAI.update();
    if (state == NULL)
        return;
    state->update(timeElapsed);
}

void Zombie::moveTowards(int xObj, int yObj){
    if (xObj > x){
        moveRight();
    }
    else if (xObj < x){
        moveLeft();
    }
    else if (yObj > y){
        moveDown();
    }
    else if (yObj < y){
        moveUp();
    }
}

bool Zombie::isInRange(int xObj, int yObj, int range){
    return (abs(xObj - x) <= range) && (abs(yObj - y) <= range);
}

bool Zombie::isInVisionRange(int xObj, int yObj){
    return isInRange(xObj, yObj, visionRange);
}

void Zombie::notifyPlayerMovement(int xObj, int yObj){
    zombieAI.notifyPlayerMovement(xObj, yObj);
}

void Zombie::attackPlayer(){
    attackEntity(game.getPlayer());
}

void Zombie::attackEntity(MovableEntity& other){
    GameItemFactory factory;
    GameItem zombieHands = factory.getBareHands();
    nextState.reset(new ZombieAttackingState(*this, other, 5, 2000000));
}

void Zombie::moveInventoryItem(int from, int to){

}

void Zombie::notifyHealthUpdate(int newHealth){

}

void Zombie::addItem(int itemId, int slot){

}

int Zombie::getDefense(int damage){
    return damage;
}

Zombie::~Zombie(){}
