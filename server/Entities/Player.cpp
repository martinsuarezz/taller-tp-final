#include <sstream>
#include "Player.h"

Player::Player(World& world, std::string& name) : Character(world) {
  this->name = name;
  this->type = PLAYER;
  this->level = 1;
  this->exp = 0;
  this->nextExp = 0;
}

Player::~Player() {

}

std::string Player::getName() const {
  return this->name;
}

int Player::getLevel() const {
  return this->level;
}

int Player::getHealth() const {
  return this->health;
}

int Player::getExp() const {
  return this->exp;
}

std::string Player::toString() const {
  std::stringstream ss;

  ss << "Nombre: " << this->name << " - "
     << "Nivel: " << this->level << " - "
     << "Experiencia: " << this->exp << " - "
     << "Posicion X: " << this->x << " Y: " << this->y;

  return ss.str();
}

void Player::react(int event, Entity *sender) {
  switch(event) {
    case 0:
      break;
  }
}
