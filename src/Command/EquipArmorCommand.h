#ifndef EQUIP_ARMOR_COMMAND_H
#define EQUIP_ARMOR_COMMAND_H
#include "Command.h"

// Clase que modela que se equipó un item como armadura.

class EquipArmorCommand: public Command{
    private:
        int entityId;
        int itemId;

    public:
        EquipArmorCommand(int entityId, int itemId);

        void execute(Client& client);

};

#endif
