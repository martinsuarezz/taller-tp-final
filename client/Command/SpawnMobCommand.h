#ifndef SPAWN_MOB_COMMAND_H
#define SPAWN_MOB_COMMAND_H
#include "Command.h"

class SpawnMobCommand: public Command{
    private:
        int entityId;
        int type;

    public:
        SpawnMobCommand(int entityId, int type, int x, int y);
        void execute(Client& client);

};

#endif
