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

    physMgr->SetLayerCollisionMask(PhysicsManager::CollisionLayers::UI, PhysicsManager::CollisionFlags::Mouse);

    /*
    Example code
    */
    //Create player texture, from simpleplayer image
    //Then scale and position it 
    mPlayer = new Texture("Simpleplayer.png");
    mPlayer->Scale(Vector2(0.5f, 0.5f));
    mPlayer->Pos(Vector2(mGraphics->SCREEN_WIDTH/2, mGraphics->SCREEN_HEIGHT/2));
    //Create text, from test.ttf font file
    mText = new Texture("Hello World!", "test.ttf", 32, {0, 0, 0, 255});
    mText->Pos(Vector2(mGraphics->SCREEN_WIDTH/2, 600.0f));
    
    mExplainText = new Texture("Use arrow keys to move around, hit 'D' for a cool sound", "test.ttf", 32, {0, 0, 0, 255});
    mExplainText->Pos(Vector2(mGraphics->SCREEN_WIDTH/2, 100.0f));
    //Create a button that will only be clicked once, with the text of "Press me"
    mButton = new Button("BoxCollider.png", "Press me", "test.ttf", 16, {0, 0, 0, 255}, true);
    mButton->Pos(Vector2(mGraphics->SCREEN_WIDTH/2, 800.0f));
    //Parent button to camera, and parent camera to player
    mButton->Parent(cameraMgr->activeCamera);
    cameraMgr->activeCamera->Parent(mPlayer);
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

    //Example Code
    
    delete mPlayer;
    mPlayer = nullptr;
    delete mButton;
    mButton = nullptr;
    delete mText;
    mText = nullptr;
    delete mExplainText;
    mExplainText = nullptr;
}

void GameManager::EarlyUpdate()
{
    mTimer->Reset();
    mInputMgr->Update();
}

void GameManager::Update()
{
    //Update objects in here

    //Example Code

    mCursor->Update();
    //Move player if arrow keys are down
    if(mInputMgr->KeyDown(SDL_SCANCODE_LEFT))
        mPlayer->Translate(VEC2_LEFT * 5.0f);
    if(mInputMgr->KeyDown(SDL_SCANCODE_RIGHT))
        mPlayer->Translate(VEC2_RIGHT * 5.0f);
    if(mInputMgr->KeyDown(SDL_SCANCODE_DOWN))
        mPlayer->Translate(VEC2_DOWN * 5.0f);
    if(mInputMgr->KeyDown(SDL_SCANCODE_UP))
        mPlayer->Translate(VEC2_UP * 5.0f);
    if(mInputMgr->KeyDown(SDL_SCANCODE_D))
        mAudioMgr->PlaySFX("boom.wav");

    mButton->Update();

    if(mButton->Clicked())
        mText->Rotate(1.0f);

}

void GameManager::Render()
{
    mGraphics->ClearBackBuffer();

    //Render things in here

    //Example Code
    mPlayer->Render();
    if(mButton->Clicked())
        mText->Render();
    
    mButton->Render();
    mExplainText->Render();
    mPlayer->Render();

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