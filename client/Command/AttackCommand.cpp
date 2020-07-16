#include "AttackCommand.h"
#include "../Client.h"

AttackCommand::AttackCommand(int itemId, int x, int y, int duration):
                        Command(x, y), itemId(itemId), duration(duration){}

void AttackCommand::execute(Client& client){
    client.notifyAttack(itemId, x / 100, y / 100, duration);
}
