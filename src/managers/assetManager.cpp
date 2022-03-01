#include "AssetManager.hpp"
using namespace oni;

//Basic singleton stuff

AssetManager* AssetManager::sInstance = nullptr;

AssetManager* AssetManager::Instance()
{
    if(sInstance == nullptr)
        sInstance = new AssetManager;

    return sInstance;
}

void AssetManager::Release()
{
    delete sInstance;
    sInstance = nullptr;
}

//Construct, empty

AssetManager::AssetManager()
{
    //Gets path to exe, checks if it's null
    const char* fullPathPointer = SDL_GetBasePath();

    if (fullPathPointer == nullptr)
    {
        printf("Failed to get path to exe: %s\n", SDL_GetError());
    }
    //Creates fullpath out of fullPathPointer and gives it the filename, and assets info
    basePath = fullPathPointer;
    delete fullPathPointer;
    fullPathPointer = nullptr;
}
//Clears the texture map, makes sure to destroy all textures
AssetManager::~AssetManager()
{
    //For every texture in the map, check if the second texture is cleared. If not, destroy it
    for (auto tex : mTextures) 
    {
        if (tex.second != nullptr)
        {
            SDL_DestroyTexture(tex.second);
        }
    }

    mTextures.clear();

    for (auto text : mText) 
    {
        if (text.second != nullptr)
        {
            SDL_DestroyTexture(text.second);
        }
    }

    mText.clear();

    for (auto font : mFonts) 
    {
        if (font.second != nullptr)
        {
            TTF_CloseFont(font.second);
        }
    }

    mFonts.clear();

    for (auto sfx : mSFX) 
    {
        if (sfx.second != nullptr)
        {
            Mix_FreeChunk(sfx.second);
        }
    }

    mSFX.clear();

    for (auto music : mMusic) 
    {
        if (music.second != nullptr)
        {
            Mix_FreeMusic(music.second);
        }
    }

    mMusic.clear();
}
//Get texture info
SDL_Texture* AssetManager::GetTexture(std::string filename)
{

    std::string fullPath = basePath + "assets/" + filename;
    //Checks if texture exists, creates it if not
    if(mTextures[fullPath] == nullptr)
    {
        mTextures[fullPath] = Graphics::Instance()->LoadTexture(fullPath);
        
        if(mTextures[fullPath] == nullptr)
            printf("Texture Loading Error: Texture-%s, Error-%s", filename.c_str(), IMG_GetError());
    }
    
    return mTextures[fullPath];
}

TTF_Font* AssetManager::GetFont(std::string filename, int size)
{
    std::string fullPath = basePath + "assets/" + filename;

    std::string key = fullPath + (char)size;
    //Check if font exists, create it if not
    if(mFonts[key] == nullptr)
    {        
        mFonts[key] = TTF_OpenFont(fullPath.c_str(), size);

        if(mFonts[key] == nullptr)
            printf("Font Loading Error: Font-%s Error-%s", filename.c_str(), TTF_GetError());
    }
    
    return mFonts[key];
}


SDL_Texture* AssetManager::GetText(std::string text, std::string filename, int size, SDL_Color color)
{
    TTF_Font* font = GetFont(filename, size);

    std::string key = text + filename + (char)size + (char)color.r + (char)color.b + (char)color.g + (char)color.a;

    if(mText[key] == nullptr)
    {
        mText[key] = Graphics::Instance()->CreateTextTexture(font, text, color);
    }

    return mText[key];
}

Mix_Music* AssetManager::GetMusic(std::string filename)
{
    std::string fullPath = basePath + "assets/" + filename;

    if(mMusic[fullPath] == nullptr)
    {
        mMusic[fullPath] = Mix_LoadMUS(fullPath.c_str());
        if(mMusic[fullPath] == nullptr)
            printf("Music Loading Error: File-%s Error-%s", filename.c_str(), Mix_GetError());
    }

    return mMusic[fullPath];
}

Mix_Chunk* AssetManager::GetSFX(std::string filename)
{
    std::string fullPath = basePath + "assets/" + filename;
    
    if(mSFX[fullPath] == nullptr)
    {
        mSFX[fullPath] = Mix_LoadWAV(fullPath.c_str());
        if(mSFX[fullPath] == nullptr)
            printf("SFX Loading Error: File-%s Error-%s", filename.c_str(), Mix_GetError());
    }
    return mSFX[fullPath];
}