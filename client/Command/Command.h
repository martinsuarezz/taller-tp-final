#ifndef COMMAND_H
#define COMMAND_H

class Client;

class Command{
    protected:
        int x;
        int y;

    public:
        Command(int x, int y);
        virtual void execute(Client& client) = 0;
        
};

#endif
