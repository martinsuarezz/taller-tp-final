#include "TossIntention.h"
#include "Intention.h"
#include "../Sender.h"

TossIntention::TossIntention(int slot): slot(slot){}

void TossIntention::execute(Sender& game){
    game.tossItem(slot);
}

TossIntention::~TossIntention() {}
