#include "Player.h"
#include "MovableEntity.h"
#include "../GameMap.h"
#include "../Sender.h"
#include "../State/WalkingState.h"
#include "../State/AttackingState.h"
#include "../State/IdleState.h"
#include "../Command/IdleCommand.h"
#include "../Constants.h"
#include "../Command/MoveCommand.h"
#include "../Configuration.h"
#include "../GameEntityContainer.h"
#include "../GameItem/GameItem.h"

static int playerSpeed(){
    Configuration& config = Configuration::getInstance();
    return config.getValue("player_speed");
}

Player::Player(Sender& game, GameMap& map, GameEntityContainer& entities,
                int entityId, int x, int y): 
                MovableEntity(game, map, entityId, x, y, playerSpeed()), 
                entities(entities), inventory(GameInventory(game)), strength(5){}

void Player::notifyMovement(int direction, int xNew, int yNew){
    game.addCommand(new MoveCommand(entityId, direction, xNew, yNew));
    entities.notifyPlayerMovement(x, y);
}

void Player::notifyIdle(){
    game.addCommand(new IdleCommand(entityId, x * 100, y * 100));
}

void Player::attackEntity(MovableEntity& entity){
    nextState.reset(new AttackingState(*this, entity, inventory.getWeapon(), strength, 2000000));
    /*
    GameItem& weapon = inventory.getWeapon();
    if (!isInRange(entity, weapon.getRange()))
        return;
    entity.getAttacked(weapon.getDamage() * strength);
    */
}

void Player::notifyPlayerMovement(int x, int y){
    return;
}

void Player::moveInventoryItem(int from, int to){
    inventory.moveItem(from, to);
}

void Player::addItem(int itemId, int slot){
    inventory.addItem(itemId, slot);
}

Player::~Player(){}
