/*
Asset manager for keeping track of different assets
Contains textures, textures made from text, and fonts
*/
#pragma once
#include "Graphics.hpp"
#include <SDL2/SDL_mixer.h>
#include <map>

namespace oni
{
//AssetManager class, singleton
class AssetManager {

public:
    //Access the assetManager instance 
    static AssetManager* Instance();
    //Release the assetManager
    static void Release();

    /**
     * @brief Returns a texture from the assetManager
     * @param filename Name of the texture to return 
    */
    SDL_Texture* GetTexture(std::string filename);

    /**
     * @brief Return a TTF_Font from the assetManager
     * @param filename Name of the font to return
     * @param size Size of the font to return 
    */
    TTF_Font* GetFont(std::string filename, int size);

    /**
     * @brief Return a texture of some text
     * @param text Text in the texture
     * @param filename Name of the font for the text
     * @param size Size of the font
     * @param color Color of the text  
    */
    SDL_Texture* GetText(std::string text, std::string filename, int size, SDL_Color color);

    /**
     * @brief Return a music variable
     * @param filename Name of the music file 
    */
    Mix_Music* GetMusic(std::string filename);

    /**
     * @brief Return a sound effect variable
     * @param filename Name of the sound effect file 
    */
    Mix_Chunk* GetSFX(std::string filename);


private:
    //Instance
    static AssetManager* sInstance;
    //Map of textures, with the path to them and the texture info
    std::map<std::string, SDL_Texture*> mTextures;
    std::map<std::string, TTF_Font*> mFonts;
    std::map<std::string, SDL_Texture*> mText;
    std::map<std::string, Mix_Music*> mMusic;
    std::map<std::string, Mix_Chunk*> mSFX;

    std::string basePath;

    //-----
    //Construct and destruct
    AssetManager();
    ~AssetManager();

};   
}

