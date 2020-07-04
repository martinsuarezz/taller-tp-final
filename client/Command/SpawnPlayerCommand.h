#ifndef SPAWN_PLAYER_COMMAND_H
#define SPAWN_PLAYER_COMMAND_H
#include "Command.h"

class SpawnPlayerCommand: public Command{
    private:
        int entityId;
        int type;

    public:
        SpawnPlayerCommand(int entityId, int x, int y);
        void execute(Client& client);

};

#endif
