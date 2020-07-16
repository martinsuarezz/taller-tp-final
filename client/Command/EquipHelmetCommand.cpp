#include "EquipHelmetCommand.h"
#include "../Client.h"

EquipHelmetCommand::EquipHelmetCommand(int entityId, int itemId): 
                Command(0, 0), entityId(entityId), itemId(itemId){}

void EquipHelmetCommand::execute(Client& client){
    client.equipHelmet(entityId, itemId);
}
