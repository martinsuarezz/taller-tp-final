#ifndef CLOCK_H
#define CLOCK_H
#include <chrono>

// Clase utilizable como cronómetro.

class Clock{
    private:
        int duration;
        std::chrono::_V2::steady_clock::time_point startTime;
        std::chrono::_V2::steady_clock::time_point endTime;
    
    public:
        Clock();

        // Comienza el cronómetro.
        void start();

        // Detine el cronómetro.
        void stop();

        // Obtiene la duración del tipo pasado entre
        // comenzar y para el cronómetro. El resultado
        // se obtiene en microsegundos.
        int getDuration() const;
};

#endif
