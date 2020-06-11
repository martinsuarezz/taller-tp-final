#include "Game.h"

Game::Game() {
  this->running = true;
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
  world.addEntity(5, 1, creature);
}

void Game::addCharacter(std::string &name) {
  Player* newPlayer = new Player(world, name);
  players.insert(make_pair(name, newPlayer));
  world.addEntity(0, 0, newPlayer);
}


void Game::move(Player* player, int nextX, int nextY) {
  player->move(nextX, nextY);
}

Player* Game::getPlayer(std::string &name) {
  return players.find(name)->second;
}