#include "GameEntityFactory.h"
#include "Player.h"
#include "Zombie.h"
#include "Merchant.h"
#include "Healer.h"
#include "../Sender.h"
#include "../GameMap.h"
#include "../GameEntityContainer.h"
#include "../Configuration.h"
#include <string>

GameEntityFactory::GameEntityFactory(Sender& game, GameMap& map, 
                                    GameEntityContainer& entities):
                                    game(game), map(map), entities(entities){}


MovableEntity* GameEntityFactory::getPlayer(int x, int y, int entityId, std::string& race, std::string& type){
    Configuration& config = Configuration::getInstance();
    int duration = config.getWalkDuration(race);

    MovableEntity* player = new Player(game, map, entities, entityId, race, type, x, y, duration);
    return player;
}

MovableEntity* GameEntityFactory::getZombie(int x, int y, int entityId, int level){
    Configuration& config = Configuration::getInstance();
    int visionRange = config.getZombieVision(level);
    int strength = config.getZombieStrength(level);
    int defense = config.getZombieDefense(level);
    int speed = config.getZombieWalkDuration();
    int constitution = config.getZombieConstitution(level);

    MovableEntity* zombie = new Zombie(game, map, entityId, x, y, visionRange, strength, defense, speed, constitution);
    return zombie;
}

MovableEntity* GameEntityFactory::getMerchant(int x, int y, int entityId){
    MovableEntity* merchant = new Merchant(game, map, entityId, x, y);
    return merchant;
}

MovableEntity* GameEntityFactory::getHealer(int x, int y, int entityId){
    MovableEntity* merchant = new Healer(game, map, entityId, x, y);
    return merchant;
}

