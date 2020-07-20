#include "AddItemCommand.h"
#include "../Client.h"

AddItemCommand::AddItemCommand(int itemId, int slot):
                            Command(0, 0), itemId(itemId), slot(slot){}

void AddItemCommand::execute(Client& client){
    client.addItem(itemId, slot);
}
