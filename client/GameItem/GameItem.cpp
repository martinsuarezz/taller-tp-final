#include "GameItem.h"
#include "DamageDealer.h"

GameItem::GameItem(std::string name, int itemId, int damageMin, int damageMax,
                    int defenseMin, int defenseMax, int range): 
                    name(name), itemId(itemId), 
                    damageDealer(DamageDealer(damageMin, damageMax, range)){}

GameItem::GameItem(): name("null"), itemId(0), 
                    damageDealer(DamageDealer(0, 0, 0)){}


GameItem::GameItem(GameItem&& other): name(other.name), itemId(other.itemId),
                    acceptedSlots(std::move(other.acceptedSlots)), 
                    damageDealer(std::move(other.damageDealer)){}

void GameItem::addValidSlot(int slot){
    acceptedSlots.push_back(slot);
}

int GameItem::getId(){
    return itemId;
}

int GameItem::getDamage(){
    return damageDealer.getDamage();
}

int GameItem::getRange(){
    return damageDealer.getRange();
}