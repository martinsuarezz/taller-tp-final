#ifndef GAME_INVENTORY_H
#define GAME_INVENTORY_H
#include <map>
#include "GameItem/GameItem.h"
#include "GameItem/GameItemFactory.h"

class Sender;

// Clase que modela el inventario de un jugador.

class GameInventory{
    private:
        std::map<int, GameItem> items;
        Sender& game;
        GameItemFactory itemFactory;
        GameItem bareHands;
        GameItem noArmor;
        int getEmptySlot();

    public:
        GameInventory(Sender& game);

        // Mueve un item de un slot a otro
        void moveItem(int from, int to);

        // Devuelve si un slot esta vacio
        bool slotIsEmpty(int slot) const;

        // Agrega un item a un slot
        bool addItem(int itemId, int slot);

        // Remueve un item de un slot
        int removeItem(int slot);

        // Equipa un item en un slot de equipamiento.
        void equipItem(int itemId, int slot);

        // Notifica que el jugador que contiene este inventario
        // ha muerto para poder remover sus items
        void notifyDeath();

        // Obtiene los items equipados en cada slot de equipamiento
        GameItem& getWeapon();
        GameItem& getArmor();
        GameItem& getHelmet();
        GameItem& getShield();
};

#endif
