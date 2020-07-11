#include "EntityFactory.h"
#include "AssetsLoader.h"
#include "Entity.h"
#include "Screen.h" 
#include <map>
#include <string>

EntityFactory::EntityFactory(AssetsLoader& assets, Screen& screen):
                            assets(assets), screen(screen){}

Entity EntityFactory::getPlayer(int x, int y){
    std::map<std::string, std::string> equiped;
    equiped["1body"] = "leather_armor";
    equiped["2head"] = "human_head";
    equiped["3weapon"] = "item4";

    return std::move(Entity(assets, screen, equiped, x, y));
}

Entity EntityFactory::getZombie(int x, int y){
    std::map<std::string, std::string> equiped;
    equiped["1zombie_body"] = "zombie_body";

    return std::move(Entity(assets, screen, equiped, x, y));
}
