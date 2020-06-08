#include <iostream>
#include "Game.h"

Game::Game() {
  this->running = true;
  this->map = new Map();
}

Game::~Game() {}

bool Game::isRunning() const {
  return this->running;
}

void Game::stop() {
  this->running = false;
}

std::string Game::draw() {
  return map->draw();
}

void Game::addCreature() {
  this->creature = new Creature();
  map->addCreature(creature);
}

void Game::addCharacter(std::string name) {
  this->player = new Player(name);
  map->addPlayer(player);
}


void Game::move(Player* player, int nextX, int nextY) {
  int actualX = player->getX();
  int actualY = player->getY();

  if(!map->hasObstacle(nextX, nextY) && map->isInbound(nextX, nextY)) {
    map->update(actualX, actualY, nextX, nextY, 2);
    player->setPosition(nextX, nextY);
    notify();
  }
}

void Game::notify() {
  if(creature->isNextTo(player)) {
    // TODO: Combat mode
  } else if(creature->isNearFrom(player)) {
    int actualX = creature->getX();
    int actualY = creature->getY();
    creature->moveTo(player);
    map->update(actualX, actualY, creature->getX(), creature->getY(), 3);
  }
}

// TODO: Just for testing
Player * Game::getPlayer() {
  return this->player;
}