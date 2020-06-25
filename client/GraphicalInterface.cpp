#include "GraphicalInterface.h"
#include "AssetsLoader.h"
#include "Configuration.h"
#include "Item.h"
#include <map>
#include <stdexcept>
#include <iostream>

#define SLOT_SIZE 32

GraphicalInterface::GraphicalInterface(AssetsLoader& assets): assets(assets), gui(assets.getTexture("interface")), selected(-1){
    Configuration& config = Configuration::getInstance();
    gui.setHeight(config.getValue("window_height"));
    gui.setWidth(config.getValue("window_width"));
    inventorySlots = config.getValue("inventory_slots") + config.getValue("equipment_slots");
}

int GraphicalInterface::getX(int position) const{
    if (position >= inventorySlots)
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

int GraphicalInterface::getY(int position) const{
    if (position >= inventorySlots)
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

void GraphicalInterface::render(){
    gui.render(0, 0);
    
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

void GraphicalInterface::selectSlot(int slot){
    selected = slot;
}

void GraphicalInterface::resetSelection(){
    selected = -1;
}

bool GraphicalInterface::slotIsInbound(int x, int y, int slot) const{
    if (slot >= inventorySlots)
        throw std::out_of_range("Wrong inventory slot");
    int slotX = getX(slot);
    int slotY = getY(slot);
    return (x > slotX) && (x < slotX + SLOT_SIZE) && (y > slotY) && (y < slotY + SLOT_SIZE);

}

int GraphicalInterface::getInventarySlot(int x, int y){
    for(int slot = 0; slot < inventorySlots; slot++){
        if (slotIsInbound(x, y, slot))
            return slot;
    }
    throw std::runtime_error("Coordinates don't correspond to a valid slot");
}

void GraphicalInterface::addItem(int itemId, int position){
    if (position >= inventorySlots)
        throw std::out_of_range("Wrong inventory slot");

    items.emplace(std::make_pair(position, std::move(Item(itemId, assets))));
}

void GraphicalInterface::removeItem(int position){
    if (position >= inventorySlots)
        throw std::out_of_range("Wrong inventory slot");
    items.erase(position);
}

void GraphicalInterface::moveItem(int from, int to){
    if (from >= inventorySlots || to >= inventorySlots)
        throw std::out_of_range("Wrong inventory slot");
    if (from == to)
        return;
    int itemId = items.at(from).getItemId();
    items.emplace(std::make_pair(to, std::move(Item(itemId, assets))));
    items.erase(from);
}

GraphicalInterface::~GraphicalInterface(){
}