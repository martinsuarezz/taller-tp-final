#include "EquipWeaponCommand.h"
#include "../Client.h"

EquipWeaponCommand::EquipWeaponCommand(int entityId, int itemId): 
                Command(0, 0), entityId(entityId), itemId(itemId){}

void EquipWeaponCommand::execute(Client& client){
    client.equipWeapon(entityId, itemId);
}
