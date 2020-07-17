#ifndef ATTACK_COMMAND_H
#define ATTACK_COMMAND_H
#include "Command.h"
#include <vector>

class ShowProductsCommand: public Command{
    private:
        std::vector<int> products;

    public:
        ShowProductsCommand(std::vector<int> products);

        void execute(Client& client);

};

#endif
