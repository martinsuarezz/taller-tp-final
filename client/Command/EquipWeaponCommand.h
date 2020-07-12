#ifndef EQUIP_WEAPON_COMMAND_H
#define EQUIP_WEAPON_COMMAND_H
#include "Command.h"

class EquipWeaponCommand: public Command{
    private:
        int entityId;
        int itemId;

    public:
        EquipWeaponCommand(int entityId, int itemId);

        void execute(Client& client);

};

#endif
