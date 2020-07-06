#include "IdleState.h"
#include "../GameEntities/MovableEntity.h"
#include <stdexcept>
#include <iostream>

IdleState::IdleState(MovableEntity& entity): 
                        State(entity){}

void IdleState::update(int timeElapsed){
    entity.changeState();
}

bool IdleState::isValid(){
    return true;
}

void IdleState::activate(){
    entity.notifyIdle();
}
