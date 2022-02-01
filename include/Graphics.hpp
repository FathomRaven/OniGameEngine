/*
Graphics, contains window and renderer info
*/
#pragma once

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>

class Graphics
{
public:
    //Width of the window
    static const int SCREEN_WIDTH = 1024;
    //Height of the window
    static const int SCREEN_HEIGHT = 896;
    //Title of the windows
    const char* WINDOW_TITLE = "Testing";
    //Instance functions
    static Graphics* Instance();
    static void Release();
    static bool Initialized();
    //Load texture, and create texture from text
    SDL_Texture* LoadTexture(std::string path);
    SDL_Texture* CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color);
    //Clear renderer
    void ClearBackBuffer();
    //Draw a texture to the screen with the renderer
    void DrawTexture(SDL_Texture* tex, SDL_Rect* clip = nullptr, SDL_Rect* rend = nullptr, float angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE);
    //Present screen
    void Render();
    SDL_Renderer* mRenderer;
private:
    //Instance variables
    static Graphics* sInstance;
    static bool sInitalized;
    //Window and backbuffers
    SDL_Window* mWindow;
    SDL_Surface* mBackBuffer;
    //Renderer
 
    //Construct and destruct
    Graphics();
    ~Graphics();
    //Init function
    bool Init();  

};