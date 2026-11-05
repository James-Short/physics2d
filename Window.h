#pragma once
#include <SDL3/SDL.h>

class Window{
    public:
        SDL_Window* SDLWindow{nullptr};
        Window(){
            SDLWindow = SDL_CreateWindow(
                "Hello Window",
                1200, 800, 0
            );
        }
};