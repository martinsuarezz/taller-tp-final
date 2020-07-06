#include "SpawnPlayerCommand.h"
#include "../Client.h"

SpawnPlayerCommand::SpawnPlayerCommand(int entityId, int x, int y):
                                Command(x, y), entityId(entityId) {}

void SpawnPlayerCommand::execute(Client& client){
    client.addPlayer(entityId, x, y);
}
