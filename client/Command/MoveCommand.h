#ifndef MOVE_COMMAND_H
#define MOVE_COMMAND_H
#include "Command.h"

class MoveCommand: public Command{
    private:
        int entityId;
        int direction;

    public:
        MoveCommand(int entityId, int direction, int x, int y);
        void execute(Client& client);

};

#endif
