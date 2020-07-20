#include "RemoveItemMapCommand.h"
#include "../Client.h"

RemoveItemMapCommand::RemoveItemMapCommand(int x, int y):
                            Command(x, y){}

void RemoveItemMapCommand::execute(Client& client){
    client.removeItemMap(x / 100, y / 100);
}
