#ifndef ENTITY_H
#define ENTITY_H

#include "Texture.h"
#include "Sound.h"
#include "Action/Action.h"
#include <memory>
#include <map>
#include <string>

class AssetsLoader;

class Screen;

// Clase que modela una entidad en el entorno gráfico.

class Entity{
    private:
        int x;
        int y;
        AssetsLoader& assets;
        Screen& screen;
        std::map<std::string, std::string> equiped;
        std::unique_ptr<Action> action;

    public:
        Entity(AssetsLoader& assets, Screen& screen, 
                std::map<std::string, std::string> equiped, 
                int x, int y);
        
        // Actualiza la entidad correspondiente al paso del tiempo.
        void update(int timeElapsed);

        // Obtiene la ubicación en pixeles de la entidad.
        int getPixelsX() const;
        int getPixelsY() const;

        // Obtiene la ubicación en pixeles de la entidad relativo al
        // comienzo de la pantalla.
        int getRelativeX() const;
        int getRelativeY() const;

        // Mueve la entidad a las coordenadas indicadas en pixeles absolutos.
        void moveUp(int x, int y);
        void moveDown(int x, int y);
        void moveRight(int x, int y);
        void moveLeft(int x, int y);

        // Actualiza la posición a las coordenadas indicadas en pixeles absolutos.
        void updatePosition(int x, int y);

        // La entidad pasa a estar idle en las coordenadas indicadas.
        void idle(int x, int y);
        
        // Actualiza la acción que está realizando.
        void updateAction(Action* newAction);

        // Obtiene los items equipados por la entidad.
        std::map<std::string, std::string>& getEquipedItems();

        // Devuelve si la entidad se encuentra en la pantalla.
        bool isOnScreen() const;
        
        // Equipa un arma
        void equipWeapon(int itemId);

        // Equipa una armadura.
        void equipArmor(int itemId);

        void equipShield(int itemId);

        void equipHelmet(int itemId);

        Entity(Entity&&);
};

#endif
