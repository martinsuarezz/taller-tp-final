#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H
#include <memory>
#include "GameEntity.h"
#include "../GameInventory.h"
#include "MovableEntity.h"
#include "../State/State.h"

class GameMap;

class Sender;

class GameEntityContainer;

// Clase que modela una entidad de jugador.

class Player: public MovableEntity{
    private:
        GameEntityContainer& entities;
        GameInventory inventory;
        std::string race;
        std::string type;
        int strength;
        int agility;

    public:
        Player(Sender& game, GameMap& map, GameEntityContainer& entities, 
                int entityId, std::string race, std::string type, 
                int x, int y, int duration);

        // Notifica que el jugador se movió
        void notifyMovement(int direction, int x, int y);
        void notifyIdle();

        // Notifica que el jugador cambió su posicón.
        void notifyPlayerMovement(int x, int y);

        // Mueve un item del inventario.
        void moveInventoryItem(int from, int to);

        // Agrega un item al inventario.
        bool addItem(int itemId, int slot);

        // Quita un item del inventario,
        int removeItem(int slot);

        // Ataca a otra entidad.
        void attackEntity(MovableEntity& entity);

        // Notifica que valores del jugador han cambiado.
        void notifyHealthUpdate(int newHealth);
        void notifyExperienceUpdate(int experience);
        void notifyLevelUpdate(int level);
        void notifyManaUpdate(int mana);
        void notifyGoldUpdate(int gold);

        // Actualiza al jugador con el paso del tiempo.
        void update(int timeElapsed);

        // Chequea si evade un ataque.
        bool evadeAttack();

        // Mata a la entidad.        
        void kill(MovableEntity& killer);

        // Obtiene el ataque que recibe luego de aplicarle la defensa.
        int getDefense(int damage);

        // Interacciona con otro NPC.
        void interact(MovableEntity& other);

        // Revive al jugador.
        void revive();

        // Intenta comprar un item. No implementado para esta clase.
        void buyItem(MovableEntity& buyer, int itemIndex);
        ~Player();
};

#endif 
