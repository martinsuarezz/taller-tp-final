#include "Effect.h"
#include "Animation/Animation.h"
#include "Configuration.h"

Effect::Effect(Animation&& animation, int x, int y, int duration): 
                    animation(std::move(animation)),
                    finished(false), duration(duration), time(0){
    
    Configuration& config = Configuration::getInstance();
    this->x = x * config.getValue("tile_size") + config.getValue("mob_render_offset_x");
    this->y = y * config.getValue("tile_size") + config.getValue("mob_render_offset_y");
}

Effect::Effect(Effect&& other): animation(std::move(other.animation)),
                x(other.x), y(other.y), finished(other.finished), 
                duration(other.duration) {}

void Effect::render(int timeElapsed, int xScreen, int yScreen){
    if (finished)
        return;
    time += timeElapsed;
    if (time > duration)
        finished = true;
    animation.render(x - xScreen, y - yScreen, timeElapsed);
}

bool Effect::hasFinished(){
    return finished;
}
