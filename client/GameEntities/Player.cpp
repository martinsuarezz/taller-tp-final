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
                entities(entities), inventory(GameInventory(game)){
    Configuration& config = Configuration::getInstance();
    strength = config.getValue("human_strength");
    health = config.getValue("human_constitution") * 100;
}

void Player::notifyMovement(int direction, int xNew, int yNew){
    game.addCommand(new MoveCommand(entityId, direction, xNew, yNew));
    entities.notifyPlayerMovement(x, y);
}

void Player::notifyIdle(){
    game.addCommand(new IdleCommand(entityId, x * 100, y * 100));
}

int Player::getDefense(int damage){
    Configuration& config = Configuration::getInstance();

    int armorDef = inventory.getArmor().getDefense();
    int helmetDef = inventory.getHelmet().getDefense();
    int shieldDef = inventory.getShield().getDefense();

    int damageDealt = damage - config.getTotalDefense(armorDef, helmetDef, shieldDef);
    if (damageDealt < 0)
        damageDealt = 0;
    return damageDealt;
}

void Player::attackEntity(MovableEntity& entity){
    nextState.reset(new AttackingState(*this, entity, inventory.getWeapon(), strength, 2000000));
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
