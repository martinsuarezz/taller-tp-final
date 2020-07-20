#include "PlayerDeathCommand.h"
#include "../Client.h"

PlayerDeathCommand::PlayerDeathCommand(int entityId):
                            Command(0, 0), entityId(entityId){}

void PlayerDeathCommand::execute(Client& client){
    client.entityDeath(entityId);
}
