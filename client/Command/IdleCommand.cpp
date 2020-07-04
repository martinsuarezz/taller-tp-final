#include "IdleCommand.h"
#include "../Client.h"

IdleCommand::IdleCommand(int entityId, int x, int y): Command(x, y), entityId(entityId) {}

void IdleCommand::execute(Client& client){
    client.idleEntity(entityId, x, y);
}