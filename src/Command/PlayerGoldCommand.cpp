#include "PlayerGoldCommand.h"
#include "../Client.h"

PlayerGoldCommand::PlayerGoldCommand(int gold):
                            Command(0, 0), gold(gold){}

void PlayerGoldCommand::execute(Client& client){
    client.updateGold(gold);
}
