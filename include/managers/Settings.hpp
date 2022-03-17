#pragma once

#include <string>
#include <map>
#include <SDL2/SDL_image.h>

namespace oni
{
    class Settings
    {    
    public:
        //@brief Return the Settings instance
        static Settings* Instance();
        
        //@brief Release the Settings instance
        static void Release();

        //Graphics Variables
        std::string winTitle;
        int winWidth, winHeight;
        SDL_Color winRefreshColor;
        
        bool debugColliders;

        void AddLayer(std::string layerName);
        std::map<std::string, int> collisionLayers;
    private:
        static Settings* instanceS;
        
        Settings();
        ~Settings();

    };
}