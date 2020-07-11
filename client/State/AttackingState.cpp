#include "AttackingState.h"
#include "IdleState.h"
#include "../GameItem/GameItem.h"
#include "../GameEntities/MovableEntity.h"
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
    return true;
}

void AttackingState::activate(){
    if (!entity.isInRange(objective, weapon.getRange()))
        return;
    objective.getAttacked(weapon.getDamage() * strength);
    entity.stop();
}
