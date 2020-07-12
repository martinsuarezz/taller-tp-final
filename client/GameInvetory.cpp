#include "GameInventory.h"
#include "Command/AddItemCommand.h"
#include "Command/RemoveItemCommand.h"
#include "Sender.h"
#include "GameItem/GameItem.h"
#include <stdexcept>
#include <map>
#include "GameItem/GameItemFactory.h"
#include "Command/EquipWeaponCommand.h"
#include "Command/EquipArmorCommand.h"
#include "Configuration.h"

#define INV_SIZE 15

GameInventory::GameInventory(Sender& game): game(game), 
                            bareHands(itemFactory.getBareHands()),
                            noArmor(itemFactory.getNoArmor()){}

void GameInventory::moveItem(int from, int to){
    if (slotIsEmpty(from) || from == to)
        return;
    if (!items.at(from).canBeEquipped(to))
        return;
    int item = removeItem(from);
    if (!slotIsEmpty(to)){
        int item2 = removeItem(to);
        addItem(item2, from);
    }
    addItem(item, to);
}

bool GameInventory::slotIsEmpty(int slot) const{
    try{
        items.at(slot);
        return false;
    }
    catch (std::out_of_range& e) {}
    return true;
}

void GameInventory::equipItem(int itemId, int slot){
    Configuration& config = Configuration::getInstance();
    if (slot == config.getValue("inv_weapon_slot"))
        game.addCommand(new EquipWeaponCommand(0, itemId));
    else if (slot == config.getValue("inv_armor_slot"))
        game.addCommand(new EquipArmorCommand(0, itemId));
}

void GameInventory::addItem(int itemId, int slot){
    Configuration& config = Configuration::getInstance();
    if (!slotIsEmpty(slot))
        return;
    items.emplace(slot, std::move(itemFactory.getItem(itemId)));
    game.addCommand(new AddItemCommand(itemId, slot));
    
    if (slot >= config.getValue("inventory_slots"))
        equipItem(itemId, slot);
}

int GameInventory::removeItem(int slot){
    if (slotIsEmpty(slot))
        return 0;
    GameItem& item = items.at(slot);
    int itemId = item.getId();
    items.erase(slot);
    game.addCommand(new RemoveItemCommand(slot));
    return itemId;
}

GameItem& GameInventory::getWeapon(){
    Configuration& config = Configuration::getInstance();
    try{
        return items.at(config.getValue("inv_weapon_slot"));
    }
    catch (std::out_of_range& e){}
    return bareHands;
}

GameItem& GameInventory::getArmor(){
    Configuration& config = Configuration::getInstance();
    try{
        return items.at(config.getValue("inv_armor_slot"));
    }
    catch (std::out_of_range& e){}
    return noArmor;
}

GameItem& GameInventory::getHelmet(){
    Configuration& config = Configuration::getInstance();
    try{
        return items.at(config.getValue("inv_helmet_slot"));
    }
    catch (std::out_of_range& e){}
    return noArmor;
}

GameItem& GameInventory::getShield(){
    Configuration& config = Configuration::getInstance();
    try{
        return items.at(config.getValue("inv_shield_slot"));
    }
    catch (std::out_of_range& e){}
    return bareHands;
}
