#ifndef REMOVE_MOB_COMMAND_H
#define REMOVE_MOB_COMMAND_H
#include "Command.h"

class RemoveMobCommand: public Command{
    private:
        int entityId;
        
    public:
        RemoveMobCommand(int entityId);
        void execute(Client& client);

};

#endif
