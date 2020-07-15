#ifndef PLAYER_EXP_COMMAND_H
#define PLAYER_EXP_COMMAND_H
#include "Command.h"

class PlayerExpCommand: public Command{
    private:
        int experience;

    public:
        PlayerExpCommand(int experience);

        void execute(Client& client);

};

#endif
