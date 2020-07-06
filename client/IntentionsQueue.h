#ifndef INTENION_QUEUE_H
#define INTENION_QUEUE_H
#include <queue>
#include <mutex>
#include <condition_variable>

class Intention;

// Clase que modela la cola bloqueante de Intention.

class IntentionsQueue{
    private:
        std::queue<Intention*> queue;
        std::mutex m;
        std::condition_variable cv;
        bool isClosed;

    public:
        IntentionsQueue();

        // Obtiene un elemento de la cola. Quien lo extrae debe encargarse
        // de liberar la memoria. Si la cola está vacía el hilo duerme
        // con tomando la condition_variable
        Intention* pop();

        // Agrega el puntero a una intención a la cola.
        void push(Intention* intention);

        // Chequea si la cola esta vacía.
        bool isEmpty();

        // Cierra la cola.
        void close();

};

#endif
