#ifndef THREAD_H
#define THREAD_H
#include <thread>

class Thread{
    private:
        std::thread thread;

    public:
        Thread();

        // Comienza la ejecución del thread, se llama
        // a la función run.
        void start();

        // Se hace join del thread.
        void join();

        // Devuelve si el hilo esta ejecutandose en paralelo.
        bool joinable();

        // Las funciones que heredan de esta clase deben
        // implementar esta función. El thread realizará
        // lo que contenga esta función
        virtual void run() = 0;

        // Prohibo la copia de threads.
        Thread(const Thread&) = delete;
        Thread& operator=(const Thread&) = delete;

        Thread(Thread&&) = default;

        virtual ~Thread();
};

#endif
