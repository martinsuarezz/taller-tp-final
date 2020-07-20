#include "EquipShieldCommand.h"
#include "../Client.h"

EquipShieldCommand::EquipShieldCommand(int entityId, int itemId): 
                Command(0, 0), entityId(entityId), itemId(itemId){}

void EquipShieldCommand::execute(Client& client){
    client.equipShield(entityId, itemId);
}
