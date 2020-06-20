#include <iostream>
#include <sstream>
#include "Game.h"

Game::Game() {
  this->idCounter = 1;

  this->addPlayer("Emi");
  this->addCreature();
}

Game::~Game() {}

void Game::handle(Command& command) {
  auto* player = (Player*) world.getEntity(command.getSenderId());

  switch(command.getAction()) {
    case MOVE_UP:
      player->moveUp();
      break;
    case MOVE_DOWN:
      player->moveDown();
      break;
    case MOVE_RIGHT:
      player->moveRight();
      break;
    case MOVE_LEFT:
      player->moveLeft();
      break;
    case MAKE_ATTACK: {
      auto *enemy = (Character *) world.getEntity(command.getTargetId());
      if (enemy != nullptr)
        player->attack(enemy);
      }
      break;
     default:
      std::cout << "Opción invalida";
  }
}

std::string Game::draw() {
  std::stringstream ss;
  ss << ((Player*) world.getEntity(1))->toString() << "\n";
  ss << ((Creature*) world.getEntity(2))->toString() << "\n";
  ss << world.draw() << "\n";
  return ss.str();
}

void Game::addCreature() {
  auto* creature = new Creature(world, idCounter);
  creature->setPosition(5, 1);
  world.notify(NEW_ENTITY, creature);
  idCounter++;
}

void Game::addPlayer(std::string name) {
  auto* player = new Player(world, idCounter, name);
  players.insert(make_pair(name, player));
  player->setPosition(0, 0);
  world.notify(NEW_ENTITY, player);
  idCounter++;
}

void Game::attack(int id, int idEnemy) {
  Entity *player = world.getEntity(id);
  Entity *enemy = world.getEntity(idEnemy);

  if (player != nullptr && enemy != nullptr) {
    ((Character *) player)->attack((Character *) enemy);
  }
}

void Game::pushClient(ClientPeer *client) {
  clients.push_back(client);
}

void Game::notifyClients() {
  for(auto client: clients) {
    //client->notify();
  }
}
