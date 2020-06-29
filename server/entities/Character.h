#ifndef ARGENTUM_SERVER_CHARACTER_H_
#define ARGENTUM_SERVER_CHARACTER_H_

#include "Entity.h"
#include "../Config.h"

#define EMPTY ' '
#define PLAYER 'P'
#define CREATURE 'C'

class State;

class Character : public Entity {
 public:
  Character(World &world, int x, int y);

  bool isNextTo(Character *character);
  bool isNearFrom(Character *character);

  void setState(State* state);
  void react(Event event, Entity *sender) override = 0;
  void update(float dt) override;

  void moveRight();
  void moveLeft();
  void moveUp();
  void moveDown();

  void attack(Character *enemy);
  void receiveDamage(int damage);

  int getHealth();
  bool isAlive();

  virtual std::string toString() const = 0;

 protected:
  bool alive;
  State* state;
  int health;

  void dropItem();
};

#endif
