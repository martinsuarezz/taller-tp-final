#ifndef SENDER_H
#define SENDER_H
#include "Thread.h"
#include "GameEntities/MovableEntity.h"
#include "GameMap.h"
#include "GameEntityContainer.h"

class Command;

class IntentionsQueue;

class CommandsQueue;

class MovableEntity;

// Clase que maneja la lógica del juego
// desde la parte ex server.

// ACLARACIÓN: Utilizo PLAYER_ID que equivale a 0 en varios lugares del
// código. Esta es la id del jugador ya que es el primero en agregarse
// al juego. En una arquitectura multicliente cada jugador tendría
// su id única.

class Sender: public Thread{
    private:
        IntentionsQueue& intentions;
        CommandsQueue& commands;
        GameMap map;
        GameEntityContainer entities;
        bool continueRunning;

    public:
        Sender(IntentionsQueue& intentions, CommandsQueue& commands,
                    std::string& race, std::string& name);

        // Ejecuta la aplicación, es llamada por Thread al
        // comenzar el hilo.
        void run();
        
        // Mueve una entidad en una dirección.
        void movePlayer(int direction);

        // Detiene el movimiento del jugador.
        void stopMovementPlayer();

        // Agrega un comando a la lista de comandos para
        // enviarselo a la parte gráfica.
        void addCommand(Command* command);
        
        // Notifica que el jugador quiere tomar un item
        // del piso.
        void pickUpItem();

        // Notifica que el jugador quiere interaccionar con
        // un NPC.
        void interact();

        // Notifica que el jugador quiere comprar un item.
        void buyItem(int itemIndex);

        // Notifica que el jugador quiere tirar un item de
        // su inventario,
        void tossItem(int slot);

        // Notifica que el jugador quiere mover un item
        // de un lugar a otro de su inventario.
        void moveInventoryItem(int from, int to);

        // Se le agrega un item al inventario del jugador.
        void addItem(int itemId, int slot = -1);

        // Notifica que el jugador quiere atacar hacia cierta
        // coordenada.
        void attackEntity(int x, int y);

        // Remueve una entidad del juego.
        void removeMob(int id);

        // Obtiene al jugador.
        MovableEntity& getPlayer();
        
        // Cierra la ejecución del game loop-
        void close();

};

#endif
