#include "EntityFactory.h"
#include "AssetsLoader.h"
#include "Entity.h"
#include "Screen.h" 
#include <map>
#include <string>

EntityFactory::EntityFactory(AssetsLoader& assets, Screen& screen):
                            assets(assets), screen(screen){}

Entity EntityFactory::getPlayer(int x, int y, std::string& race){
    std::map<std::string, std::string> equiped;
    // equiped["1body"] = "human_body";
    equiped["1body"] = "item15";
    equiped["2head"] = race + "_head";
    equiped["3weapon"] = "item12";
    //equiped["5weapon"] = "item18";
    equiped["4head"] = "item20";

    return std::move(Entity(assets, screen, equiped, x, y));
}

Entity EntityFactory::getZombie(int x, int y){
    std::map<std::string, std::string> equiped;
    equiped["1zombie_body"] = "zombie_body";

    return std::move(Entity(assets, screen, equiped, x, y));
}
