#include "PlayerReviveCommand.h"
#include "../Client.h"

PlayerReviveCommand::PlayerReviveCommand(int entityId):
                            Command(0, 0), entityId(entityId){}

void PlayerReviveCommand::execute(Client& client){
    client.entityRevive(entityId);
}
