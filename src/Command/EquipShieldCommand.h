#ifndef EQUIP_SHIELD_COMMAND_H
#define EQUIP_SHIELD_COMMAND_H
#include "Command.h"

// Clase que se equipó un item como escudo.

class EquipShieldCommand: public Command{
    private:
        int entityId;
        int itemId;

    public:
        EquipShieldCommand(int entityId, int itemId);

        void execute(Client& client);

};

#endif
