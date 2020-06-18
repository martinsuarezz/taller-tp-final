#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

class Client;

class Communicator{
    private:
        Client& client;

    public:
        Communicator(Client& client);
        void sendCommand(int command);

};

#endif
