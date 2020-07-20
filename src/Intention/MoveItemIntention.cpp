#include "MoveItemIntention.h"
#include "Intention.h"
#include "../Sender.h"

MoveItemIntention::MoveItemIntention(int from, int to): from(from), to(to){}

void MoveItemIntention::execute(Sender& game){
    game.moveInventoryItem(from, to);
}

MoveItemIntention::~MoveItemIntention() {}
