#include "MoveCommand.h"
#include "Client.h"

MoveCommand::MoveCommand(int entityId, int direction, int x, int y): entityId(entityId), direction(direction), x(x), y(y) {}

void MoveCommand::execute(Client& client){
    client.moveEntity(entityId, direction, x, y);
}