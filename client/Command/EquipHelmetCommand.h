#ifndef EQUIP_HELMET_COMMAND_H
#define EQUIP_HELMET_COMMAND_H
#include "Command.h"

class EquipHelmetCommand: public Command{
    private:
        int entityId;
        int itemId;

    public:
        EquipHelmetCommand(int entityId, int itemId);

        void execute(Client& client);

};

#endif
