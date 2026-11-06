#pragma once
#include <vector>
#include <SDL3/SDL.h>
#include <cmath>

class Ball{
    public:
        float cx, cy;
        int radius;
        int segments = 26;
        float velocityX;
        float velocityY;
        float gravity;

        std::vector<float> color = {255.0, 0.0, 0.0, 1.0};
        Ball(std::vector<int> center, int radius, float gravity, float velocityX,
             float velocityY){
            cx = center[0], cy = center[1];
            this->radius = radius;
            this->segments = segments;
            this->gravity = gravity;
            this->velocityX = velocityX;
            this->velocityY = velocityY;
        }

        void Update(float dt){
            cx += velocityX * dt;
            cy += velocityY * dt;

            velocityY += gravity * dt;
        }

        void Render(SDL_Renderer* renderer){
            for(int i = 0; i < segments; i++){
                SDL_Vertex vertices[3] = {};

                vertices[0].position.x = cx;
                vertices[0].position.y = cy;
                vertices[0].color = {255.0, 0.0, 0.0, 1.0};

                const double PI = 3.141592653589793;

                float angle1 = 2 * PI * i / segments;
                float angle2 = 2 * PI * (i+1) / segments;
                
                vertices[1].position.x = cx + radius * std::cos(angle1);
                vertices[1].position.y = cy + radius * std::sin(angle1);
                vertices[1].color = {255.0, 0.0, 0.0, 1.0};

                vertices[2].position.x = cx + radius * std::cos(angle2);
                vertices[2].position.y = cy + radius * std::sin(angle2);
                vertices[2].color = {255.0, 0.0, 0.0, 1.0};

                SDL_RenderGeometry(renderer, nullptr, vertices, 3, nullptr, 0);
            }
        }
};