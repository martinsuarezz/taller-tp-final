#include <string.h>
#include "MoveIntention.h"
#include "Intention.h"
#include "../Sender.h"

MoveIntention::MoveIntention(int direction): direction(direction){}

void MoveIntention::execute(Sender& game){
    game.movePlayer(direction);
}
