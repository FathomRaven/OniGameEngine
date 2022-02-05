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

//Constructer and destructer

GameManager::GameManager()
{
    //Declare that the game is not quit yet
    mQuit = false;

    //Create graphics instance and check if it's created
    mGraphics = Graphics::Instance();

    if(!Graphics::Initialized())
        mQuit = true;

    //Create AssetManager instance
    mAssetMgr = AssetManager::Instance();
    //Create InputManager instance
    mInputMgr = InputManager::Instance();

    mAudioMgr = AudioManager::Instance();

    cameraMgr = CameraManager::Instance();

    physMgr = PhysicsManager::Instance();
    physMgr->SetLayerCollisionMask(PhysicsManager::CollisionLayers::Friendly, PhysicsManager::CollisionFlags::Tile);

    //Create timer instance
    mTimer = Timer::Instance();

    cameraMgr->AddCamera();
    
    cameraMgr->SetActiveCamera(0);

    playerOne = new Player();
    tile1 = new Tile();
    tile1->Pos(Vector2(300.0f, 500.0f));

    tile2 = new Tile();
    tile2->Pos(Vector2(140.0f, 660.0f));
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

    delete playerOne;
    playerOne = nullptr;

    delete tile1;
    tile1 = nullptr;
}

void GameManager::EarlyUpdate()
{
    mTimer->Reset();
    mInputMgr->Update();
}

void GameManager::Update()
{
    playerOne->Update();
}

void GameManager::Render()
{
    mGraphics->ClearBackBuffer();

    playerOne->Render();
    tile1->Render();
    tile2->Render();

    mGraphics->Render();
}

void GameManager::LateUpdate()
{
    physMgr->Update();
    mInputMgr->UpdatePrevInput();
}

//Run the main game loop. This is the big guy

void GameManager::Run()
{   
    //mAudioMgr->PlayMusic("Dogsong_music.wav", -1);
    //Loop runs as long as the game isn't quit
    while (!mQuit)
    {
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
        //Loop if the deltaTime is at the right rate
        if(mTimer->DeltaTime() >= (1.0f / FRAME_RATE))
        {
            //printf("DeltaTime: %F\n", mTimer->DeltaTime());

            EarlyUpdate();
            Update();
            LateUpdate();
            Render();

        }
    }
}