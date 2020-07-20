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

Zombie::Zombie(Sender& game, GameMap& map, int entityId, int x, int y,
                int visionRange, int strength, int defense, int speed, int constitution):
                MovableEntity(game, map, entityId, x, y, speed), 
                visionRange(visionRange), strength(strength),
                defense(defense), zombieAI(ZombieAI(*this, visionRange)){
    
    health.setMaxHealth(constitution);
}

void Zombie::notifyMovement(int direction, int xNew, int yNew){
    game.addCommand(new MoveCommand(entityId, direction, xNew, yNew));
}

void Zombie::notifyIdle(){
    game.addCommand(new IdleCommand(entityId, x * 100, y * 100));
}

void Zombie::kill(MovableEntity& killer){
    RandomGenerator& random = RandomGenerator::getInstance();
    Configuration& config = Configuration::getInstance();
    if (random(100) < config.getValue("spawn_item_prob")){
        int itemId = random(4, 21);
        map.addItem(itemId, x, y);
    }
    if (random(100) < config.getValue("spawn_gold_prob")){
        int goldDrop = config.getRandomGold(health.getMaxHealth());
        killer.addGold(goldDrop);
    }
    killer.addExperience(config.getKillExp(health.getMaxHealth(), level.getLevel(), killer.getLevel()));
    game.removeMob(entityId);
}

int Zombie::removeItem(int slot){
    std::runtime_error("No inventory");
    return -1;
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

bool Zombie::evadeAttack(){
    return false;
}

void Zombie::attackEntity(MovableEntity& other){
    GameItemFactory factory;
    Configuration& config = Configuration::getInstance();
    int attackCooldown = config.getValue("zombie_attack_cooldown");
    nextState.reset(new ZombieAttackingState(*this, other, strength, attackCooldown));
}

bool Zombie::hasManaAvailable(int neededMana){
    return true;
}

void Zombie::moveInventoryItem(int from, int to){}

void Zombie::notifyHealthUpdate(int newHealth){}

void Zombie::notifyExperienceUpdate(int newExperience){}

void Zombie::notifyLevelUpdate(int newLevel){}

void Zombie::notifyManaUpdate(int mana){}

void Zombie::notifyGoldUpdate(int gold){}

bool Zombie::addItem(int itemId, int slot){
    return false;
}

void Zombie::revive(){}

void Zombie::interact(MovableEntity& other){}

void Zombie::buyItem(MovableEntity& buyer, int itemIndex){}

int Zombie::getDefense(int damage){
    return damage - defense;
}

Zombie::~Zombie(){}
