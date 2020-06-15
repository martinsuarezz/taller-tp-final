#include "Animation.h"
#include "Texture.h"

Animation::Animation(Texture& texture): texture(texture) {}

Animation::Animation(Animation&& other): texture(other.texture), areas(other.areas) {}

void Animation::render(int x, int y, int frame){
    texture.render(x, y, &areas[frame % areas.size()]);
}

Animation& Animation::operator=(Animation&& other){
    this->texture = other.texture;
    this->areas = other.areas;
    return *this;
}