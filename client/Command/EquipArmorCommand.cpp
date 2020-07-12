#include "EquipArmorCommand.h"
#include "../Client.h"

EquipArmorCommand::EquipArmorCommand(int entityId, int itemId): 
                Command(0, 0), entityId(entityId), itemId(itemId){}

void EquipArmorCommand::execute(Client& client){
    client.equipArmor(entityId, itemId);
}
