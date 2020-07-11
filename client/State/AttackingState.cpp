#include "AttackingState.h"
#include "IdleState.h"
#include "../GameItem/GameItem.h"
#include "../GameEntities/MovableEntity.h"
#include <math.h>
#include <stdexcept>

AtackingState::AttackingState(MovableEntity& entity, MovableEntity& objective, GameItem& weapon, int strength, int duration): 
                        State(entity), objective(objective), weapon(weapon), strength(strength), duration(duration){}

void AtackingState::update(int timeElapsed){
    if (duration <= 0){
        entity.changeState();
        return;
    }
    
    duration -= timeElapsed;
}

bool AtackingState::isValid(){
    return true;
}

void AtackingState::activate(){
    if (!entity.isInRange(objective, weapon.getRange()))
        return;
    objective.getAttacked(weapon.getDamage() * strength);
    entity.stop();
}