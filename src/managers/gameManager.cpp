/*
# -------------------
#   Oni Game Engine 
# -------------------
#
# Credit to Ather Omar for the base engine
#
# Use:
# Create instances of singletons in GameManager
# Update and render them in GameManager's loop
# Can also create objects
#
# GameEntity is the base class from which all other entities inherit
# Can be parented to another GameEntity
# Has local and world pos, rotation, and scale
# Local is the exact space on the screen, world is space according to parents
#
# PhysEntity is an GameEntity with collisions
# Can have box or circle colliders
#
# Texture is a GameEntity that renders as a SDL_Texture
# Can be a texture or text 
#
# AnimatedTexture is a texture that uses a spritesheet to create an animation
# Inherits from texture
#
# Cursor is a simple entity that is always at the mouse position, used for collisions
#
# Cameras are simple GameEntities that can be set to be the active camera with the cameramanager
# All textures are rendered in respect to the active cameras position
#
# Buttons are modified textures that collide with the cursor
#
*/



//TODO:
/*
Terminology: 
! Means error
// Meanings it's being ignored for now
* Is worked on
This all works best with VSCode bettercomments extension
*/

//Docs

//! Occasional odd collision
    //? More info needed
//Rework collision to use maps instead of enums
//Animator State
//Random class
//Improve comments
    /*
    Some poor wording throughout
    Add in param info
    Spell checking
    */
//Collision assets in engine code itself, not in individual projects
//// Particle engine
//// Camera zooming

#include "GameManager.hpp"
using namespace oni;

//Basic singleton instance stuff

GameManager* GameManager::sInstance = nullptr;

GameManager* GameManager::Instance()
{
    if (sInstance == nullptr)
        sInstance = new GameManager();
    
    return sInstance;
}

void GameManager::Release()
{
    delete sInstance;
    sInstance = nullptr;
}

//Constructor and destructor

GameManager::GameManager()
{
    //Declare that the game is not quit yet
    mQuit = false;

    //Create graphics instance and check if it's created
    mGraphics = Graphics::Instance();

    if(!Graphics::Initialized())
        mQuit = true;

    mAssetMgr = AssetManager::Instance();
    mInputMgr = InputManager::Instance();
    mAudioMgr = AudioManager::Instance();
    cameraMgr = CameraManager::Instance();
    physMgr = PhysicsManager::Instance();
    mTimer = Timer::Instance();
    mCursor = Cursor::Instance();
    
    cameraMgr->AddCamera();
    cameraMgr->SetActiveCamera(0);

    mCursor->Parent(cameraMgr->activeCamera);

    physMgr->SetLayerCollisionMask(PhysicsManager::CollisionLayers::UI, PhysicsManager::CollisionFlags::Mouse);;
}

GameManager::~GameManager()
{
    //Clean up everything
    AssetManager::Release();
    mAssetMgr = nullptr;

    PhysicsManager::Release();
    physMgr = nullptr;

    Graphics::Release();
    mGraphics = nullptr;

    InputManager::Release();
    mInputMgr = nullptr;

    AudioManager::Release();
    mAudioMgr = nullptr;

    CameraManager::Release();
    cameraMgr = nullptr;

    Timer::Release();
    mTimer = nullptr;

    Cursor::Release();
    mCursor = nullptr;

    for (int i = 0; i < (int)mEntityRender.size(); i++)
    {
        delete mEntityRender[i];
        mEntityRender[i] = nullptr;
    }

    for (int i = 0; i < (int)mEntityUpdate.size(); i++)
    {
        delete mEntityUpdate[i];
        mEntityUpdate[i] = nullptr;
    }
}

void GameManager::EarlyUpdate()
{
    mTimer->Reset();
    mInputMgr->Update();
}

void GameManager::Update()
{
    //Update objects in here

    mCursor->Update();

    for (int i = 0; i < (int)mEntityUpdate.size(); i++)
    {
        mEntityUpdate[i]->Update();
    }
}

void GameManager::Render()
{
    mGraphics->ClearBackBuffer();

    //Render things in here

    for (int i = 0; i < (int)mEntityRender.size(); i++)
    {
        mEntityRender[i]->Render();
    }
    
    mGraphics->Render();
}

void GameManager::LateUpdate()
{
    physMgr->Update();
    mInputMgr->UpdatePrevInput();
}

void GameManager::AddToUpdates(GameEntity* entity)
{
    mEntityUpdate.push_back(entity);
}

void GameManager::AddToRenders(GameEntity* entity)
{
    mEntityRender.push_back(entity);
}

bool GameManager::FrameLimit()
{
    return mTimer->DeltaTime() >= (1.0f / FRAME_RATE);
}

//Run the main game loop. This is the big guy

bool GameManager::Run()
{   
    mQuit = false;
    //Loop runs as long as the game isn't quit

    //Update the timer
    mTimer->Update();

    //As long as there are SDL events, keep running this
    while (SDL_PollEvent(&mEvents) != 0)
    {
        //If close button was hit on window, quit the application
        if (mEvents.type == SDL_QUIT)
        {
            mQuit = true;
        }
        
    }
    return mQuit;
}