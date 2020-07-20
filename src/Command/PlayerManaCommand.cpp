#include "PlayerManaCommand.h"
#include "../Client.h"

PlayerManaCommand::PlayerManaCommand(int mana):
                            Command(0, 0), mana(mana){}

void PlayerManaCommand::execute(Client& client){
    client.updateMana(mana);
}
