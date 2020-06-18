#ifndef CLIENT_H
#define CLIENT_H
#include "Communicator.h"

class Window;

class Client{
    private:
        Communicator communicator;
        Window& window;

    public:
        Client(Window& window);
        void run();
        void sendOrder(int order);

};

#endif
