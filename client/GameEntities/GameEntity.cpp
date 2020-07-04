#include "GameEntity.h"
#include "../GameMap.h"
#include "../Sender.h"
#include "../State/WalkingState.h"
#include "../State/IdleState.h"
#include "../Command/IdleCommand.h"
#include "../Constants.h"
#include "../Command/MoveCommand.h"
#include <iostream>

#define MOVE_SPEED 1000000

GameEntity::GameEntity(Sender& game, GameMap& map, int x, int y): 
                        game(game), map(map), x(x), y(y) {}


void GameEntity::updatePosition(int xNew, int yNew){
    map.move(x, y, xNew, yNew);
    x = xNew;
    y = yNew;
}