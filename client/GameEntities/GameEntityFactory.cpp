#include "GameEntityFactory.h"
#include "Player.h"
#include "Zombie.h"
#include "../Sender.h"
#include "../GameMap.h"
#include "../GameEntityContainer.h"
#include "../Configuration.h"
#include <string>

GameEntityFactory::GameEntityFactory(Sender& game, GameMap& map, 
                                    GameEntityContainer& entities):
                                    game(game), map(map), entities(entities){}


MovableEntity* GameEntityFactory::getPlayer(int x, int y, int entityId){
    std::string race = "human";
    std::string type = "wizard";

    //Configuration& config = Configuration::getInstance();
    //int maxHealth = config.getMaxHealth(race, type, 1);
    //int maxMana = config.getMaxMana(race, type, 1);

    MovableEntity* player = new Player(game, map, entities, entityId, race, type, x, y);
    return player;
}

MovableEntity* GameEntityFactory::getZombie(int x, int y, int entityId){

    //Configuration& config = Configuration::getInstance();
    //int maxHealth = config.getMaxHealth(race, type, 1);
    //int maxMana = config.getMaxMana(race, type, 1);

    MovableEntity* zombie = new Zombie(game, map, entityId, x, y);
    return zombie;
}
