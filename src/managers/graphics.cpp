#include "Graphics.hpp"

using namespace oni;

//Basic singleton instance

Graphics* Graphics::sInstance = nullptr;
bool Graphics::sInitalized = false;

Graphics* Graphics::Instance()
{
    if (sInstance == nullptr)
        sInstance = new Graphics();
    
    return sInstance;
}

void Graphics::Release()
{
    delete sInstance;
    sInstance = nullptr;

    sInitalized = false;
}

bool Graphics::Initialized()
{
    return sInitalized;
}

//Constructor and destructor

Graphics::Graphics()
{
    mBackBuffer = nullptr;

    WINDOW_TITLE = Settings::Instance()->winTitle;
    SCREEN_WIDTH = Settings::Instance()->winWidth;
    SCREEN_HEIGHT = Settings::Instance()->winHeight;
    REFRESHCOLOR = Settings::Instance()->winRefreshColor;

    sInitalized = Init();
}

Graphics::~Graphics()
{
    //Destroy window, renderer, and quit IMG and SDL
    SDL_DestroyWindow(mWindow);
    mWindow = nullptr;

    SDL_DestroyRenderer(mRenderer);
    mRenderer = nullptr;

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

//Prepare and create the main systems

bool Graphics::Init()
{
    //Init video
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("SDL Init Error: %s\n", SDL_GetError());
        return false;
    }

    if(TTF_Init() < 0)
    {
        printf("TTF");
    }
    //Create window and throw error if failed
    mWindow = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(mWindow == nullptr)
    {
        printf("Window Creation Error: %s\n", SDL_GetError());
        return false;
    }
    //Create renderer and throw error if failed
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    if(mRenderer == nullptr)
    {
        printf("Renderer Creation Error: %s\n", SDL_GetError());
        return false;
    }
    //Set draw color
    SDL_SetRenderDrawColor(mRenderer, REFRESHCOLOR.r, REFRESHCOLOR.g, REFRESHCOLOR.b, REFRESHCOLOR.a);
    //Init SDL_image
    int flags = IMG_INIT_PNG;
    if(!(IMG_Init(flags) & flags))
    {
        printf("IMG Init Error %s\n", IMG_GetError());
        return false;
    }
    
    if(TTF_Init() == -1)
    {
        printf("TTF Init Error: %s\n", TTF_GetError());
        return false;
    }
    
    //Define the backbuffer
    mBackBuffer = SDL_GetWindowSurface(mWindow);
    
    return true;
}

//Function for loading textures, takes in a path to the file it's loading

SDL_Texture* Graphics::LoadTexture(std::string path)
{
    //Create the tex variable
    SDL_Texture* tex = nullptr;
    //Load a surface and make sure it's loaded, else throw an error
    SDL_Surface* surface = IMG_Load(path.c_str());
    if(surface == nullptr)
    {
        printf("Surface load Error: Path(%s) - Error(%s)\n", path.c_str(), IMG_GetError());
        return tex;
    }
    //Create the texture from the surface, and check it created correctly
    tex = SDL_CreateTextureFromSurface(mRenderer, surface);
    if(tex == nullptr)
    {
        printf("Create texture Error %s\n", IMG_GetError());
        return tex;
    }
    //Free surface and then return tex
    SDL_FreeSurface(surface);

    return tex;
}

SDL_Texture* Graphics::CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color)
{
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if(surface == nullptr)
    {
        printf("Text Render Error: %s\n", TTF_GetError());
        return nullptr;
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(mRenderer, surface);
    if(tex == nullptr)
    {
        printf("Text Texture Creation Error: %s\n", SDL_GetError());
        return nullptr;
    }

    SDL_FreeSurface(surface);
    return tex;
}

//Clears the renderer

void Graphics::ClearBackBuffer()
{
    SDL_RenderClear(mRenderer);
}

//Draws a texture with two main rects, clip = src, rend = dst

void Graphics::DrawTexture(SDL_Texture* tex, SDL_Rect* clip, SDL_Rect* rend, float angle, SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(mRenderer, tex, clip, rend, angle, nullptr, flip);
}

//Render to the screen

void Graphics::Render()
{
    SDL_RenderPresent(mRenderer);
}