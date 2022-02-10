/*
GameManager singleton class. Handles most the main game loop
*/
#pragma once

#include "AudioManager.hpp"
#include "InputManager.hpp"
#include "AnimatedTexture.hpp"
#include "CameraManager.hpp"
#include "PhysicsManager.hpp"
#include "Cursor.hpp"
#include "Button.hpp"

class GameManager{
public:    
    //Instance stuff
    
    static GameManager* Instance();
    static void Release();
    //Run loop
    void Run();

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

    //! Example code below

    Texture* mPlayer;
    Texture* mText;
    Texture* mExplainText;
    Button* mButton;

    //Construct and destruct

    GameManager();
    ~GameManager();

    void EarlyUpdate();
    void Update();
    void LateUpdate();

    void Render();
};