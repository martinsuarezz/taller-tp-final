#include "SpawnPlayerCommand.h"
#include "../Client.h"
#include <string>

SpawnPlayerCommand::SpawnPlayerCommand(int entityId, int x, int y, std::string& race):
                                Command(x, y), entityId(entityId), race(race) {}

void SpawnPlayerCommand::execute(Client& client){
    client.addPlayer(entityId, x, y, race);
}
