/*
Texture class, come from gameEntity
*/
#pragma once
#include "GameEntity.hpp"
#include "AssetManager.hpp"
#include "CameraManager.hpp"

class Texture : public GameEntity
{

public:
    //Construct, construct overflow, and destruct
    Texture(std::string filename);
    Texture(std::string filename, int x, int y, int w, int h);
    Texture(std::string text, std::string fontpath, int size, SDL_Color color);
    ~Texture();
    //Render
    virtual void Render();

    Vector2 ScaledDimemsions();

protected:
    //Texture
    SDL_Texture* mTex;
    //Graphics instance
    Graphics* mGraphics;
    CameraManager* cameraMgr;
    //Width and height
    int mWidth, mHeight;
    //Clipping info
    bool mClipped;
    SDL_Rect mRenderRect;
    SDL_Rect mClipRect;    
};