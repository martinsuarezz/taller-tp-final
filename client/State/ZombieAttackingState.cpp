#include "ZombieAttackingState.h"
#include "IdleState.h"
#include "../GameItem/GameItem.h"
#include "../GameEntities/MovableEntity.h"
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
    objective.getAttacked(strength * 2);
    entity.stop();
}
