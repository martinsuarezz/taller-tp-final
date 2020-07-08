#include "GameItemFactory.h" 
#include "GameItem.h"
#include "../Configuration.h"
#include "../Constants.h"

GameItemFactory::GameItemFactory(){}

GameItem GameItemFactory::getBareHands(){
    Configuration& config = Configuration::getInstance();
    int damageMin = config.getValue("damage_min_bare_hands");
    int damageMax = config.getValue("damage_max_bare_hands");
    int defenseMin = config.getValue("defense_min_bare_hands");
    int defenseMax = config.getValue("defense_max_bare_hands");
    int range = config.getValue("range_bare_hands");
    int weaponSlot = config.getValue("inv_weapon_slot");
    int shieldSlot = config.getValue("inv_shield_slot");
    GameItem hands("bare_hands", HANDS_ID, damageMin, damageMax, 
                    defenseMin, defenseMax, range);
    hands.addValidSlot(weaponSlot);
    hands.addValidSlot(shieldSlot);
    return hands;
}

GameItem GameItemFactory::getItem(int id){
    switch(id){
        case HANDS_ID:
            return getBareHands();
    }
    return std::move(GameItem());
}