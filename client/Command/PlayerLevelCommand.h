#ifndef PLAYER_LEVEL_COMMAND_H
#define PLAYER_LEVEL_COMMAND_H
#include "Command.h"

class PlayerLevelCommand: public Command{
    private:
        int level;

    public:
        PlayerLevelCommand(int level);

        void execute(Client& client);

};

#endif
