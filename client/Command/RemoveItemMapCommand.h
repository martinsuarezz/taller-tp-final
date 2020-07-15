#ifndef REMOVE_ITEM_MAP_COMMAND_H
#define REMOVE_ITEM_MAP_COMMAND_H
#include "Command.h"

class RemoveItemMapCommand: public Command{
    private:

    public:
        RemoveItemMapCommand(int x, int y);

        void execute(Client& client);

};

#endif
