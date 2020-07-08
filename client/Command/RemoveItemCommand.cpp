#include "RemoveItemCommand.h"
#include "../Client.h"

RemoveItemCommand::RemoveItemCommand(int slot):
                            Command(0, 0), slot(slot){}

void RemoveItemCommand::execute(Client& client){
    client.removeItem(slot);
}
