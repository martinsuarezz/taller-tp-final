#include "GameEntity.h"
#include "../GameMap.h"
#include "../Sender.h"
#include "../State/WalkingState.h"
#include "../State/IdleState.h"
#include "../Command/IdleCommand.h"
#include "../Constants.h"
#include "../Command/MoveCommand.h"

GameEntity::GameEntity(Sender& game, GameMap& map, int x, int y): 
                        game(game), map(map), x(x), y(y) {}


void GameEntity::updatePosition(int xNew, int yNew){
    map.moveEntity(x, y, xNew, yNew);
    x = xNew;
    y = yNew;
}

int GameEntity::getX(){
    return x;
}

int GameEntity::getY(){
    return y;
}

