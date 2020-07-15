#ifndef REMOVE_ITEM_MAP_COMMAND_H
#define REMOVE_ITEM_MAP_COMMAND_H
#include "Command.h"

class PlayerHealthCommand: public Command{
    private:
        int health;

    public:
        PlayerHealthCommand(int health);

        void execute(Client& client);

};

#endif
