#ifndef PLAYER_REVIVE_COMMAND_H
#define PLAYER_REVIVE_COMMAND_H
#include "Command.h"

class PlayerReviveCommand: public Command{
    private:
        int entityId;

    public:
        PlayerReviveCommand(int entityId);

        void execute(Client& client);

};

#endif
