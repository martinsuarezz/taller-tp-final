#include "MoveCommand.h"
#include "../Client.h"

MoveCommand::MoveCommand(int entityId, int direction, int x, int y): Command(x, y), entityId(entityId), direction(direction){
}

void MoveCommand::execute(Client& client){
    client.moveEntity(entityId, direction, x, y);
}
