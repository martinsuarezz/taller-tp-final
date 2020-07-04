#include "MovableEntity.h"
#include "../GameMap.h"
#include "../Sender.h"
#include "../State/WalkingState.h"
#include "../State/IdleState.h"
#include "../Command/IdleCommand.h"
#include "../Constants.h"
#include "../Command/MoveCommand.h"
#include <iostream>

#define MOVE_SPEED 1000000

MovableEntity::MovableEntity(Sender& game, GameMap& map, int entityId, int x, int y): 
                    GameEntity(game, map, x, y), state(new IdleState(*this)), entityId(entityId){}

MovableEntity::MovableEntity(MovableEntity&& other):
                    GameEntity(other.game, other.map, other.x, other.y), state(new IdleState(*this)), entityId(other.entityId){

}

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
    nextState.reset(new WalkingState(*this, x, y, x, y - 1, MOVE_SPEED, UP));
}

void MovableEntity::moveRight(){
    nextState.reset(new WalkingState(*this, x, y, x + 1, y, MOVE_SPEED, RIGHT));      
}

void MovableEntity::moveDown(){
    nextState.reset(new WalkingState(*this, x, y, x, y + 1, MOVE_SPEED, DOWN));
}

void MovableEntity::moveLeft(){
    nextState.reset(new WalkingState(*this, x, y, x - 1, y, MOVE_SPEED, LEFT));
}

void MovableEntity::stop(){
    nextState.reset(new IdleState(*this));
}

void MovableEntity::notifyMovement(int direction, int x, int y){
    game.addCommand(new MoveCommand(entityId, direction, x, y));
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

bool MovableEntity::canMove(int x, int y){
    return map.canMove(x, y);
}

void MovableEntity::updatePosition(int xNew, int yNew){
    map.move(x, y, xNew, yNew);
    x = xNew;
    y = yNew;
} 
