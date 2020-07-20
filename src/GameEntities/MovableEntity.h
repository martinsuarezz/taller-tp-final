#ifndef MOVABLE_ENTITY_H
#define MOVABLE_ENTITY_H
#include <memory>
#include "GameEntity.h"
#include "../State/State.h"
#include "Health.h"
#include "Level.h"
#include "Mana.h"
#include "GoldContainer.h"

class GameMap;

class Sender;

// Clase que modela una entidad que se puede mover.

class MovableEntity: public GameEntity{
    protected:
        std::unique_ptr<State> state;
        std::unique_ptr<State> nextState;
        int entityId;
        int moveSpeed;
        Health health;
        Level level;
        Mana mana;
        GoldContainer gold;
        bool alive;

    public:
        MovableEntity(Sender& game, GameMap& map, int entityId, int x, int y, int moveSpeed, bool alive = true);

        // Determinan el próximo estado de la entidad.
        void move(int direction);
        void moveUp();
        void moveRight();
        void moveDown();
        void moveLeft();
        void stop();
        
        // Cambia el estado de la entidad al próximo.
        void changeState();

        // Chequea si es posible moverse hacia dichas coordenadas.
        bool canMove(int x, int y);

        // Actualiza la posición de la entidad.
        void updatePosition(int x, int y);

        // Recibe un ataque de otra entidad.
        void getAttacked(int damage, MovableEntity& attacker, bool critical = false);

        // Obtiene la id de la entidad.
        int getId();

        // Obtiene el nivel de la entidad.
        int getLevel();

        // Notifican a la parte gráfica los sucesos.
        void notifyAttack(int weaponId, int x, int y, int duration);
        void notifyIdle();

        // Consume la mana determinada.
        void consumeMana(int ammount);

        // Chequea si tiene disponible la mana determinada.
        virtual bool hasManaAvailable(int mana);

        // Agrega experiencia a la entidad.
        void addExperience(int experience);

        // Agrega oro a la entidad.
        void addGold(int ammount);

        // Chequea si está entidad esta en rango de otra.
        bool isInRange(MovableEntity& other, int range);

        // Devuelve si está viva.
        bool isAlive();

        // Chequea si tiene disponible la cantidad de oro determinado.
        bool hasGoldAvailable(int ammount);

        // Remueve la cantidad de oro determinado.
        void removeGold(int ammount);

        virtual int removeItem(int slot) = 0;
        virtual bool addItem(int itemId, int slot) = 0;
        
        virtual void revive() = 0;

        virtual void buyItem(MovableEntity& buyer, int itemIndex) = 0;
        virtual void interact(MovableEntity& other) = 0;
        virtual bool evadeAttack() = 0;
        virtual void update(int time) = 0;
        virtual void kill(MovableEntity& killer) = 0;
        virtual int getDefense(int damage) = 0;

        virtual void attackEntity(MovableEntity& other) = 0;
        virtual void notifyMovement(int direction, int x, int y) = 0;
        virtual void notifyPlayerMovement(int x, int y) = 0;
        virtual void notifyHealthUpdate(int newHealth) = 0;
        virtual void notifyExperienceUpdate(int experience) = 0;
        virtual void notifyLevelUpdate(int level) = 0;
        virtual void notifyManaUpdate(int mana) = 0;
        virtual void notifyGoldUpdate(int gold) = 0;
        virtual void moveInventoryItem(int from, int to) = 0;
        virtual ~MovableEntity();
};

#endif 
