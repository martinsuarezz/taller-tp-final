#include <sstream>
#include "Player.h"

Player::Player() : Character() {
  this->name = "";
  this->level = 0;
  this->exp = 0;
  this->nextExp = 0;
}

Player::Player(std::string name) : Character() {
  this->name = name;
  this->level = 1;
  this->exp = 0;
  this->nextExp = 0;
}

// TODO: Make a Constructor with loaded data
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
