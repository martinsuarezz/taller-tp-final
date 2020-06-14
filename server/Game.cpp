#include "Game.h"

Game::Game() {
  this->idCounter = 1;
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
  Creature* creature = new Creature(world, idCounter);
  creature->setPosition(5, 1);
  world.notify(NEW_ENTITY, creature);
  idCounter++;
}

void Game::addCharacter(std::string &name) {
  Player* player = new Player(world, idCounter, name);
  players.insert(make_pair(name, player));
  player->setPosition(0, 0);
  world.notify(NEW_ENTITY, player);
  idCounter++;
}

void Game::move(int id, int nextX, int nextY) {
  Player* player = dynamic_cast<Player *>(world.getEntity(id));
  player->move(nextX, nextY);
}

Player *Game::getPlayer(std::string &name) {
  return players.find(name)->second;
}

Creature *Game::getCreature(int id) {
  return dynamic_cast<Creature *>(world.getEntity(id));
}

void Game::attack(int id, int idEnemy) {
  Entity *player = world.getEntity(id);
  Entity *enemy = world.getEntity(idEnemy);

  if (player != nullptr && enemy != nullptr) {
    ((Character *) player)->attack((Character *) enemy);
  }
}
