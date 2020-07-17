#include "MovableEntity.h"
#include "../GameMap.h"
#include "../Sender.h"
#include "../State/WalkingState.h"
#include "../State/IdleState.h"
#include "../Command/IdleCommand.h"
#include "../Constants.h"
#include "../Command/MoveCommand.h"
#include "../Command/AttackCommand.h"
#include "../Configuration.h"
#include <iostream>

MovableEntity::MovableEntity(Sender& game, GameMap& map, int entityId, 
                            int x, int y, int moveSpeed, bool alive): 
                    GameEntity(game, map, x, y), state(new IdleState(*this)), 
                    entityId(entityId), moveSpeed(moveSpeed), 
                    health(Health(*this)), level(Level(*this)),
                    mana(Mana(*this)), gold(GoldContainer(*this)),
                    alive(alive){}

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

int MovableEntity::getLevel(){
    return level.getLevel();
}

void MovableEntity::notifyAttack(int weaponId, int x, int y, int duration){
    game.addCommand(new AttackCommand(weaponId, x * 100, y * 100, duration));
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

void MovableEntity::addExperience(int experience){
    level.addExperience(experience);
}

void MovableEntity::addGold(int ammount){
    gold.add(ammount);
}

bool MovableEntity::hasManaAvailable(int neededMana){
    return mana.getMana() >= neededMana;
}

void MovableEntity::consumeMana(int ammount){
    mana.removeMana(ammount);
}

void MovableEntity::getAttacked(int damage, MovableEntity& attacker, bool critical){
    if(!alive)
        return;

    Configuration& config = Configuration::getInstance();

    if (!critical && evadeAttack())
        return;
    
    int damageDealt = getDefense(damage);
    health.dealDamage(damageDealt);
    attacker.addExperience(config.getAttackExp(damageDealt, getLevel(), attacker.getLevel()));
    
    std::cout << "Done: " << damageDealt << " of damage" << std::endl;

    int newHealth = health.getHealth();
    std::cout << "Current HP: " << newHealth << std::endl;
    if (newHealth <= 0){
        this->kill(attacker);
    } 
}

bool MovableEntity::hasGoldAvailable(int ammount){
    return gold.areAvailable(ammount);
}

void MovableEntity::removeGold(int ammount){
    gold.remove(ammount);
}

bool MovableEntity::isInRange(MovableEntity& other, int range){
    return ((abs(other.getX() - x)) <= range) && ((abs(other.getY() - y)) <= range);
}

bool MovableEntity::canMove(int x, int y){
    return map.canMove(x, y);
}

bool MovableEntity::isAlive(){
    return alive;
}

void MovableEntity::updatePosition(int xNew, int yNew){
    map.moveEntity(x, y, xNew, yNew);
    x = xNew;
    y = yNew;
} 

MovableEntity::~MovableEntity(){}
