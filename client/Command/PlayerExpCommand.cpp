#include "PlayerExpCommand.h"
#include "../Client.h"

PlayerExpCommand::PlayerExpCommand(int experience):
                            Command(0, 0), experience(experience){}

void PlayerExpCommand::execute(Client& client){
    client.updateExperience(experience);
}
