#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Window.h"
#include "Ball.h"


int main(int, char**){
    SDL_Init(SDL_INIT_VIDEO);
    Window PhysicsWindow;

    Ball ball({50, 50}, 25);

    SDL_Renderer* renderer = SDL_CreateRenderer(
        PhysicsWindow.SDLWindow,
        nullptr
    );


    bool IsRunning = true;
    SDL_Event Event;

    Uint64 lastTime = SDL_GetTicks();

    while(IsRunning){
        while(SDL_PollEvent(&Event)){
            if(Event.type == SDL_EVENT_QUIT){
                IsRunning = false;
            }
        }

        Uint64 currentTime = SDL_GetTicks();

        float dt = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        ball.Update(dt);
        ball.Render(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_Quit();

    return 0;
}