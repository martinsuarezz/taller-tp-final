#ifndef MOVABLE_ENTITY_H
#define MOVABLE_ENTITY_H
#include <memory>
#include "GameEntity.h"
#include "../State/State.h"
#include "Health.h"
#include "Level.h"
#include "Mana.h"

class GameMap;

class Sender;

class MovableEntity: public GameEntity{
    protected:
        std::unique_ptr<State> state;
        std::unique_ptr<State> nextState;
        int entityId;
        int moveSpeed;
        Health health;
        Level level;
        Mana mana;

    public:
        MovableEntity(Sender& game, GameMap& map, int entityId, int x, int y, int moveSpeed);
        //MovableEntity(MovableEntity&&);
        void move(int direction);
        void moveUp();
        void moveRight();
        void moveDown();
        void moveLeft();
        void stop();
        virtual void notifyMovement(int direction, int x, int y) = 0;
        void notifyIdle();
        virtual void update(int time) = 0;
        void changeState();
        bool canMove(int x, int y);
        void updatePosition(int x, int y);
        void getAttacked(int damage, MovableEntity& attacker, bool critical = false);
        int getId();
        int getLevel();
        void consumeMana(int ammount);
        virtual bool hasManaAvailable(int mana);
        void addExperience(int experience);
        virtual bool evadeAttack() = 0;
        bool isInRange(MovableEntity& other, int range);
        virtual void kill() = 0;
        virtual int getDefense(int damage) = 0;
        virtual void attackEntity(MovableEntity& other) = 0;
        virtual void notifyPlayerMovement(int x, int y) = 0;
        virtual void notifyHealthUpdate(int newHealth) = 0;
        virtual void notifyExperienceUpdate(int experience) = 0;
        virtual void notifyLevelUpdate(int level) = 0;
        virtual void notifyManaUpdate(int mana) = 0;
        virtual void moveInventoryItem(int from, int to) = 0;
        virtual void addItem(int itemId, int slot) = 0;
        virtual ~MovableEntity();
};

#endif 
