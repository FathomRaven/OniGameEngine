/*
Graphics, contains window and renderer info
*/
#pragma once

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>

namespace oni
{
    class Graphics
    {
    public:
        //Width of the window
        int SCREEN_WIDTH;
        //Height of the window
        int SCREEN_HEIGHT;
        //Title of the windows
        std::string WINDOW_TITLE;

        SDL_Color refreshColor;
        //Instance functions
        static Graphics* Instance(std::string winTitle = "Test", int winWidth = 1024, int winHeight = 1024, SDL_Color winColor = {255, 255, 255, 255});
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
        Graphics(std::string winTitle, int winWidth, int winHeight, SDL_Color winColor);
        ~Graphics();
        //Init function
        bool Init();  

    };
}