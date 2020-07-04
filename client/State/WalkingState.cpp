#include "WalkingState.h"
#include "IdleState.h"
#include "../GameEntities/MovableEntity.h"
#include <math.h>
#include <stdexcept>
#include <iostream>

WalkingState::WalkingState(MovableEntity& entity, int xInitial, int yInitial, int xFinal, int yFinal, int duration, int direction): 
                        State(entity), x(xInitial*100), y(yInitial*100), xFinal(xFinal*100), yFinal(yFinal*100), duration(duration), direction(direction){}

void WalkingState::update(int timeElapsed){
    if (duration <= 0){
        entity.changeState();
        return;
    }
        
    float xToMove = nearbyint((float)((xFinal - x) * timeElapsed) / duration);
    float yToMove = nearbyint((float)((yFinal - y) * timeElapsed) / duration);

    x += (int) xToMove;
    y += (int) yToMove;
    duration -= timeElapsed;
    entity.notifyMovement(direction, x, y);
}

bool WalkingState::isValid(){
    return entity.canMove(xFinal / 100, yFinal / 100);
}

void WalkingState::activate(){
    entity.updatePosition(xFinal / 100, yFinal / 100);
    entity.move(direction);
}