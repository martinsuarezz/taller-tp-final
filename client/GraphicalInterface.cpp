#include "GraphicalInterface.h"
#include "AssetsLoader.h"
#include "Configuration.h"
#include "Item.h"
#include <map>
#include <stdexcept>
#include <iostream>

GraphicalInterface::GraphicalInterface(AssetsLoader& assets): assets(assets), gui(assets.getTexture("interface")), inventory(Inventory(assets)),selected(-1){
    Configuration& config = Configuration::getInstance();
    gui.setHeight(config.getValue("window_height"));
    gui.setWidth(config.getValue("window_width"));
}

void GraphicalInterface::render(){
    gui.render(0, 0);
    inventory.render();
}

void GraphicalInterface::selectSlot(int slot){
    inventory.selectSlot(slot);
}

void GraphicalInterface::resetSelection(){
    inventory.resetSelection();
}

bool GraphicalInterface::slotIsInbound(int x, int y, int slot) const{
    return inventory.slotIsInbound(x, y, slot);
}

int GraphicalInterface::getInventorySlot(int x, int y){
    return inventory.getSlot(x, y);
}

void GraphicalInterface::addItemInventory(int itemId, int position){
    inventory.addItem(itemId, position);
}

void GraphicalInterface::removeItemInventory(int position){
    inventory.removeItem(position);
}

void GraphicalInterface::moveItemInventory(int from, int to){
    inventory.moveItem(from, to);
}

GraphicalInterface::~GraphicalInterface(){
}