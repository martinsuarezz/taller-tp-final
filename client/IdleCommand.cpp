#include "IdleCommand.h"
#include "Client.h"

IdleCommand::IdleCommand(int entityId, int x, int y): entityId(entityId), x(x), y(y) {}

void IdleCommand::execute(Client& client){
    client.idleEntity(entityId, x, y);
}