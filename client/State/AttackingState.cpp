#include "AttackingState.h"
#include "IdleState.h"
#include "../GameItem/GameItem.h"
#include "../GameEntities/MovableEntity.h"
#include "../Configuration.h"
#include "../RandomGenerator.h"
#include <math.h>
#include <stdexcept>

AttackingState::AttackingState(MovableEntity& entity, MovableEntity& objective, GameItem& weapon, int strength, int duration): 
                        State(entity), objective(objective), weapon(weapon), strength(strength), duration(duration){}

void AttackingState::update(int timeElapsed){
    if (duration <= 0){
        entity.changeState();
        return;
    }
    
    duration -= timeElapsed;
}

bool AttackingState::isValid(){
    return entity.isInRange(objective, weapon.getRange()) && entity.hasManaAvailable(weapon.getManaNeeded());
}

void AttackingState::activate(){
    Configuration& config = Configuration::getInstance();
    RandomGenerator& random = RandomGenerator::getInstance();

    bool critical = false;
    int damage = weapon.getDamage() * strength;
    if (random(100) < config.getValue("critical_chance")){
        damage = config.getCriticalDamage(damage);
        critical = true;
    }
    
    entity.consumeMana(weapon.getManaNeeded());

    objective.getAttacked(damage, entity, critical);
    entity.stop();
}
