#ifndef ATTACK_COMMAND_H
#define ATTACK_COMMAND_H
#include "Command.h"

class AttackCommand: public Command{
    private:
        int itemId;
        int duration;

    public:

        AttackCommand(int itemId, int x, int y, int duration);

        void execute(Client& client);

};

#endif
