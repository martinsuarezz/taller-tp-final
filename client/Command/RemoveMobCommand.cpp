#include "RemoveMobCommand.h"
#include "../Client.h"

RemoveMobCommand::RemoveMobCommand(int entityId): Command(-1, -1), entityId(entityId) {}

void RemoveMobCommand::execute(Client& client){
    client.removeMob(entityId);
}