#include "MovableEntity.h"
#include "../GameMap.h"
#include "../Sender.h"
#include "../State/WalkingState.h"
#include "../State/IdleState.h"
#include "../Command/IdleCommand.h"
#include "../Constants.h"
#include "../Command/MoveCommand.h"
#include "../Configuration.h"
#include <iostream>

MovableEntity::MovableEntity(Sender& game, GameMap& map, int entityId, int x, int y, int moveSpeed): 
                    GameEntity(game, map, x, y), state(new IdleState(*this)), 
                    entityId(entityId), moveSpeed(moveSpeed), health(Health(*this)){}

void MovableEntity::move(int direction){
    switch (direction){
        case UP:
            moveUp();
            break;
        
        case RIGHT:
            moveRight();
            break;
        
        case DOWN:
            moveDown();
            break;
        
        case LEFT:
            moveLeft();
            break;
    }
}

void MovableEntity::moveUp(){
    nextState.reset(new WalkingState(*this, x, y, x, y - 1, moveSpeed, UP));
}

void MovableEntity::moveRight(){
    nextState.reset(new WalkingState(*this, x, y, x + 1, y, moveSpeed, RIGHT));      
}

void MovableEntity::moveDown(){
    nextState.reset(new WalkingState(*this, x, y, x, y + 1, moveSpeed, DOWN));
}

void MovableEntity::moveLeft(){
    nextState.reset(new WalkingState(*this, x, y, x - 1, y, moveSpeed, LEFT));
}

void MovableEntity::stop(){
    nextState.reset(new IdleState(*this));
}

void MovableEntity::notifyIdle(){
    game.addCommand(new IdleCommand(entityId, x * 100, y * 100));
}

void MovableEntity::update(int timeElapsed){
    if (state == NULL)
        return;
    state->update(timeElapsed);
}

void MovableEntity::changeState(){
    if (nextState == NULL)
        return;
    if (nextState->isValid()){
        state.swap(nextState);
        nextState.release();
        state->activate();
    }
}

int MovableEntity::getId(){
    return entityId;
}

void MovableEntity::getAttacked(int damage, bool critical){
    Configuration& config = Configuration::getInstance();
    if (critical)
        damage *= 2;
    else if (config.evadeAttack())
        return;
    
    int damageDealt = getDefense(damage);
    health.dealDamage(damageDealt);
    
    std::cout << "Done: " << damageDealt << " of damage" << std::endl;

    int newHealth = health.getHealth();
    std::cout << "Current HP: " << newHealth << std::endl;
    if (newHealth <= 0){
        this->kill();
    }
        
}

bool MovableEntity::isInRange(MovableEntity& other, int range){
    return ((abs(other.getX() - x)) <= range) && ((abs(other.getY() - y)) <= range);
}

bool MovableEntity::canMove(int x, int y){
    return map.canMove(x, y);
}

void MovableEntity::updatePosition(int xNew, int yNew){
    map.moveEntity(x, y, xNew, yNew);
    x = xNew;
    y = yNew;
} 

MovableEntity::~MovableEntity(){}
