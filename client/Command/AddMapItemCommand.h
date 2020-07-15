#ifndef ADD_MAP_ITEM_COMMAND_H
#define ADD_MAP_ITEM_COMMAND_H
#include "Command.h"

class AddMapItemCommand: public Command{
    private:
        int itemId;

    public:
        AddMapItemCommand(int itemId, int x, int y);

        void execute(Client& client);

};

#endif
