#include "GraphicalInterface.h"
#include "AssetsLoader.h"
#include "Configuration.h"
#include "Item.h"
#include "Renderer.h"
#include "Texture.h"
#include "Text.h"
#include <map>
#include <stdexcept>

GraphicalInterface::GraphicalInterface(AssetsLoader& assets): 
                    assets(assets), gui(assets.getTexture("interface")),
                    health(assets.getText("health")),
                    inventory(Inventory(assets)){

    Configuration& config = Configuration::getInstance();
    gui.setHeight(config.getValue("window_height"));
    gui.setWidth(config.getValue("window_width"));
}

void GraphicalInterface::render(){
    Configuration& config = Configuration::getInstance();
    gui.render(0, 0);

    int xHealth = config.getValue("gui_x_health_perc") * config.getValue("window_width") / 100;
    int yHealth = config.getValue("gui_y_health_perc") * config.getValue("window_height") / 100;
    health.render(xHealth, yHealth);
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

int GraphicalInterface::getInventorySlot(int x, int y) const{
    return inventory.getSlot(x, y);
}

int GraphicalInterface::getSelectedSlot() const{
    return inventory.getSelectedSlot();
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

void GraphicalInterface::updateHealth(int healthValue){
    health.changeText(std::to_string(healthValue));
}

GraphicalInterface::~GraphicalInterface(){}
