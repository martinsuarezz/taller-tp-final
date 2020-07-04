#include <string.h>
#include "StopMoveIntention.h"
#include "Intention.h"
#include "../Sender.h"

StopMoveIntention::StopMoveIntention(){}

void StopMoveIntention::execute(Sender& game){
    game.stopMovementPlayer();
}
