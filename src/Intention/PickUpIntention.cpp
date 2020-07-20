#include "PickUpIntention.h"
#include "Intention.h"
#include "../Sender.h"

PickUpIntention::PickUpIntention() {}

void PickUpIntention::execute(Sender& game){
    game.pickUpItem();
}

PickUpIntention::~PickUpIntention() {}
