#ifndef IDLE_COMMAND_H
#define IDLE_COMMAND_H
#include "Command.h"

class IdleCommand: public Command{
    private:
        int entityId;
        int x;
        int y;

    public:
        IdleCommand(int entityId, int x, int y);
        void execute(Client& client);

};

#endif
