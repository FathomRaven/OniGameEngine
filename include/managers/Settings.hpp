#pragma once

#include <string>
#include <SDL2/SDL_image.h>

namespace oni
{
    class Settings
    {    
    public:
        static Settings* Instance();
        static void Release();

        //Graphics Variables
        std::string winTitle;
        int winWidth, winHeight;
        SDL_Color winRefreshColor;
        
        bool debugColliders;
    private:
        static Settings* instanceS;
        
        Settings();
        ~Settings();

    };
}