#include "Animation.h"
#include "Texture.h"
#include <iostream>

#define FRAMES_PER_LOOP 10

Animation::Animation(Texture& texture, int xInitial, int yInitial,
                        int xFinal, int yFinal): 
                        texture(texture), xInitial(xInitial), yInitial(yInitial),
                        xFinal(xFinal), yFinal(yFinal) {}

Animation::Animation(Animation&& other): texture(other.texture), areas(other.areas), 
                        xInitial(other.xInitial), yInitial(other.yInitial),
                        xFinal(other.xFinal), yFinal(other.yFinal) {}

void Animation::render(int frame){
    int x = xInitial + (xFinal - xInitial) * frame / FRAMES_PER_LOOP;
    int y = yInitial + (yFinal - yInitial) * frame / FRAMES_PER_LOOP;
    texture.render(x, y, &areas[frame % areas.size()]);
}

Animation& Animation::operator=(Animation&& other){
    this->texture = other.texture;
    this->areas = other.areas;
    this->xInitial = other.xInitial;
    this->yInitial = other.yInitial;
    this->xFinal = other.xFinal;
    this->yFinal = other.yFinal;
    return *this;
}

Animation::~Animation(){}