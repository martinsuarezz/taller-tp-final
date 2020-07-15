#ifndef PLAYER_HEALTH_COMMAND_H
#define PLAYER_HEALTH_COMMAND_H
#include "Command.h"

class PlayerHealthCommand: public Command{
    private:
        int health;

    public:
        PlayerHealthCommand(int health);

        void execute(Client& client);

};

#endif
