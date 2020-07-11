#include "GameItemFactory.h" 
#include "GameItem.h"
#include "../Configuration.h"
#include "../Constants.h"
#include <iostream>

GameItemFactory::GameItemFactory(){}

GameItem GameItemFactory::getBareHands(){
    Configuration& config = Configuration::getInstance();
    GameItem bareHands = getItem("bare_hands", HANDS_ID);
    int weaponSlot = config.getValue("inv_weapon_slot");
    int shieldSlot = config.getValue("inv_shield_slot");
    bareHands.addValidSlot(weaponSlot);
    bareHands.addValidSlot(shieldSlot);
    return bareHands;
}

GameItem GameItemFactory::getItem(std::string name, int id){
    Configuration& config = Configuration::getInstance();
    int damageMin = config.getValue("damage_min_" + name);
    int damageMax = config.getValue("damage_max_" + name);
    int defenseMin = config.getValue("defense_min_" + name);
    int defenseMax = config.getValue("defense_max_" + name);
    int range = config.getValue("range_" + name);
    return std::move(GameItem(name, id, damageMin, damageMax, 
                    defenseMin, defenseMax, range));
}

GameItem GameItemFactory::getSword(){
    Configuration& config = Configuration::getInstance();
    GameItem sword = getItem("sword", SWORD_ID);
    int weaponSlot = config.getValue("inv_weapon_slot");
    sword.addValidSlot(weaponSlot);
    return sword;
}

GameItem GameItemFactory::getHammer(){
    Configuration& config = Configuration::getInstance();
    GameItem hammer = getItem("hammer", HAMMER_ID);
    int weaponSlot = config.getValue("inv_weapon_slot");
    hammer.addValidSlot(weaponSlot);
    return hammer;
}

GameItem GameItemFactory::getAxe(){
    Configuration& config = Configuration::getInstance();
    GameItem axe = getItem("axe", AXE_ID);
    int weaponSlot = config.getValue("inv_weapon_slot");
    axe.addValidSlot(weaponSlot);
    return axe;
}

GameItem GameItemFactory::getItem(int id){
    switch(id){
        case HANDS_ID:
            return getBareHands();
        case SWORD_ID:
            return getSword();
        case AXE_ID:
            return getAxe();
        case HAMMER_ID:
            return getHammer();
    }

    std::cout << "Warning: item not implemented!" << std::endl;
    return std::move(GameItem());
}