/*
Graphics, contains window and renderer info
*/
#pragma once

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include "Settings.hpp"

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

        SDL_Color REFRESHCOLOR = {255, 255, 255, 255};
        
        //@brief Return the Graphics instance
        static Graphics* Instance();
        
        //@brief Release the Graphics instance
        static void Release();

        //@brief Return if Graphics is initialized or not
        static bool Initialized();

        /**
         * @brief Return a SDL_Texture* from an image
         * @param path Path to the image 
        */
        SDL_Texture* LoadTexture(std::string path);

        /**
         * @brief Create a text texture
         * @param font Font of the text
         * @param text Text to load as an image
         * @param color Color of the text
        */
        SDL_Texture* CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color);
        
        void ClearBackBuffer();
        
        //TODO: Comment out this function
        void DrawTexture(SDL_Texture* tex, SDL_Rect* clip = nullptr, SDL_Rect* rend = nullptr, float angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE);
        
        //TODO: Finish this function
        void DrawPoint(int x, int y, SDL_Color color);
        
        //@brief Render the screen
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
}