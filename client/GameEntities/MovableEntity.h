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
        //MovableEntity(MovableEntity&&);
        void move(int direction);
        void moveUp();
        void moveRight();
        void moveDown();
        void moveLeft();
        void stop();
        
        void notifyIdle();
        
        void changeState();
        bool canMove(int x, int y);
        void updatePosition(int x, int y);
        void getAttacked(int damage, MovableEntity& attacker, bool critical = false);
        int getId();
        int getLevel();
        void notifyAttack(int weaponId, int x, int y, int duration);
        void consumeMana(int ammount);
        virtual bool hasManaAvailable(int mana);
        void addExperience(int experience);
        void addGold(int ammount);
        bool isInRange(MovableEntity& other, int range);
        bool isAlive();
        bool hasGoldAvailable(int ammount);
        void removeGold(int ammount);

        virtual int removeItem(int slot) = 0;
        virtual void revive() = 0;
        virtual void buyItem(MovableEntity& buyer, int itemIndex) = 0;
        virtual void interact(MovableEntity& other) = 0;
        virtual bool evadeAttack() = 0;
        virtual void notifyMovement(int direction, int x, int y) = 0;
        virtual void update(int time) = 0;
        virtual void kill(MovableEntity& killer) = 0;
        virtual int getDefense(int damage) = 0;
        virtual void attackEntity(MovableEntity& other) = 0;
        virtual void notifyPlayerMovement(int x, int y) = 0;
        virtual void notifyHealthUpdate(int newHealth) = 0;
        virtual void notifyExperienceUpdate(int experience) = 0;
        virtual void notifyLevelUpdate(int level) = 0;
        virtual void notifyManaUpdate(int mana) = 0;
        virtual void notifyGoldUpdate(int gold) = 0;
        virtual void moveInventoryItem(int from, int to) = 0;
        virtual bool addItem(int itemId, int slot) = 0;
        virtual ~MovableEntity();
};

#endif 
