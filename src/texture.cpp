#include "Texture.hpp"
//Texture construct
Texture::Texture(std::string filename)
{
    //Get graphics instance
    mGraphics = Graphics::Instance();
    cameraMgr = CameraManager::Instance();
    //Get the texture from the assetManager
    mTex = AssetManager::Instance()->GetTexture(filename);
    //Get the attributes of a texture
    SDL_QueryTexture(mTex, NULL, NULL, &mWidth, &mHeight);
    //Set to not be clipped
    mClipped = false;
    //Set rect width and height
    mRenderRect.w = mWidth;
    mRenderRect.h = mHeight;
}
//Secondary Construct
Texture::Texture(std::string filename, int x, int y, int w, int h)
{   
    //Get graphics instance
    mGraphics = Graphics::Instance();
    cameraMgr = CameraManager::Instance();
    //Get the texture from the assetManager
    mTex = AssetManager::Instance()->GetTexture(filename);
    //Clipped to true
    mClipped = true;
    //Set widths and heights
    mWidth = w;
    mHeight = h;

    mRenderRect.w = mWidth;
    mRenderRect.h = mHeight;

    mClipRect.x = x;
    mClipRect.y = y;
    mClipRect.w = mWidth;
    mClipRect.h = mHeight;
}

Texture::Texture(std::string text, std::string fontpath, int size, SDL_Color color)
{
    mGraphics = Graphics::Instance();
    cameraMgr = CameraManager::Instance();
    mTex = AssetManager::Instance()->GetText(text, fontpath, size, color);

    mClipped = false;

    SDL_QueryTexture(mTex, nullptr, nullptr, &mWidth, &mHeight);

    mRenderRect.w = mWidth;
    mRenderRect.h = mHeight;
}

//Destruct
Texture::~Texture()
{
    mTex = nullptr;
    mGraphics = nullptr;
}

Vector2 Texture::ScaledDimemsions()
{
    Vector2 scaledDimemsions = Scale(world);
    scaledDimemsions.x *= mWidth;
    scaledDimemsions.y *= mHeight;

    return scaledDimemsions;
}

//Render to screen
void Texture::Render()
{
    
    //Set positions
    Vector2 pos = Pos(world);
    Vector2 scale = Scale(world);

    if(cameraMgr->activeCamera != nullptr)
    {
        pos = Pos(world) - cameraMgr->activeCamera->Pos(world);
    }

    if(pos.x + ((mWidth * scale.x)/2) < 0 || pos.y + ((mHeight * scale.y)/2) < 0 ||
       pos.x - ((mWidth * scale.x)/2) > cameraMgr->activeCamera->cameraSize.x || pos.y - ((mHeight * scale.y)/2) > cameraMgr->activeCamera->cameraSize.y)
    {
        return;
    }

    // printf("Adjust: %f\n", pos.x);

    mRenderRect.x = (int)(pos.x - mWidth * scale.x * 0.5f);
    mRenderRect.y = (int)(pos.y - mHeight * scale.y * 0.5f);
    mRenderRect.w = (int)(mWidth * scale.x);
    mRenderRect.h = (int)(mHeight * scale.y);

    //Draw texture to screen
    mGraphics->DrawTexture(mTex, (mClipped)? &mClipRect : nullptr, &mRenderRect, Rotation(world));
}