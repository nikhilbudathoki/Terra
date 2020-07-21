#ifndef GAME_H
#define GAME_H

#include "../../MinGW/include/SDL2/SDL.h"
#include "../../MinGW/include/SDL2/SDL_image.h"
#include "../../MinGW/include/SDL2/SDL_ttf.h"
#include "Component.h"
#include "Entity.h"
#include "EntityManager.h"

class AssetManager;

class Game {
   private:
    bool isRunning;
    SDL_Window *window;

   public:
    Game();
    ~Game();
    int ticksLastFrame = 0;
    bool IsRunning() const;
    static SDL_Renderer *renderer;
    static AssetManager *assetManager;
    void LoadLevel(int levelNumber);
    void Initialize(int width, int height);
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();
};

#endif
