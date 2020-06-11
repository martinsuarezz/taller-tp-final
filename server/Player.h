#ifndef ARGENTUM__CHARACTER_H_
#define ARGENTUM__CHARACTER_H_

#include <string>
#include "Character.h"

class Player : public Character {

 public:
  Player(World& map, std::string& name);

  std::string getName() const;

  int getLevel() const;
  int getExp() const;
  int getHealth() const;

  std::string toString() const;

  ~Player();
 private:
  std::string name;

  int level;
  int health;
  int exp;
  int nextExp;
};

#endif