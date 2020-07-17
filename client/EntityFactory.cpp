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
    equiped["1body"] = race + "_body";
    equiped["2head"] = race + "_head";
    equiped["3weapon"] = "";
    equiped["4head"] = "";
    equiped["5weapon"] = "";

    return std::move(Entity(assets, screen, equiped, race, x, y));
}

Entity EntityFactory::getZombie(int x, int y){
    std::map<std::string, std::string> equiped;
    equiped["1zombie_body"] = "zombie_body";

    return std::move(Entity(assets, screen, equiped, "zombie", x, y));
}

Entity EntityFactory::getMerchant(int x, int y){
    std::map<std::string, std::string> equiped;
    equiped["1body"] = "merchant_body";

    return std::move(Entity(assets, screen, equiped, "merchant", x, y));
}

Entity EntityFactory::getHealer(int x, int y){
    std::map<std::string, std::string> equiped;
    equiped["1body"] = "healer_body";

    return std::move(Entity(assets, screen, equiped, "healer", x, y));
}
