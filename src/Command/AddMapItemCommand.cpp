#include "AddMapItemCommand.h"
#include "../Client.h"

AddMapItemCommand::AddMapItemCommand(int itemId, int x, int y):
                            Command(x, y), itemId(itemId){}

void AddMapItemCommand::execute(Client& client){
    client.addMapItem(itemId, x / 100, y / 100);
}
