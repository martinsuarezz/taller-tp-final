#include "GameItem.h"
#include "DamageDealer.h"
#include "DefenseDealer.h"
#include "../Configuration.h"
#include <algorithm>

GameItem::GameItem(std::string name, int itemId, int damageMin, int damageMax,
                    int defenseMin, int defenseMax, int range, int duration, int manaNeeded): 
                    name(name), itemId(itemId), 
                    damageDealer(DamageDealer(damageMin, damageMax, range, duration)),
                    defenseDealer(DefenseDealer(defenseMin, defenseMax)),
                    manaNeeded(manaNeeded) {}

GameItem::GameItem(): name("null"), itemId(0), 
                    damageDealer(DamageDealer(0, 0, 0, 0)),
                    defenseDealer(DefenseDealer(0, 0)),
                    manaNeeded(0) {}

GameItem::GameItem(GameItem&& other): name(other.name), itemId(other.itemId),
                    acceptedSlots(std::move(other.acceptedSlots)), 
                    damageDealer(std::move(other.damageDealer)),
                    defenseDealer(std::move(other.defenseDealer)), 
                    manaNeeded(other.manaNeeded) {}

void GameItem::addValidSlot(int slot){
    acceptedSlots.push_back(slot);
}

int GameItem::getId(){
    return itemId;
}

int GameItem::getDamage(){
    return damageDealer.getDamage();
}

int GameItem::getDuration(){
    return damageDealer.getDuration();
}

bool GameItem::canBeEquipped(int slot){
    Configuration& config = Configuration::getInstance();
    if (slot < config.getValue("inventory_slots"))
        return true;
    if (std::find(acceptedSlots.begin(), acceptedSlots.end(), slot) != acceptedSlots.end())
        return true;
    return false;
}

int GameItem::getRange(){
    return damageDealer.getRange();
}

int GameItem::getDefense(){
    return defenseDealer.getDefense();
}

int GameItem::getManaNeeded(){
    return manaNeeded;
}
