#ifndef COMMAND_H
#define COMMAND_H

class Client;

// Clase que modela un comando que la lógica del juego le envía
// a la parte gráfica para que realice las tareas acordes.

class Command{
    protected:
        int x;
        int y;

    public:
        // Recibe las coordenadas donde se encontrará la entidad objetivo
        // del comando. Las coordenadas deben ser ingresadas en múltiplos
        // de 100 de las posiciones del mapa de la lógica del juego.
        Command(int x, int y);

        virtual void execute(Client& client) = 0;
        
};

#endif
