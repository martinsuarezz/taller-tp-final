#include "Inventory.h"
#include "Item.h"
#include "Configuration.h"
#include "Texture.h"
#include "AssetsLoader.h"
#include <map>
#include <stdexcept>
#include <iostream>

#define SLOT_SIZE 32

Inventory::Inventory(AssetsLoader& assets): assets(assets){
    Configuration& config = Configuration::getInstance();
    slots = config.getValue("inventory_slots") + config.getValue("equipment_slots");
    selected = -1;
}

int Inventory::getSlot(int x, int y){
    for(int slot = 0; slot < slots; slot++){
        if (slotIsInbound(x, y, slot))
            return slot;
    }
    throw std::runtime_error("Coordinates don't correspond to a valid slot");
}

void Inventory::addItem(int itemId, int position){
    if (position >= slots)
        throw std::out_of_range("Wrong inventory slot");

    items.emplace(std::make_pair(position, std::move(Item(itemId, assets))));
}

void Inventory::removeItem(int position){
    if (position >= slots)
        throw std::out_of_range("Wrong inventory slot");
    items.erase(position);
}

void Inventory::moveItem(int from, int to){
    if (from >= slots || to >= slots)
        throw std::out_of_range("Wrong inventory slot");
    if (from == to)
        return;
    int itemId = items.at(from).getItemId();
    items.emplace(std::make_pair(to, std::move(Item(itemId, assets))));
    items.erase(from);
}

int Inventory::getX(int position) const{
    if (position >= slots)
        throw std::out_of_range("Wrong inventory slot");
    
    Configuration& config = Configuration::getInstance();
    int windowWidth = config.getValue("window_width");
    int saveSlots = config.getValue("inventory_slots");
    int returnValue = 0;    
    
    if (position < saveSlots){
        int columns = config.getValue("inventory_columns");
        int initialX = windowWidth * config.getValue("inv_x_start_perc") / 100;
        int stepX = windowWidth * config.getValue("inv_x_step_perc") / 100;
        returnValue = initialX + (stepX * (position % columns));
    }
    else if (position == config.getValue("inv_helmet_slot")){
        returnValue = windowWidth * config.getValue("inv_x_helmet_slot_perc") / 100;
    }
    else if (position == config.getValue("inv_weapon_slot")){
        returnValue = windowWidth * config.getValue("inv_x_weapon_slot_perc") / 100;
    }
    else if (position == config.getValue("inv_armor_slot")){
        returnValue = windowWidth * config.getValue("inv_x_armor_slot_perc") / 100;
    }
    else if (position == config.getValue("inv_shield_slot")){
        returnValue = windowWidth * config.getValue("inv_x_shield_slot_perc") / 100;
    }
    return returnValue;
}

int Inventory::getY(int position) const{
    if (position >= slots)
        throw std::out_of_range("Wrong inventory slot");
    
    Configuration& config = Configuration::getInstance();
    int windowHeight = config.getValue("window_height");
    int saveSlots = config.getValue("inventory_slots");
    int returnValue = 0;    

    if (position < saveSlots){
        int columns = config.getValue("inventory_columns");
        int initialY = windowHeight * config.getValue("inv_y_start_perc") / 100;
        int stepY = windowHeight * config.getValue("inv_y_step_perc") / 100;
        returnValue = initialY + (stepY * (int)(position / columns));
    }
    else if (position == config.getValue("inv_helmet_slot")){
        returnValue = windowHeight * config.getValue("inv_y_helmet_slot_perc") / 100;
    }
    else if (position == config.getValue("inv_weapon_slot")){
        returnValue = windowHeight * config.getValue("inv_y_weapon_slot_perc") / 100;
    }
    else if (position == config.getValue("inv_armor_slot")){
        returnValue = windowHeight * config.getValue("inv_y_armor_slot_perc") / 100;
    }
    else if (position == config.getValue("inv_shield_slot")){
        returnValue = windowHeight * config.getValue("inv_y_shield_slot_perc") / 100;
    }
    return returnValue;
}

void Inventory::render(){
    if (selected != -1){
        Texture& selectionBox = assets.getTexture("selected_slot");
        selectionBox.render(getX(selected), getY(selected));
    }

    std::map<int, Item>::iterator it;
    for(it = items.begin(); it != items.end(); it++){
        int position = it->first;
        it->second.render(getX(position), getY(position));
    }
}

void Inventory::selectSlot(int slot){
    selected = slot;
}

void Inventory::resetSelection(){
    selected = -1;
}

void Inventory::handleLeftClick(int x, int y){
    
}

bool Inventory::slotIsInbound(int x, int y, int slot) const{
    if (slot >= slots)
        throw std::out_of_range("Wrong inventory slot");
    int slotX = getX(slot);
    int slotY = getY(slot);
    return (x > slotX) && (x < slotX + SLOT_SIZE) && (y > slotY) && (y < slotY + SLOT_SIZE);
}

Inventory::~Inventory(){}
