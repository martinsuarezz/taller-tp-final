#ifndef CLIENT_H
#define CLIENT_H
#include "Sender.h"
#include "GraphicalInterface.h"
#include "AssetsLoader.h"
#include "Entity.h"
#include "CommandsQueue.h"
#include "IntentionsQueue.h"
#include "MusicPlayer.h"
#include "EntityContainer.h"
#include "MapGraphic.h"
#include "Screen.h"
#include "MapGraphic.h"
#include "EventHandler.h"
#include "SFXGenerator.h"
#include <map>
#include <string>

class Window;

class Configuration;

// Clase que corre el game loop de la parte gráfica
// del juego.

class Client{
    private:
        Window& window;
        Renderer& renderer;
        Configuration& config;
        AssetsLoader assets;
        GraphicalInterface gui;
        CommandsQueue commands;
        IntentionsQueue intentions;
        Sender sender;
        MapGraphic map;
        Screen screen;
        MusicPlayer musicPlayer;
        EntityContainer entities;
        SFXGenerator effects;
        EventHandler eventHandler;
        SDL_Rect mapViewport;
        bool continueExectuion;

    public:
        Client(Window& window, std::string& race, std::string& type);

        // Ejecuta el ciclo del game loop.
        void run();

        // Comandan acciones de movimiento a entidades del juego
        void moveEntity(int entityId, int direction, int x, int y);
        void idleEntity(int entityId, int x, int y);

        // Modificaciones de items del inventario del jugador.
        void addItem(int itemId, int position);
        void removeItem(int position);
        void moveItem(int from, int to);

        // Ordenan a cierta entidad a equipar cierto item.
        void equipWeapon(int entityId, int itemId);
        void equipArmor(int entityId, int itemId);
        void equipShield(int entityId, int itemId);
        void equipHelmet(int entityId, int itemId);

        // Modificaciones de los items que se muestran dropeados
        // en el mapa.
        void addMapItem(int itemId, int x, int y);
        void removeItemMap(int x, int y);
        
        // Agregar o quitar entidades del juego.
        void addPlayer(int entityId, int x, int y, std::string& race);
        void addMob(int entityId, int x, int y, int type);
        void removeMob(int entityId);
        
        // Actualizaciones de los atributos en la GUI del jugador.
        void updateHealth(int health);
        void updateLevel(int level);
        void updateExperience(int experience);
        void updateMana(int mana);
        void updateGold(int gold);

        // Reproducción de la música de fondo del juego.
        void nextSong();
        void stopPlaySong();
        void previousSong();

        // Notifica de sucesos para que el cliente muestre
        // las animaciones y sonidos acordes.
        void notifyAttack(int itemId, int x, int y, int duration);
        void entityDeath(int entityId);
        void entityRevive(int entityId);
        void showProducts(std::vector<int>& products);
        
        // Obtiene las coordenadas del mapa en tiles para un respectivo
        // par (x, y) de pixeles de la pantalla.
        std::pair<int, int> getMapCoordinates(int x, int y);

        // Chequea si ciertas coordenadas de tiles del mapa
        // están visibles en la pantalla actual.
        bool isClickOnMapScreen(int x, int y);

        // Obtiene una referencia a la interfaz gráfica.
        GraphicalInterface& getGui();

        // Detener la ejecución del cliente.
        void stopExecution();

};

#endif
