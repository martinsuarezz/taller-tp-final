#ifndef COMMAND_H
#define COMMAND_H

class Client;

class Command{
    private:

    public:
        virtual void execute(Client& client) = 0;
        
};

#endif
