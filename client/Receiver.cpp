#include "Receiver.h"
#include "CommandsQueue.h"
#include "Command.h"
#include "MoveCommand.h"
#include "IdleCommand.h"
#include "Package.h"
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <istream>
#include <fstream>

enum directions{UP, RIGHT, DOWN, LEFT};
std::ifstream file("input.txt");

Receiver::Receiver(CommandsQueue& queue): commandsQueue(queue), package(Package((char*) "\0")){
}

void Receiver::receivePackage(){
    //std::string inputLine;
    //std::getline(std::cin, inputLine);
    char buffer[13] = "";

    file.read(buffer, 13);
 
    std::cout << "String: " << buffer << std::endl;
    package = std::move(Package(buffer));
}

void Receiver::run(){
    while(1){
        receivePackage();
        int commandId = package[0];

        if (commandId <= 9){
            int entityId = package[1];
            int x = package[2];
            int y = package[3];
            switch(commandId){
                case 1:
                    commandsQueue.push(new IdleCommand(entityId, x, y));
                    break;
                
                default:
                    commandsQueue.push(new MoveCommand(entityId, commandId - 2, x, y));
                    break;
            }   
        }
        else if(commandId <= 11){
            /*
            int itemId = package[1];
            int x = package[2];
            int y = package[3];
            switch(commandId){
                case 11:
                    //Agregar item mapa
                    break;
            } 
            */
        }
        usleep(100000);
    }
    
}