#include "GameManager.hpp"

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

//Constructer and destructor

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