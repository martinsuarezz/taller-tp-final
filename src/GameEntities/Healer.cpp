#include "Healer.h"
#include "MovableEntity.h"
#include "GameEntity.h"
#include "../GameMap.h"
#include "../Sender.h"
#include "../State/WalkingState.h"
#include "../State/IdleState.h"
#include "../Command/IdleCommand.h"
#include "../Constants.h"
#include "../Command/MoveCommand.h"
#include "../Command/ShowProductsCommand.h"
#include "../Configuration.h"
#include <random>
#include "../GameItem/GameItemFactory.h"
#include <time.h>
#include <iostream>
#include <vector>

Healer::Healer(Sender& game, GameMap& map, int entityId, int x, int y): 
                    MovableEntity(game, map, entityId, x, y, 0, false){  
    health.setMaxHealth(100);
}

void Healer::notifyMovement(int direction, int xNew, int yNew){
    game.addCommand(new MoveCommand(entityId, direction, xNew, yNew));
}

void Healer::kill(MovableEntity& killer){
    game.removeMob(entityId);
}

void Healer::update(int timeElapsed){
}

void Healer::notifyPlayerMovement(int xObj, int yObj){
}

bool Healer::evadeAttack(){
    return true;
}

void Healer::attackEntity(MovableEntity& other){
}

void Healer::moveInventoryItem(int from, int to){}

void Healer::notifyHealthUpdate(int newHealth){}

void Healer::notifyExperienceUpdate(int newExperience){}

void Healer::notifyLevelUpdate(int newLevel){}

void Healer::notifyManaUpdate(int mana){}

void Healer::notifyGoldUpdate(int gold){}

bool Healer::addItem(int itemId, int slot){
    return false;
}

void Healer::buyItem(MovableEntity& buyer, int itemIndex){

}

int Healer::removeItem(int slot){
    std::runtime_error("No inventory");
    return -1;
}

int Healer::getDefense(int damage){
    return damage;
}

void Healer::interact(MovableEntity& other){
    other.revive();
}

void Healer::revive(){}

Healer::~Healer(){}
