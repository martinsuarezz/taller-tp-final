#include "PlayerHealthCommand.h"
#include "../Client.h"

PlayerHealthCommand::PlayerHealthCommand(int health):
                            Command(0, 0), health(health){}

void PlayerHealthCommand::execute(Client& client){
    client.updateHealth(health);
}
