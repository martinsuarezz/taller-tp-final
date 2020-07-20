#include "QuitIntention.h"
#include "Intention.h"
#include "../Sender.h"

QuitIntention::QuitIntention() {}

void QuitIntention::execute(Sender& game){
    game.close();
}
