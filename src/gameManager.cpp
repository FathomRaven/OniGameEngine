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
    physMgr->SetLayerCollisionMask(PhysicsManager::CollisionLayers::UI, PhysicsManager::CollisionFlags::Mouse);
    physMgr->SetLayerCollisionMask(PhysicsManager::CollisionLayers::Friendly, PhysicsManager::CollisionFlags::Tile);

    //Create timer instance
    mTimer = Timer::Instance();

    cameraMgr->AddCamera();
    
    cameraMgr->SetActiveCamera(0);

    mCursor = Cursor::Instance();
    mCursor->Parent(cameraMgr->activeCamera);

    testButton = new Button("button.png", "Play", "emulogic.ttf", 48, {0, 0, 0, 255}, true);
    testButton->Pos(Vector2(512.0f, 750.0f));
    testButton->Parent(cameraMgr->activeCamera);

    playerOne = new Player();
    playerOne->Pos(Vector2(600.0f, 600.0f));
    
    tile1 = new Tile();
    tile1->Pos(Vector2(300.0f, 500.0f));

    tile2 = new Tile();
    tile2->Pos(Vector2(140.0f, 660.0f));
    
    cameraMgr->activeCamera->Parent(playerOne);
    // cameraMgr->activeCamera->Pos(Vector2(playerOne->Pos().x - (mGraphics->SCREEN_WIDTH / 2), playerOne->Pos().y - (mGraphics->SCREEN_HEIGHT / 2)));
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

    delete playerOne;
    playerOne = nullptr;

    delete tile1;
    tile1 = nullptr;

    delete tile2;
    tile1 = nullptr;
}

void GameManager::EarlyUpdate()
{
    mTimer->Reset();
    mInputMgr->Update();
}

void GameManager::Update()
{
    // if(mInputMgr->KeyDown(SDL_SCANCODE_D))
    //     playerOne->Scale(playerOne->Scale() + (VEC2_ONE / 4));
    // if(mInputMgr->KeyDown(SDL_SCANCODE_A))
    //     playerOne->Scale(playerOne->Scale() + -(VEC2_ONE / 4));
    // if(mInputMgr->KeyDown(SDL_SCANCODE_W))
    //     cameraMgr->activeCamera->Translate(Vector2(0.0f, -5.0f));
    // if(mInputMgr->KeyDown(SDL_SCANCODE_S))
    //     cameraMgr->activeCamera->Translate(Vector2(0.0f, 5.0f));
    testButton->Update();
    playerOne->Update();
    mCursor->Update();
}

void GameManager::Render()
{
    mGraphics->ClearBackBuffer();

    mCursor->Render();

    testButton->Render();
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
    // mAudioMgr->PlayMusic("Dogsong_music.wav", -1, 128);
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