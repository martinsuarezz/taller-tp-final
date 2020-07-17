#include "InteractIntention.h"
#include "Intention.h"
#include "../Sender.h"

InteractIntention::InteractIntention() {}

void InteractIntention::execute(Sender& game){
    game.interact();
}

InteractIntention::~InteractIntention() {}
