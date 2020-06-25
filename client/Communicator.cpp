#include "Communicator.h"
#include "CommandsQueue.h"
#include "Command.h"
#include "MoveCommand.h"
#include <iostream>
#include <string>

Communicator::Communicator(CommandsQueue& queue): commandsQueue(queue){}

void Communicator::run(){
    std::string inputText;
    int x = 12;
    int y = 16;
    while (std::getline(std::cin, inputText)){
        if (inputText == "right"){
            x += 2;
            commandsQueue.push(new MoveCommand(1, 1, x, y));
        }
        if (inputText == "down"){
            y += 2;
            commandsQueue.push(new MoveCommand(1, 2, x, y));
        }
        if (inputText == "exit"){
            break;
        }
    }    
}