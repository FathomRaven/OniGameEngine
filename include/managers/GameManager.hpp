/*
GameManager singleton class. Handles most the main game loop
*/
#pragma once

#include "AudioManager.hpp"
#include "AnimatedTexture.hpp"
#include "Button.hpp"

class GameManager{
public:    
    //Instance stuff
    
    static GameManager* Instance();
    static void Release();
    //Run loop
    bool Run();

    bool FrameLimit();
    
    void AddToRenders(GameEntity* entity);
    void AddToUpdates(GameEntity* entity);

    void EarlyUpdate();
    void Update();
    void LateUpdate();

    void Render();
private:
    //Instance 
    static GameManager* sInstance;
    //The framerate to keep the game at
    const int FRAME_RATE = 60;
    //If quit yet
    bool mQuit;
    //Various Managers
    Graphics* mGraphics;
    AssetManager* mAssetMgr;
    InputManager* mInputMgr;
    AudioManager* mAudioMgr;
    CameraManager* cameraMgr;
    PhysicsManager* physMgr;
    //Timer
    Timer* mTimer;
    
    Cursor* mCursor;

    //Different events
    SDL_Event mEvents;

    std::vector<GameEntity*> mEntityRender;
    std::vector<GameEntity*> mEntityUpdate;

    //Construct and destruct

    GameManager();
    ~GameManager();
};