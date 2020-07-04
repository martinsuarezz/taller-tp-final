#include "SpawnMobCommand.h"
#include "../Client.h"

SpawnMobCommand::SpawnMobCommand(int entityId, int type, int x, int y): Command(x, y), entityId(entityId), type(type) {}

void SpawnMobCommand::execute(Client& client){
    client.addMob(entityId, x, y, type);
}