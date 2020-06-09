#include <iostream>

#include "server/Game.h"

void printMenu() {
  std::cout << "Menu:" << std::endl;
  std::cout << "1) Salir" << std::endl;
  std::cout << "2) Arriba" << std::endl;
  std::cout << "3) Abajo" << std::endl;
  std::cout << "4) Derecha" << std::endl;
  std::cout << "5) Izquierda" << std::endl;
}

int main() {
  Game game;

  std::string command;

  game.addCharacter("Emi");
  game.addCreature();
  Player* character = game.getPlayer();

  while(game.isRunning()) {

    std::cout << character->toString() << std::endl;

    std::cout << game.draw() << std::endl;

    printMenu();

    std::cin >> command;
    std::cout << std::endl;

    switch(std::stoi(command)) {
      case 1:
        game.stop();
        break;
      case 2:
        game.move(character, character->getX(), character->getY() - 1);
        break;
      case 3:
        game.move(character, character->getX(), character->getY() + 1);
        break;
      case 4:
        game.move(character, character->getX() + 1, character->getY());
        break;
      case 5:
        game.move(character, character->getX() - 1, character->getY());
        break;
      default:
        std::cout << "Opción invalida";
    }
  }

  return 0;
}
