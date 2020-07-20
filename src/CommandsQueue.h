#ifndef COMMAND_QUEUE_H
#define COMMAND_QUEUE_H
#include <queue>
#include <mutex>

class Command;

// Cola bloqueante de comandos.

class CommandsQueue{
    private:
        std::queue<Command*> queue;
        std::mutex m;

    public:
        CommandsQueue();

        // Obtiene un puntero a un comando.
        // Quien lo pide se debe encargar de liberar la
        // memoria.
        Command* pop();

        // Recibe un puntero a un comando para agregarlo a la cola.
        void push(Command* command);

        // Devuelve si la cola esta vacía.
        bool isEmpty();

};

#endif
