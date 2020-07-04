#ifndef IDLE_COMMAND_H
#define IDLE_COMMAND_H
#include "Command.h"

class IdleCommand: public Command{
    private:
        int entityId;

    public:
        IdleCommand(int entityId, int x, int y);
        void execute(Client& client);

};

#endif
