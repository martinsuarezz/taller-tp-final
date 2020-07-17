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
                    level(assets.getText("level")),
                    experience(assets.getText("exp")),
                    mana(assets.getText("mana")),
                    gold(assets.getText("gold")),
                    inventory(Inventory(assets)){

    Configuration& config = Configuration::getInstance();
    gui.setHeight(config.getValue("window_height"));
    gui.setWidth(config.getValue("window_width"));
}

void GraphicalInterface::render(){
    Configuration& config = Configuration::getInstance();
    gui.render(0, 0);
    inventory.render();

    int xHealth = config.getValue("gui_x_health_perc") * config.getValue("window_width") / 100;
    int yHealth = config.getValue("gui_y_health_perc") * config.getValue("window_height") / 100;
    health.render(xHealth, yHealth);

    int xLevel = config.getValue("gui_x_level_perc") * config.getValue("window_width") / 100;
    int yLevel = config.getValue("gui_y_level_perc") * config.getValue("window_height") / 100;
    level.render(xLevel, yLevel);

    int xExperience = config.getValue("gui_x_exp_perc") * config.getValue("window_width") / 100;
    int yExperience = config.getValue("gui_y_exp_perc") * config.getValue("window_height") / 100;
    experience.render(xExperience, yExperience);
    
    int xMana = config.getValue("gui_x_mana_perc") * config.getValue("window_width") / 100;
    int yMana = config.getValue("gui_y_mana_perc") * config.getValue("window_height") / 100;
    mana.render(xMana, yMana);

    int xGold = config.getValue("gui_x_gold_perc") * config.getValue("window_width") / 100;
    int yGold = config.getValue("gui_y_gold_perc") * config.getValue("window_height") / 100;
    gold.render(xGold, yGold);
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

void GraphicalInterface::updateLevel(int levelValue){
    level.changeText(std::to_string(levelValue));
}

void GraphicalInterface::updateExperience(int expValue){
    experience.changeText(std::to_string(expValue));
}

void GraphicalInterface::updateMana(int manaValue){
    mana.changeText(std::to_string(manaValue));
}

void GraphicalInterface::updateGold(int goldValue){
    gold.changeText(std::to_string(goldValue));
}

GraphicalInterface::~GraphicalInterface(){}
