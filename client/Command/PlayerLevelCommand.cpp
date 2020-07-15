#include "PlayerLevelCommand.h"
#include "../Client.h"

PlayerLevelCommand::PlayerLevelCommand(int level):
                            Command(0, 0), level(level){}

void PlayerLevelCommand::execute(Client& client){
    client.updateLevel(level);
}
