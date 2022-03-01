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
    //Instance stuff
    static AssetManager* Instance();
    static void Release();
    //Get texture from texture manager @param filename the filename of the image 
    SDL_Texture* GetTexture(std::string filename);
    //Get font texture from font map. Creates the font if it doesn't exist
    //@param filename name of the ttf file @param size the size of the font @param color the color of the font
    TTF_Font* GetFont(std::string filename, int size);
    SDL_Texture* GetText(std::string text, std::string filename, int size, SDL_Color color);

    Mix_Music* GetMusic(std::string filename);
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

