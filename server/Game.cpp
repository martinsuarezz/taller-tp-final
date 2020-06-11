#include "Game.h"

Game::Game() {
  this->running = true;
  this->world = World();
}

Game::~Game() {}

bool Game::isRunning() const {
  return this->running;
}

void Game::stop() {
  this->running = false;
}

std::string Game::draw() {
  return world.draw();
}

void Game::addCreature() {
  Creature* creature = new Creature(world);
  //this->creatures.push_back(creature);
}

void Game::addCharacter(std::string &name) {
  //Player* player = new Player(world, name);
}


void Game::move(Player* player, int nextX, int nextY) {
  //player->move(nextX, nextY);
}


// TODO: Just for testing
Player * Game::getPlayer() {
  std::string str("asd");
  return new Player(world, str);
}