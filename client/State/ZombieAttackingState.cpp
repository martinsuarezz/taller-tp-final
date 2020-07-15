#include "ZombieAttackingState.h"
#include "IdleState.h"
#include "../GameItem/GameItem.h"
#include "../GameEntities/MovableEntity.h"
#include "../Configuration.h"
#include "../RandomGenerator.h"
#include <math.h>
#include <stdexcept>

ZombieAttackingState::ZombieAttackingState(MovableEntity& entity, MovableEntity& objective, int strength, int duration): 
                        State(entity), objective(objective), strength(strength), duration(duration){}

void ZombieAttackingState::update(int timeElapsed){
    if (duration <= 0){
        entity.changeState();
        return;
    }
    
    duration -= timeElapsed;
}

bool ZombieAttackingState::isValid(){
    return true;
}

void ZombieAttackingState::activate(){
    if (!entity.isInRange(objective, 1))
        return;

    Configuration& config = Configuration::getInstance();
    RandomGenerator& random = RandomGenerator::getInstance();

    bool critical = false;
    int damage = strength * random(2, 4);
    if (random(100) < config.getValue("critical_chance")){
        damage = config.getCriticalDamage(damage);
        critical = true;
    }

    objective.getAttacked(damage, entity, critical);
    entity.stop();
}
