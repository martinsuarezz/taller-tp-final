#include "Player.h"
#include "MovableEntity.h"
#include "../GameMap.h"
#include "../Sender.h"
#include "../State/WalkingState.h"
#include "../State/IdleState.h"
#include "../Command/IdleCommand.h"
#include "../Constants.h"
#include "../Command/MoveCommand.h"
#include "../Configuration.h"
#include "../GameEntityContainer.h"

static int playerSpeed(){
    Configuration& config = Configuration::getInstance();
    return config.getValue("player_speed");
}

Player::Player(Sender& game, GameMap& map, GameEntityContainer& entities, int entityId, int x, int y): 
                    MovableEntity(game, map, entityId, x, y, playerSpeed()), entities(entities){}

void Player::notifyMovement(int direction, int xNew, int yNew){
    game.addCommand(new MoveCommand(entityId, direction, xNew, yNew));
    entities.notifyPlayerMovement(x, y);
}

void Player::notifyIdle(){
    game.addCommand(new IdleCommand(entityId, x * 100, y * 100));
}

void Player::notifyPlayerMovement(int x, int y){
    return;
}

Player::~Player(){}
