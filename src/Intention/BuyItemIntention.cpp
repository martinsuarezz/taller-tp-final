#include "BuyItemIntention.h"
#include "Intention.h"
#include "../Sender.h"

BuyItemIntention::BuyItemIntention(int itemIndex): itemIndex(itemIndex){}

void BuyItemIntention::execute(Sender& game){
    game.buyItem(itemIndex);
}

BuyItemIntention::~BuyItemIntention() {}
