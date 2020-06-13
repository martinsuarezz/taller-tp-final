#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "SDL2/SDL.h"
#include "Renderer.h"
#include "Texture.h"
#include <string>

class Screen {
    private:
    Texture background;
    SDL_Rect camera;

    //Check if the x value is valid or return a valid value.
    int checkBoundryX(int x) const;
    //Check if the y value is valid or return a valid value.
    int checkBoundryY(int y) const;

    public:
    //Create camera and load background image.
    Screen(const std::string & path, Renderer & renderer,
    int screen_w, int screen_h);
    //Deallocate resources
    ~Screen();

    //Set the screen size
    void setScreenSize(int width, int height);
    //Set position of the camera.
    void setPosition(int x, int y);
    //Move position of the camera.
    void movePosition(int x, int y);
    //Render the camera.

    //Get position x of the screen on the background.
    int getPositionX() const;
    //Get position y of the screen on the background.
    int getPositionY() const;
    //Get width of the screen.
    int getWidth() const;
    //Get height of the screen.
    int getHeight() const;

    //Render the screen.
    void render();
};


#endif
