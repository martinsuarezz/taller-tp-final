#ifndef EQUIP_HELMET_COMMAND_H
#define EQUIP_HELMET_COMMAND_H
#include "Command.h"

// Clase que modela que se equipó un item como casco.

class EquipHelmetCommand: public Command{
    private:
        int entityId;
        int itemId;

    public:
        EquipHelmetCommand(int entityId, int itemId);

        void execute(Client& client);

};

#endif
