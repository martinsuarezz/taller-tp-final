#ifndef PLAYER_MANA_COMMAND_H
#define PLAYER_MANA_COMMAND_H
#include "Command.h"

class PlayerManaCommand: public Command{
    private:
        int mana;

    public:
        PlayerManaCommand(int mana);

        void execute(Client& client);

};

#endif
