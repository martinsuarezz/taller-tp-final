#include "AttackIntention.h"
#include "Intention.h"
#include "../Sender.h"

AttackIntention::AttackIntention(int x, int y): x(x), y(y){}

void AttackIntention::execute(Sender& game){
    game.attackEntity(x, y);
}
