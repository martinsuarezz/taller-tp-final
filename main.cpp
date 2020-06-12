#include <iostream>

#include "server/Game.h"

void printMenu() {
  std::cout << "Menu:" << std::endl;
  std::cout << "1) Salir" << std::endl;
  std::cout << "2) Arriba" << std::endl;
  std::cout << "3) Abajo" << std::endl;
  std::cout << "4) Derecha" << std::endl;
  std::cout << "5) Izquierda" << std::endl;
  std::cout << "6) Atacar" << std::endl;
}

int main() {
  std::string name = "Emi";
  Game game;

  std::string command;

  game.addCharacter(name);
  game.addCreature();
  game.addCreature();
  Player* character = game.getPlayer(name);
  Creature* creature1 = game.getCreature(2);
  Creature* creature2 = game.getCreature(3);

  while(game.isRunning()) {

    std::cout << character->toString() << std::endl;
    std::cout << creature1->toString() << std::endl;
    std::cout << creature2->toString() << std::endl;

    std::cout << game.draw() << std::endl;

    printMenu();

    std::cin >> command;
    std::cout << std::endl;

    switch(std::stoi(command)) {
      case 1:
        game.stop();
        break;
      case 2:
        game.move(character->getId(), character->getX(), character->getY() - 1);
        break;
      case 3:
        game.move(character->getId(), character->getX(), character->getY() + 1);
        break;
      case 4:
        game.move(character->getId(), character->getX() + 1, character->getY());
        break;
      case 5:
        game.move(character->getId(), character->getX() - 1, character->getY());
        break;
      case 6:
        game.attack(character->getId(), creature1->getId());
      default:
        std::cout << "Opción invalida";
    }
  }

  return 0;
}
