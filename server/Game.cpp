#include <iostream>
#include <sstream>
#include "Game.h"

Game::Game() {
  this->idCounter = 1;

  this->addCreature(2, 1);
  this->addCreature(3, 1);
  this->addItem(5,0);
}

Game::~Game() {}

void Game::handle(Command &command) {
  auto *player = (Player *) world.getEntity(command.getSenderId());

  switch (command.getAction()) {
    case MOVE_UP: player->moveUp();
      break;
    case MOVE_DOWN: player->moveDown();
      break;
    case MOVE_RIGHT: player->moveRight();
      break;
    case MOVE_LEFT: player->moveLeft();
      break;
    case MAKE_ATTACK: {
      auto *enemy = (Character *) world.getEntity(command.getTargetId());
      if (enemy != nullptr)
        player->attack(enemy);
      }
      break;
    case JOIN:
      this->addPlayer("Emi");
      break;
    case DISCONNECT:
      this->removePlayer("Emi");
      break;
    default:
      std::cout << "Opción invalida";
  }
}

std::string Game::draw() {
  std::stringstream ss;
  ss << ((Player *) world.getEntity(1))->toString() << "\n";
  //ss << ((Creature*) world.getEntity(2))->toString() << "\n";
  ss << world.draw() << "\n";
  return ss.str();
}

void Game::addCreature(int x, int y) {
  auto *creature = new Creature(world, idCounter);
  creature->setPosition(x, y);
  world.notify(NEW_ENTITY, creature);
  idCounter++;
}

void Game::addPlayer(std::string name) {
  auto *player = new Player(world, idCounter, name);
  players.insert(make_pair(name, player));
  player->setPosition(0, 0);
  world.notify(NEW_ENTITY, player);
  idCounter++;
}

void Game::removePlayer(std::string name) {
  auto *player = players.at(name);
  world.notify(REMOVE_ENTITY, player);
}

void Game::addItem(int x, int y) {
  auto *item = new Item();
  item->setPosition(4, 0);
  world.notify(NEW_ENTITY, item);
  idCounter++;
}

void Game::pushClient(ClientPeer *client) {
  clients.push_back(client);
}

void Game::notifyClients() {
  ProtocolMessage message;
  for (auto client: clients) {
    client->notify(message);
  }
}
