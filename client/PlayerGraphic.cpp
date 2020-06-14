#include "PlayerGraphic.h"
#include "AssetsLoader.h"

PlayerGraphic::PlayerGraphic(AssetsLoader& assets):assets(assets), x(0), y(0){
    rectangles[0].x =   0;
    rectangles[0].y = 145;
    rectangles[0].w =  25;
    rectangles[0].h =  45;

    rectangles[1].x =  25;
    rectangles[1].y = 145;
    rectangles[1].w =  25;
    rectangles[1].h =  45;

    rectangles[2].x =  50;
    rectangles[2].y = 145;
    rectangles[2].w =  25;
    rectangles[2].h =  45;

    rectangles[3].x =  75;
    rectangles[3].y = 145;
    rectangles[3].w =  25;
    rectangles[3].h =  45;

    rectangles[4].x = 100;
    rectangles[4].y = 145;
    rectangles[4].w =  25;
    rectangles[4].h =  45;
}

void PlayerGraphic::render(int frame){
    SDL_Rect* rect = &rectangles[frame];
    x += 1;
    /*
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 145;
    rect.h = 45;
    rect.w = 25;
    */
    assets.getTexture(0).render(x, y, rect);
}

void PlayerGraphic::moveRight(){
}
