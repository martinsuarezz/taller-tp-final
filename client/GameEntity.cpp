#include "GameEntity.h"
#include "GameMap.h"
#include "Sender.h"
#include "State/WalkingState.h"
#include "Constants.h"
#include "MoveCommand.h"

#define MOVE_SPEED 1000

GameEntity::GameEntity(Sender& game, GameMap& map, int entityId): game(game), map(map), entityId(entityId), x(0), y(0) {}

void GameEntity::move(int direction){
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

void GameEntity::moveUp(){
    if (map.move(x, y, x, y - 1)){
        state.reset(new WalkingState(*this, x, y, x, y - 1, MOVE_SPEED, UP));
        y -= 1;
    }
}

void GameEntity::moveRight(){
    if (map.move(x, y, x + 1, y)){
        state.reset(new WalkingState(*this, x, y, x + 1, y, MOVE_SPEED, RIGHT));
        x += 1;
    }      
}

void GameEntity::moveDown(){
    if (map.move(x, y, x, y + 1)){
        state.reset(new WalkingState(*this, x, y, x, y + 1, MOVE_SPEED, DOWN));
        y += 1;
    }
}

void GameEntity::moveLeft(){
    if (map.move(x, y, x - 1, y))
        x -= 1;
}

void GameEntity::notifyMovement(int direction, int x, int y){
    game.addCommand(new MoveCommand(entityId, direction, x, y));
}

void GameEntity::update(int timeElapsed){
    if (state == NULL)
        return;
    state->update(timeElapsed);
}