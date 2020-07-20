#ifndef GAME_H
#define GAME_H

#include "../../MinGW/include/SDL2/SDL.h"
#include "../../MinGW/include/SDL2/SDL_image.h"
#include "../../MinGW/include/SDL2/SDL_ttf.h"

class Game {
   private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;

   public:
    Game();
    ~Game();
    int ticksLastFrame;
    bool IsRunning() const;
    void Initialize(int width, int height);
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();
};

#endif