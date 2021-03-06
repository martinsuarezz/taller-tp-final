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
#include "Command/EquipShieldCommand.h"
#include "Command/EquipHelmetCommand.h"
#include "Configuration.h"
#include <iostream>

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
    else if (slot == config.getValue("inv_shield_slot"))
        game.addCommand(new EquipShieldCommand(0, itemId));
    else if (slot == config.getValue("inv_helmet_slot"))
        game.addCommand(new EquipHelmetCommand(0, itemId));
}

int GameInventory::getEmptySlot(){
    Configuration& config = Configuration::getInstance();
    int invSize = config.getValue("inventory_slots");
    for (int i = 0; i < invSize; i++){
        if (slotIsEmpty(i))
            return i;
    }
    throw std::out_of_range("No empty space on inventory");
}

void GameInventory::notifyDeath(){
    Configuration& config = Configuration::getInstance();
    int invSize = config.getValue("inventory_slots");
    for (int i = 0; i < invSize; i++){
        removeItem(i);
    }
    moveItem(config.getValue("inv_weapon_slot"), 0);
    moveItem(config.getValue("inv_armor_slot"), 1);
    moveItem(config.getValue("inv_shield_slot"), 2);
    moveItem(config.getValue("inv_helmet_slot"), 3);
}

bool GameInventory::addItem(int itemId, int slot){
    if (slot == -1){
        try{
            slot = getEmptySlot();
        }
        catch(std::out_of_range& e){
            std::cout << "No empty space on inventory" << std::endl;
            return false;
        }
    }

    Configuration& config = Configuration::getInstance();
    if (!slotIsEmpty(slot))
        return false;
    items.emplace(slot, std::move(itemFactory.getItem(itemId)));
    game.addCommand(new AddItemCommand(itemId, slot));
    
    if (slot >= config.getValue("inventory_slots"))
        equipItem(itemId, slot);
    return true;
}

int GameInventory::removeItem(int slot){
    if (slotIsEmpty(slot))
        return 0;
    GameItem& item = items.at(slot);
    int itemId = item.getId();
    items.erase(slot);
    game.addCommand(new RemoveItemCommand(slot));

    Configuration& config = Configuration::getInstance();
    if (slot >= config.getValue("inventory_slots"))
        equipItem(-1, slot);

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
