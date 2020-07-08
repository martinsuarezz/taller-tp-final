#include "GameInventory.h"
#include "Command/AddItemCommand.h"
#include "Command/RemoveItemCommand.h"
#include "Sender.h"
#include "GameItem/GameItem.h"
#include <stdexcept>
#include <map>
#include "GameItem/GameItemFactory.h"
#include "Configuration.h"

#define INV_SIZE 15

GameInventory::GameInventory(Sender& game): game(game), bareHands(itemFactory.getBareHands()){}

void GameInventory::moveItem(int from, int to){
    if (slotIsEmpty(from) || from == to)
        return;
    int item = removeItem(from);
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

void GameInventory::addItem(int itemId, int slot){
    if (!slotIsEmpty(slot))
        return;
    items.emplace(slot, std::move(itemFactory.getItem(itemId)));
    game.addCommand(new AddItemCommand(itemId, slot));
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
