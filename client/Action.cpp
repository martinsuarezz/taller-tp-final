#include "Action.h"
#include "Animation.h"
#include "PlayerGraphic.h"
#include <vector>

Action::Action(PlayerGraphic& player): player(player){

}

void Action::render(){
    std::vector<Animation>::iterator it;
    for(it = animations.begin(); it != animations.end(); it++)
        it->render(player.getRelativeX(), player.getRelativeY());
}