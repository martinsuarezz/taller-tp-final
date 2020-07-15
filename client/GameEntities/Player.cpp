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
#include "../Command/PlayerHealthCommand.h"
#include "../Command/PlayerLevelCommand.h"
#include "../Command/PlayerExpCommand.h"
#include "../Command/PlayerManaCommand.h"
#include "../Configuration.h"
#include "../GameEntityContainer.h"
#include "../GameItem/GameItem.h"
#include "../GameInventory.h"
#include <iostream>

static int playerSpeed(){
    Configuration& config = Configuration::getInstance();
    return config.getValue("player_speed");
}

Player::Player(Sender& game, GameMap& map, GameEntityContainer& entities,
                int entityId, std::string race, std::string type, int x, int y): 
                MovableEntity(game, map, entityId, x, y, playerSpeed()), 
                entities(entities), inventory(GameInventory(game)), race(race), type(type){
    
    Configuration& config = Configuration::getInstance();
    strength = config.getValue(race + "_strength");
    agility = config.getValue(race + "_agility");
    health.setMaxHealth(config.getMaxHealth(race, type, 1));
    health.setHealthRegen(config.getHealthRegen(race));
    mana.setMaxMana(config.getMaxMana(race, type, 1));
    mana.setManaRegen(config.getManaRegen(race));
}

void Player::notifyMovement(int direction, int xNew, int yNew){
    game.addCommand(new MoveCommand(entityId, direction, xNew, yNew));
    entities.notifyPlayerMovement(x, y);
}

void Player::notifyIdle(){
    game.addCommand(new IdleCommand(entityId, x * 100, y * 100));
}

void Player::kill(){
    health.addHealth(1000);
    std::cout << "YOU DIED" << std::endl;
}

void Player::update(int timeElapsed){
    if (state == NULL)
        return;
    state->update(timeElapsed);
    health.regenerate(timeElapsed);
    mana.regenerate(timeElapsed);
}

void Player::notifyHealthUpdate(int newHealth){
    game.addCommand(new PlayerHealthCommand(newHealth));
}

void Player::notifyExperienceUpdate(int newExperience){
    game.addCommand(new PlayerExpCommand(newExperience));
}

void Player::notifyLevelUpdate(int newLevel){
    Configuration& config = Configuration::getInstance();

    game.addCommand(new PlayerLevelCommand(newLevel));
    health.setMaxHealth(config.getMaxHealth(race, type, level.getLevel()));
    mana.setMaxMana(config.getMaxMana(race, type, level.getLevel()));
}

void Player::notifyManaUpdate(int newMana){
    game.addCommand(new PlayerManaCommand(newMana));
}

bool Player::evadeAttack(){
    Configuration& config = Configuration::getInstance();
    return config.evadeAttack(agility);
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
