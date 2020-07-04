#include "Action.h"
#include "../Animation/Animation.h"
#include "../Entity.h"
#include <vector>

Action::Action(Entity& entity): entity(entity){

}

void Action::render(){
    if (!entity.isOnScreen())
        return;
    std::vector<Animation>::iterator it;
    for(it = animations.begin(); it != animations.end(); it++)
        it->render(entity.getRelativeX(), entity.getRelativeY());
}