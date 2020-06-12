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
  world.addEntity(5, 1, creature);
  idCounter++;
}

void Game::addCharacter(std::string &name) {
  Player* newPlayer = new Player(world, idCounter, name);
  players.insert(make_pair(name, newPlayer));
  world.addEntity(0, 0, newPlayer);
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
  Character* player = dynamic_cast<Character *>(world.getEntity(id));
  Character* enemy = dynamic_cast<Character *>(world.getEntity(idEnemy));

  player->attack(enemy);
}

